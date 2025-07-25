#include "DxLib.h"
#include "../config/02_Clock.h"
#include "../config/01_GuiButton.h"
#include "../config/00_AppState.h"
#include "../config/03_Alarm.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  SetGraphMode(640, 480, 32);
  ChangeWindowMode(TRUE);
  DxLib_Init();
  SetDrawScreen(DX_SCREEN_BACK);

  AppState state = {MODE_CLOCK, true};
  Clock clock;
  Alarm alarm;
  char timeStr[16]; // "HH:MM:SS"用
  
  // GUIボタン定義
  GuiButton btnClock(10, 10, 100, 30, "Clock");
  GuiButton btnAlarm(120, 10, 100, 30, "Alarm");
  GuiButton btnTimer(230, 10, 100, 30, "Timer");
  GuiButton btnStopWatch(340, 10, 120, 30, "StopWatch");
  GuiButton btnMode(480, 10, 100, 30, "Light/Dark");
  GuiButton btnExit(590, 10, 40, 30, "X");

  // Resource/Sounds/
  int alarmSoundHandle = LoadSoundMem("alarm.wav");
  
  while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
  {
    int bgColor = state.darkMode ? GetColor(0, 0, 0) : GetColor(255, 255, 255);
    int fgColor = state.darkMode ? GetColor(255, 255, 255) : GetColor(0, 0, 0);
    int borderColor = state.darkMode ? GetColor(100, 100, 100) : GetColor(50, 50, 50);
    ClearDrawScreen();
    SetBackgroundColor(0, 0, 0);
    DrawBox(0, 0, 640, 480, bgColor, TRUE);

    
    if (state.currentMode == MODE_ALARM)
    {

      DrawAlarmMode(alarm, bgColor, borderColor);


      if (alarm.enabled && !alarm.triggered)
      {
        if (clock.hour == alarm.hour && clock.minute == alarm.minute)
        {
          alarm.triggered = true;
          PlaySoundMem(alarmSoundHandle, DX_PLAYTYPE_BACK);
        }
      }


      // Alarm解除（例：Zキー）
      if (alarm.triggered && CheckHitKey(KEY_INPUT_Z))
      {
        StopSoundMem(alarmSoundHandle);
        alarm.triggered = false;
      }
    }

    // ボタン描画
    btnClock.Draw(fgColor, bgColor, borderColor, btnClock.isClicked());
    btnAlarm.Draw(fgColor, bgColor, borderColor, btnAlarm.isClicked());
    btnTimer.Draw(fgColor, bgColor, borderColor, btnTimer.isClicked());
    btnStopWatch.Draw(fgColor, bgColor, borderColor, btnStopWatch.isClicked());
    btnMode.Draw(fgColor, bgColor, borderColor, btnMode.isClicked());
    btnExit.Draw(fgColor, bgColor, borderColor, btnExit.isClicked());

    // ボタンクリック処理
    if (btnClock.isClicked())
      state.currentMode = MODE_CLOCK;
    if (btnAlarm.isClicked())
      state.currentMode = MODE_ALARM;
    if (btnTimer.isClicked())
      state.currentMode = MODE_TIMER;
    if (btnStopWatch.isClicked())
      state.currentMode = MODE_STOPWATCH;
    if (btnMode.isClicked())
      state.darkMode = !state.darkMode;
    if (btnExit.isClicked())
      break;

    // 現在のモード表示
    switch (state.currentMode)
    {
    case MODE_CLOCK:
      clock.Update();
      clock.GetTimeString(timeStr, sizeof(timeStr));
      DrawString(280, 240, timeStr, fgColor);
      break;
    case MODE_ALARM:
      DrawString(280, 240, "Alarm Mode", fgColor);
      break;
    case MODE_TIMER:
      DrawString(280, 240, "Timer Mode", fgColor);
      break;
    case MODE_STOPWATCH:
      DrawString(280, 240, "Stopwatch Mode", fgColor);

      break;
    }
    clock.GetTimeString(timeStr, sizeof(timeStr));

    ScreenFlip();
    WaitTimer(100);
  }

  DxLib_End();
  return 0;
}
