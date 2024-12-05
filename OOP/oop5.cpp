#include <iostream>
#include <string>
using namespace std;

class Personnel {
private:
    string name;
    string dob;
    string bloodGroup;
    float height;
    float weight;
    string insurancePolicyNo;
    string contactAddress;
    string phoneNumber;
    string drivingLicenseNo;
    static int personnelCount;

public:
    Personnel(string n = "N/A", string d = "N/A", string bg = "N/A", float h = 0, float w = 0,
              string ip = "N/A", string ca = "N/A", string pn = "N/A", string dl = "N/A")
        : name(n), dob(d), bloodGroup(bg), height(h), weight(w),
          insurancePolicyNo(ip), contactAddress(ca), phoneNumber(pn), drivingLicenseNo(dl) {
        personnelCount++;
    }

    Personnel(const Personnel &p) : name(p.name), dob(p.dob), bloodGroup(p.bloodGroup),
                                    height(p.height), weight(p.weight),
                                    insurancePolicyNo(p.insurancePolicyNo),
                                    contactAddress(p.contactAddress),
                                    phoneNumber(p.phoneNumber),
                                    drivingLicenseNo(p.drivingLicenseNo) {
        personnelCount++;
    }

    ~Personnel() {
        personnelCount--;
    }

    static int getPersonnelCount() {
        return personnelCount;
    }

    void displayDetails() const {
        cout << "Name: " << name << "\nDOB: " << dob << "\nBlood Group: " << bloodGroup
             << "\nHeight: " << height << " cm\nWeight: " << weight << " kg"
             << "\nInsurance Policy No.: " << insurancePolicyNo
             << "\nContact Address: " << contactAddress
             << "\nPhone Number: " << phoneNumber
             << "\nDriving License No.: " << drivingLicenseNo << "\n";
    }

    friend class Admin;
};

class Admin {
public:
    void updatePhoneNumber(Personnel &p, const string &newNumber) {
        p.phoneNumber = newNumber;
    }
};

int Personnel::personnelCount = 0;

int main() {
    Personnel *p1 = new Personnel("John Doe", "01/01/1990", "A+", 180, 75,
                                  "IP12345", "123 Elm Street", "555-1234", "DL123456");

    Personnel p2;
    Personnel p3 = *p1;

    cout << "Personnel 1 Details:\n";
    p1->displayDetails();

    cout << "\nPersonnel 2 Details (Default Constructor):\n";
    p2.displayDetails();

    cout << "\nPersonnel 3 Details (Copy Constructor):\n";
    p3.displayDetails();

    Admin admin;
    admin.updatePhoneNumber(*p1, "555-6789");

    cout << "\nPersonnel 1 Details (After Admin Update):\n";
    p1->displayDetails();

    cout << "\nTotal Personnel Count: " << Personnel::getPersonnelCount() << "\n";

    delete p1;

    cout << "\nTotal Personnel Count After Deletion: " << Personnel::getPersonnelCount() << "\n";

    return 0;
}
