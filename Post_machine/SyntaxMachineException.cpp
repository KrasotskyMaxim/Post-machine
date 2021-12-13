/*
 * File:   SyntaxMachineException.cpp
 * Author: Krasotsky Maxim
 */

#include "SyntaxMachineException.h"

SyntaxMachineException::SyntaxMachineException(const std::string& msg)
	: MachineException(msg)
{
}

SyntaxMachineException::~SyntaxMachineException() throw()
{
}