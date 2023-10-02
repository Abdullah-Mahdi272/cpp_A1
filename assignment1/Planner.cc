//
// Created by abdul on 2023-09-29.
//

#include "Planner.h"



Planner::Planner() {

    sizePlannerDate = 0;

}

Planner::~Planner(){
    for (int i = 0; i < sizePlannerDate; ++i){
        delete pdArray[i];
    }
}

PlannerDate* Planner::getDate(Date& dd){
    PlannerDate pd = PlannerDate(dd);
    for (int i = 0; i < sizePlannerDate; ++i){
        if(pdArray[i]->equals(pd)){
            return pdArray[i];
        }
    }

    int index = 0;

    while (index < sizePlannerDate){
        if(pd.lessThan(*pdArray[index])){
            break;
        }
        ++index;
    }

    for (int i = sizePlannerDate; i > index; --i){
        pdArray[i] = pdArray[i-1];
    }

    pdArray[index] = &pd;

    ++sizePlannerDate;
    return pdArray[index];
}

void Planner::addEvent(string title, string description, Date& date, int startTime, int duration){
    bool noMatch;



    for(int i=0;i<sizePlannerDate;i++){

        if(pdArray[i]->getDate().equals(date)){

            pdArray[i]->addEvent(title, description, startTime, duration);
            noMatch = false;
            break;

        }
        else{
            noMatch = true;
        }

    }
    if(noMatch || sizePlannerDate == 0){

        int index = 0;
        PlannerDate pd = PlannerDate(date);
        while (index < sizePlannerDate){
            if(pd.lessThan(*pdArray[index])){
                break;
            }
            ++index;
        }

        for (int i = sizePlannerDate; i > index; --i){
            pdArray[i] = pdArray[i-1];
        }

        pdArray[index] = &pd;

        ++ sizePlannerDate;

    }

}

//void Planner::addEvent(string title, string description, Date& date, int startTime, int duration){
//    bool noMatch;
//    for(int i=0;i<sizePlannerDate;i++){
//
//        if(pdArray[i]->getDate().equals(date)){
//
//            pdArray[i]->addEvent(title, description, startTime, duration);
//            noMatch = false;
//            break;
//
//        }
//        else{
//            noMatch = true;
//        }
//
//    }
//    if(noMatch){
//
//        int index = 0;
//        PlannerDate pd = PlannerDate(date);
//        while (index < sizePlannerDate){
//            if(pd.lessThan(*pdArray[index])){
//                break;
//            }
//            ++index;
//        }
//
//        for (int i = sizePlannerDate; i > index; --i){
//            pdArray[i] = pdArray[i-1];
//        }
//
//        pdArray[index] = &pd;
//
//        ++ sizePlannerDate;
//
//    }
//
//}



void Planner::printAllDates(){
    for(int i=0;i<sizePlannerDate;i++){
        pdArray[i]->print();
    }
}
void Planner::printDate(Date& d){
    for(int i=0;i<sizePlannerDate;i++){
        if(pdArray[i]->getDate().equals(d)){
            pdArray[i]->print();
        }
    }
}

void Planner::addDailyEvent(std::string title, std::string description, Date &startDate, Date &endDate, int startTime, int duration) {


    for(int i=startDate.getYear();i<endDate.getYear();i++){
        for(int j=startDate.getMonth();j<endDate.getMonth();j++){
            for(int k=startDate.getDay();k<endDate.getDay();k++){
                Date d =  Date(i,j,k);
                addEvent(title, description, d,startTime, duration);
            }
        }
    }

}

void Planner::addWeeklyEvent(std::string title, std::string description, Date &startDate, Date &endDate, int startTime, int duration) {

    for(int i=startDate.getYear();i<endDate.getYear();i++){
        for(int j=startDate.getMonth();j<endDate.getMonth();j++){
            for(int k=startDate.getDay();k<endDate.getDay();k=k+7){
                Date d =  Date(i,j,k);
                addEvent(title, description, d,startTime, duration);
            }
        }
    }

}

void Planner::printDatesInRange(Date& startDate, Date& endDate){
    for(int i=0;i<sizePlannerDate;i++){
        if(pdArray[i]->getDate().equals(startDate) || pdArray[i]->getDate().equals(endDate)){
            pdArray[i]->print();
        }
        if(pdArray[i]->getDate().lessThan(endDate) && pdArray[i]->getDate().getDay() > startDate.getDay() && pdArray[i]->getDate().getMonth() > startDate.getMonth() && pdArray[i]->getDate().getYear() > startDate.getYear()){
            pdArray[i]->print();
        }
    }
}


void Planner::printDatesWithEvent(const std::string &title) {
    for(int i=0;i<sizePlannerDate;i++){
        if(pdArray[i]->hasEvent(title)){
            pdArray[i]->print();
        }
    }
}

void Planner::printDatesWithConflict() {
    for(int i=0;i<sizePlannerDate;i++){

        if(pdArray[i]->hasConflict()){
            pdArray[i]->print();
        }
    }
}