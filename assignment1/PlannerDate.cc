#include "PlannerDate.h"
#include "Event.h"

PlannerDate::PlannerDate(Date d){

    date = d;
    sizeEvent = 0;
}


PlannerDate::~PlannerDate(){
    for (int i = 0; i < sizeEvent; ++i){
        delete eArray[i];
    }
}

bool PlannerDate::equals(PlannerDate &pd){
    return this->date.equals(pd.date);
}

bool PlannerDate::equals(Date &d){
    return this->date.equals(d);
}

bool PlannerDate::lessThan(PlannerDate &pd){
    return this->date.lessThan(pd.date);
}

bool PlannerDate::lessThan(Date &d){
    return this->date.lessThan(d);
}

bool PlannerDate::addEvent(const string& title,const string& description, int startTime, int duration){
    if (sizeEvent >= MAX_ARRAY) return false;

    Event* event = new Event(title, description, startTime, duration);

    int index = 0;

    while (index < sizeEvent){
        if(event->lessThan(*eArray[index])){
            break;
        }
        ++index;
    }

//    for (int i = sizeEvent; i > index; --i){
//        event[i] = event[i-1];
//    }

    for (int i = sizeEvent; i > index; --i){
        eArray[i] = eArray[i-1];
    }

    eArray[index] = event;

    ++ sizeEvent;

    return true;
}

bool PlannerDate::hasEvent(const std::string& title){
    Event e = Event(title, "",0,0);
    for(int i=0;i<sizeEvent;i++){
        if(eArray[i]->equals(e)){
            return true;
        }
    }
    return false;
}
bool PlannerDate::hasConflict(){
    for(int i=0;i<sizeEvent;i++){
        for(int j=0;j<sizeEvent;j++){
            if(eArray[i]->conflictsWith(*eArray[j])){
                return true;
            }
        }
    }
    return false;
}

void PlannerDate::print(){
    for(int i=0;i<sizeEvent;i++){
        eArray[i]->print();
    }
}

Date PlannerDate::getDate() {return date;}
