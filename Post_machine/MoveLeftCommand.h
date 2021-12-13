/*
 * File:   MoveLeftCommand.h
 * Author: Krasotsky Maxim
 */

#ifndef MOVELEFTCOMMAND_H
#define	MOVELEFTCOMMAND_H

#include "SimpleCommand.h"

 // class-command left move

class MoveLeftCommand : public SimpleCommand {
public:
    MoveLeftCommand(size_t line, size_t to);
    virtual ~MoveLeftCommand();
    virtual void execute(State& state) const;
private:

};

#endif	/* MOVELEFTCOMMAND_H */