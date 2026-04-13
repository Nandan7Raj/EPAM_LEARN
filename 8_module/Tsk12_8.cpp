//
// Created by NandanRaj on 10-04-2026.
//
#include<iostream>
#include<set>
#include<string>
#include<vector>

bool scheduleEvent(std::set<int>& scheduledEvents, int startTime) {
    auto insertResult=scheduledEvents.insert(startTime);
    if (insertResult.second) {
        std::cout<<"SUCCESSFULLY scheduled the event\n";
    }
    else
        std::cout<<"This time slot is not available\n";

    return insertResult.second;
}

void displayScheduledEvents(const std::set<int>& events) {
    if (events.empty()) {
        std::cout<<"No events scheduled\n";
        return;
    }
    std::cout<<"\n-------Displaying Events-------\n";
    for (const auto& time:events) {
        std::cout<<time<<" minutes\n";
    }
    std::cout << "--------------------------------\n" << std::endl;

}

int main(int argc, char *argv[]) {
    std::set<int> myCalendar;
    std::cout << "Attempting to schedule events for the first time:\n";
    scheduleEvent(myCalendar,900);
    scheduleEvent(myCalendar,1030);
    scheduleEvent(myCalendar,1010);
    scheduleEvent(myCalendar,1200);
    scheduleEvent(myCalendar,1500);

    displayScheduledEvents(myCalendar);

    std::cout << "\nAttempting to schedule a conflicting event:\n";
    scheduleEvent(myCalendar,1010);
    displayScheduledEvents(myCalendar);

    scheduleEvent(myCalendar,1300);
    displayScheduledEvents(myCalendar);

    std::cout << "\nAttempting to schedule a batch of events (some new, some duplicates):\n";

    std::vector<int> newEventTimes = {800, 1400, 1600, 900, 1800}; // 1400 and 900 are duplicates
    for (int time : newEventTimes) {
        scheduleEvent(myCalendar, time);
    }
    displayScheduledEvents(myCalendar);
}
