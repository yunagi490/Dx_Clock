// Clock.cpp
#define _CRT_SECURE_NO_WARNINGS
#include "02_Clock.h"
#include <ctime>
#include <cstdio>
#include <cstring>



Clock::Clock() {
    hour = minute = second = 0;
    Update();
}

void Clock::Update() {
    time_t now = time(nullptr);
    struct tm* ltm = localtime(&now);

    if (ltm) {
        hour = ltm->tm_hour;
        minute = ltm->tm_min;
        second = ltm->tm_sec;
    }
}

void Clock::GetTimeString(char* buffer, int bufSize) const {
    if (!buffer || bufSize < 9) return; // "HH:MM:SS" = 8文字 + null

    snprintf(buffer, bufSize, "%02d:%02d:%02d", hour, minute, second);
}
