#include "IFramelessWindow.h"

IFramelessWindow::IFramelessWindow(FORM_TYPE_e eFormType /*= FORM_TYPE_NONE*/, QWidget* parent /*= Q_NULLPTR*/)
	: IFramelessWidget<QFrame>(parent),
	m_bDeleteLater(false),
	m_eFormType(eFormType)
{

}

IFramelessWindow::~IFramelessWindow()
{

}

void IFramelessWindow::AddCloseButton()
{
	AddMenuWidget(CreateUIExitButton(QIcon(), "X", SLOT(OnClickBtnExit()), MenuButtonHeight(), MenuButtonHeight()));
}

FORM_TYPE_e IFramelessWindow::Mode()
{
	return m_eFormType;
}

void IFramelessWindow::SetDeleteLater()
{
	m_bDeleteLater = true;
}

void IFramelessWindow::OnClickBtnExit()
{
	if (!DoBeforeClose())
	{
		return;
	}
	Dump();
}

void IFramelessWindow::InitLayout(QString strBackgroundName /*= ""*/)
{
	IFramelessWidget<QFrame>::InitLayout(strBackgroundName);
}

bool IFramelessWindow::DoBeforeClose()
{
	return true;
}

void IFramelessWindow::Dump()
{
	close();
	if (m_bDeleteLater)
	{
		deleteLater();
	}
	emit SigWindowClosed(m_eFormType);
}
