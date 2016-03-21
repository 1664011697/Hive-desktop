#include "GlobalData.h"
#include <QPalette>


///UI
QFont GlobalData::g_font;
QColor GlobalData::g_windowColor = QColor(255,255,255);
QColor GlobalData::g_alphaTabColor = QColor(255,255,255,240);
QColor GlobalData::g_tabColor = QColor(0,0,0,0);

QColor GlobalData::g_chatBubbleColorI = QColor(255,215,126);
QColor GlobalData::g_chatBubbleColorO = QColor(225,225,225);
QColor GlobalData::g_mChatBubbleColorI = GlobalData::g_chatBubbleColorI;
QColor GlobalData::g_mChatBubbleColorO = GlobalData::g_chatBubbleColorO;

///data
UsrProfileStruct GlobalData::g_my_profile;
QMap<QString, UsrProfileStruct> GlobalData::saved_usr_profile_map;
QMap<QString, UsrProfileStruct> GlobalData::online_usr_profile_map;

///net
QString GlobalData::g_localHostIP;

QString GlobalData::g_currentTime()
{
  return QDateTime::currentDateTime().toString("yyyy_MM_dd_hh_mm_ss");
}




////////Data Standard:////////
/*
usrInfoStrList:
usrKey<<usrName<<ipAddr<<avatarPath
l
myProfile:
usrKey<<usrName<<avatarPath


*/
