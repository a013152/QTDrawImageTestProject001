#pragma once

struct PREV_PREDICT_t
{
    bool bProcessed;
};


enum DETECT_FLAG_e
{
    DETECT_FLAG_NONE,		// 未初始化;
    DETECT_FLAG_OK,			// 被分类为合格;
    DETECT_FLAG_NG,			// 被分类为不合格;
    DETECT_FLAG_OK_DEBUG,	// 被分类为合格，且需要显示
    DETECT_FLAG_INVALID,	// 缺陷无效;
};

enum DETECT_DATA_STATUS_e
{
    DETECT_DATA_STATUS_NONE = 0,
    DETECT_DATA_STATUS_ALGO = 1,   //after the Detect Algorithm return
    DETECT_DATA_STATUS_RULE = 2,   //after the Detect Rule filter
};

enum INFERENCE_CLASSIFY_e   //add 20230718 // use for kick off channel
{
    INFERENCE_CLASSIFY_UNKNOW = 0,
    INFERENCE_CLASSIFY_TYPE_ONE,
    INFERENCE_CLASSIFY_TYPE_TWO,
    INFERENCE_CLASSIFY_TYPE_THREE,
};
enum PREDICTION_ALGORITHM_INDEX_e
{
    PREDICT_NONE = -1,
    PREDICT_BOTTLE_GAP_C1_V1 = 0,//Peite C1 detect gap  == QBottleGapAlgorithm
};
struct DEFECT_DATA_t
{
    int pattern;
    double confidence;
    QRect region;
    PREDICTION_ALGORITHM_INDEX_e detector;  //  //add 20210326
    DETECT_DATA_STATUS_e dataStatus; //add 20220120
    double doseDifferences; //add 20220526
    DEFECT_DATA_t()
    {
        Clear();
    }
    void Clear()
    {
        pattern = -1;
        confidence = 0.0f;
        region = QRect();
        detector = PREDICT_NONE;
        dataStatus = DETECT_DATA_STATUS_NONE;
        doseDifferences = 0.0;
    }

    DEFECT_DATA_t& operator=(const DEFECT_DATA_t& stData)
    {
        pattern = stData.pattern;
        confidence = stData.confidence;
        region = stData.region;
        detector = stData.detector;
        dataStatus = stData.dataStatus;
        doseDifferences = stData.doseDifferences;
        return *this;
    }

    bool IsValid() const
    {
        return pattern >= 0;
    }
};

struct DEFECT_RESULT_t
{
    int nID;
    DETECT_FLAG_e flag;
    DEFECT_DATA_t data;
    QString patternName;
    INFERENCE_CLASSIFY_e classify;

    DEFECT_RESULT_t()
    {
        Clear();
    }
    DEFECT_RESULT_t(int id) :nID(id) 
    {
    }
    void Clear()
    {
        flag = DETECT_FLAG_NONE;
        data.Clear();
        patternName.clear();
        classify = INFERENCE_CLASSIFY_UNKNOW;
    }

    DEFECT_RESULT_t(const DEFECT_DATA_t& stData)
    {
        Clear();
        this->data = stData;
    }

    DEFECT_RESULT_t& operator=(const DEFECT_RESULT_t& stResult)
    {
        flag = stResult.flag;
        data = stResult.data;
        patternName = stResult.patternName;
        classify = stResult.classify;
        this->nID = stResult.nID;
        return *this;
    }

    DEFECT_RESULT_t& operator=(const DEFECT_DATA_t& stData)
    {
        Clear();
        this->data = stData;
        return *this;
    }
};
struct PREDICT_DATA_t
{
    int base;
};
struct COMBO_PARSE_DEFECT_ITEM_t
{
    PREDICT_DATA_t* pPredictData;
    const QMap<long, QList<long>*>* pMapDefectRules;
    QVector<DEFECT_RESULT_t>* pDefectResult;
    int nDefectCount;  // 0 defects meaning OK

    COMBO_PARSE_DEFECT_ITEM_t() { Clear(); }

    ~COMBO_PARSE_DEFECT_ITEM_t() { Clear(); }

    void Clear() {
        pPredictData = nullptr;
        pMapDefectRules = nullptr;
        pDefectResult = nullptr;
        nDefectCount = 0;
    }
};