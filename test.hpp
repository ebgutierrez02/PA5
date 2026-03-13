#pragma once
#include "queue.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;

class Test
{
public:

	void testEmptyenqueue();

	void testOneenqueue();

	void testOnedequeue();

	void testTwodequeue();

	void testSimulation();

	void runSimulation(int runTime);
};