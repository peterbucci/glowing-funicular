/**
 * @file Student.h
 * @brief This file contains the declaration of the Student class
 */
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    Student();
    Student(string name, string id);
    void setName(string name);
    void setId(string id);
    string getName();
    string getId();
    string toString();

private:
    string name;
    string id;
};

#endif