/*
 * File:   RuntimeMachineException.h
 * Author: Krasotsky Maxim
 */

#ifndef RUNTIMEMACHINEEXCEPTION_H
#define	RUNTIMEMACHINEEXCEPTION_H

#include "MachineException.h"
#include "State.h"

 // machine executing time exception

class RuntimeMachineException : public MachineException {
public:
    RuntimeMachineException(const std::string& msg, const State& state);
    virtual ~RuntimeMachineException() throw();
    // return machine state
    State state() const;
private:
    State _state;
};

#endif	/* RUNTIMEMACHINEEXCEPTION_H */