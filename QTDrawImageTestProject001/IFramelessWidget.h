#ifndef _IFRAMELESS_H_
#define _IFRAMELESS_H_

#pragma once

#include "QFormShell.h"

#include <QApplication>
#include <QString>
#include <QObject>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QLabel>
#include <QIcon>
#include <QBitmap>
#include <QPainter>
#include <QStyleOption>
#include <QDesktopWidget>
#include <QPaintEvent>
#include <QPainterPath>
#include <QPainter>
#include <QColor>
#include <QtMath>
#include <QImage>
#include <QPixmap>
#include <QButtonGroup>
#include <QList>

static const char* ROOT_BACKGROUND_NAME			= "rootbg";
static const int BUTTON_HEIGHT_DEFAULT			= 30;
static const int BORDER_SCALE_MARGIN			= 5;
static const int SHADOW_EFFECT_SIZE				= 6;
static const int SHADOW_EFFECT_OFFSET			= 2;
static const char* TITLE_CAPTION_FONT			= "Consoles";

template <typename T>
class IFramelessWidget : public QFormShell<T>
{
public:
	IFramelessWidget(QWidget* parent = Q_NULLPTR)
		: QFormShell<T>(parent), m_bMousePress(false), m_bMoveEnable(false), m_bScaleEnable(false), m_bShadowEnable(true), m_pBtnGroup(nullptr), m_pListBtn(nullptr), m_pLblCaption(nullptr)
	{
		SetRootBackgroundName(ROOT_BACKGROUND_NAME);
	};

	virtual ~IFramelessWidget() 
	{
		if (m_pBtnGroup != nullptr)
		{
			delete m_pBtnGroup;
			m_pBtnGroup = nullptr;
		}
		if (m_pListBtn != nullptr)
		{
			delete m_pListBtn; m_pListBtn = nullptr;
		}
	};

public:
	virtual void SetRootBackgroundName(QString strName)
	{
		setObjectName(strName);
	}

	virtual void SetShadow(bool bEnable)
	{
		m_bShadowEnable = bEnable;
	}

	void SetupTitleBar(QString strCaption, QString strTitleName, QString strCaptionName, QString strIconPath = "", int nCaptionWidth = 0, bool bCaptionInCenter = false)
	{
		QLabel* pLblCaption = new QLabel(strCaption);
		SetupTitleBar(pLblCaption, strTitleName, strCaptionName, strIconPath, nCaptionWidth, bCaptionInCenter);
	}

	void SetupTitleBar(QLabel* pLblCaption, QString strTitleName, QString strCaptionName, QString strIconPath = "", int nCaptionWidth = 0, bool bCaptionInCenter = false)
	{
		Q_ASSERT(pLblCaption != nullptr);
		m_pLblCaption = pLblCaption;
		m_pTitleBar = new QWidget();
		m_pTitleBar->setObjectName(strTitleName);

		QHBoxLayout* pTitleLayout = new QHBoxLayout();
		pTitleLayout->setContentsMargins(6, 0, 0, 0);
		pTitleLayout->setSpacing(0);

		m_pMenuLayout = new QHBoxLayout();
		m_pMenuLayout->setSpacing(0);
		m_pMenuLayout->setContentsMargins(0, 0, 8, 0);

		if (!strIconPath.isEmpty())
		{
			QLabel* pLblImage = new QLabel();
			pLblImage->setPixmap(QPixmap::fromImage(QImage(strIconPath)));
			pTitleLayout->addWidget(pLblImage);
		}
		if (bCaptionInCenter)
		{
			pTitleLayout->addStretch();
		}

		SetTitleCaption(pLblCaption, strCaptionName, TITLE_CAPTION_FONT, nCaptionWidth);

		pTitleLayout->addWidget(pLblCaption);
		pTitleLayout->addStretch();
		pTitleLayout->addLayout(m_pMenuLayout);
		m_pTitleBar->setLayout(pTitleLayout);
		m_pMainLayout->addWidget(m_pTitleBar);
	}

	bool AddMenuExclusiveButton(QIcon icon, const char* szName, const char *slotMember, int nFixedWidth = 0, int nSpacing = 0, QString strToolTip = "", bool bChecked = false)
	{
		if (m_pBtnGroup == nullptr)
		{
			m_pBtnGroup = new QButtonGroup();
			m_pBtnGroup->setExclusive(true);
		}
		if (m_pListBtn == nullptr)
		{
			m_pListBtn = new QList<QPushButton *>();
		}
		QPushButton* pButton = CreateUIButton(icon, szName, slotMember, MenuButtonHeight(), nFixedWidth, strToolTip);
		pButton->setCheckable(true);
		pButton->setChecked(bChecked);
		m_pBtnGroup->addButton(pButton);
		m_pListBtn->append(pButton);
		m_pMenuLayout->addWidget(pButton);
		m_pMenuLayout->addSpacing(nSpacing);
		return true;
	}

	bool AddMenuButton(QIcon icon, const char* szName, const char *slotMember, int nFixedWidth = 0, int nSpacing = 0, QString strToolTip = "")
	{
		if (m_pMenuLayout == nullptr)
		{
			return false;
		}
		m_pMenuLayout->addWidget(CreateUIButton(icon, szName, slotMember, MenuButtonHeight(), nFixedWidth, strToolTip));
		m_pMenuLayout->addSpacing(nSpacing);
		return true;
	}

	bool AddMenuWidget(QWidget* pButton, int nSpacing = 0)
	{
		if (m_pMenuLayout == nullptr)
		{
			return false;
		}
		m_pMenuLayout->addWidget(pButton);
		m_pMenuLayout->addSpacing(nSpacing);
		return true;
	}

	void SetLayout(QLayout* pLayout)
	{
		m_pMainLayout->insertLayout(m_pMainLayout->count(), pLayout);
	}
	
	void AppendWidget(QWidget* pWidget)
	{
		m_pMainLayout->insertWidget(m_pMainLayout->count(), pWidget);
	}

	virtual int MenuButtonHeight()
	{
		return BUTTON_HEIGHT_DEFAULT - 2;
	}

	void SetMoveEnable(bool bEnable)
	{
		m_bMoveEnable = bEnable;
		if (m_bMoveEnable && m_pTitleBar != nullptr)
		{
			m_pTitleBar->installEventFilter(this);
		}
	}

	void SetScaleEnable(bool bEnable)
	{
		m_bScaleEnable = bEnable;
		EnableMouseTracking(bEnable);

		if (bEnable)
		{
			m_pMainLayout->setContentsMargins(BORDER_SCALE_MARGIN, 0, BORDER_SCALE_MARGIN, BORDER_SCALE_MARGIN);
		}
		else
		{
			m_pMainLayout->setMargin(0);
		}
	}

	virtual void ShowCenter()
	{
		//modify by ChenLin 20200707
		int nDesktopWidth = QApplication::desktop()->width();
		move(((nDesktopWidth >1920?1920: nDesktopWidth) - width()) / 2, (QApplication::desktop()->height() - height()) / 2);
		//end modify
		if (isVisible())
		{
			raise();
		}
		else
		{
			show();
		}
	}

protected:
	void SetTitleCaption(QLabel* pLblTitleCaption, QString strName, QString strFontName, int nFixedWidth)
	{
		pLblTitleCaption->setObjectName(strName);
		if (nFixedWidth != 0)
		{
			pLblTitleCaption->setFixedWidth(nFixedWidth);
		}
		pLblTitleCaption->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
	}

	virtual bool eventFilter(QObject *obj, QEvent * event) override
	{
		if (m_pTitleBar != NULL && obj == m_pTitleBar && m_bMoveEnable)
		{
			switch (event->type())
			{
			case QEvent::MouseMove:
				TitleMouseMoveEvent(dynamic_cast<QMouseEvent*>(event));
				return true;
			default:
				return false;
			}
		}
		return T::eventFilter(obj, event);
	}

	virtual void mouseMoveEvent(QMouseEvent *event) override
	{
		if (!m_bMoveEnable && !m_bScaleEnable)
		{
			return;
		}
		if (event->button() == Qt::LeftButton)
		{
			m_ptDragPosition = event->globalPos() - pos();
			event->accept();
		}
		if (m_bScaleEnable)
		{
			int nMoveArea = MoveScaleArea(event->pos());
			SetScaleMouseStyle(nMoveArea);
			if (m_bMousePress)
			{
				ScaleWindow(event, nMoveArea);
			}
		}
		return;
	}

	virtual void mousePressEvent(QMouseEvent *event) override
	{
		if (!m_bMoveEnable && !m_bScaleEnable)
		{
			return;
		}
		if (event->button() == Qt::LeftButton)
		{
			m_bMousePress = true;
			m_ptDragPosition = event->globalPos() - pos();
			m_ptScalePosition = event->globalPos();
			event->accept();
		}
		return;
	}

	virtual void mouseReleaseEvent(QMouseEvent *event) override
	{
		m_bMousePress = false;
		return;
	}

	virtual void paintEvent(QPaintEvent* event) override
	{
		if (!m_bShadowEnable)
		{
			return;
		}

		QPainter painter(this);
		painter.setRenderHint(QPainter::Antialiasing, true);

		QColor color(32, 32, 32, 50);
		for (int i = 0; i < SHADOW_EFFECT_SIZE; i++)
		{
			QPainterPath path;
			path.setFillRule(Qt::WindingFill);
			path.addRoundRect(SHADOW_EFFECT_SIZE + SHADOW_EFFECT_OFFSET, SHADOW_EFFECT_SIZE + SHADOW_EFFECT_OFFSET, this->width() - SHADOW_EFFECT_OFFSET - SHADOW_EFFECT_SIZE * 2 + i, this->height() - SHADOW_EFFECT_OFFSET - SHADOW_EFFECT_SIZE * 2 + i, SHADOW_EFFECT_SIZE);
			color.setAlpha(160 - qSqrt(i) * 50);
			painter.setPen(color);
			painter.drawPath(path);
		}
	}

	virtual void showEvent(QShowEvent* event) override
	{
		//解决无边框窗口最小化还原后子控件不刷新Bug
		this->setAttribute(Qt::WA_Mapped);
		QWidget::showEvent(event);
	}

	void TitleMouseMoveEvent(QMouseEvent *event)
	{
		if (this->isMaximized())
			return;

		if (event->buttons() && Qt::LeftButton)
		{
			move(event->globalPos() - m_ptDragPosition);
			event->accept();
		}
		return;
	}

	virtual void EnableMouseTracking(bool bEnable)
	{
		this->setMouseTracking(true);
		m_pContentFrame->setMouseTracking(true);
	}

	virtual void InitLayout(QString strBackgroundName = "") override
	{
		setAttribute(Qt::WA_TranslucentBackground);
		setWindowFlags(Qt::FramelessWindowHint);

		m_pContentFrame = new QFrame(this);
		if (!strBackgroundName.isEmpty())
		{
			m_pContentFrame->setObjectName(strBackgroundName);
		}

		QVBoxLayout* pContentLayout = new QVBoxLayout();
		pContentLayout->addWidget(m_pContentFrame);
		pContentLayout->setMargin(SHADOW_EFFECT_SIZE);
		pContentLayout->setSpacing(0);
		m_pMainLayout = new QVBoxLayout();
		m_pMainLayout->setMargin(0);
		m_pMainLayout->setSpacing(0);
		m_pContentFrame->setLayout(m_pMainLayout);
		setLayout(pContentLayout);
	}

public:
	virtual void SetContentMargins_(int left = SHADOW_EFFECT_SIZE, int top = SHADOW_EFFECT_SIZE, int right = SHADOW_EFFECT_SIZE, int bottom = SHADOW_EFFECT_SIZE)  //add 20211127
	{
		QVBoxLayout* pContentLayout = (QVBoxLayout*)layout();
		pContentLayout->setMargin(0);
		pContentLayout->setContentsMargins(left, top, right, bottom);
	}

	int GetShadowEffectSize()
	{
		return SHADOW_EFFECT_SIZE;
	}

	QVBoxLayout* GetRootWidgetMainLayout()
	{
		return m_pMainLayout;
	}
	QHBoxLayout* GetMenuLayout()
	{
		return m_pMenuLayout;
	}
	QList<QPushButton*>* GetBtnList()
	{
		return m_pListBtn;
	}
	QWidget* GetCaptureWidget()
	{
		return m_pTitleBar;
	}
	QLabel* GetLabelCation()
	{
		return m_pLblCaption;
	}

private:
	int GetScaleRow(QPoint pos)
	{
		if (pos.y() < BORDER_SCALE_MARGIN)
		{
			return 10;
		}
		else if (pos.y() > height() - BORDER_SCALE_MARGIN)
		{
			return 30;
		}
		else
		{
			return 20;
		}
	}

	int GetScaleCol(QPoint pos)
	{
		if (pos.x() < BORDER_SCALE_MARGIN)
		{
			return 1;
		}
		else if (pos.x() > width() - BORDER_SCALE_MARGIN)
		{
			return 3;
		}
		else
		{
			return 2;
		}
	}

	int MoveScaleArea(QPoint pos)
	{
		return GetScaleRow(pos) + GetScaleCol(pos);
	}

	void SetScaleMouseStyle(int moveArea)
	{
		switch (moveArea) {
		case 11:
			setCursor(Qt::SizeFDiagCursor);
			break;
		case 12:
			setCursor(Qt::SizeVerCursor);
			break;
		case 13:
			setCursor(Qt::SizeBDiagCursor);
			break;
		case 21:
			setCursor(Qt::SizeHorCursor);
			break;

		case 22:
			if (!m_bMousePress)
			{
				setCursor(Qt::ArrowCursor);
			}
			break;
		case 23:
			setCursor(Qt::SizeHorCursor);
			break;
		case 31:
			setCursor(Qt::SizeBDiagCursor);
			break;
		case 32:
			setCursor(Qt::SizeVerCursor);
			break;
		case 33:
			setCursor(Qt::SizeFDiagCursor);
			break;

		default:
			setCursor(Qt::WaitCursor);
			break;
		}
	}

	void ScaleWindow(QMouseEvent *event, int nMoveArea)
	{
		QPoint tempPos = event->globalPos() - m_ptScalePosition;
		QRect rect = geometry();
		switch (nMoveArea)
		{
		case 11:
			rect.setTopLeft(rect.topLeft() + tempPos);
			break;

		case 13:
			rect.setTopRight(rect.topRight() + tempPos);
			break;

		case 31:
			rect.setBottomLeft(rect.bottomLeft() + tempPos);
			break;

		case 33:
			rect.setBottomRight(rect.bottomRight() + tempPos);
			break;

		case 12:
			rect.setTop(rect.top() + tempPos.y());
			break;

		case 21:
			rect.setLeft(rect.left() + tempPos.x());
			break;

		case 23:
			rect.setRight(rect.right() + tempPos.x());
			break;

		case 32:
			rect.setBottom(rect.bottom() + tempPos.y());
			break;
		default:
			break;
		}
		this->setGeometry(rect);
		m_ptScalePosition = event->globalPos();
	}

private:
	bool			m_bMousePress;
	bool			m_bScaleEnable;
	bool			m_bMoveEnable;
	bool			m_bShadowEnable;
	QPoint			m_ptDragPosition;
	QPoint			m_ptScalePosition;
	QWidget*		m_pTitleBar;
	QFrame*			m_pContentFrame;

	QVBoxLayout*	m_pMainLayout;

	QHBoxLayout*	m_pMenuLayout;

	QButtonGroup*	m_pBtnGroup;

	QList<QPushButton*>* m_pListBtn; //add 20211104

	QLabel* m_pLblCaption;
};
#endif