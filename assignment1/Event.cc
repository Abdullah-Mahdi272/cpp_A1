
#include "Event.h"

Event::Event(const std::string& title, const std::string& description, int startTime, int duration){
    this->title = title;
    this-> description = description;
    this-> startTime = startTime;
    this-> duration = duration;

}
bool Event::lessThan(Event& e){
    return (startTime<e.startTime);
}

bool Event::equals(Event& e){
    return (title == e.title);
}
bool Event::conflictsWith(Event& e){
    int endTime1 = startTime + duration;
    int endTime2 = e.startTime + e.duration;

    if (startTime >= e.startTime && startTime < endTime2) {
        return true;
    } else if (e.startTime >= startTime && e.startTime < endTime1) {
        return true;
    }

    return false;
}
void Event::print(){

    std::cout.width(10);std::cout << std::left <<"Title: "<< title << std::endl;
    std::cout.width(10);std::cout << std::left <<"Description: "<< description << std::endl;
    std::cout.width(10);std::cout << std::left <<"Start time: "<< startTime << std::endl;
    std::cout.width(10);std::cout << std::left <<"Duration: "<< duration << std::endl;

}
