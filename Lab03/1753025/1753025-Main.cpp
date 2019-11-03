#include "1753025-Function.h"



int main() {

	List l;

	//save List of Examinee from data.txt to LIST
	l.CLC = readExamineeList("data.txt");

	//sum scores of all examinees and print out to another file
	writeSumOfScore(l, "output.txt");

	//Read examinee information base one line in data.txt
	Examinee e = readExamineeInfo("4");
	cout << "SBD " << "Math " << "Literture " << "Physic " 
		<< "Chemistry " << "Biology " << "History " << "Geography " 
		<< "Civic Edu " << "KHTN " << "KHXH " << "NN " << endl;
	cout << endl;
	cout << e.id << " "
		<< e.math << " "
		<< e.literature << " "
		<< e.physic << " "
		<< e.chemistry << " "
		<< e.biology << " "
		<< e.history << " "
		<< e.geography << " "
		<< e.civic_education << " "
		<< e.natural_science << " "
		<< e.social_science << " "
		<< e.foreign_language << " " << endl << endl;

	system("pause");
	return 0;
}