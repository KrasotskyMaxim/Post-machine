/*
 * File:   StopMachine.cpp
 * Author: Krasotsky Maxim
 */

#include "StopMachineException.h"

StopMachineException::StopMachineException()
	: MachineException("������� ���������")
{
}

StopMachineException::~StopMachineException() throw()
{
}