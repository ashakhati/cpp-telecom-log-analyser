#pragma once

#include "LogEvent.h"
#include <vector>

class LogAnalyzer
{
public:
    void analyze(const std::vector<LogEvent>& events);

    int totalHandovers() const;
    int successfulHandovers() const;
    int failedHandovers() const;

private:
    int totalHandovers_ = 0;
    int successfulHandovers_ = 0;
    int failedHandovers_ = 0;
};
