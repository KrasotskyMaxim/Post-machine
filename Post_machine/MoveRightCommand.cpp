/*
 * File:   MoveRightCommand.cpp
 * Author: Krasotsky Maxim
 */

#include "MoveRightCommand.h"

MoveRightCommand::MoveRightCommand(size_t cur, size_t to)
    : SimpleCommand(cur, RIGHT, to)
{
}

MoveRightCommand::~MoveRightCommand()
{
}

void MoveRightCommand::execute(State& state) const
{
    if (++state.pos == state.tape.size())
    {
        state.tape.push_back(false);
    }
    SimpleCommand::execute(state);
}
