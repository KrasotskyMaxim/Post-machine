/*
 * File:   State.h
 * Author: Krasotsky Maxim
 */

#ifndef STATE_H
#define	STATE_H

#include <cstddef>
#include <deque>
#include <string>
#include <iostream>
#include "MachineException.h"

typedef std::deque<bool> tape_t;

class Program;

// machine state

struct State {
    State(tape_t::size_type pos, const tape_t& data, size_t line, Program* program = 0);
    // You can specify data in the form of a string consisting of '0' and '1'
    State(tape_t::size_type pos, const std::string& data, size_t line, Program* program = 0);
    // "infinity" tape
    tape_t tape;
    // pointer position
    tape_t::size_type pos;
    // Current instruction and previous instruction
    size_t line, last;
    // step number
    size_t step;
    // program pointer, if needed
    Program* program;
};

std::ostream& operator<<(std::ostream& out, const State& state);

#endif	/* STATE_H */
