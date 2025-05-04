#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <chrono>
#include <ctime>

struct FaultEntry {
    std::string fault_id;
    std::string description;
    std::string timestamp;
    std::string severity;
};

class BITELogger {
private:
    std::vector<FaultEntry> fault_log;

    BITELogger() {}  // Private constructor
    BITELogger(const BITELogger&) = delete;
    BITELogger& operator=(const BITELogger&) = delete;

public:
    static BITELogger& get_instance() {
        static BITELogger instance;
        return instance;
    }

    void log_fault(const std::string& id, const std::string& desc, const std::string& severity = "Major") {
        auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        FaultEntry entry{id, desc, std::ctime(&now), severity};
        fault_log.push_back(entry);
    }

    void show_log() const {
        std::cout << "\n[BITE LOG START]\n";
        for (const auto& f : fault_log) {
            std::cout << f.timestamp << " | " << f.fault_id << " | " << f.description << " | " << f.severity << "\n";
        }
        std::cout << "[BITE LOG END]\n";
    }
};
