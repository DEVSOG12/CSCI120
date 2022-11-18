//
// Created by Oreofe Solarin on 11/7/22.
//

#ifndef STLDEMO_TIME_HPP
#define STLDEMO_TIME_HPP


class Time {

private:
    int hour;
    int minute;
public:
    Time();
    Time(int hour, int minute);
    ~Time();
    void setTime(int hour, int minute);
    void display();
    float getDifference(Time time); // in minutes
    // overload - operator
    Time operator-(const Time &time) ; // return the difference between two times
};
// Time time
// time = Time(1,2)
// driver.

// Constructor
// @pre: none
// @post: hour and minute are set to 0
// @return: none
Time::Time() {
    hour = 0;
    minute = 0;
}

// Constructor
// @pre: none
// @param: hour, minute
// @post: hour and minute are set to the values passed in as parameters
// @return: none
Time::Time(int hour, int minute) {
    this->hour = hour;
    this->minute = minute;
}

// Destructor
// @pre: none
// @post: none
// @return: none
Time::~Time() = default;

// setTime
// @pre: none
// @param: hour, minute
// @post: hour and minute are set to the values passed in as parameters
// @return: none
void Time::setTime(int n_hour, int n_minute) {
    this->hour = n_hour;
    this->minute = n_minute;
}

// getDifference
// @pre: none
// @param: [Time] object
// @post: none
// @return: the difference between the time passed in as a parameter and the time object
float Time::getDifference(Time time) {
    return (hour - time.hour) * 60 + (minute - time.minute);
}

// operator-
// @pre: none
// @param: [Time] object
// @post: none
// @return: the difference between the time passed in as a parameter and the time object
Time Time::operator-(const Time &time)  {
     hour = this->hour - time.hour;
     minute = this->minute - time.minute;
    return Time(hour, minute);
}

void Time::Time::display() {
    std::cout << "Hour: " << hour << std::endl;
    std::cout << "Minute: " << minute << std::endl;

}

#endif //STLDEMO_TIME_HPP
