#define APP_STATE_H
enum AppMode
{
  MODE_CLOCK,
  MODE_ALARM,
  MODE_TIMER,
  MODE_STOPWATCH
};

struct AppState
{
  AppMode currentMode;
  bool darkMode;
};




