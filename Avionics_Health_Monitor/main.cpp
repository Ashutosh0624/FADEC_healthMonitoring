#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#include "SensorInterface.h"
#include "TaskScheduler.h"
#include "BITELogger.h"
#include "SensorTypes.h"  // <-- this file contains all sensor structs and function definitions

using namespace std;

int main() {
    // ✅ Step 1: Create Sensor Objects
    EGTSensor egt;
    Altimeter alt;
    RPMSensor rpm;
    BleedValve bv;

    // ✅ Step 2: Create Task List
    std::vector<SensorTask> tasks = {
        {
            .Interface = {read_EGT, status_EGT, &egt},
            .period_ms = 1000,
            .last_executed = chrono::steady_clock::now()
        },
        {
            .Interface = {read_Altitude, status_Altitudde, &alt},
            .period_ms = 1500,
            .last_executed = chrono::steady_clock::now()
        },
        {
            .Interface = {read_rpm, status_rpm, &rpm},
            .period_ms = 1200,
            .last_executed = chrono::steady_clock::now()
        },
        {
            .Interface = {read_BleedValve, status_bleedValve, &bv},
            .period_ms = 1800,
            .last_executed = chrono::steady_clock::now()
        }
    };

    cout << "\n[Avionics Health Monitor RTOS Scheduler Started]\n" << endl;

    // ✅ Step 3: Main Loop (RTOS-style)
    while (true) {
        auto now = chrono::steady_clock::now();

        for (auto& task : tasks) {
            auto elapsed = chrono::duration_cast<chrono::milliseconds>(now - task.last_executed).count();
            if (elapsed >= task.period_ms) {
                // Read sensor
                cout << task.Interface.read(task.Interface.self) << endl;

                // Check sensor status
                string status = task.Interface.status(task.Interface.self);
                cout << status << endl;

                // Log to BITE if fault detected
                if (status.find("FAULT") != string::npos) {
                    BITELogger::get_instance().log_fault("0x999", status);  // placeholder fault ID
                }

                task.last_executed = now;
                cout << "---------------------------" << endl;
            }
        }

        // Sleep for 100ms (simulate task tick)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
