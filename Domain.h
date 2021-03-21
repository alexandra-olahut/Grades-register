#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Grades
{
private:
	float year1 = 0;
	float year2 = 0;
	float year3 = 0;

public:
	Grades() {}
	Grades(float y1, float y2, float y3) : year1(y1), year2(y2), year3(y3) {}

	float get1() { return year1; }
	float get2() { return year2; }
	float get3() { return year3; }

	void set1(float grade) { year1 = grade; }
	void set2(float grade) { year2 = grade; }
	void set3(float grade) { year3 = grade; }

	void reset() { year1 = 0; year2 = 0; year3 = 0; }

	friend std::ostream& operator<<(std::ostream& os, const Grades& obj)
	{
		os << obj.year1 << ',' << obj.year2 << ',' << obj.year3;
		return os;
	}
};

class Status
// buget/taxa
{
private:
	std::string year1 = "";
	std::string year2 = "";
	std::string year3 = "";

public:
	Status() {}
	Status(std::string y1, std::string y2, std::string y3) : year1(y1), year2(y2), year3(y3) {}

	std::string get1() { return year1; }
	std::string get2() { return year2; }
	std::string get3() { return year3; }

	void set1(std::string stat) { year1 = stat; }
	void set2(std::string stat) { year2 = stat; }
	void set3(std::string stat) { year3 = stat; }

	void reset() { year1 = ""; year2 = ""; year3 = ""; }

	friend std::ostream& operator<<(std::ostream& os, const Status& obj)
	{
		os << obj.year1 << ',' << obj.year2 << ',' << obj.year3;
		return os;
	}
};

class Name
{
private:
	std::string first = "";
	std::string last = "";

public:
	Name() {}
	Name(std::string f, std::string l) : first(f), last(l) {}

	std::string getFirst() { return first; }
	std::string getLast() { return last; }
	void setFirst(std::string n) { first = n; }
	void setLast(std::string n) { last = n; }

	std::string toString() { return first + " " + last; }

	void reset() { first = ""; last = ""; }

	friend std::ostream& operator<<(std::ostream& os, const Name& obj)
	{
		os << obj.first << ' ' << obj.last;
		return os;
	}
};



class Student
{
private:
	Name name;
	std::string username;
	int id = 0;
	int group = 0;
	Grades grades;
	Status status;

public:
	Student() {}
	Student(std::string f, std::string l, std::string u, int id, int gr, Grades g, Status s) : name(f, l), username(u), id(id), group(gr), grades(g), status(s) {}
	Student(std::string f, std::string l, std::string u, int id, int gr) : name(f, l), username(u), id(id), group(gr) {}
	Student(Name n, std::string u, int id, int gr) : name(n), username(u), id(id), group(gr) {}

	Name getName() { return name; }
	std::string getUser() { return username; }
	int getId() { return id; }
	int getGroup() { return group; }
	Grades getGrades() { return grades; }
	Status getStatus() { return status; }

	void setName(Name n) { name = n; }
	void setUser(std::string u) { username = u; }
	void setId(int i) { id = i; }
	void setGroup(int gr) { group = gr; }
	void setGrades(Grades g) { grades = g; }
	void setStatus(Status s) { status = s; }

	void setGrade1(float g) { grades.set1(g); }
	void setGrade2(float g) { grades.set2(g); }
	void setGrade3(float g) { grades.set3(g); }
	void setStat1(std::string s) { status.set1(s); }
	void setStat2(std::string s) { status.set2(s); }
	void setStat3(std::string s) { status.set3(s); }


	void reset() { name.reset(); username = ""; id = 0; group = 0; grades.reset(); status.reset(); }

	friend std::ostream& operator<<(std::ostream& os, const Student& obj);
	friend std::istream& operator>>(std::istream& is, Student& obj);

};

std::vector<std::string> tokenize(const std::string& str, char delimiter);
