/*
 * File:   machine_error.cpp
 * Author: Krasotsky Maxim
 */

#include "MachineException.h"

MachineException::MachineException(const std::string& msg)
    :message(msg)
{
}

MachineException::~MachineException() throw()
{
}

const char* MachineException::what() const throw()
{
    return message.c_str();
}