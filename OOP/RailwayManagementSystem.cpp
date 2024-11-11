#include <iostream>
#include <string>

using namespace std;

struct Passenger {
    string name;
    int age;
    string gender;
    int seatNumber;
};

struct Train {
    int trainNumber;
    string trainName;
    string source;
    string destination;
    int totalSeats;
    int bookedSeats;
    Passenger passengers[100];
};

Train trains[10];
int trainCount = 0;

void addTrain(int trainNumber, string trainName, string source, string destination, int totalSeats) {
    if (trainCount < 10) {
        trains[trainCount].trainNumber = trainNumber;
        trains[trainCount].trainName = trainName;
        trains[trainCount].source = source;
        trains[trainCount].destination = destination;
        trains[trainCount].totalSeats = totalSeats;
        trains[trainCount].bookedSeats = 0;
        trainCount++;
        cout << "Train " << trainName << " added successfully!" << endl;
    } else {
        cout << "Train list is full!" << endl;
    }
}

void displayTrains() {
    cout << "\nAvailable Trains:" << endl;
    for (int i = 0; i < trainCount; i++) {
        cout << "Train Number: " << trains[i].trainNumber
             << ", Name: " << trains[i].trainName
             << ", From: " << trains[i].source
             << ", To: " << trains[i].destination
             << ", Total Seats: " << trains[i].totalSeats
             << ", Booked Seats: " << trains[i].bookedSeats << endl;
    }
}

void bookTicket(int trainNumber, string name, int age, string gender) {
    for (int i = 0; i < trainCount; i++) {
        if (trains[i].trainNumber == trainNumber) {
            if (trains[i].bookedSeats < trains[i].totalSeats) {
                int seatNumber = trains[i].bookedSeats + 1;
                trains[i].passengers[trains[i].bookedSeats] = {name, age, gender, seatNumber};
                trains[i].bookedSeats++;
                cout << "Ticket booked successfully for " << name << " on train " << trains[i].trainName << endl;
            } else {
                cout << "No seats available on this train!" << endl;
            }
            return;
        }
    }
    cout << "Train number " << trainNumber << " not found!" << endl;
}

void viewPassengerList(int trainNumber) {
    for (int i = 0; i < trainCount; i++) {
        if (trains[i].trainNumber == trainNumber) {
            cout << "Passenger List for Train " << trains[i].trainName << ":" << endl;
            for (int j = 0; j < trains[i].bookedSeats; j++) {
                cout << "Name: " << trains[i].passengers[j].name
                     << ", Age: " << trains[i].passengers[j].age
                     << ", Gender: " << trains[i].passengers[j].gender
                     << ", Seat Number: " << trains[i].passengers[j].seatNumber << endl;
            }
            return;
        }
    }
    cout << "Train number " << trainNumber << " not found!" << endl;
}

void showMainMenu() {
    cout << "\n---- Railway Management System ----" << endl;
    cout << "1. Add Train" << endl;
    cout << "2. Display All Trains" << endl;
    cout << "3. Book Ticket" << endl;
    cout << "4. View Passenger List" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    while (true) {
        showMainMenu();
        cin >> choice;

        if (choice == 1) {
            int trainNumber, totalSeats;
            string trainName, source, destination;
            cout << "Enter train number: ";
            cin >> trainNumber;
            cout << "Enter train name: ";
            cin.ignore();
            getline(cin, trainName);
            cout << "Enter source: ";
            getline(cin, source);
            cout << "Enter destination: ";
            getline(cin, destination);
            cout << "Enter total seats: ";
            cin >> totalSeats;
            addTrain(trainNumber, trainName, source, destination, totalSeats);
        } else if (choice == 2) {
            displayTrains();
        } else if (choice == 3) {
            int trainNumber, age;
            string name, gender;
            cout << "Enter train number: ";
            cin >> trainNumber;
            cout << "Enter passenger name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter gender: ";
            cin >> gender;
            bookTicket(trainNumber, name, age, gender);
        } else if (choice == 4) {
            int trainNumber;
            cout << "Enter train number: ";
            cin >> trainNumber;
            viewPassengerList(trainNumber);
        } else if (choice == 5) {
            cout << "Exiting the program. Thank you!" << endl;
            break;
        } else {
            cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}
