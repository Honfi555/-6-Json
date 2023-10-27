#pragma once
#include <string>


struct Student {
	size_t id = 0;
	std::string name = "";
	std::string surname = "";
	std::string patronymic = "";
	int age = 0;
	std::string group = "";
	int course = 0;
	bool scholarship = false;

	Student() {};
	Student(size_t id,
		std::string name,
		std::string surname,
		std::string patronymic,
		int age,
		std::string group,
		int course,
		bool scholarship) :
		id(id), name(name),
		surname(surname),
		patronymic(patronymic),
		age(age),
		group(group),
		course(course),
		scholarship(scholarship)
	{}
};
