#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QTDrawImageTestProject001.h"
#include "QThreadTest.h"
#include <QVector>
#include <QMap>
#define DEFECT_NUMBER_MAX 20

const char* const BFS_VIAL_PATTERN_C062_0001_BODY_DOWN_CN[]{
	"装量",  //0
	"黑点",  //1
	"凹陷",  //2
	"划痕",  //3
	"变形",  //4
	"堆料",	 //5
	"毛边",	 //6
	"",	     //7
	"",	     //8
	"缺支、空瓶",  //9
	"装量多", //10 add form software, not algorithm	
	"装量少"  //11 add form software, not algorithm	
};
struct DEFECT_STATISTIC_ITEM_t
{
	bool used;
	char defectName[32];
	int count;
	DEFECT_STATISTIC_ITEM_t() { Clear(); }
	void Clear()
	{
		used = false;
		memset(defectName, 0, 32);
		count = 0;
	}	
	DEFECT_STATISTIC_ITEM_t(const DEFECT_STATISTIC_ITEM_t& other_)
	{
		this->used = other_.used;
		memcpy(this->defectName, other_.defectName, 32);
		this->count = other_.count;
	}
	static bool compare(const DEFECT_STATISTIC_ITEM_t& one, const DEFECT_STATISTIC_ITEM_t& two)
	{
		return one.count > two.count;
	}
};
struct DEFECT_STATISTIC_t
{
	int defectCountTotal;
	DEFECT_STATISTIC_ITEM_t defects[DEFECT_NUMBER_MAX];
	void Clear()
	{
		defectCountTotal = 0;
		for (int nIndex = 0; nIndex < DEFECT_NUMBER_MAX; nIndex++)
		{
			defects[nIndex].Clear();
		}
	}
	DEFECT_STATISTIC_t() { Clear(); }
	bool AddDefect(const char* const szDefectName, int defectCount = 1)
	{
		if (szDefectName == nullptr || strlen(szDefectName) == 0)
			return false;
		defectCountTotal += defectCount;
		bool bAddSuccess = false;
		for (int nIndex = 0; nIndex < DEFECT_NUMBER_MAX; nIndex++)
		{
			if (defects[nIndex].used == false)
			{
				defects[nIndex].used = true;
				strcpy_s(defects[nIndex].defectName, szDefectName);
				defects[nIndex].count += defectCount;
				bAddSuccess = true;
				break;
			}
			if (defects[nIndex].used == true
				&& strcmp(defects[nIndex].defectName, szDefectName) == 0)
			{
				defects[nIndex].count += defectCount;
				bAddSuccess = true;
				break;
			}
		}
		return bAddSuccess;
	}
};

class QImageDetectFrame;
class QFailureCountFloatPan;
class QTipsLabel;
class QLCDNumber;
class QStackedWidget;
class MCU_DEVICE_PROTOCOL_BIT_INFO_t;
class QLabel;
class QTDrawImageTestProject001 : public QMainWindow
{
    Q_OBJECT

public:
    QTDrawImageTestProject001(QWidget *parent = Q_NULLPTR);

public slots:
	void OnClickLoadImage();
	void OnClickTest();

	void showfloatwindow();
	void hidefloatwindow();
	void OnClickShowExportDialog();
	void OnUpdateTime();

	void OnClickSwitchPage();
	void OnClickChangeLabelBG();
private:
	void CreatePage1();
	void CreatePage2();
	void CreatePage3();
    void CreatePage4();
    void CreatePage5();
private:
    Ui::QTDrawImageTestProject001Class ui;

	QVector<QImageDetectFrame*> m_vecDefectShowsBody;

private:
	QFailureCountFloatPan* pFloatPan;
	QTipsLabel* pLab;
	QLCDNumber* m_pLcdDataTime;
	QThreadTest1* m_pThread1;
	QThreadTest2* m_pThread2;


	QStackedWidget * m_pStackedWidget;

	QMap<int, MCU_DEVICE_PROTOCOL_BIT_INFO_t*> m_InputbitInfo;
	QMap<int, MCU_DEVICE_PROTOCOL_BIT_INFO_t*> m_OutputbitInfo;
	QVector<QLabel*> m_vtStatusInput;
	QVector<QLabel*> m_vtStatusOutput;
	int m_nChangeLebalBG;
};

struct MCU_DEVICE_PROTOCOL_BIT_INFO_t
{
	int bitPostion;
	char message_[64];
	MCU_DEVICE_PROTOCOL_BIT_INFO_t()
	{
		bitPostion = 0;
		memset(message_, 0, 64);
	}
};