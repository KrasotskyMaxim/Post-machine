/*
 * File:   command.h
 * Author: Krasotsky Maxim
 */

#ifndef COMMAND_H
#define	COMMAND_H

#include "State.h"

 // basic commands abstract class

class Command {
public:
    // command types

    enum commands {
        STOP = '!',
        SET = 'V',
        CLEAR = 'X',
        LEFT = '<',
        RIGHT = '>',
        IF = '?'
    };

    Command(size_t line, commands op);
    virtual ~Command();
    // execute command
    virtual void execute(State& state) const = 0;
    // command string representation
    virtual std::string toString() const = 0;
    // string number
    size_t line() const;
    // command
    commands command() const;
protected:
    size_t _line;
    commands _op;
};

#endif	/* COMMAND_H */