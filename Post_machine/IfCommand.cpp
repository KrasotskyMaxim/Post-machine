/*
 * File:   IfCommand.cpp
 * Author: Krasotsky Maxim
 */

#include <sstream>
#include "IfCommand.h"

IfCommand::IfCommand(size_t cur, size_t falseLine, size_t trueLine)
    : Command(cur, IF)
    , _falseLine(falseLine)
    , _trueLine(trueLine)
{
}

IfCommand::~IfCommand()
{
}

void IfCommand::execute(State& state) const
{
    state.last = state.line;
    if (state.tape[state.pos])
    {
        state.line = _trueLine;
    }
    else
    {
        state.line = _falseLine;
    }
}

std::string IfCommand::toString() const
{
    std::stringstream sstr;
    sstr << _line << ' ' << static_cast<char> (_op) << ' ' << _falseLine << ',' << _trueLine;
    return sstr.str();
}
