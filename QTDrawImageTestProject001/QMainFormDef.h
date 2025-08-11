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

const char* const CS_APP_LAUNCH_FAILURE = "MBDD����ʧ��";
const char* const MSG_CLOSE_BY_LICENSE = "��ʽ�޷�����, û����Ȩ���!!";
const char* const MSG_CLOSE_BY_FACTORY = "��ʽ�޷�����, �޷�ʶ��Ĺ������!!";
const char* const MSG_CLOSE_BY_FACTORY_PARAM = "��ʽ�޷�����, �޷����ݹ��������ز���!!";
const char* const MSG_CLOSE_BY_LOGIN = "��ʽ�޷�����, �û���¼ʧ��!!";
const char* const MSG_CLOSE_BY_LOAD_CONFIG = "��ʽ�޷�����, ���������û�������ô���!!";

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