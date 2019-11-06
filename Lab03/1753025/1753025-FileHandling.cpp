#include "1753025-Function.h"

//BD1200001,,4.0,5.0,,,,4.25,7.0,7.75,,,2.0,N1,BinhDinh
Examinee readExamineeInfo(string line_info) {
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

	t.id = list_str[0];

	t.math       = atof(list_str[2].c_str());
	t.literature = atof(list_str[3].c_str());
	t.physic     = atof(list_str[4].c_str());
	t.chemistry  = atof(list_str[5].c_str());
	t.biology    = atof(list_str[6].c_str());
	t.history    = atof(list_str[7].c_str());
	t.geography  = atof(list_str[8].c_str());
	t.civic_education  = atof(list_str[9].c_str());
	t.natural_science = t.physic + t.chemistry + t.biology;
	t.social_science  = t.history + t.geography + t.civic_education;
	t.foreign_language= atof(list_str[12].c_str());

	return t;
}	
	
vector<Examinee> readExamineeList(string file) {
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
			
			t = readExamineeInfo(str);
			cout << t.id << endl;

			tempV.push_back(t);
		}
		fin.close();
	}
	//cout << "Read successfully";
	return tempV;
}

void writeSumOfScore(List l, string file) {
	ofstream fout;
	fout.open(file, ios_base::trunc);

	fout << "SBD" << "       ";
	fout << "Tong diem" << "\n";

	for (int i = 0; i < l.CLC.size(); i++) {
		fout << l.CLC[i].id << " ";

		//l.CLC[i].natural_science =  l.CLC[i].physic + l.CLC[i].chemistry + l.CLC[i].biology;

		//l.CLC[i].social_science = l.CLC[i].history + l.CLC[i].geography + l.CLC[i].civic_education;
		
		float sum = l.CLC[i].math + l.CLC[i].literature + l.CLC[i].natural_science +
					l.CLC[i].social_science + l.CLC[i].foreign_language;

		fout << sum << "\n";
	}
	
	fout.close();
}