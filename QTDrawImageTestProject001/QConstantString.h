#ifndef _QCONSTANTSTRING_H_
#define _QCONSTANTSTRING_H_

#pragma once

#pragma execution_character_set("utf-8")

// command name;
const char* const BTN_COMFIRM_NAME = "确认";
const char* const BTN_APPLY_NAME = "应用";
const char* const BTN_CLOSE_NAME = "关闭";
const char* const BTN_CANCEL_NAME = "取消";
const char* const BTN_ADD_NAME = "+";
const char* const BTN_REBOOT_APP_NAME = "重新登录";
const char* const BTN_REBOOT_OS_NAME = "重 启";
const char* const BTN_SHUTDOWN_OS_NAME = "关 机";
const char* const BTN_START_NAME = "开始";
const char* const BTN_LAUNCH_NAME = "启 动";
const char* const BTN_STOP_NAME = "停止";

const char* const CS_SUCCEED_EN_NAME = "Succeed";
const char* const CS_FAILURE_EN_NAME = "Failure";
const char* const CS_SUCCEED_CHS_NAME = "成功";
const char* const CS_FAILURE_CHS_NAME = "失败";

// from QFactory
const char* const ERR_FACTORY_DEVICE_CONTROL_NULL = "【设备控制器】尚未创建!!";
const char* const ERR_FACTORY_CAMERA_CONTROL_NULL = "【相机控制器】尚未创建!!";
const char* const ERR_FACTORY_DEVICE_UPDATE_PARAM = "【设备控制器】更新参数失败!!";
const char* const ERR_FACTORY_CAMERA_UPDATE_PARAM = "【相机控制器】更新参数失败!!";
const char* const ERR_FACTORY_DEVICE_BEGIN_FAILURE = "【设备控制器】启动失败!!";
const char* const ERR_FACTORY_CAMERA_BEGIN_FAILURE = "【相机控制器】启动失败!!";
const char* const ERR_CAMERA_CONTROL_CREATE_FAILURE = "【相机控制器】创建失败!!";
const char* const CS_CAMERA_CONTROL_CHS_NAME = "相机处理器";
const char* const ERR_CAMERA_CONTROL_CAM_NOT_FOUND = "未检测出可用相机，请检查相机连接是否正常?!";
const char* const ERR_CAMERA_CONTROL_CAM_NOT_MATCH = "相机连接个数与设定值不匹配!!";
const char* const ERR_FACTORY_WORK_MODE_CONTROL_NULL = "【工作模式控制器】尚未创建!!";
const char* const ERR_FACTORY_WORK_MODE_UPDATE_PARAM = "【工作模式控制器】更新参数失败!!";
const char* const ERR_FACTORY_WORK_MODE_BEGIN_FAILURE = "【工作模式控制器】启动失败!!";

// from Login;
const char* const ERR_ACCOUNT_CHECK_EMPTY = "账户名为空!!";
const char* const ERR_PASSWORD_CHECK_EMPTY = "密码为空!!";
const char* const ERR_ACCOUNT_LOGIN_FAILURE = "登录失败，请确认后重新尝试..";
const char* const ACT_ACCOUNT_LOGIN_SUCCEED = "登录成功!";
const char* const MSG_LOAD_PARAM_SUCCEED = "系统加载参数成功";
const char* const MSG_LOAD_PARAM_FAILURE = "系统加载参数失败";

const char* const CS_LOGIN_ACCOUNT_NAME = "账户";
const char* const CS_LOGIN_ACCOUNT_PASSWORD = "密码";
const char* const BTN_LOGIN_NAME = "登 录";

const char* const MSG_INIT_MODULE = ">> 初始化 ";

const char* const MSG_LOGIN_AND_WAIT = "登录成功, 请耐心等待程式初始化...";

// from QMainForm;
const char* const MSG_APP_START_NAME = "------------ App Start ------------";
const char* const MSG_APP_END_NAME = "------------ App End   ------------";

const char* const PRODUCT_DETECT = "产品检测";
const char* const PRODUCT_SETTING = "产品设置";
const char* const DETECT_SETTING = "检测设置";
const char* const SYSTEM_SETTING = "系统设置";

const char* const ACT_SWITCH_TO_PRODUCT_DETECT = "切换至产品检测页";
const char* const ACT_SWITCH_TO_PRODUCT_SETTING = "切换至产品设置页";
const char* const ACT_SWITCH_TO_DETECT_SETTING = "切换至检测设置页";
const char* const ACT_SWITCH_TO_SYSTEM_SETTING = "切换至系统设置页";
const char* const MSG_SWITCH_TO_PRODUCT_DETECT = "系统自动切换至产品检测页";
const char* const ACT_SWITCH_TO_DEFECT_REVIEW = "切换至缺陷回看页";

const char* const ACT_CLOSE_MAIN_FORM = "关闭软件";
const char* const ACT_REBOOT_APP = "重启软件";
const char* const ACT_REBOOT_SYSTEM = "重启系统";
const char* const ACT_SHUTDOWN_SYSTEM = "关闭系统";

const char* const ASK_MAIN_CLOSE_CAPTION = "系统关闭确认";
const char* const ASK_MAIN_CLOSE_CONFIRM = "确定要关闭检测系统吗?";

// from QDetectDetailWidget;
const char* const CS_DETECT_DETAIL_CAPTION = "不合格产品明细列表";

const char* const TABLE_DEFECT_ITEM_NAME[] =
{
	"瓶数",
	"相机",
	"检测",
	"时间"
};

// from QDetectModeWidget;
const char* const CS_DETECT_MODE_SWITCH_TO = "切换到: %1";
const char* const CS_DETECT_MODE_CAPTION = "模式: ";
const char* const CS_DETECT_VIEW_CAPTION = "视图: ";
const char* const CS_DETECT_CURRENT_MODE_CAPTION = "当前模式: %1";
const char* const CS_DETECT_CURRENT_VIEW_CAPTION = "当前视图: %1";

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
	"检测缓存视图",
	"性能监控视图",
};

// from QDetectStatisticsWidet;
const char* const CS_DETECT_STATISTICS_CAPTION = "产品检测统计";
const char* const CS_DETECT_TOTAL_CAPTION = "检测总数量：";
const char* const CS_DETECT_FAILURE_RATIO_CAPTION = "报 废 率：";
const char* const CS_DETECT_STANDARD_COUNT_CAPTION = "合格品";
const char* const CS_DETECT_FAILURE_COUNT_CAPTION = "空瓶 / 不合格";
const char* const CS_DETECT_FAILURE_COUNT_CAPTION_ = "不合格";
const char* const CS_DETECT_FLOW_SPEED_CAPTION = "瓶子流速";

const char* const CS_DETECT_DEFECT_TYPE_STATISTICS = "缺陷类别统计";
const char* const CS_DETECT_PRODUCT_FAILURE_COUNT = "不合格产品数";
const char* const CS_DETECT_DEFECT_COUNT_TOTAL = "检测缺陷总数";
const char* const TABLE_FAILURE_COUNT_ITEM_NAME[] =
{
	"缺陷类别",
	"缺陷个数",
	"缺陷比例"
};
// from QDeviceStatusWidget;
const char* const CS_DEVICE_STATUS_CAPTION = "设备状态";

// from QOperatorInfoWidget;
const char* const CS_OPERATOR_NAME_CAPTION = "操作员 :";
const char* const CS_OPERATOR_LOGIN_TIME_CAPTION = "登入时间 :";
const char* const CS_DETECT_TIME_CAPTION = "检测时间 :";

// from QProductInfoWidget;
const char* const CS_PRODUCT_INFO_CAPTION = "产品信息";
const char* const CS_BATCH_NUMBER_CAPTION = "生产批号";
const char* const CS_PRODUCT_INFO_NAME_CAPTION = "产品名称";
const char* const CS_PRODUCT_INFO_SPECIFICATION_CAPTION = "产品规格";
const char* const CS_PRODUCT_INFO_PATTERN_CAPTION = "检测规则";

const char* const ACT_PRODUCT_NAME_SELECT_EMPTY = "选择产品名称为: 空";
const char* const ACT_PRODUCT_NAME_SELECT = "选择产品为: %1 - %2";
const char* const ACT_PRODUCT_BATCH_INPUT = "输入产品批次为: %1";

// from QMainControlWidget;
const char* const CS_MAIN_CONTROL_CAPTION = "系统操作";
const char* const WRN_LICENSE_STOP_FAILURE = "侦测到软件尚未授权, 系统自动结束检测, 如需使用请与开发商联系.";
const char* const WRN_LICENSE_FAILURE = "尚未授权, 检测功能失效";
const char* const WRN_LICENSE_SUCCEED = "授权成功, 检测功能启用";

const char* const WRN_CHANGE_PRODUCT_STOP_FAILURE = "侦测到修改产品信息, 系统自动结束检测.";


const char* const ACT_DATA_RESET = "计数清零";
const char* const ACT_LAUNCH_STARTING = "启动检测..";
const char* const MSG_LAUNCH_STARTED = "启动检测成功";
const char* const MSG_LAUNCH_START_FAILURE = "检测启动失败";
const char* const ACT_LAUNCH_ENDING = "停止检测..";
const char* const MSG_LAUNCH_ENDED = "停止检测成功";

const char* const ACT_SHOW_EXPAND_VIEW[] =
{
	"",
	"操作记录视图",
	"生产记录视图",
	"性能参数监视"
};


const char* const BTN_UNAUTHORIZED_NAME = "授 权\r\n\r\n\r\n拒 绝";
const char* const BTN_RESET_DATA_NAME = "计数清零";
const char* const BTN_RESERVED_NAME = "保 留";
const char* const BTN_PRODUCE_BILL_NAME = "生产记录";
const char* const BTN_SYSTEM_LOG_NAME = "操作记录";
const char* const BTN_RESET_NAME = "复 位";

const char* const ASK_DATE_RESET_COMFIRM = "确认要统计数据清零处理吗?";

// from ProduceBillWidget;
const char* const ACT_PRODUCE_QUERY = "开始查询生产记录: %1@%2[%3 - %4]";
const char* const ACT_PRODUCE_REPORT = "开始对查询生产记录生成报告..";
const char* const ACT_IMAGE_UPLOAD = "开始对不合格图像进行上传..";
const char* const WRN_PRODUCE_QUERY_FAILURE = "查找查询失败!!";
const char* const MSG_PRODUCE_BILL_COUNT = " %1 条记录符合条件";
const char* const WRN_PRODUCE_REPORT_BATCH_NEED = "只能根据产品批次生成报告!!";
const char* const WRN_PRODUCE_REPORT_DATA_NEED = "查询数据数量为0, 请先查询数据后再生成报告!!";
const char* const MSG_REPORT_SAVE_DIALOG_NAME = "请选择保存报告的路径";
const char* const WRN_REPORT_SAVE_RESULT_SUCCEED = "生产记录报告保存成功,路径为:%1";
const char* const ERR_REPORT_SAVE_RESULT_FAILURE = "生产记录报告保存失败!!";
const char* const WRN_IMAGE_UPLOAD_SUCCEED = "上传不合格图像完成";
const char* const ERR_IMAGE_UPLOAD_CANCEL = "取消上传不合格图像";

// from QMvCamera;
const char* const ERR_CAMERA_NOT_FOUND = "相机不存在!!";
const char* const ERR_CAMERA_INSTANCE_FAILURE = "相机建立失败!!";
const char* const ERR_CAMERA_OPEN_FAILURE = "相机连接失败!!";
const char* const ERR_CAMERA_INITIALIZE_FAILURE = "相机初始化失败!!";
const char* const ERR_CAMERA_GRAB_FAILURE = "相机采集失败!!";
const char* const ERR_CAMERA_REG_EXCEP_FAILURE = "相机注册异常回调失败!!";
const char* const ERR_CAMERA_RECONNECTING = "相机丢失，尝试连接中!!";
const char* const ERR_CAMERA_RECONNECT_FAILURE = "相机连接异常，请检查相机!!";

// from Account View;
const char* const CS_ACCOUNT_CAPTION = "账户：";
const char* const CS_ACCOUNT_PASSWORD_CAPTION = "密码：";
const char* const CS_ACCOUNT_PASSWORD_CONFIRM_CAPTION = "确认密码: ";
const char* const CS_ACCOUNT_GROUP_CAPTION = "账户组: ";

const char* const CS_ACCOUNT_TABLE_TITLE = "账户";
const char* const CS_ACCOUNT_TABLE_COLUMN_USER = "用户名";
const char* const CS_ACCOUNT_TABLE_COLUMN_GROUP = "群组";

const char* const ASK_DELETE_ACCOUNT_TITLE = "删除账户";
const char* const ASK_DELETE_ACCOUNT_COMFIRM = "确定要删除【%1】账户吗?";

const char* const ERR_ACCOUNT_NAME_EMPTY = "账户名不能为空!!";
const char* const ERR_ACCOUNT_PASSWORD_EMPTY = "密码不能为空!!";
//add by ChenLin 20200821
const char* const ERR_ACCOUNT_NAME_NOT_CONFORM = "账户名不符合规则，限定3位数字、字母、下划线!!";
const char* const ERR_ACCOUNT_PASSWORD_NOT_CONFORM = "密码不符合规则，限定6位数字、字母、下划线!!";
//add end 20200821
const char* const ERR_ACCOUNT_PASSWORD_CONFIRM = "确认密码不正确!!";
const char* const ERR_ACCOUNT_GROUP_EMPTY = "请选择账户组!!";
const char* const ERR_ACCOUNT_NAME_EXIST = "账户已存在!!";
const char* const ERR_ACCOUNT_ADD_FAILURE = "保存新账户失败!!";
const char* const ERR_ACCOUNT_MODIFY_FAILURE = "修改账户失败!!";

//20210204
const char* const CS_DETECT_RULE_TABLE_TITLE = "检测规则";
const char* const CS_DETECT_RULE_TABLE_COLUMN_NAME = "规则名称";
const char* const ASK_DELETE_DETECT_RULE_ERROR_1 = "不可删除【%1】，它已经被产品【%2】关联。";
const char* const ASK_DELETE_DETECT_RULE_TITLE = "删除检测规则";
const char* const ASK_DELETE_DETECT_RULE_COMFIRM = "确定要删除【%1】检测规则吗?";

//20210902
const char* const CS_DETECT_RULE_DOSE_UP_LIMIT = "装量上限";
const char* const CS_DETECT_RULE_DOSE_DOWN_LIMIT = "装量下限";

//const char* const CS_DETECT_VIAL_CAP = "检测瓶盖缺陷：";
//const char* const CS_DETECT_VIAL_BODY = "检测瓶盖缺陷：";
//const char* const CS_DETECT_VIAL_BOTTOM = "检测瓶盖缺陷："; 
const char* const CS_DETECT_VIAL_PATTERN_CAP_CN[]{
	"检测胶塞高度",
	"检测瓶盖缺陷：",
	"检测瓶身缺陷：",
	"检测瓶底缺陷：",
	"检测装量缺陷",
	"检测盖色缺陷"
	,"检测BFS瓶身上半"
	,"检测BFS瓶身下半"
	,"检测BFS瓶身顶部"
	,"检测BFS瓶身底部"
	,"检测瓶盖缺陷："
	,"检测瓶身2缺陷："
	,"检测瓶身1缺陷："
	,"检测瓶底缺陷："
	,"检测BFS瓶身上半"
	,"检测BFS瓶身下半"
	,"检测BFS瓶身顶部"
	,"检测BFS瓶身底部"
	,"检测输液袋-光背景"
	,"检测BFS瓶身上半"
	,"检测BFS瓶身下半"
	,"检测BFS瓶身顶部"
	,"检测BFS瓶身底部"
};
const char* const NEW_CAPTION = "新增检测规程 - MBDD";
const char* const MODIFY_CAPTION = "修改检测规则 - MBDD";
const char* const ERR_DETECT_RULE_NAME_EMPTY = "规则名称不能为空!!";
const char* const ERR_DETECT_RULE_NAME_NOT_CONFORM = "规则名称长度需大于3且小于30!!";
const char* const ERR_DETECT_RULE_NAME_THE_SAME = "规则名称重复!!";
const char* const ERR_DETECT_RULE_DOSE_LIMIT_NOT_CONFORM = "装量只能设置整数，且不超过";
const char* const ERR_DETECT_RULE_DOSE_LIMIT_UP_LESS_DOWN = "装量像素单位时，上限不能超过下限！";
const char* const ERR_DETECT_RULE_DOSE_LIMIT_DOWN_MORE_UP = "装量百分比单位时，下限不能超过上限！";
const char* const ERR_DETECT_RULE_ADD_FAILURE = "保存新检测规则数据库执行失败!!";
const char* const ERR_DETECT_RULE_MODIFY_FAILURE = "修改检测规则数据库执行失败!!";
// from Camera View;
const char* const CS_CAMERA_VIEW_TITLE = "%1 > 相机";

// from Detect View;
const char* const CS_DETECT_VIEW_NAME = "检测";
const char* const CS_DETECT_VIEW_PROMPT = "区域与阀值";
const char* const CS_DETECT_CONTEXT_TITLE = "检测参数";

// from Device View;
const char* const CS_DEVICE_VIEW_TITLE = "%1 > 设备";
const char* const CS_DEVICE_CONTEXT_TITLE = "%1 - Com%2";

// from Product View;
const char* const CS_PRODUCT_BATCH_CAPTION = "产品批次: ";
const char* const CS_PRODUCT_NAME_CAPTION = "*产品名称: ";
const char* const CS_PRODUCT_SPECIFICATION_CAPTION = "*产品规格: ";
const char* const CS_PRODUCT_FORMULA_CAPTION = " 产品配方: ";
const char* const CS_PRODUCT_DETECT_SOLUTION_CAPTION = "*检测方案: ";

const char* const ERR_PRODUCT_BATCH_EMPTY = "产品批次为空!!";
const char* const ERR_PRODUCT_NAME_EMPTY = "产品名称为空!!";
const char* const ERR_PRODUCT_NAME_LENGTH = "产品名称长度超出限制!!";
const char* const ERR_PRODUCT_SPECIFICATION_EMPTY = "产品规格为空!!";
const char* const ERR_PRODUCT_FORMULA_EMPTY = "产品配方为空!!";
const char* const ERR_PRODUCT_BATCH_EXIST = "产品批次已存在!!";
const char* const ERR_PRODUCT_EXIST = "产品已存在!!";
const char* const ERR_ATTACH_DETECT_SOLUTION_FAILURE = "连接检测方案失败!!";
const char* const ERR_PRODUCT_ADD_FAILRE = "保存新产品失败!!";
const char* const ERR_PRODUCT_ADD_NAME_EXIST = "产品名称已存在!!";

const char* const CS_PRODUCT_TABLE_TITLE = "产品列表";
const char* const CS_PRODUCT_TABLE_COLUMN_BATCH = "批次号";
const char* const CS_PRODUCT_TABLE_COLUMN_DESCRIPTION = "说明";
const char* const CS_PRODUCT_TABLE_COLUMN_NAME = "名称";
const char* const CS_PRODUCT_TABLE_COLUMN_SPECIFICATION = "规格";
const char* const CS_PRODUCT_TABLE_COLUMN_BUILDTIME = "创建时间";

const char* const ASK_DELETE_PRODUCT_TITLE = "删除产品";
const char* const ASK_DELETE_PRODUCT_COMFIRM = "确定要删除【%1】产品吗?";

const char* const ACT_CLICK_NEW_PRODUCT = "点击添加新产品..";
const char* const ACT_CANCEL_NEW_PRODUCT = "取消添加新产品";
const char* const ACT_CONFIRM_NEW_PRODUCT = "新产品添加成功：%1";

const char* const ACT_CLICK_MODIFY_PRODUCT = "点击修改产品..";
const char* const MSG_MODIFY_PRODUCT_ENABLE = "修改产品使能开启，用户现在可以修改第【%1】项产品信息了";
const char* const MSG_MODIFY_PRODUCT_DISENABLE = "修改产品使能关闭";

// from Product Param SubContext;
const char* const ACT_CANCEL_MODIFY_PRODUCT = "取消修改产品信息";
const char* const ACT_CONFIRM_MODIFY_PRODUCT = "确认修改【%1】产品信息";

// from Bottle Count Column;
const char* const CS_BOTTLE_COUNT_DIRECTION = "入瓶方向";
const char* const CS_BOTTLE_COUNT_ROT_LEFT = "左边界";
const char* const CS_BOTTLE_COUNT_ROT_TOP = "上边界";
const char* const CS_BOTTLE_COUNT_ROT_WIDTH = "区域宽度";
const char* const CS_BOTTLE_COUNT_ROT_HEIGHT = "区域高度";
const char* const CS_BOTTLE_COUNT_THRESHOLD_NAME = "灰度阀值";
const char* const CS_BOTTLE_COUNT_ACCEPTANCE_CRITERIA_NAME = "触发标准";

// from Bottle Gap Column;
const char* const CS_VIAL_PLUG_GAP_CONTEXT_TITLE = "瓶塞缝隙等级";

// from Vial detect rule Column;  //add by chenlin 20210202
const char* const CS_VIAL_DETECT_RULE_TITLE = "检测规则";

// from Camera Inherence Column;
const char* const CS_CAMERA_NAME = "名称";
const char* const CS_CAMERA_INTERFACE_NAME = "接口";
const char* const CS_CAMERA_RESOLUTION_NAME = "分辨率";
const char* const CS_CAMERA_PIXEL_TYPE_NAME = "像素格式";

// from Camera Solution Column;
const char* const CS_CAMERA_WIDTH_NAME = "图像宽度";
const char* const CS_CAMERA_HEIGHT_NAME = "图像高度";
const char* const CS_CAMERA_RESOLUTION_MAX_NAME = "最大值为%1";
const char* const CS_CAMERA_OFFSET_X_NAME = "X轴偏移";
const char* const CS_CAMERA_OFFSET_Y_NAME = "Y轴偏移";
const char* const CS_CAMERA_EXPOSURE_NAME = "曝光时间（us）";
const char* const CS_BALANCE_AUTO_NAME = "白平衡调整";
const char* const CS_BALANCE_RATIO_R_NAME = "红色平衡值";
const char* const CS_BALANCE_RATIO_G_NAME = "绿色平衡值";
const char* const CS_BALANCE_RATIO_B_NAME = "蓝色平衡值";

const char* const CS_GAMMA_ENABLE_NAME = "伽马校正使能";
const char* const CS_GAMMA_SELECTOR_NAME = "伽马校正选择器";
const char* const CS_GAMMA_NAME = "伽马校正";

const char* const CS_AUTO_GAIN_NAME = "自动增益";
const char* const CS_GAIN_NAME = "增益（dB）";

const char* const CS_TRIGGER_MODE_NAME = "触发模式";
const char* const CS_PARAM_SWITCH_NAME[] =
{
	"关闭",
	"打开"
};
const char* const CS_TRIGGER_SOURCE_NAME = "触发源";
const char* const CS_TRIGGER_SOURCE_ITEM_NAME[] =
{
	"线路0",
	"线路1",
	"线路2",
	"线路3",
	"计数器0",
	"软触发"
};
//const char* const CS_TRIGGER_LINE0_NAME = "线路0";
//const char* const CS_TRIGGER_LINE1_NAME = "线路1";
//const char* const CS_TRIGGER_LINE2_NAME = "线路2";
//const char* const CS_TRIGGER_LINE3_NAME = "线路3";
//const char* const CS_TRIGGER_COUNTER0_NAME = "计数器0";
//const char* const CS_TRIGGER_SOFTWARE_NAME = "软触发";
const char* const CS_TRIGGER_DELAY_NAME = "触发延迟（us）";
const char* const CS_TRIGGER_ACTIVATION_NAME = "触发极性";
const char* const CS_TRIGGER_ACTIVATION_ITEM_NAME[] =
{
	"上升沿",
	"下降沿"
};
const char* const CS_REVERSE_X_NAME = "水平翻转";
const char* const CS_REVERSE_Y_NAME = "垂直翻转";

// from Detect Solution Column;
const char* const CS_CAMERA_SOLUTION_NAME = "相机方案";
const char* const CS_DEVICE_SOLUTION_NAME = "设备方案";
const char* const CS_BOTTLE_COUNT_NAME = "药瓶计数";
const char* const CS_VIAL_PLUG_GAP_NAME = "瓶塞缝隙等级";

// from Device Command Column;
const char* const CS_DEVICE_PULSE_WIDTH_NAME = "脉冲宽度";
const char* const CS_DEVICE_DELAY_TIME_NAME = "剔除延时";

//add by ChenLin 20200706
// from PCIE Device Command Column's item;
const char* const CS_SCREW_CONVEYOR_TURNS_NAME = "绞龙圈数检测";
const char* const CS_BOTTLE_REIGNING_NAME = "瓶子在位检测";
const char* const CS_KICK_OFF_STATE_NAME = "剔除状态";
const char* const CS_KICK_OFF_TRIGGER_NAME = "剔除触发";
const char* const CS_SIGNAL_DIRECTION_NAME = "信号方向";
const char* const CS_TERMINALS_CONNECT_NAME = "端子连接";
const char* const CS_TERMINALS_NUMBER_NAME = "端子号";
const char* const CS_SIGNAL_TYPES_NAME = "信号种类";
const char* const CS_SIGNAL_INPUT_NAME = "输入";
const char* const CS_SIGNAL_OUTPUT_NAME = "输出";
const char* const CS_LOW_LEVEL_NAME = "低电平"; 
const char* const CS_HIGHT_LEVEL_NAME = "高电平";
const char* const CS_FALLING_EGDE_NAME = "下降沿"; 
const char* const CS_RISING_EGDE_NAME = "上升沿";

const char* const ASK_PCIE_COMMAND_CAPTION = "PCIE指令提示";
const char* const ASK_PCIE_COMMAND_HAVE_COMFLICT = "PCIE指令与";
const char* const ASK_PCIE_COMMAND_SAME = "相同，设置无效。";
//add end



// from Product Param Column;
const char* const CS_PRODUCT_NAME_NAME = "产品名称";
const char* const CS_PRODUCT_SPECIFICATION_NAME = "产品规格";
const char* const CS_PRODUCT_FORMULA_NAME = "产品配方";
const char* const CS_PRODUCT_POWDER_COLOR_NAME = "药粉颜色";
const char* const CS_PRODUCT_CAP_COLOR_NAME = "瓶盖颜色";
const char* const CS_PRODUCT_POWDER_COLOR[] =
{
	"白色粉",
	"黄色粉"
};
const char* const CS_PRODUCT_CAP_COLOR[] =
{
	"蓝色盖",
	"紫色盖"
};


// from Serial Port Param Column;
const char* const CS_COM_PORT_NAME = "串口号";
const char* const CS_BAUD_RATE_NAME = "波特率";
const char* const CS_DATA_BITS_NAME = "数据位";
const char* const CS_PARITY_NAME = "奇偶校验";
const char* const CS_STOP_BITS_NAME = "停止位";

// from Camera Param Context;
const char* const CS_ROI_VIEW_NAME = "感应区域"; 
const char* const CS_CAMERA_INHERENCY = "特性";

// from Pcie digital io carl Column
const char* const CS_PARALLEL_DEV_NUM = "板卡号";

// from Detect Param Context;
const char* const CS_BOTTLE_COUNT_COLUMN_NAME = "药瓶计数 - 相机 M%1I%2";
const char* const CS_VIAL_PLUG_GAP_COLUMN_NAME = "瓶塞缝隙";

// from Product Param Context;
const char* const CS_PRODUCT_PARAM_NAME = "产品参数";
const char* const CS_DETECT_SOLUTION_NAME = "检测方案";

// from Serial Port Param Context;
const char* const CS_SERIAL_PORT_NAME = "串口";
const char* const CS_COMMAND_PARAM_NAME = "指命参数";
const char* const CS_PARALLEL_PORT_NAME = "并口";

// from System Form;
const char* const CS_SYSTEM_NAVIGATION_NAME = "导航栏";
const char* const CS_SYSTEM_PAGE_NAME = "系统设置";
const char* const CS_ACCOUNT_COLUMN_NAME = "账户";
const char* const CS_CAMERA_COLUMN_NAME = "相机";
const char* const CS_DEVICE_COLUMN_NAME = "设备";
const char* const CS_DETECT_COLUMN_NAME = "检测";
const char* const CS_DEBUGGER_COLUMN_NAME = "调试";
const char* const CS_SYSTEM_COLUMN_NAME = "其它";

const char* const ASK_SYSTEM_PARAM_SAVE_CAPTION = "变更参数保存提示";
const char* const ASK_SYSTEM_PARAM_SAVE_CONTENT = "系统参数已被修改, 请问是否需要保存?";

// from Product Form;
const char* const CS_PRODUCT_PAGE_NAME = "产品设置";
const char* const CS_PRODUCT_SETTING_NAME = "产品列表";

const char* const ASK_PRODUCT_PARAM_SAVE_CAPTION = "变更参数保存提示";
const char* const ASK_PRODUCT_PARAM_SAVE_CONTENT = "产品参数已被修改, 请问是否需要保存?";

// for DetectSetting Form
const char* const CS_DETECT_SETTING_PAGE_NAME = "检测设置";
const char* const CS_DETECT_RULE_LIST_NAME = "检测规则列表";
const char* const ASK_DETECT_PARAM_SAVE_CONTENT = "检测参数已被修改, 请问是否需要保存?";

// from System Param View;
const char* const CS_TIME_LOCKER_NAME = "系统时间锁定";
const char* const CS_REPORT_FORMAT_NAME = "报告输出格式";
const char* const CS_ERROR_IMAGE_SAVE_NAME = "异常图像保存";
const char* const CS_OK_IMAGE_SAVE_NAME = "合格图像保存";
const char* const CS_NG_ORIGNAL_IMAGE_SAVE_NAME = "NG原图保存";
const char* const CS_TRIGGER_IMAGE_SAVE_NAME = "触发图像保存(ROI)";
const char* const CS_TRIGGER_IMAGE_FORMAT_NAME = "触发图像保存格式";
const char* const CS_CAMERA_ORIGNAL_IMAGE_SAVE_NAME = "相机原图保存(非ROI)";
const char* const CS_SYSTEM_REBOOT_PROMPT_NAME = "设置需要在重启电脑后生效!!";
const char* const ASK_CLOSE_ERROR_IMAGE_TITLE = "关闭图像保存";
const char* const ASK_CLOSE_ERROR_IMAGE_COMFIRM = "关闭后，无法回看缺陷，确定要关闭吗?";

// from Produce Bill;
const char* const CS_PRODUCE_BILL_NAME_CAPTION = "产品名称";
const char* const CS_PRODUCE_BILL_BATCH_CAPTION = "产品批次";
const char* const CS_PRODUCE_START_TIME_CAPTION = "开始时间";
const char* const CS_PRODUCE_END_TIME_CAPTION = "结束时间";
const char* const BTN_PRODUCE_QUERY_NAME = "查 询";
const char* const BTN_PRODUCE_REPORT_NAME = "汇总报告";
const char* const BTN_PRODUCE_UPLOAD_IMAGE_NAME = "上传图片";

const char* const TABLE_PRODUCE_ITEM_NAME[] =
{
	"开始时间",
	"结束时间",
	"产品批次",
	"产品名称",
	"产口规格",
	"产品配方",
	"生产总数",
	"异常数量",
	"平均流速",
	"检测高度",
	"操作人员",
	"确认人员",	
	"工作模式",
	"设备编号",
	"检测信息"
};

// from QFileCopyDialog;
const char* const CS_FILE_COPY_DIALOG_TITLE = "文件复制";
const char* const ERR_NO_FILE_FOUND = "没有发现匹配文件!!";
const char* const CS_SELECT_U_DISK_SELECT = "选择U盘";
const char* const CS_U_DISK_PATH = "复制路径";
const char* const CS_GET_FILE_AMOUNT = "获取文件个数...";
const char* const ERR_NO_U_DISK_FOUND = "没有发现U盘!!";
const char* const MSG_COPY_FILE_RESULT[] =
{
	"复制文件完成",
	"复制文件失败!!",
	"文件不存在!!",
	"停止复制文件!!"
};

// from QLicenseAccessWidget;
const char* const CS_LICENSE_TITLE = "License";
const char* const CS_LICENSE_PROMPT = "授权检查";
const char* const CS_LICENSE_SUCCEED = "软件已授权";
const char* const CS_LICENSE_FAILURE = "尚未授权!!";

// from QDetectParam;
const char* const MSG_DETECT_DATA_SAVE_SUCCEED = "保存%1-%2生产数据成功";
const char* const ERR_DETECT_DATA_SAVE = "保存%1-%2生产数据失败!!(%3)";
const char* const ERR_DETECT_DATA_EMPTY = "检测数据的产品信息，时间或数量为空!!";
const char* const ERR_DETECT_ENDTIME_EMPTY = "检测数据的结束时间计算失败!!";
const char* const ERR_DETECT_RECORD_COUNT_WRONG = "检测数据插入返回行数异常!!";
const char* const ERR_SAVE_DETECT_CACHE_FILE = "检测数据缓存文件【%1】上传数据失败!!(%2)";

// from QSerialDeviceCommandTest;
const char* const CS_SERIAL_DEVICE_RESULT = "%1测试%2";
const char* const CS_SERIAL_PORT_ENUM_COUNT = "枚举串口个数有%1";
const char* const CS_SERIAL_DEVICE_TESTING = "%1开始测试...";
const char* const ERR_SERIAL_PORT_ENUM_FAILURE = "检测串口:%1个,请检查设备是否已上电?";

// from QCameraFactory;
const char* const MSG_CAMERA_ENUM_COUNT = "枚举到有效相机个数为：%1个";
const char* const ERR_CAMERA_CONNECTED_EMPTY = "未发现任何相机接入!!";

// from QSharedMemoryImageCacheManager;
const char* const WRN_SITLL_BUSY_IMAGE_COUNT = "%1 Failed, still has busy image: %2!!";
const char* const WRN_RESET_BUSY_IMAGE = "try to free all image...";
const char* const WRN_STILL_BUSY_IMAGE_INFO = "%1 Still busy image: index(%2), CacheIndex(%3), Shown(%4), Saved(%5), DetectItems(%6), Count(%7)!!";

// from QPeiteDeviceControl;
const char* const MSG_DEVICE_KICK_OFF_INFO_POSITIVE = "异常药瓶[%1]踢除(+)";
const char* const MSG_DEVICE_KICK_OFF_INFO_NEGATIVE = "异常药瓶[%1]踢除(-)";
const char* const DBG_DEVICE_REPLY = "设备回覆执行: %1";
// from QPuliDeviceControl;
const char* const ERR_DEVICE_CAPPING_FAILURE = "通知药瓶扎盖异常";

// from QBottleGapMonoBackgroundAlgorithm;
const char* const ERR_IMAGE_PREROI_EMPTY = "目标瓶盖ROI(前置)位置为空!!";

// from Debugger View;
const char* const CS_DEBUGGER_COLUMN_TITLE = "调试器";
const char* const CS_DEBUGGER_VIEW_TITLE = "%1 > 调试器";

// from Simulator Param Context;
const char* const CS_SIMULATOR_ELAPSED_NAME = "耗时仿真";
const char* const CS_SIMULATOR_PARAM_NAME = "算法仿真";

// from Simulator Elapsed Context;
const char* const CS_SIMULATOR_ELAPSED_COLUMN_NAME = "瓶缝判别 M%1I%2";

// from Simulator Elapsed Column;
const char* const CS_SIMULATOR_ENABLE_NAME = "使能";
const char* const CS_SIMULATOR_DELAYTIME_NAME = "执行时间";

//from select work mode //add 20200923
const char* const CS_SELECT_WORK_MODE_CAPTION = "工作模式选择";
const char* const CS_WORK_MODE_NAME[] = {
	"算法主导",
	"人工主导"
};  

//from review defect widget// add20210111
const char* const CS_DEFECT_REVIEW_CAPTION = "不合格品回看";
const char* const CS_DEFECT_REVIEW_LIST = "缺陷列表";
const char* const CS_DEFECT_REVIEW_IMAGE = "缺陷图片";

const char* const CS_MENU_ITEM_CN_ADD = "增加";
const char* const CS_MENU_ITEM_CN_CLONE = "克隆";
const char* const CS_MENU_ITEM_CN_MODIFY = "修改";
const char* const CS_MENU_ITEM_CN_DELETE = "删除";
const char* const CS_MENU_ITEM_CN_CHECK = "浏览"; 


// C031_0003 project Only
const char* const CS_MAIN_CAMERA_ID_C031_0003 = "Cam.M4I1";


// C071-0001 prjoect only
const char* const CS_TRIGGER_POSITION = "TriggerPosition";
const char* const CS_DETECT_FLAG_LENGTH = "DetectFlagLength";
const char* const CS_DETECT_FLAGS = "DetectFlags";

//C061-0002
const char* const CS_UNIT_PERCENT = "(单位：百分比)";
const char* const CS_UNIT_PIXEL = "(单位：像素)";
#endif