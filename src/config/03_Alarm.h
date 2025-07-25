struct Alarm
{
    mutable int hour = 7;
    mutable int minute = 0;
    mutable bool enabled = false;
    bool triggered = false;
};

void DrawAlarmMode(Alarm& alarm, int bgColor, int borderColor);