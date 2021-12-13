/*
 * File:   machine.h
 * Author: Krasotsky Maxim
 */

#ifndef MACHINE_H
#define	MACHINE_H

#include <valarray>
#include <string>
#include "State.h"
#include "Program.h"

 // Machine

class Machine {
public:
    // Type for callback function
    typedef void (*callback)(const State& state);
    Machine(const std::valarray<std::string>& program, const std::string& data, std::string::size_type pos);
    virtual ~Machine();
    // Starts the machine for execution. If a function is passed as an argument, it calls it at each step
    State Run(callback func = 0);
private:
    // Machine state
    State _state;
    // program
    Program _program;
};

#endif	/* MACHINE_H */