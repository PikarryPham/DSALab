#include "StringMatchingFunc.h"

int main() {
	Table game;
	game.readFile("input.txt");
	game.doCompare();

	system("pause");
	return 0;
}