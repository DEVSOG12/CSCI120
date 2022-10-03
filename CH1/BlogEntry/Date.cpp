//
// Created by Oreofe Solarin on 9/19/22.
//

#include <format>
#include <chrono>
#include "Date.h"
time_t t = time(NULL);
tm* timePtr = localtime(&t);


// initializer if no parameter is given
// Post: TBH just a constructor
Date::Date() {

    day =  timePtr->tm_mday;
    month = (timePtr->tm_mon +1);
    year = (timePtr->tm_year + 1900);

}
// Pre: Req. Passed Values [int] kday, kmonth, kyear : (Reason for k to dist. with the private var.
// Post: TBH just a constructor
Date::Date(int kday, int kmonth, int kyear) throw(class std::logic_error) {

    if (kday > 31 || kmonth > 12 || kmonth < 1 || kday < 1 || kyear < 1902){
        throw logic_error("Bro What are you thinking");
    }

    day = kday;
    month = kmonth;
    year = kyear;
}

// getter of int day
// Pre: Nothing tbh
// Post: Return the private value day. [int]
int Date::getDay() const {
    return day;
}

// getter of int month
// Pre: Nothing tbh
// Post: Return the private value month. [int]
int Date::getMonth() const {
    return month;
}

// getter of int year
// Pre: Nothing tbh
// Post: Return the private value year. [int]
int Date::getYear() const {
    return year;
}

// Print cout the Structure of the Type of Date,
// Pre: Nothing tbh
// Post: std::cout each value: [int] Day, Month, Year
void Date::showStructure() const {
    std::cout << std::endl << "Day: " << day << std::endl;
    std::cout << "Month: " << month << std::endl;
    std::cout << "Year: " << year << std::endl;
}

// Checking if a given year is a Leap Year
// Pre: Req. Parameter Year as [int]
// Post: Return boolean if the given parameter [int] is a leap year
bool Date::isLeapYear(int year) {
    if( year %  400 == 0 && year % 100 == 0)
    {
        return true;
    }else if(year % 4 == 0 && year % 100 != 0){
        return true;
    }
        return false;
}

// Returns number of days in a given month based on the month and year
// Pre: Req. Parameter month and year as [int]
// Post: Return int value representing the number of days in the giving month
int Date::daysInMonth(int month, int year) {
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


// Overload operator .. .
// Pre: Req. Parameter std::ostream and Type Date
// Post: Returns std::ostream...
std::ostream& operator<<(std::ostream &out, const Date& date){
    std::cout << std::endl << "Day: " << date.day << std::endl;
    std::cout << "Month: " << date.month << std::endl;
    std::cout << "Year: " << date.year << std::endl;
    return out;
}
