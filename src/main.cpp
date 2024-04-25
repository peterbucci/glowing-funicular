/**
 * @title: Topic 13 - Lab 1 - Maps!
 * @date: 04/25/2024
 * @description: This program demonstrates the use of maps, pairs, and iterators to store
 * and manipulate student data.
 */
#include <iostream> // For cout and cin
#include <vector>   // For vector
#include <string>   // For string
#include <utility>  // For pair
#include <map>      // For map
#include "Student.h"

using namespace std; // Using the standard namespace

// Student data
const vector<pair<string, string>> STUDENTS = {
    {"Alice Smith", "S101"},
    {"Josephine Lyons", "S102"},
    {"Abdur Downs", "S103"},
    {"Dave Moore", "S104"},
    {"Eva Jordan", "S105"},
    {"Isobella Horton", "S106"},
    {"Grace Hall", "S107"},
    {"Blanche Zimmerman", "S108"},
    {"Ivy Black", "S109"},
    {"Calvin Benson", "S110"}};

// Map to store student data
map<string, Student> studentMap;

// Function prototypes
void printStudentMap();
void changeStudentName(string id, string name);
void changeStudentId(string id, string newId);

int main()
{
    /*
     * Initialize studentMap with student data using the STUDENTS vector
     * The key is the student id and the value is the Student object
     */
    for (vector<pair<string, string>>::const_iterator it = STUDENTS.begin(); it != STUDENTS.end(); ++it)
    {
        studentMap[it->second] = Student(it->first, it->second);
    }

    // Print the initial student list
    cout << "Initial student list: " << endl;
    printStudentMap();

    // Change student name and print the updated student information
    cout << endl
         << "Changing the following student's name from: " << endl;
    cout << studentMap["S101"].toString() << endl;
    cout << "to: " << endl;
    changeStudentName("S101", "Alice Brown");
    cout << studentMap["S101"].toString() << endl;

    // Change student id and print the updated student information
    cout << endl
         << "Changing the following student's id from: " << endl;
    cout << studentMap["S101"].toString() << endl;
    cout << "to: " << endl;
    changeStudentId("S101", "S111");
    cout << studentMap["S111"].toString() << endl;

    // Print the final student list
    cout << endl
         << "Final student list: " << endl;
    printStudentMap();

    return 0;
}

/**
 * Print the student map
 * Iterate through the student map and print each student's information
 */
void printStudentMap()
{
    for (map<string, Student>::iterator it = studentMap.begin(); it != studentMap.end(); ++it)
    {
        cout << it->second.toString() << endl; // Print student information
    }
}

/**
 * Change the name of a student with the given id
 * @param id The id of the student to change
 * @param name The new name of the student
 */
void changeStudentName(string id, string name)
{
    studentMap[id].setName(name); // Update the student's name
}

/**
 * Change the id of a student with the given id
 * The student is removed from the map and then reinserted with the new id
 * @param id The id of the student to change
 * @param newId The new id of the student
 */
void changeStudentId(string id, string newId)
{
    studentMap[newId] = studentMap[id]; // Insert the student with the new id
    studentMap.erase(id);               // Remove the student with the old id

    studentMap[newId].setId(newId); // Update the student's id
}