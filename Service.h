#pragma once

#include "Repository.h"
#include "Domain.h"

class Service
{
private:
	Repository<Student> students;

public:
	Service(Repository<Student>& repo) : students(repo) {}

	std::vector<Student> getStudents() { return students.getAll(); }
	std::vector<Student> sortByGrade(int year)
	{
		std::vector<Student> students = this->getStudents();
		switch (year)
		{
		case 1:
			std::sort(students.begin(), students.end(), [](Student& s1, Student& s2) {
				return s1.getGrades().get1() > s2.getGrades().get1();
				});
		case 2:
			std::sort(students.begin(), students.end(), [](Student& s1, Student& s2) {
				return s1.getGrades().get2() > s2.getGrades().get2();
				});
		case 3:
			std::sort(students.begin(), students.end(), [](Student& s1, Student& s2) {
				return s1.getGrades().get3() > s2.getGrades().get3();
				});
		}
		return students;
	}

	std::vector<Student> sortForGroup(std::vector<Student> initial)
	{
		std::sort(initial.begin(), initial.end(), [](Student& s1, Student& s2) {
			return s1.getGrades().get1() > s2.getGrades().get1();
			});
		return initial;
	}

	
	std::vector<Student> filterByGroup(int gr)
	{
		std::vector<Student> students = this->getStudents();
		std::vector<Student> filtered;

		for(auto s : students)
			if (s.getGroup() == gr)
			{
				filtered.push_back(s);
			}
		return filtered;
	}
};