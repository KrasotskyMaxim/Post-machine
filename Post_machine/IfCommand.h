/*
 * File:   IfCommand.h
 * Author: Krasotsky Maxim
 */

#ifndef IFCOMMAND_H
#define	IFCOMMAND_H

#include "Command.h"

 // Conditional transition command class

class IfCommand : public Command {
public:
    IfCommand(size_t cur, size_t falseLine, size_t trueLine);
    virtual ~IfCommand();
    // transit string if no mark
    size_t falseLine() const;
    // transit string if mark
    size_t trueLine() const;
    virtual void execute(State& state) const;
    virtual std::string toString() const;
private:
    size_t _falseLine, _trueLine;
};

#endif	/* IFCOMMAND_H */