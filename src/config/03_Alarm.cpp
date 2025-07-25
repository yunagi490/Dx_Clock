#define _CRT_SECURE_NO_WARNINGS
#include "DxLib.h"
#include "03_Alarm.h"

void DrawAlarmMode(Alarm &alarm, int bgColor, int borderColor)
{
  char buffer[64];

  // 表示するテキスト
  sprintf(buffer, "Alarm Time: %02d:%02d", alarm.hour, alarm.minute);
  int textWidth = GetDrawStringWidth(buffer, strlen(buffer));
  DrawString((640 - textWidth) / 2, 150, buffer, GetColor(255, 255, 255));

  sprintf(buffer, "Status: %s", alarm.enabled ? "ON" : "OFF");
  textWidth = GetDrawStringWidth(buffer, strlen(buffer));
  DrawString((640 - textWidth) / 2, 190, buffer, alarm.enabled ? GetColor(0, 255, 0) : GetColor(255, 0, 0));

  // ボタンやキー入力で変更
  if (CheckHitKey(KEY_INPUT_LEFT))
    alarm.hour = (alarm.hour + 23) % 24;
  if (CheckHitKey(KEY_INPUT_RIGHT))
    alarm.hour = (alarm.hour + 1) % 24;
  if (CheckHitKey(KEY_INPUT_UP))
    alarm.minute = (alarm.minute + 59) % 60;
  if (CheckHitKey(KEY_INPUT_DOWN))
    alarm.minute = (alarm.minute + 1) % 60;

  if (CheckHitKey(KEY_INPUT_RETURN))
    alarm.enabled = !alarm.enabled;
}