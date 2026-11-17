#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Student
{
    string name;
    int marks;
};

int main()
{
    vector<Student> students =
    {
        {"Tara", 85},
        {"Amtul", 87},
        {"Sneha", 64},
        {"Riya", 78}
    };

    // Display original data
    cout << "Student Marks:\n";

    for (auto s : students)
        cout << s.name << " : " << s.marks << endl;

    // sort() - sort students according to marks
    sort(students.begin(), students.end(),
         [](Student a, Student b)
         {
             return a.marks > b.marks;
         });

    cout << "\nSorted by Marks:\n";

    for (auto s : students)
        cout << s.name << " : " << s.marks << endl;

    // find_if() - find first student having marks above 80
    auto result = find_if(students.begin(), students.end(),
                          [](Student s)
                          {
                              return s.marks > 80;
                          });

    if (result != students.end())
    {
        cout << "\nFirst student with marks above 80: "
             << result->name << endl;
    }

    // transform() - add 5 grace marks
    vector<int> marks;

    for (auto s : students)
        marks.push_back(s.marks);

    transform(marks.begin(), marks.end(), marks.begin(),
              [](int m)
              {
                  return m + 5;
              });

    cout << "\nMarks after adding 5 grace marks:\n";

    for (int m : marks)
        cout << m << " ";

    cout << endl;

    return 0;
}
