#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include"LogEvent.h"
#include"logAnalyzer.h"


std::string eventTypeToString(EventType type)
{
    switch (type) {
        case EventType::HANDOVER_SUCCESS:
            return "HANDOVER_SUCCESS";

        case EventType::HANDOVER_FAILURE:
            return "HANDOVER_FAILURE";
    }

    return "UNKNOWN";
}
int main()
{
    std::vector<LogEvent> events;	
    std::ifstream file ("data/network.log");
    if (!file)
    {
        std::cerr << "Unable to open file network.log";
        return 1; // Return with error code                 
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string timestampPart, ueIdPart, eventTypePart;
        iss>> timestampPart >> ueIdPart >> eventTypePart;

        int ueID = std::stoi(ueIdPart.substr(3)); 
        std::string eventString = eventTypePart.substr(6);
	EventType eventType;
	  if (eventString == "HANDOVER_SUCCESS") {
            eventType = EventType::HANDOVER_SUCCESS;
        }
        else if (eventString == "HANDOVER_FAILURE") {
            eventType = EventType::HANDOVER_FAILURE;
        }
        else {
            continue;
        }

	LogEvent event{timestampPart, ueID, eventType};
	events.push_back(event);
       
    } 

    LogAnalyzer analyzer;

    analyzer.analyze(events);

    // Display statistics
    std::cout << "\nHandover Statistics\n";
    std::cout << "-------------------\n";

    std::cout << "Total handovers : "
              << analyzer.totalHandovers() << '\n';

    std::cout << "Successful      : "
              << analyzer.successfulHandovers() << '\n';

    std::cout << "Failed          : "
              << analyzer.failedHandovers() << '\n';

    return 0; // Return with success code
}
