#ifndef _QMAINFORMDEF_H_
#define _QMAINFORMDEF_H_

#pragma once

#pragma execution_character_set("utf-8")

static const char* CS_SINGLE_APP_NAME = "YZYL-MBDD";

static const char* CS_LANUCH_AUTORUN_ARG = " - autorun";
static const char* CS_LANUCH_AUTORUN_KEY = "autorun";

const char* const QT_IM_MODULE = "QT_IM_MODULE";
const char* const CS_KEYBOARD_NAME = "Qt5Input";
const char* const CS_QSS_PATH = "styles/Darkgreen.qss";
const char* const CS_QSS_PATH_C602 = "styles/DarkgreenC602.qss";

const char* const STATISTICS_PROPERTY = "statistics";
const char* const BIG_BLOD_NAME = "bigbold";
const char* const RED_BLOD_NAME = "redbold";

const char* const CS_APP_LAUNCH_FAILURE = "MBDD启动失败";
const char* const MSG_CLOSE_BY_LICENSE = "程式无法启动, 没有授权许可!!";
const char* const MSG_CLOSE_BY_FACTORY = "程式无法启动, 无法识别的工厂类别!!";
const char* const MSG_CLOSE_BY_FACTORY_PARAM = "程式无法启动, 无法根据工厂类别加载参数!!";
const char* const MSG_CLOSE_BY_LOGIN = "程式无法启动, 用户登录失败!!";
const char* const MSG_CLOSE_BY_LOAD_CONFIG = "程式无法启动, 加载主配置或相机配置错误!!";

enum MAIN_CONTROL_BUTTON_e
{
	MAIN_CONTROL_BUTTON_NONE,
	MAIN_CONTROL_BUTTON_GOSTOP,
	MAIN_CONTROL_BUTTON_STANDARD,
	MAIN_CONTROL_BUTTON_FORMULA,
	MAIN_CONTROL_BUTTON_PRODUCE_LOG,
	MAIN_CONTROL_BUTTON_SYSTEM_LOG,
};

enum FORM_TYPE_e
{
	FORM_TYPE_NONE,
	FORM_TYPE_MAIN,
	FORM_TYPE_PRODUCT,
	FORM_TYPE_SYSTEM,
};

enum EXPAND_VIEW_e
{
	EXPAND_VIEW_DETECT,
	EXPAND_VIEW_SYSTEM_LOG,
	EXPAND_VIEW_PRODUCE_BILL,
	EXPAND_VIEW_MONITOR_DATA,  // use for DeNuo detect widget. //add 20201013
};
enum FORM_MAIN_CONTROL_e  //use for show the select work mode view //add 20200923
{
	MAIN_CONTROL_VIEW = 0,
	SELECT_WORK_MODE_VIEW,
};

enum UPDATE_UI_TYPE_e   //add 20210107
{
	NONE_UI = -1
	, RESET_UI
	, UPDATE_UI
};
 
enum MAIN_TAB_VIEW_e
{
	MAIN_TAB_VIEW_DETECT,
	MAIN_TAB_VIEW_PRODUCT,
	MAIN_TAB_VIEW_SYSTEM,
	MAIN_TAB_VIEW_DEFECT_REVIEW,  //add 20210114
	MAIN_TAB_VIEW_DETECT_SETTING, //add 20210228
};

#endif