/*
 * File:   machine.cpp
 * Author: Krasotsky Maxim
 */

#include "StopMachineException.h"
#include "RuntimeMachineException.h"
#include "Machine.h"

Machine::Machine(const std::valarray<std::string>& program, const std::string& data, std::string::size_type pos)
    : _program(program)
    , _state(pos, data, 1, &_program)
{
}

Machine::~Machine()
{
}

State Machine::Run(callback func)
{
    try
    {
        if (func)
        {
            func(_state);
        }
        // Execution cycle. Enter by exception
        while (true)
        {
            _program[_state.line]->execute(_state);
            ++_state.step;
            if (func)
            {
                func(_state);
            }
        }
    }
    catch (StopMachineException&)
    {
        // In case of normal program termination
    }
    catch (MachineException& ex)
    {
        throw RuntimeMachineException(ex.what(), _state);
    }
    catch (...)
    {
        throw;
    }
    return _state;
}
