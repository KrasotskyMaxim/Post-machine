/*
 * File:   SetCommand.h
 * Author: Krasotsky Maxim
 */

#ifndef SETCOMMAND_H
#define	SETCOMMAND_H

#include "SimpleCommand.h"

 // mark setting command

class SetCommand : public SimpleCommand {
public:
    SetCommand(size_t line, size_t to);
    virtual ~SetCommand();
    virtual void execute(State& state) const;
private:
};

#endif	/* SETCOMMAND_H */
