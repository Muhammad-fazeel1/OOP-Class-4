#include <iostream>
#include <cstring> 
using namespace std;

class Person {
private:
    char name[50];
    char cnic[20];
public:
    Person(const char*, const char*);
    void PrintInfo();
    void SetValues(const char*, const char*);
    const char* GetName();
    ~Person();
};

const char* Person::GetName() {
    return name;
}

Person::Person(const char* _name = "", const char* nic = "") {
    strcpy(name, _name); // Using strcpy
    strcpy(cnic, nic);
    cout << "Person Overloaded Constructor Called for " << name << endl;
}

Person::~Person() {
    cout << "~Person() Called for " << name << endl;
}

void Person::PrintInfo() {
    cout << "Name:\t" << name << endl;
    cout << "CNIC:\t" << cnic << endl;
}

void Person::SetValues(const char* empName, const char* nic) {
    strcpy(name, empName); // Using strcpy
    strcpy(cnic, nic);
}

class Faculty : public Person {
private:
    char designation[20];
public:
    Faculty(const char*, const char*, const char*);
    void SetValues(const char*, const char*, const char*);
    ~Faculty();
    void PrintInfo();
    const char* GetDesignation() { return designation; }
};

Faculty::Faculty(const char* _name = "", const char* nic = "", const char* _designation = "") : Person(_name, nic) {
    cout << "Faculty Overloaded Constructor Called.\n";
    strcpy(designation, _designation); // Using strcpy
}

void Faculty::SetValues(const char* _name, const char* nic, const char* _designation) {
    Person::SetValues(_name, nic);
    strcpy(designation, _designation); // Using strcpy
}

Faculty::~Faculty() {
    cout << "~Faculty() " << GetName() << endl;
}

void Faculty::PrintInfo() {
    Person::PrintInfo();
    cout << "Designation:\t" << designation << endl;
}

class HourlyWorker : public Person {
private:
    int workingHours;
    int wagePerHour;
public:
    HourlyWorker();
    HourlyWorker(const char*, const char*, int, int);
    void SetValues(const char*, const char*, int, int);
    ~HourlyWorker();
    void PrintInfo();
    int CalculatePay();
};

int HourlyWorker::CalculatePay() {
    return workingHours * wagePerHour;
}

void HourlyWorker::PrintInfo() {
    Person::PrintInfo();
    cout << "Total Working Hours :\t" << workingHours << endl;
    cout << "Wage per Hour :\t" << wagePerHour << endl;
    cout << "Total Payment:\t" << CalculatePay() << endl;
}

HourlyWorker::~HourlyWorker() {
    cout << "HourlyWorker Destructor Called for " << GetName() << endl;
}

HourlyWorker::HourlyWorker(const char* empName = "", const char* nic = "", int workHrs = 0, int wPh = 0) : Person(empName, nic) {
    cout << "HourlyWorker Overloaded Constructor Called.\n";
    workingHours = workHrs;
    wagePerHour = wPh;
}

void HourlyWorker::SetValues(const char* empName, const char* nic, int workHrs, int wPh) {
    Person::SetValues(empName, nic);
    workingHours = workHrs;
    wagePerHour = wPh;
}

int main() {
    cout << "---------------------------------------------TEST 1--------------------------------------------\n";
    {
        Faculty f1;
        cout << "\n\n\n";
    }

    cout << "---------------------------------------------TEST 2--------------------------------------------\n";
    {
        Faculty f1;
        f1.SetValues("abc xyz", "1234567890", "lecturer");
        cout << "\n\n\n";
        f1.PrintInfo();
        cout << "\n\n\n";
    }

    cout << "---------------------------------------------TEST 3--------------------------------------------\n";
    {
        Faculty f1;
        f1.Person::SetValues("abc xyz", "1234567890");
        cout << "\n\n\n";
        f1.PrintInfo();
        cout << "\n\n\n";
    }

    cout << "---------------------------------------------TEST 4--------------------------------------------\n";
    {
        Faculty f1;
        f1.SetValues("abc xyz", "1234567890", "lecturer");
        cout << "\n\n\n";
        cout << "Name:\t" << f1.GetName();
        cout << "\n\n\n";
    }

    cout << "---------------------------------------------TEST 5--------------------------------------------\n";
    {
        Faculty f1;
        f1.SetValues("abc xyz", "1234567890", "lecturer");
        cout << "\n\n\n";
        f1.Person::PrintInfo();
        cout << "\n\n\n";
    }

    cout << "---------------------------------------------TEST 6--------------------------------------------\n";
    {
        Faculty f1;
        f1.SetValues("abc xyz", "1234567890", "lecturer");
        cout << "\n\n\n";
        cout << "Designation:\t" << f1.GetDesignation();
        cout << "\n\n\n";
    }

    cout << "---------------------------------------------TEST 7--------------------------------------------\n";
    {
        HourlyWorker hw1("dummy Person", "111222333", 50, 500);
        cout << "\n\n\n";
        hw1.PrintInfo();
        cout << "\n\n\n";
    }

    return 0;
}

