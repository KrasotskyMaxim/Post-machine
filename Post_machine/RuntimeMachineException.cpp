/*
 * File:   RuntimeMachineException.cpp
 * Author: Krasotsky Maxim
 */

#include "RuntimeMachineException.h"

RuntimeMachineException::RuntimeMachineException(const std::string& msg, const State& state)
    : MachineException(msg)
    , _state(state)
{
}

RuntimeMachineException::~RuntimeMachineException() throw()
{
}

State RuntimeMachineException::state() const
{
    return _state;
}
