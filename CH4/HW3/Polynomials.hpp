//
// Created by Oreofe Solarin on 10/5/22.
//

#ifndef HW3_POLYNOMIALS_HPP
#define HW3_POLYNOMIALS_HPP

#include <string>
#include <vector>


class Polynomials {
private:
    std::string poly;
    std::vector<int> poly_vector;



public:
    Polynomials();
    Polynomials(const std::string& poly);
    Polynomials toPoly(const std::string& poly);
    Polynomials operator = (const std::string& poly);
    Polynomials operator + (const Polynomials & first);

    //    ~Polynomials();
void add(const Polynomials& poly1);

bool increase(int co_eff, int value);

void display(std::ostream &out);

void displayCoeffHighest();







};


#endif //HW3_POLYNOMIALS_HPP
