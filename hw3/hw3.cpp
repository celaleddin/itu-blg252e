/***************************************
Student Number : 040130332
Student Name   : Celaleddin Hidayetoglu
Course         : BLG252E
CRN            : 11922
Term           : 2016-Fall
Homework       : #3
***************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;


template <typename T> void Print_Grades(map<T, int> grades);

class Student {
    private:
        string fname;
        string lname;

        map<string, int> grades;

    public:
        int id_number;

        Student(int id_number, string fname, string lname);
        void add_grade(string course_code, int points);
        void print();
};


class Course {
    private:
        map<int, int> grades;

    public:
        string course_code;

        Course(string course_code);
        void add_grade(int id_number, int points);
        void print();
};


Student::Student(int id_number, string fname, string lname) {
    this->id_number = id_number;
    this->fname = fname;
    this->lname = lname;
}

void Student::add_grade(string course_code, int points) {
    grades[course_code] = points;
}

void Student::print() {
    cout << "Student: " << id_number << " " << fname << " " << lname << '\n';
    cout << "Grades: " << '\n';
    Print_Grades(grades);
}


Course::Course(string course_code) {
    this->course_code = course_code;
}

void Course::add_grade(int id_number, int points) {
    grades[id_number] = points;
}

void Course::print() {
    cout << "Course Code: " << course_code << '\n';
    cout << "Grades: " << '\n';
    Print_Grades(grades);
}


template <typename T> void Print_Grades(map<T, int> grades) {
    typename map<T, int>::iterator it = grades.begin();
    int total_points = 0;

    while (it != grades.end()) {
        cout << '\t' << it->first << '\t' << it->second << '\n';

        total_points += it->second;

        it++;
    }

    cout << "Average: " << (float)total_points / grades.size() << '\n';
    cout << "----------------------------------------" << '\n';
}


int main(void) {
    vector<Student> students;
    vector<Course> courses;

    ifstream input("data.txt");

    // data into objects and vectors
    for (string line; getline(input, line); ) {
        int id, point;
        string name, surname, code;
        stringstream ss(line);

        ss >> id;
        ss >> name;
        ss >> surname;
        ss >> code;
        ss >> point;

        // look for a possible same student in the students vector
        int position = 0;
        bool found = false;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].id_number == id) {
                found = true;
                position = i;

                break;
            }
        }

        if (!found) {
            Student student(id, name, surname);

            student.add_grade(code, point);
            students.push_back(student);
        } else {  // current student not found in students vector
            students[position].add_grade(code, point);
        }


        // look for a possible same course in the courses vector
        position = 0;
        found = false;

        for (int i = 0; i < courses.size(); i++) {
            if (courses[i].course_code == code) {
                found = true;
                position = i;

                break;
            }
        }

        if (!found) {
            Course course(code);

            course.add_grade(id, point);
            courses.push_back(course);
        } else {  // current course not found in courses vector
            courses[position].add_grade(id, point);
        }
    }


    cout << "PHASE 1: Printing by Students" << "\n\n";
    for (int i = 0; i < students.size(); i++) {
        students[i].print();
    }

    cout << "\n\n";

    cout << "PHASE 2: Printing by Courses" << "\n\n";
    for (int i = 0; i < courses.size(); i++) {
        courses[i].print();
    }

    return 0;
}

