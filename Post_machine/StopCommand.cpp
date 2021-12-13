/*
 * File:   ExitCommand.cpp
 * Author: Krasotsky Maxim
 */

#include <sstream>
#include "StopCommand.h"
#include "StopMachineException.h"

StopCommand::StopCommand(size_t cur)
    : Command(cur, STOP)
{
}

StopCommand::~StopCommand()
{
}

void StopCommand::execute(State& state) const
{
    state.last = state.line;
    throw StopMachineException();
}

std::string StopCommand::toString() const
{
    std::stringstream sstr;
    sstr << _line << ' ' << static_cast<char> (_op);
    return sstr.str();
}