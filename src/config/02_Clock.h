
#define CLOCK_H

class Clock
{
public:
    Clock();
    void Update();
    void GetTimeString(char* buffer, int bufSize) const;
    void GetTimeString(char* buffer, int* bufSize);

public:
    int hour;
    int minute;
    int second;

    void FormatTwoDigits(int value, char* buffer) const;
};


