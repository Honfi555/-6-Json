#pragma once


struct Student {
	size_t id;
	std::string name;
	std::string surname;
	std::string patronymic;
	int age;
	std::string group;
	int course;
	bool scholarship;

	Student(const size_t& id=0,
		const std::string& name="-",
		const std::string& surname="-",
		const std::string& patronymic="-",
		const int& age=0,
		const std::string& group="-",
		const int& course=0,
		const bool& scholarship=false) :
		id(id), name(name),
		surname(surname),
		patronymic(patronymic),
		age(age),
		group(group),
		course(course),
		scholarship(scholarship)
	{}
};
