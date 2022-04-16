#include "Manager.h"

//TODO: Implement Manager.cpp
Manager::Manager() {};

Manager::Manager(int id, const string& name, char gender, const Date& entry_date, Department dept) : 
    Employee(id, name, gender, entry_date, "Manager", dept) {
        staffs = new Employee* [MAX_STAFF_NUM];
        // for (int i=0; i<MAX_STAFF_NUM; i++)
        //     staffs[0] = new Employee [i];
    };

Manager::~Manager() {
    for (int i=0; i<MAX_STAFF_NUM; i++) 
        delete staffs[i];
    delete [] staffs;

    cout << "Resign: Manager " << name << endl;
}

void Manager::manage(Technician *t) {
    staffs[num_staff] = t;
    cout << staffs[num_staff++]->get_name() << " is managed by " << this->get_name() << " now!" << endl;
}

// 20000 + 2000 * num_staff
void Manager::calculate_salary() {salary = 20000 + 2000*num_staff;}

void Manager::print_description() const {
    cout << "ID: " << id << ", Name: " << this->get_name() << ", Gender: " << gender 
    << ", Entry date: " << entry_date.year << "-" << entry_date.month << "-" << entry_date.day << ", Post: Manager, Group: " << enum_to_str(dept) << endl;
}

// name_m is managing num_staff staffs: [name_1, ][name_2, ]...[name_x, ]
void Manager::print_staff() const {
    cout << this->get_name() << " is managing " << num_staff << " staffs: ";
    for (int i=0; i< num_staff; i++) 
        cout << staffs[i]->get_name() << ", ";
    cout << endl;
}