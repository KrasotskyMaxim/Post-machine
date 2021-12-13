/*
 * File:   program.h
 * Author: Krasotsky Maxim
 */

#ifndef PROGRAM_H
#define	PROGRAM_H

#include <valarray>
#include <memory>
#include "Command.h"

 // Program, that contains instructions list, where every command is represent it`s own class

class Program {
public:
    // Constructor. Get program string array
    Program(const std::valarray<std::string>& prog);
    virtual ~Program();
    // return program pointer by string number
    const Command* operator [](size_t line) const;
private:
    Program(const Program& orig);
    Command* createCommand(const std::string& cmd) const;
    template<class T> T convert(const std::string& str) const;
    std::valarray<std::shared_ptr<Command > > _commands;
};

#endif	/* PROGRAM_H */