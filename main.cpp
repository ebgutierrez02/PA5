#include "test.hpp"
#include <iostream>
using namespace std;

int main(void)
{
	Test tester;

	tester.testEmptyenqueue();

	tester.testOneenqueue();

	tester.testOnedequeue();

	tester.testTwodequeue();

	tester.testSimulation();

	return 0;
}