#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Student
{
public:
    int rollNo;
    string name;
    float marks;
    void input()
    {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }
   void display()
    {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
    }
};
int main()
{
    Student s;
    // Writing student record to CSV file
    fstream file("students.csv", ios::in | ios::out | ios::app);
    if (!file)
    {
        cout << "File could not be opened.";
        return 0;
    }
    cout << "Enter Student Details\n";
    s.input();
    file << s.rollNo << "," << s.name << "," << s.marks << endl;
    cout << "\nCurrent write position: " << file.tellp() << endl;
    file.close();
    // Reading student records
    file.open("students.csv", ios::in);
    if (!file)
    {
        cout << "File could not be opened.";
        return 0;
    }
    cout << "\nStudent Records:\n";
    string line;
    cout << "Starting read position: " << file.tellg() << endl;
    file.seekg(0, ios::beg);
    cout << "After seekg position: " << file.tellg() << endl;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    cout << "\nFinal read position: " << file.tellg() << endl;
    file.close();
    // Demonstrating seekp()
    file.open("students.csv", ios::in | ios::out);
    file.seekp(0, ios::end);
    cout << "\nCurrent write pointer: " << file.tellp() << endl;
    file.seekp(0, ios::beg);
    cout << "After seekp position: " << file.tellp() << endl;
    file.close();
    return 0;
}
