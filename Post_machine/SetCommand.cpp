/*
 * File:   SetCommand.cpp
 * Author: Krasotsky Maxim
 */

#include "SetCommand.h"
#include "RuntimeMachineException.h"

SetCommand::SetCommand(size_t cur, size_t to)
    : SimpleCommand(cur, SET, to)
{
}

SetCommand::~SetCommand()
{
}

void SetCommand::execute(State& state) const
{
    if (state.tape[state.pos])
    {
        throw RuntimeMachineException("������ �������� � ���������� ����", state);
    }
    state.tape[state.pos] = true;
    SimpleCommand::execute(state);
}
