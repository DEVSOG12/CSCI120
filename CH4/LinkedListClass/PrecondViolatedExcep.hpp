/** Listing 7-5.
    @file PrecondViolatedExcep.h */

#ifndef PRECOND_VIOLATED_EXCEP_HPP
#define PRECOND_VIOLATED_EXCEP_HPP

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


#endif
