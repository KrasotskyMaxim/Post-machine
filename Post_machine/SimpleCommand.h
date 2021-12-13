/*
 * File:   SimpleCommand.h
 * Author: Krasotsky Maxim
 */

#ifndef MOVECOMMAND_H
#define	MOVECOMMAND_H

#include "Command.h"

 // Commands of type a op b

class SimpleCommand : public Command {
public:
    SimpleCommand(size_t line, commands op, size_t to);
    virtual ~SimpleCommand();
    virtual void execute(State& state) const;
    virtual std::string toString() const;
    // The statement to which execution proceeds after the command
    size_t to() const;
protected:
    size_t _to;
};

#endif	/* MOVECOMMAND_H */