#include "Domain.h"
#include <sstream>
#include <iostream>

using namespace std;

std::ostream& operator<<(std::ostream& os, const Student& obj)
{
	os << obj.id << ',';
	os << obj.username << ',';
	os << obj.name << ',';
	os << obj.group << ',';
	os << obj.grades << ',';
	os << obj.status;

	return os;
}

std::istream& operator>>(std::istream& is, Student& obj)
{
	obj.reset();

	std::string line{};
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() == 0)
		return is;
	
	obj.id = stoi(tokens[0]);
	obj.username = tokens[1];
	obj.group = stoi(tokens[3]);

	string name = tokens[2];
	vector<string> names = tokenize(name, ' ');
	Name n(names[0], names[1]);
	obj.name = n;

	Grades g(stod(tokens[4]), stod(tokens[5]), stod(tokens[6]));
	Status s(tokens[7], tokens[8], tokens[9]);

	obj.grades = g;
	obj.status = s;

	/*
	obj.username = tokens[0];
	obj.id = stoi(tokens[0].substr(4, 4));

	string grade = tokens[1];
	if (grade == "-" || grade == "*")
	{
		Grades g(0, 0, 0);
		Status s("", "exm", "-");
		obj.grades = g;
		obj.status = s;
	}
	else
	{
		if (grade[0] == '*')
		{
			grade.erase(0, 1);
			Status s("", "taxa", "-");
			Grades g(stod(grade), 0, 0);
			obj.grades = g;
			obj.status = s;
		}
		else
		{
			Status s("", "buget", "-");
			Grades g(stod(grade), 0, 0);
			obj.grades = g;
			obj.status = s;
		}
	}

	obj.group = stoi(tokens[2]);

	string name = tokens[3];
	vector<string> names = tokenize(name, ' ');
	Name n(names[0], names[1]);
	obj.name = n;

	obj.setStat1(tokens[4]);
	*/
	return is;
}

std::vector<std::string> tokenize(const std::string& str, char delimiter)
{
	vector <string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}
