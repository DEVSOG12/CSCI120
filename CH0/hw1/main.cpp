#include <iostream>
using namespace std;

// this C-style struct models a temperature objects having two attributes
struct Temperature
{
    double degree;
    char scale; // Celsius or Fahrenheit
};

// Receives by reference original and new temperatures
// If origTemp is in Celsius, it populates the newTemp with Fahrenheit equivalent
// If origTemp is in Fahrenheit, it populates the newTemp with Celsius equivalent
void convertTemperature(const Temperature& origTemp, Temperature& newTemp) {
    // Implementation of conversion from org. Temperature to new Temperature
    assert( origTemp.scale == 'C' || origTemp.scale == 'F');
    //Firstly we need to know the temperature type
    if (origTemp.scale == 'C') // Tells us that we are working with Celsius
    {
        // Converting from Degree C to Degree F
        newTemp.degree = (origTemp.degree * 9/5) + 32;
        newTemp.scale = 'F';
    }else
    {
        // Converting from Degree F to Degree C
        newTemp.degree = (origTemp.degree - 32) * (5.0/9);
        newTemp.scale = 'C';
    }




}

int main() {

    Temperature t1{}, t2{};
    t1.degree = 32;
    t1.scale = 'F';

    convertTemperature( t1, t2 );
    cout << "Temperature t1 is: " << t1.degree << "\t" << t1.scale << endl;
    cout << "Temperature t1 converted is: " << t2.degree << "\t" << t2.scale << endl << endl;

    Temperature t3{}, hot = {42, 'C'};
    convertTemperature( hot, t3 );
    cout << "Temperature hot is: " << hot.degree << "\t" << hot.scale << endl;
    cout << "Temperature hot converted is: " << t3.degree << "\t" << t3.scale << endl;

    return 0;
}


//class Xa{
//private:
//    bool why;};

