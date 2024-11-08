#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Structure to represent a student record
struct Student {
    string name;
    int rollNumber;
    string course;
};

// Function to add a new student record
void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter student name: ";
    getline(cin >> ws, newStudent.name); 
    cout << "Enter roll number: ";
    cin >> newStudent.rollNumber;
    cout << "Enter course: ";
    getline(cin >> ws, newStudent.course); 
    students.push_back(newStudent);
    cout << "Student added successfully!\n";
}

// Function to display a student record
void displayStudent(const Student& student) {
    cout << "Name: " << student.name << endl;
    cout << "Roll Number: " << student.rollNumber << endl;
    cout << "Course: " << student.course << endl;
}

// Function to search for a student by roll number
void searchStudent(const vector<Student>& students) {
    int rollNumber;
    cout << "Enter roll number to search: ";
    cin >> rollNumber;
    // Corrected line: removed the & from [&rollNumber]
    auto it = find_if(students.begin(), students.end(),
                      [rollNumber](const Student& s) { return s.rollNumber == rollNumber; }); 
    if (it != students.end()) {
        displayStudent(*it);
    } else {
        cout << "Student not found.\n";
    }
}

// Function to display all student records
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students in the database.\n";
        return;
    }
    for (const auto& student : students) {
        displayStudent(student);
        cout << "--------------------\n";
    }
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\nStudent Database Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Display All Students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                searchStudent(students);
                break;
            case 3:
                displayAllStudents(students);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
