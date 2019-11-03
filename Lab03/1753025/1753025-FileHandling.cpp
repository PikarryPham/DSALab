#include "1753025-Function.h"

Examinee readExamineeInfo(string line_info) {
	Examinee t;
	int count = 2;

	ifstream fin;
	fin.open("data.txt", ios_base::in);

	if (fin.fail()) {
		cout << "File doest exist!" << endl;
		return t;
	}
	else {
		string temp;
		string::size_type sz;

		//get the first line
		string str;
		getline(fin, str);

		while (!fin.eof()) {
			//cout << "Reading";
			
			
				getline(fin, t.id, ',');
				getline(fin, temp, ',');

				getline(fin, temp, ',');
				if (temp == "")
					t.math = 0;
				else
					t.math = std::stof(temp, &sz);

				getline(fin, temp, ',');
				if (temp == "")
					t.literature = 0;
				else
					t.literature = std::stof(temp, &sz);

				getline(fin, temp, ',');
				if (temp == "")
					t.physic = 0;
				else
					t.physic = std::stof(temp, &sz);

				getline(fin, temp, ',');
				if (temp == "")
					t.chemistry = 0;
				else
					t.chemistry = std::stof(temp, &sz);

				getline(fin, temp, ',');
				if (temp == "")
					t.biology = 0;
				else
					t.biology = std::stof(temp, &sz);

				getline(fin, temp, ',');
				if (temp == "")
					t.history = 0;
				else
					t.history = std::stof(temp, &sz);

				getline(fin, temp, ',');
				if (temp == "")
					t.geography = 0;
				else
					t.geography = std::stof(temp, &sz);

				getline(fin, temp, ',');
				if (temp == "")
					t.civic_education = 0;
				else
					t.civic_education = std::stof(temp, &sz);

				getline(fin, temp, ',');
				if (temp == "")
					t.natural_science = 0;
				else
					t.natural_science = std::stof(temp, &sz);

				getline(fin, temp, ',');
				if (temp == "")
					t.social_science = 0;
				else
					t.social_science = std::stof(temp, &sz);

				getline(fin, temp, ',');
				if (temp == "")
					t.foreign_language = 0;
				else
					t.foreign_language = std::stof(temp, &sz);

				getline(fin, temp, ',');

				getline(fin, temp, '\n');

				if (line_info == to_string(count)) {
					break;
				}
				else
					count += 1;
				
		}
		fin.close();
	}

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
			//cout << "Reading";
			getline(fin, t.id, ',');
			getline(fin, temp, ',');
			
			getline(fin, temp, ',');
			if (temp == "")
				t.math = 0;
			else
				t.math = std::stof(temp, &sz);

			getline(fin, temp, ',');
			if (temp == "")
				t.literature = 0;
			else
				t.literature = std::stof(temp, &sz);

			getline(fin, temp, ',');
			if (temp == "")
				t.physic = 0;
			else
				t.physic = std::stof(temp, &sz);

			getline(fin, temp, ',');
			if (temp == "")
				t.chemistry = 0;
			else
				t.chemistry = std::stof(temp, &sz);

			getline(fin, temp, ',');
			if (temp == "")
				t.biology = 0;
			else
				t.biology = std::stof(temp, &sz);

			getline(fin, temp, ',');
			if (temp == "")
				t.history = 0;
			else
				t.history = std::stof(temp, &sz);

			getline(fin, temp, ',');
			if (temp == "")
				t.geography = 0;
			else
				t.geography = std::stof(temp, &sz);

			getline(fin, temp, ',');
			if (temp == "")
				t.civic_education = 0;
			else
				t.civic_education = std::stof(temp, &sz);

			getline(fin, temp, ',');
			if (temp == "")
				t.natural_science = 0;
			else
				t.natural_science = std::stof(temp, &sz);

			getline(fin, temp, ',');
			if (temp == "")
				t.social_science = 0;
			else
				t.social_science = std::stof(temp, &sz);

			getline(fin, temp, ',');
			if (temp == "")
				t.foreign_language = 0;
			else
				t.foreign_language = std::stof(temp, &sz);

			getline(fin, temp, ',');

			getline(fin, temp, '\n');

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

		l.CLC[i].natural_science =  l.CLC[i].physic + l.CLC[i].chemistry + l.CLC[i].biology;

		l.CLC[i].social_science = l.CLC[i].history + l.CLC[i].geography + l.CLC[i].civic_education;
		
		float sum = l.CLC[i].math + l.CLC[i].literature + l.CLC[i].natural_science +
					l.CLC[i].social_science + l.CLC[i].foreign_language;

		fout << sum << "\n";
	}
	
	fout.close();
}