#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Flight {
    string flightNumber;
    string destination;
    int seatsAvailable;
};

vector<Flight> flights = {
    {"FL1001", "NewYork", 5},
    {"FL2002", "London", 3},
    {"FL3003", "Paris", 4}
};

// Function to display available flights
void displayFlights() {
    cout << "\nAvailable Flights:\n";
    for (const auto &f : flights) {
        cout << "Flight: " << f.flightNumber 
             << " | Destination: " << f.destination 
             << " | Seats: " << f.seatsAvailable << endl;
    }
}

// Function to book a flight
void bookFlight() {
    string flightNum;
    cout << "Enter flight number to book: ";
    cin >> flightNum;

    for (auto &f : flights) {
        if (f.flightNumber == flightNum && f.seatsAvailable > 0) {
            f.seatsAvailable--;
            cout << "Booking successful for Flight " << flightNum << "!\n";
            return;
        }
    }
    cout << "Flight not found or no seats available!\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\n1. View Flights\n2. Book a Flight\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            displayFlights();
        } 
        else if (choice == 2) {
            bookFlight();
        } 
        else if (choice == 3) {
            cout << "Thank you for using the Airline Booking System!\n";
            break;
        } 
        else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
