#pragma once

#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Result {
	int match;
	vector<string> detail;
};

class Table {
private:
	int width, height;
	vector<string> words;
	vector<string> compareWords;
public:
	Table();
	void readFile(string path);
	void doCompare();
	bool comparisionWords(string word, vector<string> map);
	Result searchingAlgorithms(string s);
	void writeToFile(string path, vector<Result> results, int match);
	~Table();
};

