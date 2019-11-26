#pragma once
#ifndef _function_HEADER
#define _function_HEADER

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


struct Examinee
{
	string ID;
	float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science, social_science, foreign_language;
};

struct List {
	vector<Examinee> CLC;
};


// Read data
Examinee ReadExaminee(string line_info);
vector<Examinee> ReadExamineeList(string file_name);

// Q1
string FindExamineeByMath(vector<Examinee> sorted_list, float m);

// Q2.1
vector<Examinee> GetTopHighestMath(vector<Examinee> list_examinee, int k);

// Q2.2
vector<Examinee> MergeTwoList(vector<Examinee> list1, vector<Examinee> list2);

#endif
