#pragma once

#include <string>

enum class EventType {
    RRC_CONNECTED,
    MEASUREMENT_REPORT,
    HANDOVER_REQUEST,
    HANDOVER_SUCCESS,
    HANDOVER_FAILURE
};

struct LogEvent {
    std::string timestamp;
    int ueId;
    EventType eventType;
};
