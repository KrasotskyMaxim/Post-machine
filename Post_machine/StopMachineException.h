/*
 * File:   StopMachineException.h
 * Author: Krasotsky Maxim
 */

#ifndef STOPMACHINE_H
#define	STOPMACHINE_H

#include "MachineException.h"

// exception at normal programm completion

class StopMachineException : public MachineException {
public:
    StopMachineException();
    virtual ~StopMachineException() throw();
private:

};

#endif	/* STOPMACHINE_H */