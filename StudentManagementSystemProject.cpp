#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

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
    virtual void editInfo() {}
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
    string registationDate;
    string email;
    string fatherEmail;
    string motherEmail;

public:
    Student(string first, string last, int studentID, string phone, string addr, string father, string mother, string fatherPhone, string motherPhone, string regDate, string mail, string fatherMail, string motherMail) :
        Person(first, last), id(studentID), phoneNumber(phone), address(addr), fatherName(father), motherName(mother), fatherPhoneNumber(fatherPhone), motherPhoneNumber(motherPhone), registationDate(regDate), email(mail), fatherEmail(fatherMail), motherEmail(motherMail) {}

    void addCourseGrade(string course, double grade) {
        coursesGrades.push_back(make_pair(course, grade));
    }

    void displayInfo() override {
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "ID: " << id << endl;
        cout << "Phone number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
        cout << "Address: " << address << endl;
        cout << "Father's Name: " << fatherName << endl;
        cout << "Mother's Name: " << motherName << endl;
        cout << "Father's Phone number: " << fatherPhoneNumber << endl;
        cout << "Mother's Phone number: " << motherPhoneNumber << endl;
        cout << "Father's Email: " << fatherEmail << endl;
        cout << "Mother's Email: " << motherEmail << endl;
        cout << "Courses and Grades: ";
        for (const auto& courseGrade : coursesGrades) {
            cout << courseGrade.first << " (" << courseGrade.second << "), ";
        }
        cout << endl;
        cout << "Registration Date: " << registationDate << endl;

        double averageGrade = calculateAverageGrade();
        cout << "Average Grade: " << averageGrade << endl;
    }

    string getType() override {
        return "Student";
    }

    string getCSVData() override {
        string csvData;

        csvData += firstName + "," + lastName + ",";
        csvData += to_string(id) + ",";
        csvData += phoneNumber + ",";
        csvData += email + ",";
        csvData += address + ",";
        csvData += fatherName + "," + motherName + ",";
        csvData += fatherPhoneNumber + "," + motherPhoneNumber + ",";
        csvData += fatherEmail + "," + motherEmail + ",";
        csvData += to_string(coursesGrades.size()) + ",";
        double totalGrade = 0;
        for (const auto& courseGrade : coursesGrades) {
            totalGrade += courseGrade.second;
        }
        double averageGrade = coursesGrades.empty() ? 0.0 : totalGrade / coursesGrades.size();
        csvData += to_string(averageGrade);
        csvData += ",";
        csvData += registationDate;

        return csvData;
    }

    void editInfo() override {
        string newPhone, newAddress, newFatherName, newMotherName, newFatherPhone, newMotherPhone, newEmail, newFatherEmail, newMotherEmail;

        cout << "Enter new phone number: ";
        cin >> newPhone;
        cout << "Enter new email: ";
        cin >> newEmail;
        cout << "Enter new address: ";
        cin >> newAddress;
        cout << "Enter new father's name: ";
        cin >> newFatherName;
        cout << "Enter new mother's name: ";
        cin >> newMotherName;
        cout << "Enter new father's phone number: ";
        cin >> newFatherPhone;
        cout << "Enter new mother's phone number: ";
        cin >> newMotherPhone;
        cout << "Enter new father's email: ";
        cin >> newFatherEmail;
        cout << "Enter new mother's email: ";
        cin >> newMotherEmail;

        phoneNumber = newPhone;
        email = newEmail;
        address = newAddress;
        fatherName = newFatherName;
        motherName = newMotherName;
        fatherPhoneNumber = newFatherPhone;
        motherPhoneNumber = newMotherPhone;
        fatherEmail = newFatherEmail;
        motherEmail = newMotherEmail;

        cout << "Information updated successfully." << endl;
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
        return firstName + "," + lastName + "," + phoneNumber + "," + address + "," + fatherName + "," + motherName + "," + fatherPhoneNumber + "," + motherPhoneNumber + "," ;
    }

    void editInfo() override {
        string newPhone, newAddress, newFatherName, newMotherName, newFatherPhone, newMotherPhone;

        cout << "Enter new phone number: ";
        cin >> newPhone;
        cout << "Enter new address: ";
        cin >> newAddress;
        cout << "Enter new father's name: ";
        cin >> newFatherName;
        cout << "Enter new mother's name: ";
        cin >> newMotherName;
        cout << "Enter new father's phone number: ";
        cin >> newFatherPhone;
        cout << "Enter new mother's phone number: ";
        cin >> newMotherPhone;

        phoneNumber = newPhone;
        address = newAddress;
        fatherName = newFatherName;
        motherName = newMotherName;
        fatherPhoneNumber = newFatherPhone;
        motherPhoneNumber = newMotherPhone;

        cout << "Information updated successfully." << endl;
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
        return firstName + "," + lastName+",";
    }

    void editInfo() override {
        cout << "Supervisors cannot be edited." << endl;
    }
};

void readDataFromCSV(const string& filename, vector<Person*>& people) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open the file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string type;
        getline(iss, type, ',');

        if (type == "Student") {
            string firstName, lastName, phone, address, fatherName, motherName, fatherPhone, motherPhone, registrationDate, email, fatherEmail, motherEmail;
            getline(iss, firstName, ',');
            getline(iss, lastName, ',');
             int id;
            iss >> id;
            getline(iss, phone, ',');
            getline(iss, email, ',');
            getline(iss, address, ',');
            getline(iss, fatherName, ',');
            getline(iss, motherName, ',');
            getline(iss, fatherPhone, ',');
            getline(iss, motherPhone, ',');
            getline(iss, fatherEmail, ',');
            getline(iss, motherEmail, ',');
            getline(iss, registrationDate, ',');




            Student* student = new Student(firstName, lastName, id, phone, address, fatherName, motherName, fatherPhone, motherPhone, registrationDate, email, fatherEmail, motherEmail);
             string course;
            double grade;
            while (getline(iss, course, ',')) {
                iss >> grade;
                student->addCourseGrade(course, grade);
            }

            people.push_back(student);

        } else if (type == "Teacher") {
            string firstName, lastName,  phone, address, fatherName, motherName, fatherPhone, motherPhone;
            getline(iss, firstName, ',');
            getline(iss, lastName, ',');
            getline(iss, phone, ',');
            getline(iss, address, ',');
            getline(iss, fatherName, ',');
            getline(iss, motherName, ',');
            getline(iss, fatherPhone, ',');
            getline(iss, motherPhone, ',');

            Teacher* teacher = new Teacher(firstName, lastName,  phone, address, fatherName, motherName, fatherPhone, motherPhone);
            people.push_back(teacher);
        } else if (type == "Supervisor") {
            string firstName, lastName;
            getline(iss, firstName, ',');
            getline(iss, lastName, ',');

            Supervisor* supervisor = new Supervisor(firstName, lastName);
            people.push_back(supervisor);
        }
    }

    file.close();
}

void addStudent(vector<Person*>& people) {
    string firstName, lastName, phone, address, fatherName, motherName, fatherPhone, motherPhone, registrationDate, email, fatherEmail, motherEmail;

    cout << "Enter student's first name: ";
    cin >> firstName;
    cout << "Enter student's last name: ";
    cin >> lastName;
    cout << "Enter student's ID: ";
    int id;
    cin >> id;
    cout << "Enter student's phone number: ";
    cin >> phone;
    cout << "Enter student's email: ";
    cin >> email;
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
    cout << "Enter student's father's email: ";
    cin >> fatherEmail;
    cout << "Enter student's mother's email: ";
    cin >> motherEmail;
    cout << "Enter student's registration date (DD/MM/YYYY): ";
    cin >> registrationDate;

    cout << "Enter student's courses and grades (type 'done' when finished):" << endl;
    string course;
    double grade;
    vector<pair<string, double>> coursesGrades;
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

    Student* student = new Student(firstName, lastName, id, phone, address, fatherName, motherName, fatherPhone, motherPhone, registrationDate, email, fatherEmail, motherEmail);
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
    ofstream studentsFile("students_data.csv");
    ofstream teachersFile("teachers_data.csv");
    ofstream supervisorsFile("supervisors_data.csv");

    if (!studentsFile.is_open() || !teachersFile.is_open() || !supervisorsFile.is_open()) {
        cout << "Failed to open the files." << endl;
        return;
    }

    studentsFile << "Type,First Name,Last Name,ID,Phone Number,Email,Address,Father's Name,Mother's Name,Father's Phone Number,Mother's Phone Number,Father's Email,Mother's Email,Number of Cources,AverageGrade,Registration Date" << endl;
    teachersFile << "Type,First Name,Last Name,Phone Number,Address,Father's Name,Mother's Name,Father's Phone Number,Mother's Phone Number" << endl;
    supervisorsFile << "Type,First Name,Last Name" << endl;

    for (const auto& person : people) {
        if (person->getType() == "Student") {
            studentsFile << person->getType() << "," << person->getCSVData() << endl;
        } else if (person->getType() == "Teacher") {
            teachersFile << person->getType() << "," << person->getCSVData() << endl;
        } else if (person->getType() == "Supervisor") {
            supervisorsFile << person->getType() << "," << person->getCSVData() << endl;
        }
    }

    studentsFile.close();
    teachersFile.close();
    supervisorsFile.close();

    cout << "Data saved to CSV files successfully." << endl;
}
void editPerson(vector<Person*>& people) {
    string fullName;
    cout << "Enter the full name of the person you want to edit: ";
    cin.ignore();
    getline(cin, fullName);

    for (const auto& person : people) {
        if (person->getFullName() == fullName) {
            person->editInfo();
            return;
        }
    }

    cout << "Person not found." << endl;
}




int main() {
    vector<Person*> people;
    readDataFromCSV("students_data.csv", people);
    readDataFromCSV("teachers_data.csv", people);
    readDataFromCSV("supervisors_data.csv", people);
 while (true) {
         cout << "---------------------------------------------" << endl;
        cout << "|          School Management System         |" << endl;
        cout << "---------------------------------------------" << endl;

        cout << "1. Add Student" << endl;
        cout << "2. Add Teacher" << endl;
        cout << "3. Add Supervisor" << endl;
        cout << "4. Search Person" << endl;
        cout << "5. Edit Person" << endl;
        cout << "6. Delete Person" << endl;
        cout << "7. Display Students" << endl;
        cout << "8. Display Teachers" << endl;
        cout << "9. Display Supervisors" << endl;
        cout << "10. Display All" << endl;
        cout << "11. Count People" << endl;
        cout << "12. Save Data to CSV" << endl;
        cout << "13. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
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
                searchPerson(people);
                break;
            case 5:
                editPerson(people);
                break;
            case 6:
               deletePerson(people);
                break;
            case 7:
                displayStudents(people);
                break;
            case 8:
                displayTeachers(people);
                break;
            case 9:
                displaySupervisors(people);
                break;
            case 10:
                displayAll(people);
                break;
            case 11:
                countPeople(people);
                break;

            case 12:
                saveDataToCSV(people);
                break;
            case 13:

                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 13." << endl;
        }
    }

    return 0;
}
