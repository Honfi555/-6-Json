#include <iostream>
#include <Windows.h>
#include "DataBase.h"
#include "table_functions.h"
#include <locale>
#include <fstream>

#define RELEASE
//#define DEBUG
//#define EXAMPLE


int main(int argc, const char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

#ifdef RELEASE

	Student danya(0, "Danya", "Morozov", "Artemovich", 19, "bo921pia", 2, true);
	Student ivan(0, "Ivan", "Ivanov", "Ivanovich", 18, "bo921pia", 1, true);
	Student sasha(0, "Alexandr", "Alexandrov", "Alexandrivich", 19, "bo921pia", 2, true);

	DataBase db(ivan);
	db.pushBack_Student(danya);
	db.pushBack_Student(sasha);

	while (true)
	{
		system("cls");
		print_table(db);

		std::cout << "Выберите: \n";
		std::cout << "1. Добавить нового студента;\n";
		std::cout << "2. Удалить студента;\n";
		std::cout << "3. Обновить данные студента;\n";
		std::cout << "4. Стереть данные БД;\n";
		std::cout << "5. Сохранить БД;\n";
		std::cout << "6. Загрузить БД;\n";
		std::cout << "7. Выйти.\n";
		int action;
		std::cin >> action;

		switch (action)
		{
		case 1:	// add new student
			system("cls");
			db.pushBack_Student(get_data());
			break;

		case 2:	// remove student
			system("cls");

			if (!db.isEmpty())
			{
				int id;
				std::cout << "Введите ID студента: ";
				std::cin >> id;
				std::cout << std::endl;

				db.eraseStudent(id);
			}
			else {
				std::cout << "Для работы добавьте студента." << std::endl;
				system("pause");
			}
			break;

		case 3:	// update student data
			system("cls");

			if (!db.isEmpty())
			{
				int id;
				std::cout << "Введите ID студента: ";
				std::cin >> id;
				std::cout << std::endl;

				db.updateStudent(id, get_data());
			}
			else {
				std::cout << "Для работы добавьте студента." << std::endl;
				system("pause");
			}
			break;

		case 4: // clear DB
			system("cls");
			db.clearDb();
			std::cout << "БД очищена.\n";
			break;

		case 5:	// save DB
		{
			system("cls");
			std::string path;
			std::cout << "Введите путь сохранения или имя файла, без расширения файла: ";
			std::cin >> path;
			db.saveDb(path + ".json");
		}
		break;

		case 6:	// load DB from .xml file
		{
			system("cls");
			std::string path;
			std::cout << "Введите путь к файлу, без расширения файла: ";
			std::cin >> path;
			db = DataBase::DataBase(path + ".json");
		}
		break;

		case 7:	// exit
			return 0;

		default:
			std::cout << "Вы ввели не корректное число\n";
		}
	}

#endif // RELEASE


#ifdef DEBUG

	Student danya(0, "danya", "morozov", "artemovich", 19, "bo921pia", 2, true);
	Student ivan(0, "Иван", "Иванов", "Иванович", 18, "БО911ПИА", 1, true);
	Student sasha(0, "Александр", "Александров", "Александрович", 19, "БО921ПИА", 2, true);

	DataBase db;

	db.pushBack_Student(danya);

	db.saveDb("jsonfile.json");

#endif // DEBUG


#ifdef EXAMPLE

	nlohmann::json file;
	nlohmann::json node;
	node["1"] = 1;
	node["2"] = 2;
	file.emplace_back(node);

	nlohmann::json node2;
	node2["3"] = 3;
	node2["4"] = 4;
	file.emplace_back(node2);
	
	std::cout << file.at(0) << std::endl;
	std::cout << file.at(1) << std::endl;

	std::ofstream o("test.json");
	o << "текст" << std::endl;

	std::cout << file << std::endl;

#endif // EXAMPLE


    return 0;
}
