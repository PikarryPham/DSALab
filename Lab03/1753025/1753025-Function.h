#pragma once

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include  <iomanip>

using namespace std;

struct Examinee {
	string id;
	float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science,
		social_science, foreign_language;
};


struct List {
	vector<Examinee> CLC;
};

Examinee readExamineeInfo(string line_info);

vector<Examinee> readExamineeList(string file);
void writeSumOfScore(List l, string file);
