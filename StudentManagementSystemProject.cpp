#include <iostream> 
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Person {
protected:
    string firstName;
    string lastName;

public:
    Person(string first, string last) : firstName(first), lastName(last) {}

    virtual void displayInfo() = 0;
    virtual string getType() = 0;
    virtual string getFullName() { return firstName + " " + lastName; }
    virtual string getCSVData() { return ""; }
};

class Student : public Person {
private:
    int id;
    vector<pair<string, double>> coursesGrades;
    string phoneNumber;
    string address;
    string fatherName;
    string motherName;
    string fatherPhoneNumber;
    string motherPhoneNumber;

public:
    Student(string first, string last, int studentID, string phone, string addr, string father, string mother, string fatherPhone, string motherPhone) :
        Person(first, last), id(studentID), phoneNumber(phone), address(addr), fatherName(father), motherName(mother), fatherPhoneNumber(fatherPhone), motherPhoneNumber(motherPhone) {}

    void addCourseGrade(string course, double grade) {
        coursesGrades.push_back(make_pair(course, grade));
    }

    void displayInfo() override {
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "ID: " << id << endl;
        cout << "Phone number: " << phoneNumber << endl;
        cout << "Address: " << address << endl;
        cout << "Father's Name: " << fatherName << endl;
        cout << "Mother's Name: " << motherName << endl;
        cout << "Father's Phone number: " << fatherPhoneNumber << endl;
        cout << "Mother's Phone number: " << motherPhoneNumber << endl;
        cout << "Courses and Grades: ";
        for (const auto& courseGrade : coursesGrades) {
            cout << courseGrade.first << " (" << courseGrade.second << "), ";
        }
        cout << endl;

        // Υπολογισμός και εμφάνιση του μέσου όρου των βαθμών
        double averageGrade = calculateAverageGrade();
        cout << "Average Grade: " << averageGrade << endl;
    }

    string getType() override {
        return "Student";
    }

    string getCSVData() override {
        string csvData;
        csvData += "Student,";
        csvData += firstName + "," + lastName + ",";
        csvData += to_string(id) + ",";
        csvData += phoneNumber + ",";
        csvData += address + ",";
        csvData += fatherName + "," + motherName + ",";
        csvData += fatherPhoneNumber + "," + motherPhoneNumber + ",";
        for (const auto& courseGrade : coursesGrades) {
            csvData += courseGrade.first + " (" + to_string(courseGrade.second) + "),";
        }
        return csvData;
    }

private:
    double calculateAverageGrade() const {
        if (coursesGrades.empty()) {
            return 0.0;
        }

        double totalGrade = 0;
        for (const auto& courseGrade : coursesGrades) {
            totalGrade += courseGrade.second;
        }

        return totalGrade / coursesGrades.size();
    }
};

class Teacher : public Person {
private:
    string department;
    string phoneNumber;
    string address;
    string fatherName;
    string motherName;
    string fatherPhoneNumber;
    string motherPhoneNumber;

public:
    Teacher(string first, string last,  string phone, string addr, string father, string mother, string fatherPhone, string motherPhone) :
        Person(first, last),  phoneNumber(phone), address(addr), fatherName(father), motherName(mother), fatherPhoneNumber(fatherPhone), motherPhoneNumber(motherPhone) {}

    void displayInfo() override {
        cout << "Teacher name: " << firstName << " " << lastName << endl;

        cout << "Phone number: " << phoneNumber << endl;
        cout << "Address: " << address << endl;
        cout << "Father's Name: " << fatherName << endl;
        cout << "Mother's Name: " << motherName << endl;
        cout << "Father's Phone number: " << fatherPhoneNumber << endl;
        cout << "Mother's Phone number: " << motherPhoneNumber << endl;
    }

    string getType() override {
        return "Teacher";
    }

    string getCSVData() override {
        return "Teacher," + firstName + "," + lastName + ",," + phoneNumber + "," + address + "," + fatherName + "," + motherName + "," + fatherPhoneNumber + "," + motherPhoneNumber + "," + "," + department;
    }
};

class Supervisor : public Person {
public:
    Supervisor(string first, string last) : Person(first, last) {}

    void displayInfo() override {
        cout << "Supervisor: " << firstName << " " << lastName << endl;
    }

    string getType() override {
        return "Supervisor";
    }

    string getCSVData() override {
        return "Supervisor," + firstName + "," + lastName;
    }
};

void addStudent(vector<Person*>& people) {
    string firstName, lastName, phone, address, fatherName, motherName, fatherPhone, motherPhone;
    int id;
    vector<pair<string, double>> coursesGrades;

    cout << "Enter student's first name: ";
    cin >> firstName;
    cout << "Enter student's last name: ";
    cin >> lastName;
    cout << "Enter student's ID: ";
    cin >> id;
    cout << "Enter student's phone number: ";
    cin >> phone;
    cout << "Enter student's address: ";
    cin >> address;
    cout << "Enter student's father's name: ";
    cin >> fatherName;
    cout << "Enter student's mother's name: ";
    cin >> motherName;
    cout << "Enter student's father's phone number: ";
    cin >> fatherPhone;
    cout << "Enter student's mother's phone number: ";
    cin >> motherPhone;

    cout << "Enter student's courses and grades (type 'done' when finished):" << endl;
    string course;
    double grade;
    while (true) {
        cout << "Course: ";
        cin >> course;
        if (course == "done") {
            break;
        }
        cout << "Grade: ";
        cin >> grade;
        coursesGrades.push_back(make_pair(course, grade));
    }

    Student* student = new Student(firstName, lastName, id, phone, address, fatherName, motherName, fatherPhone, motherPhone);
    for (const auto& courseGrade : coursesGrades) {
        student->addCourseGrade(courseGrade.first, courseGrade.second);
    }

    people.push_back(student);
}

void addTeacher(vector<Person*>& people) {
    string firstName, lastName,  phone, address, fatherName, motherName, fatherPhone, motherPhone;

    cout << "Enter teacher's first name: ";
    cin >> firstName;
    cout << "Enter teacher's last name: ";
    cin >> lastName;

    cout << "Enter teacher's phone number: ";
    cin >> phone;
    cout << "Enter teacher's address: ";
    cin >> address;
    cout << "Enter teacher's father's name: ";
    cin >> fatherName;
    cout << "Enter teacher's mother's name: ";
    cin >> motherName;
    cout << "Enter teacher's father's phone number: ";
    cin >> fatherPhone;
    cout << "Enter teacher's mother's phone number: ";
    cin >> motherPhone;

    people.push_back(new Teacher(firstName, lastName,  phone, address, fatherName, motherName, fatherPhone, motherPhone));
}

void addSupervisor(vector<Person*>& people) {
    string firstName, lastName;

    cout << "Enter supervisor's first name: ";
    cin >> firstName;
    cout << "Enter supervisor's last name: ";
    cin >> lastName;

    people.push_back(new Supervisor(firstName, lastName));
}

void deletePerson(vector<Person*>& people) {
    string fullName;
    cout << "Enter the full name of the person you want to delete: ";
    cin.ignore();
    getline(cin, fullName);

    for (auto it = people.begin(); it != people.end(); ++it) {
        if ((*it)->getFullName() == fullName) {
            delete *it;
            people.erase(it);
            cout << "Person deleted successfully." << endl;
            return;
        }
    }

    cout << "Person not found." << endl;
}

void searchPerson(const vector<Person*>& people) {
    string fullName;
    cout << "Enter the full name of the person you want to search for: ";
    cin.ignore();
    getline(cin, fullName);

    for (const auto& person : people) {
        if (person->getFullName() == fullName) {
            cout << "Person found:" << endl;
            person->displayInfo();
            return;
        }
    }

    cout << "Person not found." << endl;
}

void displayStudents(const vector<Person*>& people) {
    cout << "Students:" << endl;
    for (const auto& person : people) {
        if (person->getType() == "Student") {
            person->displayInfo();
        }
    }
}

void displayTeachers(const vector<Person*>& people) {
    cout << "Teachers:" << endl;
    for (const auto& person : people) {
        if (person->getType() == "Teacher") {
            person->displayInfo();
        }
    }
}

void displaySupervisors(const vector<Person*>& people) {
    cout << "Supervisors:" << endl;
    for (const auto& person : people) {
        if (person->getType() == "Supervisor") {
            person->displayInfo();
        }
    }
}

void displayAll(const vector<Person*>& people) {
    displayStudents(people);
    displayTeachers(people);
    displaySupervisors(people);
}

void countPeople(const vector<Person*>& people) {
    int studentCount = 0, teacherCount = 0, supervisorCount = 0;

    for (const auto& person : people) {
        if (person->getType() == "Student") {
            studentCount++;
        } else if (person->getType() == "Teacher") {
            teacherCount++;
        } else if (person->getType() == "Supervisor") {
            supervisorCount++;
        }
    }

    cout << "Number of students: " << studentCount << endl;
    cout << "Number of teachers: " << teacherCount << endl;
    cout << "Number of supervisors: " << supervisorCount << endl;
}

void saveDataToCSV(const vector<Person*>& people) {
    ofstream outputFile("people_data.csv");
    if (!outputFile.is_open()) {
        cout << "Failed to open the file." << endl;
        return;
    }

    outputFile << "Type,First Name,Last Name,ID,Phone Number,Address,Father's Name,Mother's Name,Father's Phone Number,Mother's Phone Number,Courses and Grades" << endl;

    for (const auto& person : people) {
        outputFile << person->getCSVData() << endl;
    }

    outputFile.close();
    cout << "Data saved to 'people_data.csv'." << endl;
}

int main() {
    vector<Person*> people;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add a student\n";
        cout << "2. Add a teacher\n";
        cout << "3. Add a supervisor\n";
        cout << "4. Delete a person\n";
        cout << "5. Search for a person\n";
        cout << "6. Display all students\n";
        cout << "7. Display all teachers\n";
        cout << "8. Display all supervisors\n";
        cout << "9. Display all people\n";
        cout << "10. Count people\n";
        cout << "11. Save data to CSV\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(people);
                break;
            case 2:
                addTeacher(people);
                break;
            case 3:
                addSupervisor(people);
                break;
            case 4:
                deletePerson(people);
                break;
            case 5:
                searchPerson(people);
                break;
            case 6:
                displayStudents(people);
                break;
            case 7:
                displayTeachers(people);
                break;
            case 8:
                displaySupervisors(people);
                break;
            case 9:
                displayAll(people);
                break;
            case 10:
                countPeople(people);
                break;
            case 11:
                saveDataToCSV(people);
                break;
            case 12:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 12);

    // Αποδέσμευση δυναμικής μνήμης
    for (auto person : people) {
        delete person;
    }

    return 0;
}
