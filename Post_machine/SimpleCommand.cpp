/*
 * File:   MoveCommand.cpp
 * Author: Krasotsky Maxim
 */

#include <sstream>
#include "SimpleCommand.h"

SimpleCommand::SimpleCommand(size_t cur, commands op, size_t to)
    : Command(cur, op)
    , _to(to)
{
}

SimpleCommand::~SimpleCommand()
{
}

size_t SimpleCommand::to() const
{
    return _to;
}

void SimpleCommand::execute(State& state) const
{
    state.last = state.line;
    state.line = this->_to;
}

std::string SimpleCommand::toString() const
{
    std::stringstream sstr;
    sstr << _line << ' ' << static_cast<char> (_op) << ' ' << _to;
    return sstr.str();
}