//
// Created by Sofia Visa on 9/17/20.
//

#ifndef CH9ARRAYLIST_PRECONDVIOLATEDEXCEP_HPP
#define CH9ARRAYLIST_PRECONDVIOLATEDEXCEP_HPP


#include <stdexcept>
#include <string>

class PrecondViolatedExcep : public std::logic_error
{
public:
    PrecondViolatedExcep(const std::string& message = "");
}; // end PrecondViolatedExcep


PrecondViolatedExcep::PrecondViolatedExcep(const std::string& message)
        : std::logic_error("Precondition Violated Exception: " + message)
{
}  // end constructor

// End of implementation file.

#endif //CH9ARRAYLIST_PRECONDVIOLATEDEXCEP_HPP
