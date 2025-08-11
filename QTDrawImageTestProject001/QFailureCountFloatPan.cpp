#include "QFailureCountFloatPan.h"
#include <QFont>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include "QConstantString.h"
#include "QBoxItem.h"
#include "QTDrawImageTestProject001.h"
#include <QVector>


QFailureCountFloatPan::QFailureCountFloatPan(QWidget *parent /*=Q_NULLPTR*/, QString text)
	:IFramelessWindow(FORM_TYPE_NONE, parent)
	, m_pEdtDefectProductTotal(nullptr)
	, m_pEdtFailureTotal(nullptr)
{
	m_pStatistic = new DEFECT_STATISTIC_t();
	int nSize1 = sizeof(m_pStatistic);
	int nSize2 = sizeof(DEFECT_STATISTIC_t);
	//m_pDetectParam = QDetectParamManager::Instance()->CurrParam();
	IFramelessWindow::InitLayout(/*"versionbackground"*/);
	SetupTitleBar(CS_DETECT_DEFECT_TYPE_STATISTICS, "versionttitle", "versioncaption");
	//AddCloseButton();
	
	SetMoveEnable(false);
	SetScaleEnable(false);
	setWindowFlag(Qt::WindowStaysOnTopHint);
	resize(321, 300);
	//setFixedHeight(500);
	InitLayout();
	GetCaptureWidget()->setVisible(false);
}

QFailureCountFloatPan::~QFailureCountFloatPan()
{
	//delete ui;
}

void QFailureCountFloatPan::UpdateFailureInfo()
{
	static int s_count = 0; s_count++;
	m_pEdtDefectProductTotal->setText(QString("%1").arg(s_count, 5, 10, QLatin1Char('0')));
	m_pEdtFailureTotal->setText(QString("%1").arg(m_pStatistic->defectCountTotal, 5, 10, QLatin1Char('0')));
	
	int nDefectTypeCount = 0;
	QVector< DEFECT_STATISTIC_ITEM_t> oVtDefect;
	for (; nDefectTypeCount < DEFECT_NUMBER_MAX; nDefectTypeCount++)
	{
		if (m_pStatistic->defects[nDefectTypeCount].used == false)
			break;
		DEFECT_STATISTIC_ITEM_t oItem(m_pStatistic->defects[nDefectTypeCount]);
		oVtDefect.append(oItem);
	}
	qSort(oVtDefect.begin(),oVtDefect.end(), DEFECT_STATISTIC_ITEM_t::compare);
	
	//update ui 
	int nTableRow = m_pTwDefectInfo->rowCount();
	if (nTableRow < oVtDefect.size())  //add
	{
		m_pTwDefectInfo->setRowCount(oVtDefect.size());
		for (; nTableRow < oVtDefect.size(); nTableRow++)
		{
			m_pTwDefectInfo->setItem(nTableRow, 0, new QTableWidgetItem(QString("")));
			QTableWidgetItem* pItem = new QTableWidgetItem(QString("")); pItem->setTextAlignment(Qt::AlignCenter);
			m_pTwDefectInfo->setItem(nTableRow, 1, pItem);
			pItem = new QTableWidgetItem(QString("")); pItem->setTextAlignment(Qt::AlignRight);
			m_pTwDefectInfo->setItem(nTableRow, 2, pItem);
		}	
		if (nTableRow > 5)
		{
			resize(321, 300 + (35 * (nTableRow - 5)));
		}
	}

	//update content
	for (int nIndex = 0; nIndex < oVtDefect.size(); nIndex++)
	{
		m_pTwDefectInfo->item(nIndex, 0)->setText(QString::fromLocal8Bit(oVtDefect[nIndex].defectName));
		m_pTwDefectInfo->item(nIndex, 1)->setText(QString::number(oVtDefect[nIndex].count));
		float fRatio = oVtDefect[nIndex].count *1.0f / m_pStatistic->defectCountTotal * 100;
		m_pTwDefectInfo->item(nIndex, 2)->setText(QString::number(fRatio, 'f', 2) + "%");		
	}

}

void QFailureCountFloatPan::InitLayout()
{
	QVBoxLayout* pVLayout = new QVBoxLayout();
	pVLayout->setMargin(0);
	pVLayout->setSpacing(3);
	m_pEdtDefectProductTotal = new QLineEdit();
	m_pEdtDefectProductTotal->setReadOnly(true);
	m_pEdtDefectProductTotal->setProperty("behavior", "bigbold");
	m_pEdtFailureTotal = new QLineEdit();
	m_pEdtFailureTotal->setReadOnly(true);
	m_pEdtFailureTotal->setProperty("behavior", "bigbold");
	pVLayout->addWidget(new QBoxItem(CS_DETECT_PRODUCT_FAILURE_COUNT, m_pEdtDefectProductTotal));
	pVLayout->addWidget(new QBoxItem(CS_DETECT_DEFECT_COUNT_TOTAL, m_pEdtFailureTotal));

	QFont font;
	font.setPixelSize(20);
	font.setBold(true);
	m_pEdtDefectProductTotal->setFont(font);
	m_pEdtFailureTotal->setFont(font);

	m_pTwDefectInfo = new QTableWidget();
	m_pTwDefectInfo->setColumnCount(3);
	m_pTwDefectInfo->setRowCount(0);
	m_pTwDefectInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
	m_pTwDefectInfo->setShowGrid(true);
	m_pTwDefectInfo->setGridStyle(Qt::SolidLine);
	m_pTwDefectInfo->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	m_pTwDefectInfo->resizeRowsToContents();
	m_pTwDefectInfo->verticalHeader()->setVisible(false);
	m_pTwDefectInfo->setHorizontalHeaderItem(0, new QTableWidgetItem(TABLE_FAILURE_COUNT_ITEM_NAME[0]));
	m_pTwDefectInfo->setHorizontalHeaderItem(1, new QTableWidgetItem(TABLE_FAILURE_COUNT_ITEM_NAME[1]));
	m_pTwDefectInfo->setHorizontalHeaderItem(2, new QTableWidgetItem(TABLE_FAILURE_COUNT_ITEM_NAME[2]));
	m_pTwDefectInfo->setSortingEnabled(false);
	m_pTwDefectInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::Fixed);
	//m_pTwDefectInfo->setVisible(false);
	m_pTwDefectInfo->setObjectName("defectstatisticwidget");
	QHeaderView* pHeaderView = m_pTwDefectInfo->horizontalHeader();
	pHeaderView->setHighlightSections(false);
	pHeaderView->setSectionResizeMode(QHeaderView::Fixed);
	pHeaderView->setSectionsMovable(false);
	pHeaderView->resizeSection(0, 120);
	pHeaderView->resizeSection(1, 70);
	pHeaderView->resizeSection(2, 70);
	pHeaderView->setStretchLastSection(true);
	pVLayout->addWidget(m_pTwDefectInfo); 
	
	QFrame* pContentFrame = new QFrame();
	pContentFrame->setObjectName("floatplancontent");
	pContentFrame->setLayout(pVLayout);
	AppendWidget(pContentFrame);
}

