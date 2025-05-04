#pragma once
#include "SensorInterface.h"
#include <chrono>

struct SensorTask{
    SensorInterface Interface;
    int period_ms;
    std::chrono::steady_clock::time_point last_executed;
};