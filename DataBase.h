#pragma once
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
#include "Student.h"


class DataBase
{
public:
	DataBase();
	DataBase(Student student);
	DataBase(
		std::string name,
		std::string surname,
		std::string patronymic,
		int age,
		std::string group,
		int course,
		bool scholarship
	);
	DataBase(Student* students, const size_t SIZE);
	DataBase(std::string path);
	DataBase(const DataBase&);

	void clearDb();
	void saveDb(std::string path) const;
	std::vector<Student> getEntireDb() const;

	bool isEmpty();

	Student getStudent(int id) const;
	void eraseStudent(int id);
	void updateStudent(int id, Student student);
	void pushBack_Student(Student student);
	void pushBack_Student(
		std::string name,
		std::string surname,
		std::string patronymic,
		int age,
		std::string group,
		int course,
		bool scholarship
	);

	void operator = (const DataBase&);

private:
	nlohmann::json fill_node(Student student, nlohmann::json node = nlohmann::json());
	nlohmann::json fill_node(
		size_t id,
		std::string name,
		std::string surname,
		std::string patronymic,
		int age,
		std::string group,
		int course,
		bool scholarship,
		nlohmann::json node = nlohmann::json()
	);


private:
	nlohmann::json file;
};
