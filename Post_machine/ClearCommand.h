/*
 * File:   ClearCommand.h
 * Author: Krasotsky Maxim
 */

#ifndef CLEARCOMMAND_H
#define	CLEARCOMMAND_H

#include "SimpleCommand.h"

 // Class-command for stopping the macine

class ClearCommand : public SimpleCommand {
public:
    ClearCommand(size_t line, size_t to);
    virtual ~ClearCommand();
    virtual void execute(State& state) const;
private:

};

#endif	/* CLEARCOMMAND_H */