#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person {
    string name;
    string gender;
    string address;
    int age;
    int number;

public:
    Person() : name(), gender(), address(), age(0), number(0) {}

    void set_name(string n) { name = n; }
    string get_name() { return name; }

    void set_gender(string g) { gender = g; }
    string get_gender() { return gender; }

    void set_address(string a) { address = a; }
    string get_address() { return address; }

    void set_age(int a) { age = a; }
    int get_age() { return age; }

    void set_number(int n) { number = n; }
    int get_number() { return number; }

    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Address: " << address << endl;
        cout << "Age: " << age << endl;
        cout << "Phone Number: " << number << endl;
    }

    void save_information(ofstream &file) {
        file << "Name: " << name << endl;
        file << "Gender: " << gender << endl;
        file << "Address: " << address << endl;
        file << "Age: " << age << endl;
        file << "Phone Number: " << number << endl;
    }
};

class Teacher : public Person {
    int salary;
    string qualification;

public:
    Teacher() : salary(0), qualification() {}

    void set_salary(int s) { salary = s; }
    int get_salary() { return salary; }

    void set_qualification(string q) { qualification = q; }
    string get_qualification() { return qualification; }

    void display() override {
        Person::display();
        cout << "Qualification: " << qualification << endl;
        cout << "Salary: " << salary << endl;
    }

    void save_information(string teacher_file) {
        ofstream file(teacher_file, ios::app);
        if (file.is_open()) {
            Person::save_information(file);
            file << "Qualification: " << qualification << endl;
            file << "Salary: " << salary << endl;
            file << "-------------------------" << endl;
            file.close();
            cout << "Teacher information saved successfully!" << endl;
        } else {
            cout << "Error opening file!" << endl;
        }
    }
};

class Student : public Person {
    string previous_education;
    int obtained_marks;
    int total_marks;

public:
    Student() : previous_education(), obtained_marks(0), total_marks(0) {}

    void set_previous_education(string p) { previous_education = p; }
    string get_previous_education() { return previous_education; }

    void set_obtained_marks(int o) { obtained_marks = o; }
    int get_obtained_marks() { return obtained_marks; }

    void set_total_marks(int t) { total_marks = t; }
    int get_total_marks() { return total_marks; }

    void display() override {
        Person::display();
        cout << "Previous Education: " << previous_education << endl;
        cout << "Obtained Marks: " << obtained_marks << endl;
        cout << "Total Marks: " << total_marks << endl;
    }

    void save_information(string student_file) {
        ofstream file(student_file, ios::app);
        if (file.is_open()) {
            Person::save_information(file);
            file << "Previous Education: " << previous_education << endl;
            file << "Obtained Marks: " << obtained_marks << endl;
            file << "Total Marks: " << total_marks << endl;
            file << "-------------------------" << endl;
            file.close();
            cout << "Student information saved successfully!" << endl;
        } else {
            cout << "Error opening file!" << endl;
        }
    }
};

void search_information(string file_name) {
    ifstream file(file_name);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    string line;
    cout << "File Contents:" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    bool run = true;

    while (run) {
        int choice;
        cout << "\n1. Enter Teacher Info\n";
        cout << "2. Enter Student Info\n";
        cout << "3. View Teacher Records\n";
        cout << "4. View Student Records\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        cin.ignore();

        if (choice == 1) {
            Teacher t;
            string name, gender, address, qualification;
            int age, number, salary;

            cout << "Enter Teacher's Name: ";
            getline(cin, name);
            t.set_name(name);

            cout << "Enter Gender: ";
            getline(cin, gender);
            t.set_gender(gender);

            cout << "Enter Address: ";
            getline(cin, address);
            t.set_address(address);

            cout << "Enter Age: ";
            cin >> age;
            t.set_age(age);

            cout << "Enter Phone Number: ";
            cin >> number;
            t.set_number(number);

            cout << "Enter Salary: ";
            cin >> salary;
            t.set_salary(salary);

            cin.ignore(); 
            cout << "Enter Qualification: ";
            getline(cin, qualification);
            t.set_qualification(qualification);

            t.save_information("Teacher_info.txt");

        } else if (choice == 2) {
            Student s;
            string name, gender, address, previous_education;
            int age, number, obtained_marks, total_marks;

            cout << "Enter Student's Name: ";
            getline(cin, name);
            s.set_name(name);

            cout << "Enter Gender: ";
            getline(cin, gender);
            s.set_gender(gender);

            cout << "Enter Address: ";
            getline(cin, address);
            s.set_address(address);

            cout << "Enter Age: ";
            cin >> age;
            s.set_age(age);

            cout << "Enter Phone Number: ";
            cin >> number;
            s.set_number(number);

            cin.ignore();
            cout << "Enter Previous Education: ";
            getline(cin, previous_education);
            s.set_previous_education(previous_education);

            cout << "Enter Obtained Marks: ";
            cin >> obtained_marks;
            s.set_obtained_marks(obtained_marks);

            cout << "Enter Total Marks: ";
            cin >> total_marks;
            s.set_total_marks(total_marks);

            s.save_information("Student_info.txt");

        } else if (choice == 3) {
            search_information("Teacher_info.txt");
        } else if (choice == 4) {
            search_information("Student_info.txt");
        } else if (choice == 5) { 
            run = false;
        } else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    cout << "Program Ended.\n";
    return 0;
}

