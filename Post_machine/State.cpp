/*
 * File:   State.cpp
 * Author: Krasotsky Maxim
 */
#include "State.h"
#include "Program.h"

State::State(tape_t::size_type pos, const tape_t& data, size_t line, Program* program)
    : pos(pos)
    , tape(data)
    , line(line)
    , last(0)
    , step(0)
    , program(program)
{
};

State::State(tape_t::size_type pos, const std::string& data, size_t line, Program* program)
    : pos(pos)
    , line(line)
    , last(0)
    , step(0)
    , program(program)
{
    for (std::string::size_type i = 0, end = data.length(); i < end; ++i)
    {
        switch (data[i])
        {
        case '0':
            tape.push_back(false);
            break;
        case '1':
            tape.push_back(true);
            break;
        default:
            throw MachineException("The input data must consist of zeros and ones");
        }
    }
}

std::ostream& operator<<(std::ostream& out, const State& state)
{
    out << "Step: " << state.step << std::endl;
    out << std::string(state.pos, ' ') << 'V' << std::endl;
    for (tape_t::size_type i = 0, end = state.tape.size(); i < end; ++i)
    {
        out << state.tape[i];
    }
    if (state.program)
    {
        out << "   |   " << (*state.program)[state.line]->toString() << std::endl;
    }
    return out;
}
