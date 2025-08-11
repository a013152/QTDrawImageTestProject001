#include "QTDrawImageTestProject001.h"
#include "QImageDetectFrame.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTime>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include "QTipsLabel.h"

#include "QFailureCountFloatPan.h"
#include <QTextCodec>
#include <cstdlib>
#include <ctime>
#include <QVector>
#include <QMap>
#include <QLineEdit>
#include "QAboutSoftwareWidget.h"
#include "QExportLogDialog.h"
#include <QDateTime>
#include <QLCDNumber>
#include <QTimer>
#include <QStackedWidget>
#include <QGridLayout>
#include <QList>
#include "QNoWheelComboBox.h"
#include <QStyledItemDelegate>
#include "QDefectDataDef.h"
#include "QMono8ImageWidget.h"

const char* const STR_USER_DATA = "userData";
const char* const STR_STYLE_1 = "background-color:grey; font-weight: bold;  color:black; min-width:125px;max-width:125px;";
const char* const STR_STYLE_2 = "background-color:green; font-weight: bold; color:black; min-width:125px;max-width:125px;";
const char* const STR_STYLE_3 = "background-color:red; font-weight: bold;   color:black; min-width:125px;max-width:125px;";
const char* const STR_STYLE_WIDTH125 = "min-width:125px;max-width:125px;";
const char* const STR_STYLE_WIDTH185 = "min-width:185px;max-width:185px;";
const char* const STR_STYLE_BLACK = "color:black;";



void CollectPrevPredictData(QMap<QString, PREV_PREDICT_t*>* pMap, \
	QVector<COMBO_PARSE_DEFECT_ITEM_t*>* pVtMultParseDefect, \
	QVector<QVector<DEFECT_RESULT_t>>* pVtTotalDefectResult)
{
	for (int nIndex = 0; nIndex < 3; nIndex++)
	{
		DEFECT_RESULT_t oResult(nIndex);
		//QVector<DEFECT_RESULT_t>* pVtDefectResults = new QVector<DEFECT_RESULT_t>();
		//pVtDefectResults->append(oResult);
		QVector<DEFECT_RESULT_t> vtDefectResults;
		vtDefectResults.append(oResult);
		pVtTotalDefectResult->append(vtDefectResults);

		COMBO_PARSE_DEFECT_ITEM_t* pDefectItem = new COMBO_PARSE_DEFECT_ITEM_t();
		pDefectItem->pDefectResult = &((*pVtTotalDefectResult)[nIndex]);
		pVtMultParseDefect->append(pDefectItem);

	}
}
void TestFileInfo();
void TestQLineEditRE(QVBoxLayout* pMainLayout);
void TestBottleVector();
void TestBottleQMap();
void TestComboBox(QVBoxLayout* pMainLayout);
QTDrawImageTestProject001::QTDrawImageTestProject001(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	QHBoxLayout* pHLayout_Tab1 = new QHBoxLayout();
	pHLayout_Tab1->setMargin(0);
	pHLayout_Tab1->setSpacing(10);
	QPushButton* pBtnTab1 = new QPushButton("Page1");
	QPushButton* pBtnTab2 = new QPushButton("Page2");
	QPushButton* pBtnTab3 = new QPushButton("Page3");
    QPushButton* pBtnTab4 = new QPushButton("Page4");
    QPushButton* pBtnTab5 = new QPushButton("Page5");
	pBtnTab1->setProperty(STR_USER_DATA, 0);
	pBtnTab2->setProperty(STR_USER_DATA, 1);
	pBtnTab3->setProperty(STR_USER_DATA, 2);
    pBtnTab4->setProperty(STR_USER_DATA, 3);
    pBtnTab5->setProperty(STR_USER_DATA, 4);
	pHLayout_Tab1->addWidget(pBtnTab1);
	pHLayout_Tab1->addWidget(pBtnTab2);
	pHLayout_Tab1->addWidget(pBtnTab3); //pBtnTab3->setVisible("false");
    pHLayout_Tab1->addWidget(pBtnTab4);
    pHLayout_Tab1->addWidget(pBtnTab5);
    setProperty("behavior", "data_reset");
	m_pStackedWidget = new QStackedWidget();

	CreatePage1();
	CreatePage2();
	CreatePage3();
    CreatePage4();
    CreatePage5();
	m_pStackedWidget->setCurrentIndex(0);

	QVBoxLayout* pMainLayout = new QVBoxLayout();
	pMainLayout->addLayout(pHLayout_Tab1);
	pMainLayout->addWidget(m_pStackedWidget);
	ui.centralWidget->setLayout(pMainLayout);

	QObject::connect(pBtnTab1, &QPushButton::clicked, this, &QTDrawImageTestProject001::OnClickSwitchPage);
	QObject::connect(pBtnTab2, &QPushButton::clicked, this, &QTDrawImageTestProject001::OnClickSwitchPage);
	QObject::connect(pBtnTab3, &QPushButton::clicked, this, &QTDrawImageTestProject001::OnClickSwitchPage);
    QObject::connect(pBtnTab4, &QPushButton::clicked, this, &QTDrawImageTestProject001::OnClickSwitchPage);
    QObject::connect(pBtnTab5, &QPushButton::clicked, this, &QTDrawImageTestProject001::OnClickSwitchPage);
	

	//test FileInfo
	TestFileInfo();

	//add 

	//test QVector
	TestBottleVector();

	//
	TestBottleQMap();

	m_pThread1 = new QThreadTest1();
	m_pThread2 = new QThreadTest2();
	m_pThread2->SetWaitCondition(m_pThread1->GetWaitCondition());
	m_pThread2->SetMutex(m_pThread1->GetMutex());
}

void QTDrawImageTestProject001::OnClickLoadImage()
{
	QTime oT1; oT1.start();
	int index_ = 0;
	m_vecDefectShowsBody.at(0)->ShowImage(QString(".\\InfusionBagImage\\001_Top_Left.bmp"), IMAGE_ROTATE_90);
	qDebug() << " load "<< ++index_<<"image "  <<oT1.restart() << "ms";
	m_vecDefectShowsBody.at(1)->ShowImage(QString(".\\InfusionBagImage\\004_Bottom_Left.bmp"), IMAGE_ROTATE_90);
	qDebug() << " load " << ++index_ << "image " << oT1.restart() << "ms";
	m_vecDefectShowsBody.at(2)->ShowImage(QString(".\\InfusionBagImage\\002_Top_Right.bmp"), IMAGE_ROTATE_270);
	qDebug() << " load " << ++index_ << "image " << oT1.restart() << "ms";
	m_vecDefectShowsBody.at(3)->ShowImage(QString(".\\InfusionBagImage\\003_Bottom_Right.bmp"), IMAGE_ROTATE_270);
	qDebug() << " load " << ++index_ << "image " << oT1.restart() << "ms";

}

void QTDrawImageTestProject001::OnClickTest()
{
	if(m_pThread1->isRunning() == false)
		m_pThread1->start();
	
	//for (int nIndex = 0; nIndex < 10; nIndex++)
	{
		QThread::usleep(10);
		if (m_pThread2->isRunning() == false)
			m_pThread2->start();		
	}	
}

void QTDrawImageTestProject001::showfloatwindow()
{
	//QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
	//QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
	srand(time(0));
	auto fnAdd = [&](int nLoopMax)->bool {
		for (int nIndex = 0; nIndex < nLoopMax; nIndex++)
		{
			int nRand = rand() % 12;
			QString strPattern = QString::fromLocal8Bit(BFS_VIAL_PATTERN_C062_0001_BODY_DOWN_CN[nRand]);
			QByteArray ba = strPattern.toLocal8Bit();
			char* csPattern = new char[ba.size() + 1];
			strcpy_s(csPattern, ba.size() + 1, ba.data());

			//std::string stdStrPattern = strPattern.toStdString();
			//const char* csPatternTemp = stdStrPattern.c_str();
			//char* csPattern = new char[strlen(csPatternTemp) + 1];
			//strcpy_s(csPattern, strlen(csPatternTemp) + 1, csPatternTemp);
			pFloatPan->m_pStatistic->AddDefect(strPattern.toLocal8Bit().data());
			delete csPattern;
		}
		return false;
	};
	fnAdd(1);
	pFloatPan->UpdateFailureInfo();
	QPoint posA = pLab->mapToGlobal(QPoint(0, 0));
	pFloatPan->move(QPoint(posA.x(), posA.y() + pLab->height()));
	pFloatPan->show();
}

void QTDrawImageTestProject001::hidefloatwindow()
{
	pFloatPan->hide();
}

void QTDrawImageTestProject001::OnClickShowExportDialog()
{
	QExportLogDialog oDialog;
	if (oDialog.exec() == QDialog::Accepted)
	{
		qDebug() << "Click ok";
		//ShowPrompt(QString(WRN_IMAGE_UPLOAD_SUCCEED));
	}
	else
	{
		qDebug() << "Click close";

		//ShowPrompt(QString(ERR_IMAGE_UPLOAD_CANCEL), true);
	}
}

void QTDrawImageTestProject001::OnUpdateTime()
{
	m_pLcdDataTime->display(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
}

void QTDrawImageTestProject001::OnClickSwitchPage()
{
	QPushButton* pBtn = dynamic_cast<QPushButton*>(sender());
	QVariant userData = pBtn->property(STR_USER_DATA);
	int nPageIndex = userData.toInt();
	m_pStackedWidget->setCurrentIndex(nPageIndex);

}

void QTDrawImageTestProject001::OnClickChangeLabelBG()
{
	QString strStyle;
	switch (++m_nChangeLebalBG % 3)
	{
	case 0:strStyle = STR_STYLE_1;	break;
	case 1:strStyle = STR_STYLE_2;	break;
	case 2:strStyle = STR_STYLE_3;	break;
	default:
		break;
	}
	for (int nIndex = 0; nIndex < m_vtStatusInput.size(); nIndex++)
	{
		m_vtStatusInput[nIndex]->setStyleSheet(strStyle);
	}
	for (int nIndex = 0; nIndex < m_vtStatusOutput.size(); nIndex++)
	{
		m_vtStatusOutput[nIndex]->setStyleSheet(strStyle);
	}
}

void QTDrawImageTestProject001::CreatePage1()
{
	for (int nIndex = 0; nIndex < 4; nIndex++)
	{
		m_vecDefectShowsBody.push_back(new QImageDetectFrame(this));
	}
	m_vecDefectShowsBody.at(0)->SetDrawAlign(ALIGN_RIGHT_BOTTOM);
	m_vecDefectShowsBody.at(1)->SetDrawAlign(ALIGN_RIGHT_TOP);
	m_vecDefectShowsBody.at(2)->SetDrawAlign(ALIGN_LEFT_BOTTOM);
	m_vecDefectShowsBody.at(3)->SetDrawAlign(ALIGN_LEFT_TOP);

	QHBoxLayout* pHLayout_Left1 = new QHBoxLayout();
	pHLayout_Left1->setMargin(0);
	pHLayout_Left1->setSpacing(0);

	QVBoxLayout* pVLayout1 = new QVBoxLayout();
	pVLayout1->setMargin(0);
	pVLayout1->setSpacing(0);
	pVLayout1->addWidget(m_vecDefectShowsBody.at(0));
	pVLayout1->addWidget(m_vecDefectShowsBody.at(1));
	QWidget* pWidget1 = new QWidget(this);
	pWidget1->setLayout(pVLayout1);
	pHLayout_Left1->addWidget(pWidget1);

	QVBoxLayout* pVLayout2 = new QVBoxLayout();
	pVLayout2->setMargin(0);
	pVLayout2->setSpacing(0);
	pVLayout2->addWidget(m_vecDefectShowsBody.at(2));
	pVLayout2->addWidget(m_vecDefectShowsBody.at(3));
	QWidget* pWidget2 = new QWidget(this);
	pWidget2->setLayout(pVLayout2);
	pHLayout_Left1->addWidget(pWidget2);

	QFrame* pMain = new QFrame();
	pMain->setLayout(pHLayout_Left1);
	pMain->setFixedHeight(600);

	pLab = new QTipsLabel();
	pLab->setText(QString("TestModifyWindow"));
	pFloatPan = new QFailureCountFloatPan();
	//

	QPushButton* pBtnLoadImage = new QPushButton("Load Image");
	QPushButton* pBtnShowExportDialog = new QPushButton("Show Export Dialog");
    QPushButton* pBtnTest = new QPushButton("Test Thread");

    auto setBtnWH = [](QWidget* pWidget, int nFixedWidth, int nFixedHeight) {
        pWidget->setFixedSize(nFixedWidth, nFixedHeight);
    };
    auto setBtnClear = [](QPushButton* pButton) {
        pButton->setIconSize(QSize(0, 0));
        QString str = pButton->text();
        pButton->setToolTip(str);
        pButton->setText(QString(""));
    };
    QPushButton* m_pBtnDataReset = new QPushButton("");
    m_pBtnDataReset->setProperty("behavior", "data_reset");
    setBtnWH(m_pBtnDataReset, 60, 60); setBtnClear(m_pBtnDataReset);

	QHBoxLayout* pHLayout_Btn = new QHBoxLayout();
	pHLayout_Btn->addWidget(pBtnLoadImage);
	pHLayout_Btn->addWidget(pBtnShowExportDialog);
    pHLayout_Btn->addWidget(pBtnTest);
    pHLayout_Btn->addWidget(m_pBtnDataReset);

	QWidget* pWidgetBtn = new QWidget(this);
	pWidgetBtn->setLayout(pHLayout_Btn);

	m_pLcdDataTime = new QLCDNumber();
	m_pLcdDataTime->setDigitCount(25);
	m_pLcdDataTime->setMode(QLCDNumber::Dec);
	m_pLcdDataTime->setStyleSheet("border: 0px; background: black;");
	m_pLcdDataTime->display(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

	QVBoxLayout* pMainLayout = new QVBoxLayout();
	pMainLayout->setSpacing(1);
	pMainLayout->setMargin(1);
	pMainLayout->addWidget(pLab);
	pMainLayout->addWidget(pMain);
	pMainLayout->addWidget(pWidgetBtn);
	pMainLayout->addWidget(m_pLcdDataTime);

	QTimer* pTimer = new QTimer(this);
	QObject::connect(pTimer, &QTimer::timeout, this, &QTDrawImageTestProject001::OnUpdateTime);
	pTimer->start(1000);


	QAboutSoftwareWidget* pAboutSoftware = new QAboutSoftwareWidget();
	pMainLayout->addWidget(pAboutSoftware);

	connect(pLab, SIGNAL(show()), this, SLOT(showfloatwindow()));
	connect(pLab, SIGNAL(hide()), this, SLOT(hidefloatwindow()));

	TestQLineEditRE(pMainLayout);

    TestComboBox(pMainLayout);

	QWidget* pPage1 = new QWidget();
	pPage1->setLayout(pMainLayout);

	m_pStackedWidget->addWidget(pPage1);

	QObject::connect(pBtnLoadImage, &QPushButton::clicked, this, &QTDrawImageTestProject001::OnClickLoadImage);
	QObject::connect(pBtnShowExportDialog, &QPushButton::clicked, this, &QTDrawImageTestProject001::OnClickShowExportDialog);
	QObject::connect(pBtnTest, &QPushButton::clicked, this, &QTDrawImageTestProject001::OnClickTest);

    

}

void QTDrawImageTestProject001::CreatePage2()
{
	m_InputbitInfo.clear();
	m_OutputbitInfo.clear();
	auto fnInsertBitInfo = [&](int nBitPostion, const char* szMessage, QMap<int, MCU_DEVICE_PROTOCOL_BIT_INFO_t*>& mapBitInfo)
	{
		MCU_DEVICE_PROTOCOL_BIT_INFO_t* bitInfo = new MCU_DEVICE_PROTOCOL_BIT_INFO_t();
		bitInfo->bitPostion = nBitPostion;
		strncpy(bitInfo->message_, szMessage, sizeof(bitInfo->message_) );
		mapBitInfo.insert(bitInfo->bitPostion, bitInfo);
	};

	fnInsertBitInfo(0 , "检测工位药瓶感应" , m_InputbitInfo);
	fnInsertBitInfo(1 , "剔除工位药瓶感应", m_InputbitInfo);
	fnInsertBitInfo(2 , "剔除气缸原位感应", m_InputbitInfo);
	fnInsertBitInfo(3 , "剔除气缸伸出到位感应" , m_InputbitInfo);
	fnInsertBitInfo(4 , "堆料变轨气缸原位感应" , m_InputbitInfo);
	fnInsertBitInfo(5 , "堆料变轨气缸伸出到位感应", m_InputbitInfo);
	fnInsertBitInfo(6 , "理瓶器盈余感应，可进料", m_InputbitInfo);
	fnInsertBitInfo(7 , "理瓶器满料感应，不可进料", m_InputbitInfo);
	fnInsertBitInfo(8 , "压缩空气压力大于6公斤", m_InputbitInfo);
	fnInsertBitInfo(9 , "压缩空气压力小于6公斤", m_InputbitInfo);
	fnInsertBitInfo(10, "压缩空气压力小于5公斤", m_InputbitInfo);
	fnInsertBitInfo(11, "启动", m_InputbitInfo);
	fnInsertBitInfo(12, "停止", m_InputbitInfo);
	fnInsertBitInfo(13, "急停", m_InputbitInfo);
	fnInsertBitInfo(14, "前轨是否堵料感应", m_InputbitInfo);
	fnInsertBitInfo(15, "后轨是否堵料感应", m_InputbitInfo);

	fnInsertBitInfo(0, "剔除气缸伸出", m_OutputbitInfo);
	fnInsertBitInfo(1, "堆料变轨气缸伸出", m_OutputbitInfo);
	fnInsertBitInfo(2, "堆料变轨气缸复位", m_OutputbitInfo);
	fnInsertBitInfo(3, "报警灯红灯", m_OutputbitInfo);
	fnInsertBitInfo(4, "报警灯黄灯", m_OutputbitInfo);
	fnInsertBitInfo(5, "报警灯绿灯", m_OutputbitInfo);
	
	m_vtStatusInput.clear();
	m_vtStatusOutput.clear();
	QVBoxLayout* pVLayoutBitInfo = new QVBoxLayout();
	QList<MCU_DEVICE_PROTOCOL_BIT_INFO_t*> nListBitInfo = m_InputbitInfo.values();
	QList<MCU_DEVICE_PROTOCOL_BIT_INFO_t*> nListOutputBitInfo = m_OutputbitInfo.values();
	for(int nIndex = 0; nIndex < nListBitInfo.size(); nIndex++)
	{	
		MCU_DEVICE_PROTOCOL_BIT_INFO_t* bitInfo_ = nListBitInfo.at(nIndex);
		QString strTemp = QString("DI%1").arg(bitInfo_->bitPostion, 2, 10, QLatin1Char('0'));
		QLabel* pBitPosition = new QLabel(strTemp);
		QLabel* pBitMessage = new QLabel(QString(bitInfo_->message_));

		m_vtStatusInput.push_back(pBitPosition);
		pBitPosition->setAlignment(Qt::AlignCenter);

		pBitPosition->setStyleSheet(STR_STYLE_1);
		pBitMessage->setStyleSheet(QString(STR_STYLE_WIDTH185)+ STR_STYLE_BLACK);
		
		QGridLayout* pGripLayoutBitInfo = new QGridLayout();
		pGripLayoutBitInfo->addWidget(pBitPosition,0, 0);
		pGripLayoutBitInfo->addWidget(pBitMessage, 0, 1);
		
		//QWidget* pWidInfo = new QWidget();
		//pWidInfo->setLayout(pHLayoutBitInfo);

		if (nIndex < nListOutputBitInfo.size())
		{
			bitInfo_ = nListOutputBitInfo.at(nIndex);
			strTemp = QString("DO%1").arg(bitInfo_->bitPostion, 2, 10, QLatin1Char('0'));
			QLabel* pBitPosition = new QLabel(strTemp);
			QLabel* pBitMessage = new QLabel(QString(bitInfo_->message_));
			m_vtStatusOutput.push_back(pBitPosition);
			pBitPosition->setAlignment(Qt::AlignCenter);
			pBitPosition->setStyleSheet(STR_STYLE_1);
			pBitMessage->setStyleSheet(QString(STR_STYLE_WIDTH185) + STR_STYLE_BLACK);
			pGripLayoutBitInfo->addWidget(pBitPosition, 0, 2);
			pGripLayoutBitInfo->addWidget(pBitMessage, 0, 3 );
		}
		else
		{
			QLabel* pBitPosition = new QLabel(QString(" "));
			QLabel* pBitMessage = new QLabel(QString(" "));
			pBitPosition->setStyleSheet(STR_STYLE_WIDTH125);
			pBitMessage->setStyleSheet(STR_STYLE_WIDTH185);
			//pBitPosition->setVisible(false);
			//pBitMessage->setVisible(false);
			pGripLayoutBitInfo->addWidget(pBitPosition, 0, 2);
			pGripLayoutBitInfo->addWidget(pBitMessage, 0, 3);
		}
		//pGripLayoutBitInfo->setColumnStretch(1, 1);
		//pGripLayoutBitInfo->setColumnStretch(1, 2);

		pVLayoutBitInfo->addLayout(pGripLayoutBitInfo);
	}
	QPushButton* pBtn = new QPushButton("Change BG");
	QObject::connect(pBtn, &QPushButton::clicked, this, &QTDrawImageTestProject001::OnClickChangeLabelBG);

	pVLayoutBitInfo->addWidget(pBtn);

	QWidget* pPage2 = new QWidget();
	pPage2->setLayout(pVLayoutBitInfo);
	//pPage2->setStyleSheet("background-color: blue;");
	m_pStackedWidget->addWidget(pPage2);
}

void QTDrawImageTestProject001::CreatePage3()
{
	QWidget* pPage3 = new QWidget();
	pPage3->setStyleSheet("background-color: yellow;");
	m_pStackedWidget->addWidget(pPage3);
}

void QTDrawImageTestProject001::CreatePage4()
{
	QWidget* pPage4 = new QWidget();
	pPage4->setStyleSheet("background-color: grey;");
	m_pStackedWidget->addWidget(pPage4);
}

void QTDrawImageTestProject001::CreatePage5()
{
    QWidget* pPage5 = new QMono8ImageWidget();
    pPage5->setStyleSheet("background-color: grey;");
    m_pStackedWidget->addWidget(pPage5);
}

void TestQLineEditRE(QVBoxLayout* pMainLayout)
{
	QLabel * pLabTestRE = new QLabel(QString("正则表达式限制输入："));
	pLabTestRE->setStyleSheet("QLabel { color: black; }");
	QLineEdit* pEditTestRE = new QLineEdit();
	QHBoxLayout* pHLayoutTestRE = new QHBoxLayout();
	QWidget*pWidTestRE = new QWidget();
	pHLayoutTestRE->addWidget(pLabTestRE);
	pHLayoutTestRE->addWidget(pEditTestRE);
	pWidTestRE->setLayout(pHLayoutTestRE);
	pMainLayout->addWidget(pWidTestRE);
	pEditTestRE->setStyleSheet("QLineEdit { color: RGB(65,65,65); }");


	// The Refer to the tutorial https://wenku.baidu.com/view/04954fde740bf78a6529647d27284b73f2423687.html
	QString strPattern;
	//int 1 To 4096
	strPattern = "^[1-9]\\d{0,2}+|[1-4]\\d(?<!4[1-9])\\d\\d(?<!409[7-9])$";
	//int 1 To 1440
	strPattern = "^[1-9]\\d{0,2}+|[0-1]\\d(?<!1[5-9])\\d(?<!14[5-9])\\d(?<!144[1-9])$";
	//int 1 To 1080
	strPattern = "^[1-9]\\d{0,2}+|[0-1]\\d(?<!1[1-9])\\d(?<!109)\\d(?<!108[1-9])$";
	//int 1 To 640
	strPattern = "^[1-9]\\d{0,1}+|[0-6]\\d(?<!4[5-9])\\d(?<!64[1-9])$";
	//int 1 To 480
	strPattern = "^[1-9]\\d{0,1}+|[0-4]\\d(?<!49)\\d(?<!48[1-9])$";
	//int 1 To 255
	strPattern = "^[1-9]\\d{0,1}+|[0-2]\\d(?<!2[6-9])\\d(?<!25[6-9])$";
	//int 1 To 1624
	strPattern = "^[1-9]\\d{0,2}+|[0-1]\\d(?<!1[7-9])\\d(?<!16[3-9])\\d(?<!162[5-9])$";
	//int 1 To 1240
	strPattern = "^[1-9]\\d{0,2}+|[0-1]\\d(?<!1[3-9])\\d(?<!12[5-9])\\d(?<!124[1-9])$";
	//int 1 To 1920
	strPattern = "^[1-9]\\d{0,2}+|[0-1]\\d\\d(?<!19[3-9])\\d(?<!192[1-9])$";
	//int 1 To 1200
	strPattern = "^[1-9]\\d{0,2}+|[0-1]\\d(?<!1[3-9])\\d(?<!12[1-9])\\d(?<!120[1-9])$";

	//int 1 To 9999840
	strPattern = "^[1-9]\\d{0,5}$|^[0-9][0-9][0-9][0-9]\\d(?<!99999)\\d(?<!99998[5-9])\\d(?<!999984[1-9])$";

	//float 0.0 To 4.0
	strPattern = "(^[1-3]\\.\\d{1,2}$|^4\\.0$|^0\\.\\d{1,2}$|^0$)";

	//float 0.0 To 15.0
	strPattern = "(^[0-9]\\.\\d{1,2}$|^[0-1]\\d(?<!1[5-9])\\.\\d{1,2}$|^15\\.0$|^0\\.\\d{1,2}$|^0$)";
	
	//float 0.0 To 2.0
	strPattern = "(^[0-1]\\.\\d{1,1}$|^2\\.[0]{1,1}$|^0\\.\\d{1,1}$|^0$)"; 

	//float 0.0 To 3.0
	strPattern = "(^[0-2]\\.\\d$|^3\\.0$|^0\\.\\d$|^0$)";

	//float 0.0 To 100.0
	strPattern = "(^[0-9]{1,2}\\.\\d{1,1}$|^100\\.[0]{1,1}$|^0\\.\\d{1,1}$|^0$)";

	//float 0.00 To 100.00
	strPattern = "(^[0-9]{1,2}\\.\\d{1,2}$|^100\\.[0]{1,2}$|^0\\.\\d{1,2}$|^0$)";
	//string len 64
	strPattern = "^[\u4e00-\u9fa5_a-zA-Z0-9_.:|-]{0,32}$";

	//float 0.50 To 0.99
	//strPattern = "^0.\\d(?<!0\\.[0-4])\\d{0,1}$";

	pEditTestRE->setValidator(new QRegularExpressionValidator(QRegularExpression(strPattern)));
}
const char* const CS_PRODUCT_INFO_NAME_CAPTION = "产品名称";

void TestComboBox(QVBoxLayout* pMainLayout)
{
    QLabel* pLblBatch = new QLabel(CS_PRODUCT_INFO_NAME_CAPTION);
    pLblBatch->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
    pLblBatch->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    pLblBatch->setFont(QFont("宋体", 10, QFont::DemiBold));
   
    QNoWheelComboBox* m_pCmbProductName = new QNoWheelComboBox();
    //m_pCmbProductName->setFixedWidth(PROD_CMB_WIDTH_MAX);
    m_pCmbProductName->setItemDelegate(new QStyledItemDelegate());

    QHBoxLayout* pHLayoutTestCB = new QHBoxLayout();
    QWidget*pWidTestCB = new QWidget();
    pHLayoutTestCB->addWidget(pLblBatch);
    pHLayoutTestCB->addWidget(m_pCmbProductName);
    pWidTestCB->setLayout(pHLayoutTestCB);
    pMainLayout->addWidget(pWidTestCB);

    m_pCmbProductName->clear();
    m_pCmbProductName->setFixedSize(275, 56);
    QStringList strList; strList << "" << "葡萄糖注射液50" << "乳酸左氧氟沙星氯化钠100ml:星0.2g钠0.9g\n";
    for (int nIndex = 0; nIndex < strList.size(); ++nIndex)
    {
        m_pCmbProductName->addItem(strList.at(nIndex));
    }
}

void TestFileInfo()
{
	QString strFilePath = QString("E:\\TestMarkInfo001.jpg");
	QString strFilePath2 = QString("E:\\TestMarkInfo002.jpg");
	QFileInfo oFileInfo(strFilePath);
	QFileInfo oFileInfo2(strFilePath2);
	bool bExists = false, bExists2 = false;
	if (oFileInfo2.exists() == true)
	{
		oFileInfo2.dir().remove(oFileInfo2.fileName());
	}
	bExists = oFileInfo2.exists();
	QFile::copy(strFilePath, strFilePath2);
	bExists2 = oFileInfo2.exists(strFilePath2);

	if (oFileInfo2.exists(oFileInfo2.absoluteFilePath()) == true)
	{
		oFileInfo2.dir().remove(oFileInfo2.fileName());
	}
	bExists = oFileInfo2.exists();
	bExists2 = oFileInfo2.exists(strFilePath2);
	bExists2 = oFileInfo2.exists("E:\\tempMysql.txt");
	bExists2 = oFileInfo2.exists("E:\\pythonEnvC3.txt");
}
void TestBottleVector()
{
	qDebug() << "test QVector";
	QVector<COMBO_PARSE_DEFECT_ITEM_t*> VtMultParseDefect;
	QVector<QVector<DEFECT_RESULT_t>> vtTotalDefectResult;
	CollectPrevPredictData(nullptr, &VtMultParseDefect, &vtTotalDefectResult);
	for (COMBO_PARSE_DEFECT_ITEM_t* pItem : VtMultParseDefect)
	{
		for (DEFECT_RESULT_t pResult : *pItem->pDefectResult)
			qDebug() << pResult.nID;
		//delete pItem->pDefectResult;
	}
	qDebug() << VtMultParseDefect.size();
}
void TestBottleQMap()
{
	QMap<long, bool>* pMapKickoff = new QMap<long, bool>();
	long lBottleNumber = 1;
	bool bKickFlag = false;
	for (size_t lBottleNumber = 0; lBottleNumber < 5; lBottleNumber++)
	{
		if (pMapKickoff->contains(lBottleNumber) == false)
			pMapKickoff->insert(lBottleNumber, true);
		(*pMapKickoff)[lBottleNumber] |= bKickFlag;
		if ((*pMapKickoff)[lBottleNumber] == true)
		{
			qDebug() << "B:" << lBottleNumber << "=" << (*pMapKickoff)[lBottleNumber];
		}
		pMapKickoff->remove(lBottleNumber);
	}
	pMapKickoff->clear();
	delete pMapKickoff; pMapKickoff = nullptr;

	int BottleCountIndex = 0;

	for (int nIndex = 0; nIndex < 8; nIndex++)
	{
		QString strkey = QString("M%1I%2_B%3_%4").arg(4)\
			.arg(1).arg(lBottleNumber, 5, 10, QLatin1Char('0'))\
			.arg(BottleCountIndex++);

		QStringList strList = strkey.split('_');
		int nSize = strList.size();
		QString strNunber = strList.at(1).mid(1);
		qDebug() << "lBottle Number:" << strNunber;
		lBottleNumber += 15;
	}
}