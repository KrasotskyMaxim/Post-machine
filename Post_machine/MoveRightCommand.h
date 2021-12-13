/*
 * File:   MoveRightCommand.h
 * Author: Krasostky Maxim
 */

#ifndef MOVERIGHTCOMMAND_H
#define	MOVERIGHTCOMMAND_H

#include "SimpleCommand.h"

 // class-command right move

class MoveRightCommand : public SimpleCommand {
public:
    MoveRightCommand(size_t line, size_t to);
    virtual ~MoveRightCommand();
    virtual void execute(State& state) const;
private:

};

#endif	/* MOVERIGHTCOMMAND_H */