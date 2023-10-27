#include "DataBase.h"
#include <fstream>
#include <iostream>
#include <iomanip>


using namespace nlohmann;


nlohmann::json DataBase::fill_node(Student student, json node)
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

nlohmann::json DataBase::fill_node(size_t id, std::string name, std::string surname, std::string patronymic,
	int age, std::string group, int course, bool scholarship, json node)
{
	node["id"] = id;
	node["name"] = name.c_str();
	node["surname"] = surname.c_str();
	node["patronymic"] = patronymic.c_str();
	node["age"] = age;
	node["group"] = group.c_str();
	node["course"] = course;
	node["scholarship"] = scholarship;

	return node;
}

DataBase::DataBase()
{
	this->pushBack_Student(Student());
}

DataBase::DataBase(Student student)
{
	this->pushBack_Student(student);
}

DataBase::DataBase(std::string name, std::string surname, std::string patronymic, 
	int age, std::string group, int course, bool scholarship)
{
	this->pushBack_Student(name, surname, patronymic, age, group, course, scholarship);
}

DataBase::DataBase(Student* students, const size_t SIZE)
{
	for (size_t i = 0; i < SIZE; i++)
	{
		this->pushBack_Student(students[i]);
	}
}

DataBase::DataBase(std::string path)
{
	std::ifstream writeIn(path);
	writeIn >> this->file;
}

DataBase::DataBase(const DataBase& db)
{
	this->file = db.file;
}

void DataBase::clearDb()
{
	this->file.clear();
}

void DataBase::saveDb(std::string path) const
{
	json node = this->file;

	std::ofstream saveFile(path);
	saveFile << std::setw(4) << node << std::endl;
}

std::vector<Student> DataBase::getEntireDb() const
{
	std::vector<Student> vector;

	for (json& node : json(this->file))
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

bool DataBase::isEmpty()
{
	return this->file.empty();
}

Student DataBase::getStudent(int id) const
{
	int lastId = (this->file.end() - 1).value().at("id");
	if (id < 1 || id > lastId) {
		throw std::string{ "Entered id bigger or lower than it should be!" };
	}
	
	json node = this->file.at(id - 1);

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

void DataBase::eraseStudent(int id)
{
	if (id < 1 || id > (this->file.end() - 1).value().at("id")) {
		throw std::string{ "Entered id bigger or lower than it should be!" };
	}
	
	this->file.erase(size_t(id - 1));
	for (size_t i = size_t(id - 1); i < this->file.size(); i++)
	{
		this->file.at(i)["id"] = i + 1;
	}
}

void DataBase::updateStudent(int id, Student student)
{
	if (id < 1 || id > (this->file.end() - 1).value().at("id")) {
		throw std::string{ "Entered id bigger or lower than it should be!" };
	}

	student.id = id;
	
	this->file.at(size_t(id - 1)) = this->fill_node(student, this->file.at(id - 1));
}

void DataBase::pushBack_Student(Student student)
{
	size_t id = this->file.size();
	student.id = id + 1;

	this->file.emplace_back(this->fill_node(student));
}

void DataBase::pushBack_Student(std::string name, std::string surname, std::string patronymic, int age, std::string group, 
	int course, bool scholarship)
{
	size_t id = this->file.count("id");
	id = id + 1;

	this->file.emplace_back(this->fill_node(id, name, surname, patronymic, age, group, course, scholarship));
}

void DataBase::operator=(const DataBase& db)
{
	this->file = db.file;
}
