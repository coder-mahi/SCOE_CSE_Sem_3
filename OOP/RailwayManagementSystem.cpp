// MINI PROJECT
#include <iostream>
#include <string>
#include <iomanip>
#include <queue>
#include <stack>

using namespace std;

struct Passenger {
    string name;
    int age;
    string gender;
    int seatNumber;
};

struct WaitlistPassenger {
    string name;
    int age;
    string gender;
};

struct Train {
    int trainNumber;
    string trainName;
    string source;
    string destination;
    int totalSeats;
    int bookedSeats;
    Passenger passengers[100];
    queue<WaitlistPassenger> waitlist;
};

Train trains[10];
int trainCount = 0;
stack<int> recentBookings; 
void displayHeader(const string &title) {
    cout << "\n=====================================\n";
    cout << "       " << title << "\n";
    cout << "=====================================\n";
}

void displayLine() {
    cout << "-------------------------------------\n";
}

void addTrain(int trainNumber, string trainName, string source, string destination, int totalSeats) {
    if (trainCount < 10) {
        trains[trainCount] = {trainNumber, trainName, source, destination, totalSeats, 0};
        trainCount++;
        
        displayHeader("Train Added Successfully");
        cout << "Train: " << trainName << " | Train Number: " << trainNumber << endl;
        displayLine();
    } else {
        cout << "Train list is full!\n";
    }
}

void displayTrains() {
    displayHeader("Available Trains");
    if (trainCount == 0) {
        cout << "No trains available!\n";
        displayLine();
    } else {
        cout << setw(10) << left << "Train No" << setw(15) << "Name" 
             << setw(15) << "From" << setw(15) << "To" << setw(10) << "Seats\n";
        displayLine();
        for (int i = 0; i < trainCount; i++) {
            cout << setw(10) << trains[i].trainNumber
                 << setw(15) << trains[i].trainName
                 << setw(15) << trains[i].source
                 << setw(15) << trains[i].destination
                 << trains[i].bookedSeats << "/" << trains[i].totalSeats << endl;
        }
        displayLine();
    }
}

void checkSeatAvailability(int trainNumber) {
    for (int i = 0; i < trainCount; i++) {
        if (trains[i].trainNumber == trainNumber) {
            displayHeader("Seat Availability");
            cout << "Train: " << trains[i].trainName << endl;
            cout << "Available Seats: " << (trains[i].totalSeats - trains[i].bookedSeats) << endl;
            return;
        }
    }
    cout << "Train number " << trainNumber << " not found!\n";
}

void bookTicket(int trainNumber, string name, int age, string gender) {
    for (int i = 0; i < trainCount; i++) {
        if (trains[i].trainNumber == trainNumber) {
            if (trains[i].bookedSeats < trains[i].totalSeats) {
                int seatNumber = trains[i].bookedSeats + 1;
                trains[i].passengers[trains[i].bookedSeats] = {name, age, gender, seatNumber};
                trains[i].bookedSeats++;
                recentBookings.push(i); 
                displayHeader("Ticket Booking Successful");
                cout << "Passenger Name: " << name << endl;
                cout << "Train: " << trains[i].trainName << " | Seat Number: " << seatNumber << endl;
                displayLine();
            } else {
                trains[i].waitlist.push({name, age, gender});
                displayHeader("Waitlist");
                cout << "No seats available. Added " << name << " to the waitlist.\n";
            }
            return;
        }
    }
    cout << "Train number " << trainNumber << " not found!\n";
}

void cancelTicket(int trainNumber, int seatNumber) {
    for (int i = 0; i < trainCount; i++) {
        if (trains[i].trainNumber == trainNumber) {
            bool found = false;
            for (int j = 0; j < trains[i].bookedSeats; j++) {
                if (trains[i].passengers[j].seatNumber == seatNumber) {
                    found = true;
                    string canceledName = trains[i].passengers[j].name;

                    for (int k = j; k < trains[i].bookedSeats - 1; k++) {
                        trains[i].passengers[k] = trains[i].passengers[k + 1];
                    }
                    trains[i].bookedSeats--;

                    displayHeader("Ticket Cancellation");
                    cout << "Canceled ticket for " << canceledName << " on seat number " << seatNumber << endl;
                    
                    if (!trains[i].waitlist.empty()) {
                        WaitlistPassenger wp = trains[i].waitlist.front();
                        trains[i].waitlist.pop();
                        trains[i].passengers[trains[i].bookedSeats] = {wp.name, wp.age, wp.gender, trains[i].bookedSeats + 1};
                        trains[i].bookedSeats++;
                        cout << "Moved " << wp.name << " from waitlist to seat " << trains[i].bookedSeats << endl;
                    }
                    return;
                }
            }
            if (!found) cout << "Seat number " << seatNumber << " not found on this train.\n";
            return;
        }
    }
    cout << "Train number " << trainNumber << " not found!\n";
}

void searchTrainByRoute(string source, string destination) {
    displayHeader("Train Search by Route");
    bool found = false;
    for (int i = 0; i < trainCount; i++) {
        if (trains[i].source == source && trains[i].destination == destination) {
            found = true;
            cout << setw(10) << trains[i].trainNumber << setw(15) << trains[i].trainName << endl;
        }
    }
    if (!found) cout << "No trains found from " << source << " to " << destination << endl;
}

void showMainMenu() {
    displayHeader("Railway Management System");
    cout << "1. Add Train\n";
    cout << "2. Display All Trains\n";
    cout << "3. Book Ticket\n";
    cout << "4. View Seat Availability\n";
    cout << "5. Cancel Ticket\n";
    cout << "6. Search Train by Route\n";
    cout << "7. Exit\n";
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
            cout << "Enter gender (M/F): ";
            cin >> gender;
            bookTicket(trainNumber, name, age, gender);
        } else if (choice == 4) {
            int trainNumber;
            cout << "Enter train number to check availability: ";
            cin >> trainNumber;
            checkSeatAvailability(trainNumber);
        } else if (choice == 5) {
            int trainNumber, seatNumber;
            cout << "Enter train number for cancellation: ";
            cin >> trainNumber;
            cout << "Enter seat number to cancel: ";
            cin >> seatNumber;
            cancelTicket(trainNumber, seatNumber);
        } else if (choice == 6) {
            string source, destination;
            cout << "Enter source: ";
            cin.ignore();
            getline(cin, source);
            cout << "Enter destination: ";
            getline(cin, destination);
            searchTrainByRoute(source, destination);
        } else if (choice == 7) {
            cout << "Exiting the program. Thank you!\n";
            break;
        } else {
            cout << "Invalid choice, please try again.\n";
        }
    }
    return 0;
}