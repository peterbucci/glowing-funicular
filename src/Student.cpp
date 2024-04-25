/**
 * @file Student.cpp
 * @brief This file contains the implementation of the Student class
 */
#include "Student.h"

Student::Student()
{
    name = "";
    id = "";
}

Student::Student(string name, string id)
{
    this->name = name;
    this->id = id;
}

void Student::setName(string name)
{
    this->name = name;
}

void Student::setId(string id)
{
    this->id = id;
}

string Student::getName()
{
    return name;
}

string Student::getId()
{
    return id;
}

string Student::toString()
{
    return name + " " + id;
}