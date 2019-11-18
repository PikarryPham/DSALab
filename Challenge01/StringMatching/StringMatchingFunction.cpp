#include "StringMatchingFunc.h"

//Constructor & Destructor
Table::Table() : width(0),
height(0)
{};
Table::~Table() {};

void Table::readFile(string path) {

	ifstream fin;

	fin.open(path, ios_base::in);

	if (fin.fail()) {
		cout << "File does not exist" << endl;
		return;
	}
	else {
		string temp;
		string line;

		getline(fin, temp, ' ');
		this->width = stoi(temp);
		getline(fin, temp, '\n');
		this->height = stoi(temp);

		for (int j = 0; j < this->height; j++) {
			for (int i = 0; i < this->width; i++) {
				if (i == (this->width - 1)) {
					getline(fin, temp, '\n');
				}
				else {
					getline(fin, temp, ' ');
				}

				line += temp;
			}
			this->words.push_back(line);
			line.clear();
			cout << this->words[j] << endl;
		}

		while (!fin.eof()) {
			getline(fin, temp);
			if (temp == "#") {
				break;
			}
			else
			{
				this->compareWords.push_back(temp);
			}
		}
		fin.close();
	}

};

bool Table::comparisionWords(string word, vector<string> map) {
	return false;
};

void Table::doCompare() {
	vector<Result> r;
	bool flag = false;
	int count = 0;

	//flag = comparisionWords(this->compareWords[0], this->words);

	for (int i = 0; i < compareWords.size(); i++) {
		r.push_back(searchingAlgorithms(compareWords[i]));
		count += r[i].match;
	}

	this->writeToFile("output.txt", r, count);
};

Result Table::searchingAlgorithms(string s) {
	Result tmp;
	string test = s;
	int left(0), ver_left(0);
	int size_s = test.size();
	string t;
	cout << "\n\n";
	int check(0), ver_check(0);
	vector<string> result;

	cout << "=>> FINDING: " << test << endl;
	//Checking in horizon
	for (int i = 0; i < words.size(); i++) {
		for (int j = 0; j < (width); j++) {
			if (words[i][j] == test[left]) {
				left++;
			} 
			else if (left > 0) {
				left = 0;
				if (words[i][j] == test[left])
					left++;
			}
			if (left == size_s) {
				//cout << "left & j: " << left<< " " << j << endl;
				cout << "Found: " << test << " at (" << i + 1 << "," << j - left + 2 << ") LR" << endl;
				tmp.detail.push_back(test + " (" + to_string(i+1) +"," + to_string(j - left +2) + ") " + "LR");
				cout << t << endl;
				check++;
				//break;
			}
		}
		left = 0;
	}

	//Checking in vertical
	for (int j = 0; j < width; j++) {
		for (int i = 0; i < words.size(); i++) {
			if (words[i][j] == test[ver_left]){
				ver_left++;
			}
			else if (ver_left > 0) {
				ver_left = 0;
				if (words[i][j] == test[ver_left])
					ver_left++;
			}

			if (ver_left == size_s) {
				//cout << "left & j: " << left<< " " << j << endl;
				cout << "Found: " << test << " at (" <<  i - ver_left + 2 << "," << j + 1 << ") TD" << endl;
				tmp.detail.push_back(test + " (" + to_string(i - ver_left + 2) + "," + to_string(j + 1) + ") " + "TD");
				ver_check++;
				//break;
			}
		}
		ver_left = 0;
	}

	if ((check + ver_check) == 0) {
		cout << test << " (0,0) NF" << endl;
		tmp.detail.push_back(test + " (0,0) NF");
	}
	
	tmp.match = check + ver_check;

	return tmp;
};

void Table::writeToFile(string path, vector<Result> results, int match) {
	ofstream fout;

	fout.open(path, ios::out | ios::trunc);

	fout << to_string(match) << endl;

	for (int i = 0; i < results.size(); i++) {
		for (int j = 0; j < results[i].detail.size(); j++) {
			fout << results[i].detail[j] << endl;
		}
	}
	
	fout.close();
}