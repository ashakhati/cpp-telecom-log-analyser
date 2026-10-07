#include "logAnalyzer.h"

void LogAnalyzer::analyze(const std::vector<LogEvent>& events)
{
    for (const auto& event : events)
    {
        if (event.eventType == EventType::HANDOVER_SUCCESS)
        {
            ++successfulHandovers_;
            ++totalHandovers_;
        }
        else if (event.eventType == EventType::HANDOVER_FAILURE)
        {
            ++failedHandovers_;
            ++totalHandovers_;
        }
    }
}

int LogAnalyzer::totalHandovers() const
{
    return totalHandovers_;
}

int LogAnalyzer::successfulHandovers() const
{
    return successfulHandovers_;
}

int LogAnalyzer::failedHandovers() const
{
    return failedHandovers_;
}
