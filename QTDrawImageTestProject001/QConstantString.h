#ifndef _QCONSTANTSTRING_H_
#define _QCONSTANTSTRING_H_

#pragma once

#pragma execution_character_set("utf-8")

// command name;
const char* const BTN_COMFIRM_NAME = "ȷ��";
const char* const BTN_APPLY_NAME = "Ӧ��";
const char* const BTN_CLOSE_NAME = "�ر�";
const char* const BTN_CANCEL_NAME = "ȡ��";
const char* const BTN_ADD_NAME = "+";
const char* const BTN_REBOOT_APP_NAME = "���µ�¼";
const char* const BTN_REBOOT_OS_NAME = "�� ��";
const char* const BTN_SHUTDOWN_OS_NAME = "�� ��";
const char* const BTN_START_NAME = "��ʼ";
const char* const BTN_LAUNCH_NAME = "�� ��";
const char* const BTN_STOP_NAME = "ֹͣ";

const char* const CS_SUCCEED_EN_NAME = "Succeed";
const char* const CS_FAILURE_EN_NAME = "Failure";
const char* const CS_SUCCEED_CHS_NAME = "�ɹ�";
const char* const CS_FAILURE_CHS_NAME = "ʧ��";

// from QFactory
const char* const ERR_FACTORY_DEVICE_CONTROL_NULL = "���豸����������δ����!!";
const char* const ERR_FACTORY_CAMERA_CONTROL_NULL = "���������������δ����!!";
const char* const ERR_FACTORY_DEVICE_UPDATE_PARAM = "���豸�����������²���ʧ��!!";
const char* const ERR_FACTORY_CAMERA_UPDATE_PARAM = "����������������²���ʧ��!!";
const char* const ERR_FACTORY_DEVICE_BEGIN_FAILURE = "���豸������������ʧ��!!";
const char* const ERR_FACTORY_CAMERA_BEGIN_FAILURE = "�����������������ʧ��!!";
const char* const ERR_CAMERA_CONTROL_CREATE_FAILURE = "�����������������ʧ��!!";
const char* const CS_CAMERA_CONTROL_CHS_NAME = "���������";
const char* const ERR_CAMERA_CONTROL_CAM_NOT_FOUND = "δ�������������������������Ƿ�����?!";
const char* const ERR_CAMERA_CONTROL_CAM_NOT_MATCH = "������Ӹ������趨ֵ��ƥ��!!";
const char* const ERR_FACTORY_WORK_MODE_CONTROL_NULL = "������ģʽ����������δ����!!";
const char* const ERR_FACTORY_WORK_MODE_UPDATE_PARAM = "������ģʽ�����������²���ʧ��!!";
const char* const ERR_FACTORY_WORK_MODE_BEGIN_FAILURE = "������ģʽ������������ʧ��!!";

// from Login;
const char* const ERR_ACCOUNT_CHECK_EMPTY = "�˻���Ϊ��!!";
const char* const ERR_PASSWORD_CHECK_EMPTY = "����Ϊ��!!";
const char* const ERR_ACCOUNT_LOGIN_FAILURE = "��¼ʧ�ܣ���ȷ�Ϻ����³���..";
const char* const ACT_ACCOUNT_LOGIN_SUCCEED = "��¼�ɹ�!";
const char* const MSG_LOAD_PARAM_SUCCEED = "ϵͳ���ز����ɹ�";
const char* const MSG_LOAD_PARAM_FAILURE = "ϵͳ���ز���ʧ��";

const char* const CS_LOGIN_ACCOUNT_NAME = "�˻�";
const char* const CS_LOGIN_ACCOUNT_PASSWORD = "����";
const char* const BTN_LOGIN_NAME = "�� ¼";

const char* const MSG_INIT_MODULE = ">> ��ʼ�� ";

const char* const MSG_LOGIN_AND_WAIT = "��¼�ɹ�, �����ĵȴ���ʽ��ʼ��...";

// from QMainForm;
const char* const MSG_APP_START_NAME = "------------ App Start ------------";
const char* const MSG_APP_END_NAME = "------------ App End   ------------";

const char* const PRODUCT_DETECT = "��Ʒ���";
const char* const PRODUCT_SETTING = "��Ʒ����";
const char* const DETECT_SETTING = "�������";
const char* const SYSTEM_SETTING = "ϵͳ����";

const char* const ACT_SWITCH_TO_PRODUCT_DETECT = "�л�����Ʒ���ҳ";
const char* const ACT_SWITCH_TO_PRODUCT_SETTING = "�л�����Ʒ����ҳ";
const char* const ACT_SWITCH_TO_DETECT_SETTING = "�л����������ҳ";
const char* const ACT_SWITCH_TO_SYSTEM_SETTING = "�л���ϵͳ����ҳ";
const char* const MSG_SWITCH_TO_PRODUCT_DETECT = "ϵͳ�Զ��л�����Ʒ���ҳ";
const char* const ACT_SWITCH_TO_DEFECT_REVIEW = "�л���ȱ�ݻؿ�ҳ";

const char* const ACT_CLOSE_MAIN_FORM = "�ر����";
const char* const ACT_REBOOT_APP = "�������";
const char* const ACT_REBOOT_SYSTEM = "����ϵͳ";
const char* const ACT_SHUTDOWN_SYSTEM = "�ر�ϵͳ";

const char* const ASK_MAIN_CLOSE_CAPTION = "ϵͳ�ر�ȷ��";
const char* const ASK_MAIN_CLOSE_CONFIRM = "ȷ��Ҫ�رռ��ϵͳ��?";

// from QDetectDetailWidget;
const char* const CS_DETECT_DETAIL_CAPTION = "���ϸ��Ʒ��ϸ�б�";

const char* const TABLE_DEFECT_ITEM_NAME[] =
{
	"ƿ��",
	"���",
	"���",
	"ʱ��"
};

// from QDetectModeWidget;
const char* const CS_DETECT_MODE_SWITCH_TO = "�л���: %1";
const char* const CS_DETECT_MODE_CAPTION = "ģʽ: ";
const char* const CS_DETECT_VIEW_CAPTION = "��ͼ: ";
const char* const CS_DETECT_CURRENT_MODE_CAPTION = "��ǰģʽ: %1";
const char* const CS_DETECT_CURRENT_VIEW_CAPTION = "��ǰ��ͼ: %1";

const char* const BTN_DETECT_MODE_NAME[] =
{
	"",
	"Block Mode",
	"PPT Mode",
	"Alignment Mode",
	"Sampling Mode"
};

const char* const BTN_DETECT_VIEW_NAME[] =
{
	"Defect View",
	"Monitor Mode",
};

const char* const BTN_DETECT_VIEW_CHS_NAME[] =
{
	"��⻺����ͼ",
	"���ܼ����ͼ",
};

// from QDetectStatisticsWidet;
const char* const CS_DETECT_STATISTICS_CAPTION = "��Ʒ���ͳ��";
const char* const CS_DETECT_TOTAL_CAPTION = "�����������";
const char* const CS_DETECT_FAILURE_RATIO_CAPTION = "�� �� �ʣ�";
const char* const CS_DETECT_STANDARD_COUNT_CAPTION = "�ϸ�Ʒ";
const char* const CS_DETECT_FAILURE_COUNT_CAPTION = "��ƿ / ���ϸ�";
const char* const CS_DETECT_FAILURE_COUNT_CAPTION_ = "���ϸ�";
const char* const CS_DETECT_FLOW_SPEED_CAPTION = "ƿ������";

const char* const CS_DETECT_DEFECT_TYPE_STATISTICS = "ȱ�����ͳ��";
const char* const CS_DETECT_PRODUCT_FAILURE_COUNT = "���ϸ��Ʒ��";
const char* const CS_DETECT_DEFECT_COUNT_TOTAL = "���ȱ������";
const char* const TABLE_FAILURE_COUNT_ITEM_NAME[] =
{
	"ȱ�����",
	"ȱ�ݸ���",
	"ȱ�ݱ���"
};
// from QDeviceStatusWidget;
const char* const CS_DEVICE_STATUS_CAPTION = "�豸״̬";

// from QOperatorInfoWidget;
const char* const CS_OPERATOR_NAME_CAPTION = "����Ա :";
const char* const CS_OPERATOR_LOGIN_TIME_CAPTION = "����ʱ�� :";
const char* const CS_DETECT_TIME_CAPTION = "���ʱ�� :";

// from QProductInfoWidget;
const char* const CS_PRODUCT_INFO_CAPTION = "��Ʒ��Ϣ";
const char* const CS_BATCH_NUMBER_CAPTION = "��������";
const char* const CS_PRODUCT_INFO_NAME_CAPTION = "��Ʒ����";
const char* const CS_PRODUCT_INFO_SPECIFICATION_CAPTION = "��Ʒ���";
const char* const CS_PRODUCT_INFO_PATTERN_CAPTION = "������";

const char* const ACT_PRODUCT_NAME_SELECT_EMPTY = "ѡ���Ʒ����Ϊ: ��";
const char* const ACT_PRODUCT_NAME_SELECT = "ѡ���ƷΪ: %1 - %2";
const char* const ACT_PRODUCT_BATCH_INPUT = "�����Ʒ����Ϊ: %1";

// from QMainControlWidget;
const char* const CS_MAIN_CONTROL_CAPTION = "ϵͳ����";
const char* const WRN_LICENSE_STOP_FAILURE = "��⵽�����δ��Ȩ, ϵͳ�Զ��������, ����ʹ�����뿪������ϵ.";
const char* const WRN_LICENSE_FAILURE = "��δ��Ȩ, ��⹦��ʧЧ";
const char* const WRN_LICENSE_SUCCEED = "��Ȩ�ɹ�, ��⹦������";

const char* const WRN_CHANGE_PRODUCT_STOP_FAILURE = "��⵽�޸Ĳ�Ʒ��Ϣ, ϵͳ�Զ��������.";


const char* const ACT_DATA_RESET = "��������";
const char* const ACT_LAUNCH_STARTING = "�������..";
const char* const MSG_LAUNCH_STARTED = "�������ɹ�";
const char* const MSG_LAUNCH_START_FAILURE = "�������ʧ��";
const char* const ACT_LAUNCH_ENDING = "ֹͣ���..";
const char* const MSG_LAUNCH_ENDED = "ֹͣ���ɹ�";

const char* const ACT_SHOW_EXPAND_VIEW[] =
{
	"",
	"������¼��ͼ",
	"������¼��ͼ",
	"���ܲ�������"
};


const char* const BTN_UNAUTHORIZED_NAME = "�� Ȩ\r\n\r\n\r\n�� ��";
const char* const BTN_RESET_DATA_NAME = "��������";
const char* const BTN_RESERVED_NAME = "�� ��";
const char* const BTN_PRODUCE_BILL_NAME = "������¼";
const char* const BTN_SYSTEM_LOG_NAME = "������¼";
const char* const BTN_RESET_NAME = "�� λ";

const char* const ASK_DATE_RESET_COMFIRM = "ȷ��Ҫͳ���������㴦����?";

// from ProduceBillWidget;
const char* const ACT_PRODUCE_QUERY = "��ʼ��ѯ������¼: %1@%2[%3 - %4]";
const char* const ACT_PRODUCE_REPORT = "��ʼ�Բ�ѯ������¼���ɱ���..";
const char* const ACT_IMAGE_UPLOAD = "��ʼ�Բ��ϸ�ͼ������ϴ�..";
const char* const WRN_PRODUCE_QUERY_FAILURE = "���Ҳ�ѯʧ��!!";
const char* const MSG_PRODUCE_BILL_COUNT = " %1 ����¼��������";
const char* const WRN_PRODUCE_REPORT_BATCH_NEED = "ֻ�ܸ��ݲ�Ʒ�������ɱ���!!";
const char* const WRN_PRODUCE_REPORT_DATA_NEED = "��ѯ��������Ϊ0, ���Ȳ�ѯ���ݺ������ɱ���!!";
const char* const MSG_REPORT_SAVE_DIALOG_NAME = "��ѡ�񱣴汨���·��";
const char* const WRN_REPORT_SAVE_RESULT_SUCCEED = "������¼���汣��ɹ�,·��Ϊ:%1";
const char* const ERR_REPORT_SAVE_RESULT_FAILURE = "������¼���汣��ʧ��!!";
const char* const WRN_IMAGE_UPLOAD_SUCCEED = "�ϴ����ϸ�ͼ�����";
const char* const ERR_IMAGE_UPLOAD_CANCEL = "ȡ���ϴ����ϸ�ͼ��";

// from QMvCamera;
const char* const ERR_CAMERA_NOT_FOUND = "���������!!";
const char* const ERR_CAMERA_INSTANCE_FAILURE = "�������ʧ��!!";
const char* const ERR_CAMERA_OPEN_FAILURE = "�������ʧ��!!";
const char* const ERR_CAMERA_INITIALIZE_FAILURE = "�����ʼ��ʧ��!!";
const char* const ERR_CAMERA_GRAB_FAILURE = "����ɼ�ʧ��!!";
const char* const ERR_CAMERA_REG_EXCEP_FAILURE = "���ע���쳣�ص�ʧ��!!";
const char* const ERR_CAMERA_RECONNECTING = "�����ʧ������������!!";
const char* const ERR_CAMERA_RECONNECT_FAILURE = "��������쳣���������!!";

// from Account View;
const char* const CS_ACCOUNT_CAPTION = "�˻���";
const char* const CS_ACCOUNT_PASSWORD_CAPTION = "���룺";
const char* const CS_ACCOUNT_PASSWORD_CONFIRM_CAPTION = "ȷ������: ";
const char* const CS_ACCOUNT_GROUP_CAPTION = "�˻���: ";

const char* const CS_ACCOUNT_TABLE_TITLE = "�˻�";
const char* const CS_ACCOUNT_TABLE_COLUMN_USER = "�û���";
const char* const CS_ACCOUNT_TABLE_COLUMN_GROUP = "Ⱥ��";

const char* const ASK_DELETE_ACCOUNT_TITLE = "ɾ���˻�";
const char* const ASK_DELETE_ACCOUNT_COMFIRM = "ȷ��Ҫɾ����%1���˻���?";

const char* const ERR_ACCOUNT_NAME_EMPTY = "�˻�������Ϊ��!!";
const char* const ERR_ACCOUNT_PASSWORD_EMPTY = "���벻��Ϊ��!!";
//add by ChenLin 20200821
const char* const ERR_ACCOUNT_NAME_NOT_CONFORM = "�˻��������Ϲ����޶�3λ���֡���ĸ���»���!!";
const char* const ERR_ACCOUNT_PASSWORD_NOT_CONFORM = "���벻���Ϲ����޶�6λ���֡���ĸ���»���!!";
//add end 20200821
const char* const ERR_ACCOUNT_PASSWORD_CONFIRM = "ȷ�����벻��ȷ!!";
const char* const ERR_ACCOUNT_GROUP_EMPTY = "��ѡ���˻���!!";
const char* const ERR_ACCOUNT_NAME_EXIST = "�˻��Ѵ���!!";
const char* const ERR_ACCOUNT_ADD_FAILURE = "�������˻�ʧ��!!";
const char* const ERR_ACCOUNT_MODIFY_FAILURE = "�޸��˻�ʧ��!!";

//20210204
const char* const CS_DETECT_RULE_TABLE_TITLE = "������";
const char* const CS_DETECT_RULE_TABLE_COLUMN_NAME = "��������";
const char* const ASK_DELETE_DETECT_RULE_ERROR_1 = "����ɾ����%1�������Ѿ�����Ʒ��%2��������";
const char* const ASK_DELETE_DETECT_RULE_TITLE = "ɾ��������";
const char* const ASK_DELETE_DETECT_RULE_COMFIRM = "ȷ��Ҫɾ����%1����������?";

//20210902
const char* const CS_DETECT_RULE_DOSE_UP_LIMIT = "װ������";
const char* const CS_DETECT_RULE_DOSE_DOWN_LIMIT = "װ������";

//const char* const CS_DETECT_VIAL_CAP = "���ƿ��ȱ�ݣ�";
//const char* const CS_DETECT_VIAL_BODY = "���ƿ��ȱ�ݣ�";
//const char* const CS_DETECT_VIAL_BOTTOM = "���ƿ��ȱ�ݣ�"; 
const char* const CS_DETECT_VIAL_PATTERN_CAP_CN[]{
	"��⽺���߶�",
	"���ƿ��ȱ�ݣ�",
	"���ƿ��ȱ�ݣ�",
	"���ƿ��ȱ�ݣ�",
	"���װ��ȱ��",
	"����ɫȱ��"
	,"���BFSƿ���ϰ�"
	,"���BFSƿ���°�"
	,"���BFSƿ����"
	,"���BFSƿ��ײ�"
	,"���ƿ��ȱ�ݣ�"
	,"���ƿ��2ȱ�ݣ�"
	,"���ƿ��1ȱ�ݣ�"
	,"���ƿ��ȱ�ݣ�"
	,"���BFSƿ���ϰ�"
	,"���BFSƿ���°�"
	,"���BFSƿ����"
	,"���BFSƿ��ײ�"
	,"�����Һ��-�ⱳ��"
	,"���BFSƿ���ϰ�"
	,"���BFSƿ���°�"
	,"���BFSƿ����"
	,"���BFSƿ��ײ�"
};
const char* const NEW_CAPTION = "��������� - MBDD";
const char* const MODIFY_CAPTION = "�޸ļ����� - MBDD";
const char* const ERR_DETECT_RULE_NAME_EMPTY = "�������Ʋ���Ϊ��!!";
const char* const ERR_DETECT_RULE_NAME_NOT_CONFORM = "�������Ƴ��������3��С��30!!";
const char* const ERR_DETECT_RULE_NAME_THE_SAME = "���������ظ�!!";
const char* const ERR_DETECT_RULE_DOSE_LIMIT_NOT_CONFORM = "װ��ֻ�������������Ҳ�����";
const char* const ERR_DETECT_RULE_DOSE_LIMIT_UP_LESS_DOWN = "װ�����ص�λʱ�����޲��ܳ������ޣ�";
const char* const ERR_DETECT_RULE_DOSE_LIMIT_DOWN_MORE_UP = "װ���ٷֱȵ�λʱ�����޲��ܳ������ޣ�";
const char* const ERR_DETECT_RULE_ADD_FAILURE = "�����¼��������ݿ�ִ��ʧ��!!";
const char* const ERR_DETECT_RULE_MODIFY_FAILURE = "�޸ļ��������ݿ�ִ��ʧ��!!";
// from Camera View;
const char* const CS_CAMERA_VIEW_TITLE = "%1 > ���";

// from Detect View;
const char* const CS_DETECT_VIEW_NAME = "���";
const char* const CS_DETECT_VIEW_PROMPT = "�����뷧ֵ";
const char* const CS_DETECT_CONTEXT_TITLE = "������";

// from Device View;
const char* const CS_DEVICE_VIEW_TITLE = "%1 > �豸";
const char* const CS_DEVICE_CONTEXT_TITLE = "%1 - Com%2";

// from Product View;
const char* const CS_PRODUCT_BATCH_CAPTION = "��Ʒ����: ";
const char* const CS_PRODUCT_NAME_CAPTION = "*��Ʒ����: ";
const char* const CS_PRODUCT_SPECIFICATION_CAPTION = "*��Ʒ���: ";
const char* const CS_PRODUCT_FORMULA_CAPTION = " ��Ʒ�䷽: ";
const char* const CS_PRODUCT_DETECT_SOLUTION_CAPTION = "*��ⷽ��: ";

const char* const ERR_PRODUCT_BATCH_EMPTY = "��Ʒ����Ϊ��!!";
const char* const ERR_PRODUCT_NAME_EMPTY = "��Ʒ����Ϊ��!!";
const char* const ERR_PRODUCT_NAME_LENGTH = "��Ʒ���Ƴ��ȳ�������!!";
const char* const ERR_PRODUCT_SPECIFICATION_EMPTY = "��Ʒ���Ϊ��!!";
const char* const ERR_PRODUCT_FORMULA_EMPTY = "��Ʒ�䷽Ϊ��!!";
const char* const ERR_PRODUCT_BATCH_EXIST = "��Ʒ�����Ѵ���!!";
const char* const ERR_PRODUCT_EXIST = "��Ʒ�Ѵ���!!";
const char* const ERR_ATTACH_DETECT_SOLUTION_FAILURE = "���Ӽ�ⷽ��ʧ��!!";
const char* const ERR_PRODUCT_ADD_FAILRE = "�����²�Ʒʧ��!!";
const char* const ERR_PRODUCT_ADD_NAME_EXIST = "��Ʒ�����Ѵ���!!";

const char* const CS_PRODUCT_TABLE_TITLE = "��Ʒ�б�";
const char* const CS_PRODUCT_TABLE_COLUMN_BATCH = "���κ�";
const char* const CS_PRODUCT_TABLE_COLUMN_DESCRIPTION = "˵��";
const char* const CS_PRODUCT_TABLE_COLUMN_NAME = "����";
const char* const CS_PRODUCT_TABLE_COLUMN_SPECIFICATION = "���";
const char* const CS_PRODUCT_TABLE_COLUMN_BUILDTIME = "����ʱ��";

const char* const ASK_DELETE_PRODUCT_TITLE = "ɾ����Ʒ";
const char* const ASK_DELETE_PRODUCT_COMFIRM = "ȷ��Ҫɾ����%1����Ʒ��?";

const char* const ACT_CLICK_NEW_PRODUCT = "�������²�Ʒ..";
const char* const ACT_CANCEL_NEW_PRODUCT = "ȡ������²�Ʒ";
const char* const ACT_CONFIRM_NEW_PRODUCT = "�²�Ʒ��ӳɹ���%1";

const char* const ACT_CLICK_MODIFY_PRODUCT = "����޸Ĳ�Ʒ..";
const char* const MSG_MODIFY_PRODUCT_ENABLE = "�޸Ĳ�Ʒʹ�ܿ������û����ڿ����޸ĵڡ�%1�����Ʒ��Ϣ��";
const char* const MSG_MODIFY_PRODUCT_DISENABLE = "�޸Ĳ�Ʒʹ�ܹر�";

// from Product Param SubContext;
const char* const ACT_CANCEL_MODIFY_PRODUCT = "ȡ���޸Ĳ�Ʒ��Ϣ";
const char* const ACT_CONFIRM_MODIFY_PRODUCT = "ȷ���޸ġ�%1����Ʒ��Ϣ";

// from Bottle Count Column;
const char* const CS_BOTTLE_COUNT_DIRECTION = "��ƿ����";
const char* const CS_BOTTLE_COUNT_ROT_LEFT = "��߽�";
const char* const CS_BOTTLE_COUNT_ROT_TOP = "�ϱ߽�";
const char* const CS_BOTTLE_COUNT_ROT_WIDTH = "������";
const char* const CS_BOTTLE_COUNT_ROT_HEIGHT = "����߶�";
const char* const CS_BOTTLE_COUNT_THRESHOLD_NAME = "�Ҷȷ�ֵ";
const char* const CS_BOTTLE_COUNT_ACCEPTANCE_CRITERIA_NAME = "������׼";

// from Bottle Gap Column;
const char* const CS_VIAL_PLUG_GAP_CONTEXT_TITLE = "ƿ����϶�ȼ�";

// from Vial detect rule Column;  //add by chenlin 20210202
const char* const CS_VIAL_DETECT_RULE_TITLE = "������";

// from Camera Inherence Column;
const char* const CS_CAMERA_NAME = "����";
const char* const CS_CAMERA_INTERFACE_NAME = "�ӿ�";
const char* const CS_CAMERA_RESOLUTION_NAME = "�ֱ���";
const char* const CS_CAMERA_PIXEL_TYPE_NAME = "���ظ�ʽ";

// from Camera Solution Column;
const char* const CS_CAMERA_WIDTH_NAME = "ͼ����";
const char* const CS_CAMERA_HEIGHT_NAME = "ͼ��߶�";
const char* const CS_CAMERA_RESOLUTION_MAX_NAME = "���ֵΪ%1";
const char* const CS_CAMERA_OFFSET_X_NAME = "X��ƫ��";
const char* const CS_CAMERA_OFFSET_Y_NAME = "Y��ƫ��";
const char* const CS_CAMERA_EXPOSURE_NAME = "�ع�ʱ�䣨us��";
const char* const CS_BALANCE_AUTO_NAME = "��ƽ�����";
const char* const CS_BALANCE_RATIO_R_NAME = "��ɫƽ��ֵ";
const char* const CS_BALANCE_RATIO_G_NAME = "��ɫƽ��ֵ";
const char* const CS_BALANCE_RATIO_B_NAME = "��ɫƽ��ֵ";

const char* const CS_GAMMA_ENABLE_NAME = "٤��У��ʹ��";
const char* const CS_GAMMA_SELECTOR_NAME = "٤��У��ѡ����";
const char* const CS_GAMMA_NAME = "٤��У��";

const char* const CS_AUTO_GAIN_NAME = "�Զ�����";
const char* const CS_GAIN_NAME = "���棨dB��";

const char* const CS_TRIGGER_MODE_NAME = "����ģʽ";
const char* const CS_PARAM_SWITCH_NAME[] =
{
	"�ر�",
	"��"
};
const char* const CS_TRIGGER_SOURCE_NAME = "����Դ";
const char* const CS_TRIGGER_SOURCE_ITEM_NAME[] =
{
	"��·0",
	"��·1",
	"��·2",
	"��·3",
	"������0",
	"����"
};
//const char* const CS_TRIGGER_LINE0_NAME = "��·0";
//const char* const CS_TRIGGER_LINE1_NAME = "��·1";
//const char* const CS_TRIGGER_LINE2_NAME = "��·2";
//const char* const CS_TRIGGER_LINE3_NAME = "��·3";
//const char* const CS_TRIGGER_COUNTER0_NAME = "������0";
//const char* const CS_TRIGGER_SOFTWARE_NAME = "����";
const char* const CS_TRIGGER_DELAY_NAME = "�����ӳ٣�us��";
const char* const CS_TRIGGER_ACTIVATION_NAME = "��������";
const char* const CS_TRIGGER_ACTIVATION_ITEM_NAME[] =
{
	"������",
	"�½���"
};
const char* const CS_REVERSE_X_NAME = "ˮƽ��ת";
const char* const CS_REVERSE_Y_NAME = "��ֱ��ת";

// from Detect Solution Column;
const char* const CS_CAMERA_SOLUTION_NAME = "�������";
const char* const CS_DEVICE_SOLUTION_NAME = "�豸����";
const char* const CS_BOTTLE_COUNT_NAME = "ҩƿ����";
const char* const CS_VIAL_PLUG_GAP_NAME = "ƿ����϶�ȼ�";

// from Device Command Column;
const char* const CS_DEVICE_PULSE_WIDTH_NAME = "������";
const char* const CS_DEVICE_DELAY_TIME_NAME = "�޳���ʱ";

//add by ChenLin 20200706
// from PCIE Device Command Column's item;
const char* const CS_SCREW_CONVEYOR_TURNS_NAME = "����Ȧ�����";
const char* const CS_BOTTLE_REIGNING_NAME = "ƿ����λ���";
const char* const CS_KICK_OFF_STATE_NAME = "�޳�״̬";
const char* const CS_KICK_OFF_TRIGGER_NAME = "�޳�����";
const char* const CS_SIGNAL_DIRECTION_NAME = "�źŷ���";
const char* const CS_TERMINALS_CONNECT_NAME = "��������";
const char* const CS_TERMINALS_NUMBER_NAME = "���Ӻ�";
const char* const CS_SIGNAL_TYPES_NAME = "�ź�����";
const char* const CS_SIGNAL_INPUT_NAME = "����";
const char* const CS_SIGNAL_OUTPUT_NAME = "���";
const char* const CS_LOW_LEVEL_NAME = "�͵�ƽ"; 
const char* const CS_HIGHT_LEVEL_NAME = "�ߵ�ƽ";
const char* const CS_FALLING_EGDE_NAME = "�½���"; 
const char* const CS_RISING_EGDE_NAME = "������";

const char* const ASK_PCIE_COMMAND_CAPTION = "PCIEָ����ʾ";
const char* const ASK_PCIE_COMMAND_HAVE_COMFLICT = "PCIEָ����";
const char* const ASK_PCIE_COMMAND_SAME = "��ͬ��������Ч��";
//add end



// from Product Param Column;
const char* const CS_PRODUCT_NAME_NAME = "��Ʒ����";
const char* const CS_PRODUCT_SPECIFICATION_NAME = "��Ʒ���";
const char* const CS_PRODUCT_FORMULA_NAME = "��Ʒ�䷽";
const char* const CS_PRODUCT_POWDER_COLOR_NAME = "ҩ����ɫ";
const char* const CS_PRODUCT_CAP_COLOR_NAME = "ƿ����ɫ";
const char* const CS_PRODUCT_POWDER_COLOR[] =
{
	"��ɫ��",
	"��ɫ��"
};
const char* const CS_PRODUCT_CAP_COLOR[] =
{
	"��ɫ��",
	"��ɫ��"
};


// from Serial Port Param Column;
const char* const CS_COM_PORT_NAME = "���ں�";
const char* const CS_BAUD_RATE_NAME = "������";
const char* const CS_DATA_BITS_NAME = "����λ";
const char* const CS_PARITY_NAME = "��żУ��";
const char* const CS_STOP_BITS_NAME = "ֹͣλ";

// from Camera Param Context;
const char* const CS_ROI_VIEW_NAME = "��Ӧ����"; 
const char* const CS_CAMERA_INHERENCY = "����";

// from Pcie digital io carl Column
const char* const CS_PARALLEL_DEV_NUM = "�忨��";

// from Detect Param Context;
const char* const CS_BOTTLE_COUNT_COLUMN_NAME = "ҩƿ���� - ��� M%1I%2";
const char* const CS_VIAL_PLUG_GAP_COLUMN_NAME = "ƿ����϶";

// from Product Param Context;
const char* const CS_PRODUCT_PARAM_NAME = "��Ʒ����";
const char* const CS_DETECT_SOLUTION_NAME = "��ⷽ��";

// from Serial Port Param Context;
const char* const CS_SERIAL_PORT_NAME = "����";
const char* const CS_COMMAND_PARAM_NAME = "ָ������";
const char* const CS_PARALLEL_PORT_NAME = "����";

// from System Form;
const char* const CS_SYSTEM_NAVIGATION_NAME = "������";
const char* const CS_SYSTEM_PAGE_NAME = "ϵͳ����";
const char* const CS_ACCOUNT_COLUMN_NAME = "�˻�";
const char* const CS_CAMERA_COLUMN_NAME = "���";
const char* const CS_DEVICE_COLUMN_NAME = "�豸";
const char* const CS_DETECT_COLUMN_NAME = "���";
const char* const CS_DEBUGGER_COLUMN_NAME = "����";
const char* const CS_SYSTEM_COLUMN_NAME = "����";

const char* const ASK_SYSTEM_PARAM_SAVE_CAPTION = "�������������ʾ";
const char* const ASK_SYSTEM_PARAM_SAVE_CONTENT = "ϵͳ�����ѱ��޸�, �����Ƿ���Ҫ����?";

// from Product Form;
const char* const CS_PRODUCT_PAGE_NAME = "��Ʒ����";
const char* const CS_PRODUCT_SETTING_NAME = "��Ʒ�б�";

const char* const ASK_PRODUCT_PARAM_SAVE_CAPTION = "�������������ʾ";
const char* const ASK_PRODUCT_PARAM_SAVE_CONTENT = "��Ʒ�����ѱ��޸�, �����Ƿ���Ҫ����?";

// for DetectSetting Form
const char* const CS_DETECT_SETTING_PAGE_NAME = "�������";
const char* const CS_DETECT_RULE_LIST_NAME = "�������б�";
const char* const ASK_DETECT_PARAM_SAVE_CONTENT = "�������ѱ��޸�, �����Ƿ���Ҫ����?";

// from System Param View;
const char* const CS_TIME_LOCKER_NAME = "ϵͳʱ������";
const char* const CS_REPORT_FORMAT_NAME = "���������ʽ";
const char* const CS_ERROR_IMAGE_SAVE_NAME = "�쳣ͼ�񱣴�";
const char* const CS_OK_IMAGE_SAVE_NAME = "�ϸ�ͼ�񱣴�";
const char* const CS_NG_ORIGNAL_IMAGE_SAVE_NAME = "NGԭͼ����";
const char* const CS_TRIGGER_IMAGE_SAVE_NAME = "����ͼ�񱣴�(ROI)";
const char* const CS_TRIGGER_IMAGE_FORMAT_NAME = "����ͼ�񱣴��ʽ";
const char* const CS_CAMERA_ORIGNAL_IMAGE_SAVE_NAME = "���ԭͼ����(��ROI)";
const char* const CS_SYSTEM_REBOOT_PROMPT_NAME = "������Ҫ���������Ժ���Ч!!";
const char* const ASK_CLOSE_ERROR_IMAGE_TITLE = "�ر�ͼ�񱣴�";
const char* const ASK_CLOSE_ERROR_IMAGE_COMFIRM = "�رպ��޷��ؿ�ȱ�ݣ�ȷ��Ҫ�ر���?";

// from Produce Bill;
const char* const CS_PRODUCE_BILL_NAME_CAPTION = "��Ʒ����";
const char* const CS_PRODUCE_BILL_BATCH_CAPTION = "��Ʒ����";
const char* const CS_PRODUCE_START_TIME_CAPTION = "��ʼʱ��";
const char* const CS_PRODUCE_END_TIME_CAPTION = "����ʱ��";
const char* const BTN_PRODUCE_QUERY_NAME = "�� ѯ";
const char* const BTN_PRODUCE_REPORT_NAME = "���ܱ���";
const char* const BTN_PRODUCE_UPLOAD_IMAGE_NAME = "�ϴ�ͼƬ";

const char* const TABLE_PRODUCE_ITEM_NAME[] =
{
	"��ʼʱ��",
	"����ʱ��",
	"��Ʒ����",
	"��Ʒ����",
	"���ڹ��",
	"��Ʒ�䷽",
	"��������",
	"�쳣����",
	"ƽ������",
	"���߶�",
	"������Ա",
	"ȷ����Ա",	
	"����ģʽ",
	"�豸���",
	"�����Ϣ"
};

// from QFileCopyDialog;
const char* const CS_FILE_COPY_DIALOG_TITLE = "�ļ�����";
const char* const ERR_NO_FILE_FOUND = "û�з���ƥ���ļ�!!";
const char* const CS_SELECT_U_DISK_SELECT = "ѡ��U��";
const char* const CS_U_DISK_PATH = "����·��";
const char* const CS_GET_FILE_AMOUNT = "��ȡ�ļ�����...";
const char* const ERR_NO_U_DISK_FOUND = "û�з���U��!!";
const char* const MSG_COPY_FILE_RESULT[] =
{
	"�����ļ����",
	"�����ļ�ʧ��!!",
	"�ļ�������!!",
	"ֹͣ�����ļ�!!"
};

// from QLicenseAccessWidget;
const char* const CS_LICENSE_TITLE = "License";
const char* const CS_LICENSE_PROMPT = "��Ȩ���";
const char* const CS_LICENSE_SUCCEED = "�������Ȩ";
const char* const CS_LICENSE_FAILURE = "��δ��Ȩ!!";

// from QDetectParam;
const char* const MSG_DETECT_DATA_SAVE_SUCCEED = "����%1-%2�������ݳɹ�";
const char* const ERR_DETECT_DATA_SAVE = "����%1-%2��������ʧ��!!(%3)";
const char* const ERR_DETECT_DATA_EMPTY = "������ݵĲ�Ʒ��Ϣ��ʱ�������Ϊ��!!";
const char* const ERR_DETECT_ENDTIME_EMPTY = "������ݵĽ���ʱ�����ʧ��!!";
const char* const ERR_DETECT_RECORD_COUNT_WRONG = "������ݲ��뷵�������쳣!!";
const char* const ERR_SAVE_DETECT_CACHE_FILE = "������ݻ����ļ���%1���ϴ�����ʧ��!!(%2)";

// from QSerialDeviceCommandTest;
const char* const CS_SERIAL_DEVICE_RESULT = "%1����%2";
const char* const CS_SERIAL_PORT_ENUM_COUNT = "ö�ٴ��ڸ�����%1";
const char* const CS_SERIAL_DEVICE_TESTING = "%1��ʼ����...";
const char* const ERR_SERIAL_PORT_ENUM_FAILURE = "��⴮��:%1��,�����豸�Ƿ����ϵ�?";

// from QCameraFactory;
const char* const MSG_CAMERA_ENUM_COUNT = "ö�ٵ���Ч�������Ϊ��%1��";
const char* const ERR_CAMERA_CONNECTED_EMPTY = "δ�����κ��������!!";

// from QSharedMemoryImageCacheManager;
const char* const WRN_SITLL_BUSY_IMAGE_COUNT = "%1 Failed, still has busy image: %2!!";
const char* const WRN_RESET_BUSY_IMAGE = "try to free all image...";
const char* const WRN_STILL_BUSY_IMAGE_INFO = "%1 Still busy image: index(%2), CacheIndex(%3), Shown(%4), Saved(%5), DetectItems(%6), Count(%7)!!";

// from QPeiteDeviceControl;
const char* const MSG_DEVICE_KICK_OFF_INFO_POSITIVE = "�쳣ҩƿ[%1]�߳�(+)";
const char* const MSG_DEVICE_KICK_OFF_INFO_NEGATIVE = "�쳣ҩƿ[%1]�߳�(-)";
const char* const DBG_DEVICE_REPLY = "�豸�ظ�ִ��: %1";
// from QPuliDeviceControl;
const char* const ERR_DEVICE_CAPPING_FAILURE = "֪ͨҩƿ�����쳣";

// from QBottleGapMonoBackgroundAlgorithm;
const char* const ERR_IMAGE_PREROI_EMPTY = "Ŀ��ƿ��ROI(ǰ��)λ��Ϊ��!!";

// from Debugger View;
const char* const CS_DEBUGGER_COLUMN_TITLE = "������";
const char* const CS_DEBUGGER_VIEW_TITLE = "%1 > ������";

// from Simulator Param Context;
const char* const CS_SIMULATOR_ELAPSED_NAME = "��ʱ����";
const char* const CS_SIMULATOR_PARAM_NAME = "�㷨����";

// from Simulator Elapsed Context;
const char* const CS_SIMULATOR_ELAPSED_COLUMN_NAME = "ƿ���б� M%1I%2";

// from Simulator Elapsed Column;
const char* const CS_SIMULATOR_ENABLE_NAME = "ʹ��";
const char* const CS_SIMULATOR_DELAYTIME_NAME = "ִ��ʱ��";

//from select work mode //add 20200923
const char* const CS_SELECT_WORK_MODE_CAPTION = "����ģʽѡ��";
const char* const CS_WORK_MODE_NAME[] = {
	"�㷨����",
	"�˹�����"
};  

//from review defect widget// add20210111
const char* const CS_DEFECT_REVIEW_CAPTION = "���ϸ�Ʒ�ؿ�";
const char* const CS_DEFECT_REVIEW_LIST = "ȱ���б�";
const char* const CS_DEFECT_REVIEW_IMAGE = "ȱ��ͼƬ";

const char* const CS_MENU_ITEM_CN_ADD = "����";
const char* const CS_MENU_ITEM_CN_CLONE = "��¡";
const char* const CS_MENU_ITEM_CN_MODIFY = "�޸�";
const char* const CS_MENU_ITEM_CN_DELETE = "ɾ��";
const char* const CS_MENU_ITEM_CN_CHECK = "���"; 


// C031_0003 project Only
const char* const CS_MAIN_CAMERA_ID_C031_0003 = "Cam.M4I1";


// C071-0001 prjoect only
const char* const CS_TRIGGER_POSITION = "TriggerPosition";
const char* const CS_DETECT_FLAG_LENGTH = "DetectFlagLength";
const char* const CS_DETECT_FLAGS = "DetectFlags";

//C061-0002
const char* const CS_UNIT_PERCENT = "(��λ���ٷֱ�)";
const char* const CS_UNIT_PIXEL = "(��λ������)";
#endif