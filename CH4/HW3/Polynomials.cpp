//
// Created by Oreofe Solarin on 10/5/22.
//

#include "Polynomials.hpp"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

std::string toString(std::vector<int> mrm)
{
    std::string temp;
    for (int i = mrm.size() - 1; i > 0; --i) {
        if(mrm[i] != 0) {

            temp = temp  + std::to_string(mrm[i]) + "x^" + std::to_string(i) + (std::to_string(mrm[i -1])[0] != '-' ? "+": "");

        }

    }
    if(temp[0] != 0) {
       temp += std::to_string(mrm[0]);
    }else{
        temp.erase(temp.end() -1);

    }
    return temp;
}


std::string process(std::string const s)
{
    std::string temp = s;
    std::string::size_type pos = s.find('x');
    if (pos != std::string::npos)
    {
        temp = s.substr(0, pos);
        return temp;
    }
    else
    {
        return temp;
    }
}

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

std::string format (const std::string& str) {

    std::string seq = "-";
    std::string ins = "+";
    std::string newStr;

    auto foundPos = str.find(seq);
    if (foundPos == std::string::npos)
    {
        newStr = str;
    }
    else
    {
        newStr.reserve(str.length() * 2);
        decltype(foundPos) startPos = 0;
        auto ptr = str.c_str();
        do
        {
            foundPos += seq.length();
            newStr.append(ptr + startPos, foundPos - startPos);
            newStr.append(ins);
            startPos = foundPos;
            foundPos = str.find(seq, startPos);
        }
        while (foundPos != std::string::npos);
        newStr.append(ptr + startPos, str.length() - startPos);
    }
    replaceAll(newStr, "-+", "+-");
    return newStr;
}



std::vector<std::string> split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

//Polynomials::toPoly(const std::string& poly) {
//    for (int i = 0; i < 100; ++i) {
//        poly_vector.push_back(0);
//    }
//
//    std::vector<std::string> mrm = split(format(poly), '+');
//    for (int i = 0; i < mrm.size(); ++i) {
//        if(!mrm[i].empty()){
//            if(mrm[i].find('x') >= mrm[i].length()){
//                poly_vector[0] = poly_vector[0] + std::stoi((mrm[i]));
//            }else{
//                int position = std::stoi(mrm[i].substr(mrm[i].find('^') + 1));
//                poly_vector[position] = std::stoi(process(mrm[i]));
//            }
//
//        }
//
//    }
//
////    for (int i : poly_vector) {
////        if(i != 0)
////        std::cout << i << std::endl;
////    }
//    return
//}
Polynomials::Polynomials(const std::string& poly) {
    for (int i = 0; i < 100; ++i) {
        poly_vector.push_back(0);
    }

    std::vector<std::string> mrm = split(format(poly), '+');
    for (int i = 0; i < mrm.size(); ++i) {
    if(!mrm[i].empty()){
        if(mrm[i].find('x') >= mrm[i].length()){
            poly_vector[0] = poly_vector[0] + std::stoi((mrm[i]));
        }else{
            int position = std::stoi(mrm[i].substr(mrm[i].find('^') + 1));
            poly_vector[position] = std::stoi(process(mrm[i]));
        }

}

    }

//    for (int i : poly_vector) {
//        if(i != 0)
//        std::cout << i << std::endl;
//    }

}

void Polynomials::add(const Polynomials &poly1) {
    std::vector<int> temp;
    for (int i = 0; i < 100; ++i) {
        temp.push_back(0);
    }

    for (int i = 0; i < 100; ++i) {
       temp[i] = poly1.poly_vector[i] + poly_vector[i];
    }

    poly = toString(temp);


    poly_vector = temp;
}

bool Polynomials::increase(int co_eff, int value) {
    if(poly_vector[co_eff] != 0){
        poly_vector[co_eff] += value;
        poly = toString(poly_vector);
        return true;
    }
    return false;

}

void Polynomials::display(std::ostream &out) {
   out << poly <<std::endl;
}

void Polynomials::displayCoeffHighest() {
    int highest = 0;

    for (int i = 0; i < poly_vector.size(); ++i) {
        if(poly_vector[i] != 0){
            if(highest < i){
                highest = i;
            }
        }

    }
    std::cout << "Highest Degree Polynomial Co-efficient " << highest <<  std::endl;
}

Polynomials Polynomials::operator=( const std::string& poly) {
    toPoly(poly);
    return *this;
}

Polynomials Polynomials::operator+(const Polynomials &first) {
    add(first);
//    display(std::cout);
    return *this;
}

Polynomials::Polynomials() {

}

Polynomials Polynomials::toPoly(const std::string &polys) {
        for (int i = 0; i < 100; ++i) {
        poly_vector.push_back(0);
    }

    std::vector<std::string> mrm = split(format(polys), '+');
    for (int i = 0; i < mrm.size(); ++i) {
        if(!mrm[i].empty()){
            if(mrm[i].find('x') >= mrm[i].length()){
                poly_vector[0] = poly_vector[0] + std::stoi((mrm[i]));
            }else{
                int position = std::stoi(mrm[i].substr(mrm[i].find('^') + 1));
                poly_vector[position] = std::stoi(process(mrm[i]));
            }

        }

    }

//    for (int i : poly_vector) {
//        if(i != 0)
//        std::cout << i << std::endl;
//    }

    return *this;
}
