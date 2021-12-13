/*
* File:   program.cpp
* Author: Krasotsky Maxim
*/

#include <sstream>
#include <typeinfo>
#include <regex>
#include "MachineException.h"
#include "SyntaxMachineException.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"
#include "IfCommand.h"
#include "SetCommand.h"
#include "ClearCommand.h"
#include "StopCommand.h"
#include "Program.h"

Program::Program(const std::valarray<std::string>& prog_str)
	: _commands(prog_str.size())
{
	for (size_t i = 0, end = prog_str.size(); i < end; ++i)
	{
		auto ptr = std::shared_ptr<Command>(createCommand(prog_str[i]));
		if (ptr->line() != i + 1)
		{
			throw SyntaxMachineException(std::string("Invalid program line number (numbering out of order): ") + prog_str[i]);
		}
		_commands[i] = ptr;
	}
}

Program::~Program()
{
}

const Command* Program::operator [](size_t line) const
{
	if (line < 1 || line > _commands.size())
	{
		std::stringstream sstr;
		sstr << line;
		throw MachineException(std::string("Неверный номер строки: ") + sstr.str());
	}
	return _commands[line - 1].get();
}

Command* Program::createCommand(const std::string& cmd) const
{
	// RegEx to check syntax
	static const std::regex simpleCommand("^\\s*(\\d{1,5})\\s*([VvXx<>])\\s*(\\d{1,5}){0,1}\\s*$");
	static const std::regex ifCommand("^\\s*(\\d{1,5})\\s+(\\?)\\s+(\\d{1,5})\\s*,\\s*(\\d{1,5})\\s*$");
	static const std::regex stopCommand("^\\s*(\\d{1,5})\\s*!\\s*$");
	std::smatch m;
	if (std::regex_match(cmd, m, simpleCommand))
	{
		std::string currentStr = m[1],
			commandStr = m[2],
			toStr = m[3];
		unsigned int current = convert<unsigned int>(currentStr),
			to = toStr.empty() ? current + 1 : convert<unsigned int>(toStr);
		switch (commandStr[0])
		{
		case 'V':
		case 'v':
			return new SetCommand(current, to);
		case 'X':
		case 'x':
			return new ClearCommand(current, to);
		case '<':
			return new MoveLeftCommand(current, to);
		case '>':
			return new MoveRightCommand(current, to);
			break;
		}
	}
	else if (std::regex_match(cmd, m, ifCommand))
	{
		std::string currentStr = m[1],
			commandStr = m[2],
			falseNoStr = m[3],
			trueNoStr = m[4];
		size_t current = convert<size_t>(currentStr),
			falseLine = convert<size_t>(falseNoStr),
			trueLine = convert<size_t>(trueNoStr);
		return new IfCommand(current, falseLine, trueLine);
	}
	else if (std::regex_match(cmd, m, stopCommand))
	{
		std::string currentStr = m[1];
		size_t current = convert<size_t>(currentStr);
		return new StopCommand(current);
	}
	else
	{
		throw SyntaxMachineException(std::string("Incorrect command: '") + cmd + "'");
	}
	return 0;
}

template<class T> T Program::convert(const std::string& str) const
{
	std::istringstream sstr(str);
	T result;
	sstr >> result;
	if (sstr.fail())
	{
		throw MachineException(std::string("Error to convert('") + str + "' in " + typeid (T).name() + ")");
	}
	return result;
}