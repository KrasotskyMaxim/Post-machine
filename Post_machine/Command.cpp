/*
 * File:   command.cpp
 * Author: Krasotsky Maxim
 */

#include <iostream>
#include "Command.h"

Command::Command(size_t line, commands op)
    : _line(line)
    , _op(op)
{
}

Command::~Command()
{
}

size_t Command::line() const
{
    return _line;
}

Command::commands Command::command() const
{
    return _op;
}
