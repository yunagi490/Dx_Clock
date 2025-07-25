#include "DxLib.h"

#include "03_Alarm.h"

void DrawAlarmMode(Alarm &alarm, int bgColor, int borderColor)
{
  DrawFormatString(100, 100, GetColor(255, 255, 255),
                   "Alarm Time: %02d:%02d", alarm.hour, alarm.minute);

  DrawFormatString(100, 140, alarm.enabled ? GetColor(0, 255, 0) : GetColor(255, 0, 0),
                   "Status: %s", alarm.enabled ? "ON" : "OFF");

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