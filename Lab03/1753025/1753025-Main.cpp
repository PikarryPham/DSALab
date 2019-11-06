#include "1753025-Function.h"

int main() {
	List l;

	//save List of Examinee from data.txt to LIST
	l.CLC = readExamineeList("data.txt");

	//sum scores of all examinees and print out to another file
	writeSumOfScore(l, "output.txt");

	system("pause");
	return 0;
}