#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct student {
    string studentID;
    string name;
    string course;
    double gpa;
};

void inputStudents(student list[], int num) {
    for (int i = 0; i < num; i++) {
        cout << "\n--- Recording Student " << i + 1 << " ---" << endl;

        bool exists;
        do {
            exists = false;
            cout << "Enter Student ID: ";
            cin >> list[i].studentID;

            for (int j = 0; j < i; j++) {
                if (list[i].studentID == list[j].studentID) {
                    cout << "ID already exists! Try again." << endl;
                    exists = true;
                    break;
                }
            }
        } while (exists);

        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, list[i].name);
        cout << "Enter Course: ";
        getline(cin, list[i].course);
        cout << "Enter GPA (0-100): ";
        cin >> list[i].gpa;
    }
}

void displayStudents(student list[], int num) {
    cout << "\n" << left << setw(12) << "ID"
         << setw(20) << "Name"
         << setw(15) << "Course"
         << setw(8)  << "GPA"
         << "Standing" << endl;
    cout << string(65, '-') << endl;

    for (int i = 0; i < num; i++) {
        string standing;
        if (list[i].gpa >= 90) standing = "Excellent";
        else if (list[i].gpa >= 80) standing = "Very Good";
        else if (list[i].gpa >= 70) standing = "Good";
        else if (list[i].gpa >= 60) standing = "Passing";
        else standing = "Failed";

        cout << left << setw(12) << list[i].studentID
             << setw(20) << list[i].name
             << setw(15) << list[i].course
             << setw(8)  << list[i].gpa
             << standing << endl;
    }
}

int main() {
    char repeat;

    do {
        int num;
        cout << "Enter number of students: ";
        cin >> num;

        if (num > 100) num = 100;

        student list[100];

        inputStudents(list, num);
        displayStudents(list, num);

        cout << "\nRun again? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
