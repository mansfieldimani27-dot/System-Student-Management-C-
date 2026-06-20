//
//  main.cpp
//  System student managerment c++
//
//  Created by Imani Mansfield on 6/3/26.
//


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int roll;
    string name;
    int marks;

    void input() {
        cout << "Enter Roll No=";
        cin >> roll;

        cout << "Enter Name=";
        cin >> name;

        cout << "Enter Marks=";
        cin >> marks;
    }

    void display() {
        cout << roll << "\t" << name << "\t" << marks << endl;
    }

    void writeToFile() {
        ofstream fout("students.dat", ios::app);

        if (fout) {
            fout << roll << " "
                 << name << " "
                 << marks << endl;
        }

        fout.close();
    }

    static void readfromFile() {
        ifstream fin("students.dat");

        Student s;

        while (fin >> s.roll >> s.name >> s.marks) {
            s.display();
        }

        fin.close();
    }
};

int main() {
    int choice;
    Student s;

    do {
        cout << "\n1. Add Student";
        cout << "\n2. View Students";
        cout << "\n3. Exit";
        cout << "\nchoice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                s.input();
                s.writeToFile();
                break;

            case 2:
                Student::readfromFile();
                break;

            case 3:
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}
