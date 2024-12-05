// 6. Student Master Table
#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 
using namespace std;

class Student {
protected:
    string name;
    int rollNo;
    string subject;

public:
    Student(string n, int r, string s) : name(n), rollNo(r), subject(s) {}
    virtual void displayHeader() const {
        cout << setw(10) << left << "Name"
             << setw(10) << "Roll No"
             << setw(15) << "Subject";
    }
    virtual void display() const {
        cout << setw(10) << left << name
             << setw(10) << rollNo
             << setw(15) << subject;
    }
    virtual ~Student() = default;
};

class Marks : public Student {
    string subjectCode;
    int internalAssessment, universityExam;

public:
    Marks(string n, int r, string s, string sc, int ia, int ue)
        : Student(n, r, s), subjectCode(sc), internalAssessment(ia), universityExam(ue) {}

    void displayHeader() const override {
        Student::displayHeader();
        cout << setw(15) << "Subject Code"
             << setw(10) << "Internal"
             << setw(10) << "Exam" << endl;
        cout << string(70, '-') << endl; 
    }

    void display() const override {
        Student::display();
        cout << setw(15) << subjectCode
             << setw(10) << internalAssessment
             << setw(10) << universityExam << endl;
    }
};

int main() {
    vector<Student *> students;
    students.push_back(new Marks("Alice", 1, "Physics", "PH101", 40, 60));
    students.push_back(new Marks("Bob", 2, "Chemistry", "CH102", 35, 50));

    if (!students.empty()) {
        students[0]->displayHeader();
    }

    for (const auto &student : students) {
        student->display();
        delete student; 
    }

    return 0;
}
