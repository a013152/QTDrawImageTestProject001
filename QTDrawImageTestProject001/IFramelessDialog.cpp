#include "IFramelessDialog.h"

IFramelessDialog::IFramelessDialog(QWidget* parent /*= Q_NULLPTR*/)
	: IFramelessWidget<QDialog>(parent)
{
	
}

IFramelessDialog::~IFramelessDialog()
{

}

void IFramelessDialog::AddCloseButton()
{
	AddMenuWidget(CreateUIExitButton(QIcon(), "X", SLOT(OnClickBtnExit()), MenuButtonHeight(), MenuButtonHeight()));
}

void IFramelessDialog::OnClickBtnExit()
{
	this->reject();
}

void IFramelessDialog::InitLayout(QString strBackgroundName /*= ""*/)
{
	IFramelessWidget<QDialog>::InitLayout(strBackgroundName);
	setWindowFlag(Qt::WindowStaysOnTopHint);
}
