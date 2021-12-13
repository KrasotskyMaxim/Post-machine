/*
 * File:   ClearCommand.cpp
 * Author: Krasotsky Maxim
 */

#include "ClearCommand.h"
#include "RuntimeMachineException.h"

ClearCommand::ClearCommand(size_t cur, size_t to)
    : SimpleCommand(cur, CLEAR, to)
{
}

ClearCommand::~ClearCommand()
{
}

void ClearCommand::execute(State& state) const
{
    if (!state.tape[state.pos])
    {
        throw RuntimeMachineException("You cannot erase an empty field", state);
    }
    state.tape[state.pos] = false;
    SimpleCommand::execute(state);
}