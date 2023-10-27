#include "DataBase.h"
#include <fstream>
#include <iostream>
#include <iomanip>


using namespace nlohmann;


nlohmann::json DataBase::fill_node(Student& student, json node)
{
	node["id"] = student.id;
	node["name"] = student.name.c_str();
	node["surname"] = student.surname.c_str();
	node["patronymic"] = student.patronymic.c_str();
	node["age"] = student.age;
	node["group"] = student.group.c_str();
	node["course"] = student.course;
	node["scholarship"] = student.scholarship;

	return node;
}

DataBase::DataBase()
{
	this->pushBack_Student(Student());
}

DataBase::DataBase(const Student& student)
{
	this->pushBack_Student(student);
}

DataBase::DataBase(Student* students, const size_t& SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		this->pushBack_Student(students[i]);
	}
}

DataBase::DataBase(const std::string& path)
{
	std::ifstream writeIn(path);
	writeIn >> this->students;
}

DataBase::DataBase(const DataBase& db)
{
	this->students = db.students;
}

void DataBase::clearDb()
{
	this->students.clear();
}

void DataBase::saveDb(const std::string& path) const
{
	json node = this->students;

	std::ofstream saveFile(path);
	saveFile << std::setw(4) << node << std::endl;
}

std::vector<Student> DataBase::getEntireDb() const
{
	std::vector<Student> vector;

	for (json& node : json(this->students))
	{
		vector.push_back(
			Student(
				node["id"],
				node["name"],
				node["surname"],
				node["patronymic"],
				node["age"],
				node["group"],
				node["course"],
				node["scholarship"]
			)
		);
	}

	return vector;
}

bool DataBase::isEmpty() const
{
	return this->students.empty();
}

Student DataBase::getStudent(const int& id) const
{
	int lastId = (this->students.end() - 1).value().at("id");
	if (id < 1 || id > lastId) {
		throw std::string{ "Entered id bigger or lower than it should be!" };
	}
	
	json node = this->students.at(id - 1);

	return Student(
		node["id"],
		node["name"],
		node["surname"],
		node["patronymic"],
		node["age"],
		node["group"],
		node["course"],
		node["scholarship"]
	);
}

void DataBase::eraseStudent(const int& id)
{
	if (id < 1 || id > (this->students.end() - 1).value().at("id")) {
		throw std::string{ "Entered id bigger or lower than it should be!" };
	}
	
	this->students.erase(size_t(id - 1));
	for (size_t i = size_t(id - 1); i < this->students.size(); i++)
	{
		this->students.at(i)["id"] = i + 1;
	}
}

void DataBase::updateStudent(const int& id, Student& student)
{
	if (id < 1 || id > (this->students.end() - 1).value().at("id")) {
		throw std::string{ "Entered id bigger or lower than it should be!" };
	}

	student.id = id;
	
	this->students.at(size_t(id - 1)) = this->fill_node(student, this->students.at(id - 1));
}

void DataBase::pushBack_Student(Student student)
{
	size_t id = this->students.size();
	student.id = id + 1;

	this->students.emplace_back(this->fill_node(student));
}

void DataBase::operator=(const DataBase& db)
{
	this->students = db.students;
}
