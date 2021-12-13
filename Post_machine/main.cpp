/*
 * File:   main.cpp
 * Author: Krasotsky Maxim
 */
#include <iostream>
#include <valarray>
#include <string>
#include <locale>
#include "Machine.h"


// Print machine condition in every step
void printState(const State& state);

int main(int argc, char** argv)
{
	// Program taken from wikipedia to subtract two numbers
	std::string prg_str[] = {
		"1 x",
		"2 >",
		"3 ? 4,5",
		"4 !",
		"5 <",
		"6 ? 5,7",
		"7 x",
		"8 >",
		"9 ? 8,1"
	};

	std::valarray<std::string> prg(prg_str, sizeof(prg_str) / sizeof(prg_str[0]));

	try
	{
		std::locale::global(std::locale(""));
		// machine creation and start
		Machine(prg, "00111110111000", 8).Run(printState);
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	system("pause");
	return 0;
}

void printState(const State& state)
{
	std::cout << state << std::endl;
}
