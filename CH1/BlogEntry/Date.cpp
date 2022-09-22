//
// Created by Oreofe Solarin on 9/19/22.
//

#include <format>
#include <chrono>
#include "Date.h"
time_t t = time(NULL);
tm* timePtr = localtime(&t);

Date::Date() {

    day =  timePtr->tm_mday;
    month = (timePtr->tm_mon +1);
    year = (timePtr->tm_year + 1900);

}

Date::Date(int kday, int kmonth, int kyear) throw(class std::logic_error) {

    if (kday > 31 || kmonth > 12 || kmonth < 1 || kday < 1 || kyear < 1902){
        throw logic_error("Bro What are you thinking");
    }

    day = kday;
    month = kmonth;
    year = kyear;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::showStructure() const {
    std::cout << std::endl << "Day: " << day << std::endl;
    std::cout << "Month: " << month << std::endl;
    std::cout << "Year: " << year << std::endl;
}

bool Date::isLeapYear(int year) {
    if( year %  400 == 0 && year % 100 == 0)
    {
        return true;
    }else if(year % 4 == 0 && year % 100 != 0){
        return true;
    }
        return false;
}

int Date::daysInMonth(int month, int year) {
//    if month in {1, 3, 5, 7, 8, 10, 12}:
//    return 31
//    if month == 2:
//    if leap_year(year):
//    return 29
//    return 28
//    return 30


    if((month % 2 == 1 && month < 8) || (month > 8 && month % 2 == 0)) {
        return 31;
    }else if(month == 2){
        if(isLeapYear(year)){
            return 29;
        }else{
            return 28;
        }

    }
    return 30;
}

// std::ostream & operator<<(std::ostream & stream,  const Date& date) {
//    std::cout << date.showStructure();
//    return stream;
//}

std::ostream& operator<<(std::ostream &out, const Date& date){
    std::cout << std::endl << "Day: " << date.day << std::endl;
    std::cout << "Month: " << date.month << std::endl;
    std::cout << "Year: " << date.year << std::endl;
    return out;
}
