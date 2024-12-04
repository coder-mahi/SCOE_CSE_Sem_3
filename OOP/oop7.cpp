// Hospital Management System
#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Doctor : public Person {
    string specialization;

public:
    Doctor(string n, int a, string s) : Person(n, a), specialization(s) {}
    void display() const override {
        Person::display();
        cout << "Specialization: " << specialization << endl;
    }
};

class Nurse : public Person {
    int experience;

public:
    Nurse(string n, int a, int e) : Person(n, a), experience(e) {}
    void display() const override {
        Person::display();
        cout << "Experience: " << experience << " years" << endl;
    }
};

class AdminStaff : public Person {
    string department;

public:
    AdminStaff(string n, int a, string d) : Person(n, a), department(d) {}
    void display() const override {
        Person::display();
        cout << "Department: " << department << endl;
    }
};

int main() {
    Doctor doc("Dr. Smith", 45, "Cardiology");
    Nurse nur("Nancy", 30, 8);
    AdminStaff admin("John", 35, "HR");

    cout << "Doctor Details:\n";
    doc.display();

    cout << "\nNurse Details:\n";
    nur.display();

    cout << "\nAdministrative Staff Details:\n";
    admin.display();

    return 0;
}
