#include <iostream>
#include <cstring>

class Personnel {
private:
    std::string name;
    std::string dob;
    std::string bloodGroup;
    float height;
    float weight;
    std::string insurancePolicyNo;
    std::string contactAddress;
    std::string phoneNumber;
    std::string drivingLicenseNo;
    static int personnelCount; 

public:
    Personnel(std::string n, std::string d, std::string bg, float h, float w, 
              std::string ip, std::string ca, std::string pn, std::string dl)
        : name(n), dob(d), bloodGroup(bg), height(h), weight(w),
          insurancePolicyNo(ip), contactAddress(ca), phoneNumber(pn),
          drivingLicenseNo(dl) {
        personnelCount++;
    }

    Personnel() : name("N/A"), dob("N/A"), bloodGroup("N/A"), height(0), weight(0),
                  insurancePolicyNo("N/A"), contactAddress("N/A"),
                  phoneNumber("N/A"), drivingLicenseNo("N/A") {
        personnelCount++;
    }

    Personnel(const Personnel &p) {
        name = p.name;
        dob = p.dob;
        bloodGroup = p.bloodGroup;
        height = p.height;
        weight = p.weight;
        insurancePolicyNo = p.insurancePolicyNo;
        contactAddress = p.contactAddress;
        phoneNumber = p.phoneNumber;
        drivingLicenseNo = p.drivingLicenseNo;
        personnelCount++;
    }

    ~Personnel() {
        personnelCount--;
    }

    static int getPersonnelCount() {
        return personnelCount;
    }

    inline void displayDetails() const {
        std::cout << "Name: " << name << "\nDOB: " << dob << "\nBlood Group: " << bloodGroup
                  << "\nHeight: " << height << " cm\nWeight: " << weight << " kg"
                  << "\nInsurance Policy No.: " << insurancePolicyNo
                  << "\nContact Address: " << contactAddress
                  << "\nPhone Number: " << phoneNumber
                  << "\nDriving License No.: " << drivingLicenseNo << "\n";
    }

    friend class Admin;
};

// Friend class Admin to access private members
class Admin {
public:
    void updatePhoneNumber(Personnel &p, const std::string &newNumber) {
        p.phoneNumber = newNumber;
    }
};

// Static member initialization
int Personnel::personnelCount = 0;

int main() {
    // Dynamic memory allocation using new operator
    Personnel *p1 = new Personnel("John Doe", "01/01/1990", "A+", 180, 75,
                                  "IP12345", "123 Elm Street", "555-1234", "DL123456");

    // Using default constructor
    Personnel p2;

    // Copy constructor
    Personnel p3 = *p1;

    // Display details
    std::cout << "Personnel 1 Details:\n";
    p1->displayDetails();
    std::cout << "\nPersonnel 2 Details (Default Constructor):\n";
    p2.displayDetails();
    std::cout << "\nPersonnel 3 Details (Copy Constructor):\n";
    p3.displayDetails();

    // Admin updates phone number
    Admin admin;
    admin.updatePhoneNumber(*p1, "555-6789");
    std::cout << "\nPersonnel 1 Details (After Admin Update):\n";
    p1->displayDetails();

    // Display total personnel count
    std::cout << "\nTotal Personnel Count: " << Personnel::getPersonnelCount() << "\n";

    // Deallocate memory using delete
    delete p1;

    std::cout << "\nTotal Personnel Count After Deletion: " << Personnel::getPersonnelCount() << "\n";

    return 0;
}
