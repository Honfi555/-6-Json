#pragma once
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "Student.h"


class DataBase
{
public:
	DataBase();
	DataBase(const Student&);

	DataBase(Student*, const size_t&);
	DataBase(const std::string&);
	DataBase(const DataBase&);

	void clearDb();
	void saveDb(const std::string&) const;
	std::vector<Student> getEntireDb() const;

	bool isEmpty() const;

	Student getStudent(const int&) const;
	void eraseStudent(const int&);
	void updateStudent(const int&, Student&);
	void pushBack_Student(Student);

	void operator = (const DataBase&);

private:
	nlohmann::json fill_node(Student&, nlohmann::json=nlohmann::json());

private:
	nlohmann::json students;
};
