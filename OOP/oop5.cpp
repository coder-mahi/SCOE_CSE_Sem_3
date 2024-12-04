#include <iostream>
#include <string>
using namespace std;

class Personnel {
    string name, dob, bloodGroup, contactAddress;
    float height, weight;
    int insurancePolicyNo, telephoneNo, drivingLicenseNo;

public:
    Personnel() : name(""), dob(""), bloodGroup(""), height(0), weight(0),
                  insurancePolicyNo(0), telephoneNo(0), drivingLicenseNo(0) {}

    Personnel(string n, string d, string b, float h, float w, int ip, int t, int dl)
        : name(n), dob(d), bloodGroup(b), height(h), weight(w),
          insurancePolicyNo(ip), telephoneNo(t), drivingLicenseNo(dl) {}

    // Copy Constructor
    Personnel(const Personnel &p) {
        name = p.name;
        dob = p.dob;
        bloodGroup = p.bloodGroup;
        height = p.height;
        weight = p.weight;
        insurancePolicyNo = p.insurancePolicyNo;
        telephoneNo = p.telephoneNo;
        drivingLicenseNo = p.drivingLicenseNo;
    }

    // Destructor
    ~Personnel() { cout << "Object destroyed" << endl; }

    // Inline Function
    void display() const {
        cout << "Name: " << name << "\nDOB: " << dob << "\nBlood Group: " << bloodGroup
             << "\nHeight: " << height << "\nWeight: " << weight
             << "\nInsurance Policy No: " << insurancePolicyNo
             << "\nTelephone No: " << telephoneNo
             << "\nDriving License No: " << drivingLicenseNo << endl;
    }

    // Dynamic Memory Allocation
    void *operator new(size_t size) {
        void *p = ::operator new(size);
        cout << "Memory allocated using new\n";
        return p;
    }

    void operator delete(void *p) {
        ::operator delete(p);
        cout << "Memory deallocated using delete\n";
    }
};

int main() {
    Personnel *p1 = new Personnel("John Doe", "01-01-1990", "O+", 5.9, 70.5, 12345, 9876543210, 55555);
    p1->display();
    delete p1;

    return 0;
}
