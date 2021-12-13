/*
 * File:   StopMachine.cpp
 * Author: Krasotsky Maxim
 */

#include "StopMachineException.h"

StopMachineException::StopMachineException()
	: MachineException("Останов программы")
{
}

StopMachineException::~StopMachineException() throw()
{
}