#include "function.h"

int main() {
	Examinee t;
	vector<Examinee> a, b, c, d;

	string path1 = "data.txt";
	string path2 = "descending_Math.txt";
	string path3 = "descending_Math_1.txt";
	string path4 = "descending_Math_2.txt";

	a = ReadExamineeList("data.txt");
	b = ReadExamineeList(path2);
	c = ReadExamineeList(path3);
	d = ReadExamineeList(path4);
	

	string r = FindExamineeByMath(b, 3.6);
	cout << "Thi Sinh: " << r;

	
	//-------------
	vector<Examinee> getTop;

	float m = 5;
	getTop = GetTopHighestMath(b, 100);

	for (int i = 0; i < getTop.size(); i++) {
		cout << i << " " << getTop[i].ID << " " << getTop[i].math << endl;
	}

	vector<Examinee> k = MergeTwoList(b, c);

	cout << endl << "Merge........" << endl;
	for (int i = 0; i < 50; i++) {
		cout << k[i].ID << " " << k[i].math << endl;
	}

	system("pause");
	return 0;
}