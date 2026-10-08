#include "logAnalyzer.h"
#include <iostream>

void LogAnalyzer::analyze(const std::vector<LogEvent>& events)
{
    for (const auto& event : events)
    {
	auto& stats = ueStats[event.ueId];
	++stats.total;
        if (event.eventType == EventType::HANDOVER_SUCCESS)
        {
            ++successfulHandovers_;
            ++totalHandovers_;
	    ++stats.successful;
        }
        else if (event.eventType == EventType::HANDOVER_FAILURE)
        {
            ++failedHandovers_;
            ++totalHandovers_;
	    ++stats.failed;
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

void LogAnalyzer::printUEStats() const
{
    for (const auto& [ueId, stats] : ueStats)
    {
        std::cout << "UE " << ueId
                  << " total=" << stats.total
                  << " success=" << stats.successful
                  << " failed=" << stats.failed
                  << '\n';
    }
}
