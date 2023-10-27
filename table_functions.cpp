#include "table_functions.h"
#include <iostream>
#include <vector>
#include <iomanip>


void head() {
    std::cout 
        << " -----------------------------------------------------------------------------------------------------\n"
        << "|                                         База Данных Студентов                                       |\n"
        << " -----------------------------------------------------------------------------------------------------\n"
        << "|  ID  |       Имя       |     Фамилия     |    Отчество    | Возраст |   Группа   | Курс | Стипендия |\n"
        << " -----------------------------------------------------------------------------------------------------\n";
}

void line() {
    std::cout << " -----------------------------------------------------------------------------------------------------\n";
}

void print_table(const DataBase& db)
{
    std::vector<Student> students = db.getEntireDb();
    head();
    for (Student student : students)
    {
        std::cout << "| " 
            << std::setw(4) << student.id << " | " 
            << std::setw(15) << student.name << " | " 
            << std::setw(15) << student.surname << " | " 
            << std::setw(14) << student.patronymic << " | " 
            << std::setw(7) << student.age << " | "
            << std::setw(10) << student.group << " | "
            << std::setw(4) << student.course << " | "
            << std::setw(9) << student.scholarship << " | "
            << std::endl;
        line();
    }
}

Student& get_data()
{
    Student student;

    std::cout << "Введите имя: ";
    std::cin >> student.name;

    std::cout << "Введите фамилию: ";
    std::cin >> student.surname;

    std::cout << "Введите отчество: ";
    std::cin >> student.patronymic;

    std::cout << "Введите возраст: ";
    std::cin >> student.age;

    std::cout << "Введите группу: ";
    std::cin >> student.group;

    std::cout << "Введите курс: ";
    std::cin >> student.course;
    
    std::cout << "Введите наличие стипендии(1/0): ";
    std::cin >> student.scholarship;

    return student;
}