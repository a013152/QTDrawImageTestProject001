#include "QAboutSoftwareWidget.h" 

#include <QLabel>
#include <QHBoxLayout> 
#include <QVBoxLayout>
//#include "System\QSystemParamManager.h"
#include <QApplication>
#include <QIcon>
//#include "Factory\QFactoryManager.h"
//#include "QUIWidgetDef.h"
//#include "IFactory.h"

QAboutSoftwareWidget::QAboutSoftwareWidget(QWidget *parent)
	: QWidget(parent)	
	, m_pLabSoftware(nullptr)
	, m_pLabCompany(nullptr)
	, m_pLabLogo(nullptr)
{
	CreateMember();
	InitLayout();
}
 
QAboutSoftwareWidget::~QAboutSoftwareWidget()
{
}

void QAboutSoftwareWidget::InitLayout()
{
	setFixedHeight(60);

	QString strLogoImage = "background-image:url(./Image/MBDD_logo.png);"; 
	m_pLabLogo->setFixedSize(58, 58);
	m_pLabLogo->setStyleSheet(strLogoImage);

	m_pLabSoftware->setObjectName("about_software_label");
	m_pLabCompany->setObjectName("about_software_label");
	QHBoxLayout* pMainLayout = new QHBoxLayout();
	pMainLayout->setMargin(0);
	pMainLayout->setSpacing(5);
	//QWidget* pWidget = new QWidget();
	QString str1 = QApplication::applicationName();
	m_pLabSoftware->setText(str1);
	QString str2 = QString("%1 %2").arg(QString::fromLocal8Bit("佛山读图科技有限公司")).arg("0757-86780927");
	m_pLabCompany->setText(str2);
	
	QWidget* pMidWidget = new QWidget();
	QVBoxLayout* hLayout = new QVBoxLayout();
	hLayout->setMargin(0);
	hLayout->setSpacing(0);
	hLayout->addWidget(m_pLabSoftware);
	hLayout->addWidget(m_pLabCompany);
	pMidWidget->setLayout(hLayout);

	pMainLayout->addWidget(m_pLabLogo);
	pMainLayout->addWidget(pMidWidget);
	pMainLayout->addStretch();
	//hLayout->addStretch();

	
	QFrame* pContentFrame = new QFrame();
	pContentFrame->setObjectName("about_software");
	pContentFrame->setLayout(pMainLayout);
	QVBoxLayout* pVLayout2 = new QVBoxLayout();
	pVLayout2->setMargin(0);
	pVLayout2->setSpacing(0);
	pVLayout2->addWidget(pContentFrame);
	setLayout(pVLayout2);
}

void QAboutSoftwareWidget::CreateMember()
{

	m_pLabLogo = new QLabel();
	m_pLabSoftware = new QLabel();
	m_pLabCompany = new QLabel();
}
