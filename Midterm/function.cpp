#include "function.h"

Examinee ReadExaminee(string line_info) {
	Examinee t;

	vector<string> list_str;
	string temp = "";

	for (int i = 0; i < line_info.length(); i++) {
		if (line_info[i] == ',') {
			list_str.push_back(temp);
			temp = "";
		}
		else {
			temp += line_info[i];
		}
	}

	t.ID = list_str[0];

	t.math = atof(list_str[2].c_str());
	t.literature = atof(list_str[3].c_str());
	t.physic = atof(list_str[4].c_str());
	t.chemistry = atof(list_str[5].c_str());
	t.biology = atof(list_str[6].c_str());
	t.history = atof(list_str[7].c_str());
	t.geography = atof(list_str[8].c_str());
	t.civic_education = atof(list_str[9].c_str());
	t.natural_science = t.physic + t.chemistry + t.biology;
	t.social_science = t.history + t.geography + t.civic_education;
	t.foreign_language = atof(list_str[12].c_str());

	return t;
}

vector<Examinee> ReadExamineeList(string file) {
	vector<Examinee> tempV;

	ifstream fin;
	fin.open(file, ios_base::in);

	if (fin.fail()) {
		cout << "File doest exist!" << endl;
		return tempV;
	}
	else {
		Examinee t;
		string temp;
		string::size_type sz;

		//get the first line
		string str;
		getline(fin, str);

		while (!fin.eof()) {

			getline(fin, str);
			

			if (str.empty()) {
				break;
			}

			t = ReadExaminee(str);
			
			tempV.push_back(t);
		}
		fin.close();
	}

	return tempV;
}

// Q1
string FindExamineeByMath(vector<Examinee> sorted_list, float m) {
	string temp = "";


	for (int i = 0; i < sorted_list.size(); i++) {
		if (sorted_list[i].math == m) {
				temp = sorted_list[i].ID;
				break;
		}
	}

	if (temp == "") {
		temp = "Not Found";
	}
	
	return temp;
}


// Q2.1
vector<Examinee> GetTopHighestMath(vector<Examinee> list_examinee, int k) {
	vector<Examinee> top;

	int i, j, max_pos;
	int n = list_examinee.size();

	for (i = 0; i < k; i++) {
		max_pos = i;

		for (j = i + 1; j < k; j++) {
			if (list_examinee[j].math > list_examinee[max_pos].math) {
				max_pos = j;
			}
		}

		swap(list_examinee[max_pos], list_examinee[i]);
		top.push_back(list_examinee[i]);
	}

	return top;
}

// Q2.2
vector<Examinee> MergeTwoList(vector<Examinee> list1, vector<Examinee> list2) {
	vector<Examinee> two_list;

	int i, j, k;

	int n1 = list1.size(),
		n2 = list2.size();

	i = 0;
	j = 0;
	
	while (i < n1 && j < n2) {
		if (list1[i].math > list2[j].math) {
			two_list.push_back(list1[i]);
			i++;
		}
		else {
			two_list.push_back(list2[j]);
			j++;
		}
	}

	while (i < n1) {
		two_list.push_back(list1[i]);
		i++;
	}

	while (j < n2) {
		two_list.push_back(list2[j]);
		j++;
	}
	
	return two_list;
}


