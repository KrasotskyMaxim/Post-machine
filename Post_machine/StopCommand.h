/*
 * File:   SyntaxMachineException.h
 * Author: Krasotsky Maxim
 */

#ifndef EXITCOMMAND_H
#define	EXITCOMMAND_H

#include "Command.h"

 // program stopping command

class StopCommand : public Command {
public:
    StopCommand(size_t line);
    virtual ~StopCommand();
    virtual void execute(State& state) const;
    virtual std::string toString() const;
private:

};

#endif	/* EXITCOMMAND_H */