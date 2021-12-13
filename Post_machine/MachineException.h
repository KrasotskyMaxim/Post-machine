/*
 * File:   machine_error.h
 * Author: Krasostky Maxim
 */

#ifndef MACHINE_ERROR_H
#define	MACHINE_ERROR_H

#include <exception>
#include <string>

 // Basic class-exception for machine working

class MachineException : public std::exception {
public:
    MachineException(const std::string& msg);
    virtual ~MachineException() throw();
    virtual const char* what() const throw();
private:
    std::string message;
};

#endif	/* MACHINE_ERROR_H */