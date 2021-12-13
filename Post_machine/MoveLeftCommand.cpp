/*
 * File:   MoveLeftCommand.cpp
 * Author: Krasotsky Maxim
 */

#include "MoveLeftCommand.h"
#include "RuntimeMachineException.h"

MoveLeftCommand::MoveLeftCommand(size_t cur, size_t to)
    : SimpleCommand(cur, LEFT, to)
{
}

MoveLeftCommand::~MoveLeftCommand()
{
}

void MoveLeftCommand::execute(State& state) const
{
    if (!state.pos)
    {
        state.tape.push_front(false);
    }
    else
    {
        --state.pos;
    }
    SimpleCommand::execute(state);
}
