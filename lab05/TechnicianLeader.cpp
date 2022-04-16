#include "TechnicianLeader.h"

//TODO: Implement TechnicianLeader.cpp

TechnicianLeader::TechnicianLeader() {}

TechnicianLeader::TechnicianLeader(int id, const string& name, char gender, const Date& entry_date, int num_projects, Department dept) : 
    Technician(id, name, gender, entry_date, num_projects, dept) {post = "Technicial Leader";}

TechnicianLeader::~TechnicianLeader() {cout << "Resign: TechnicianLeader " << name << endl;}

// 20000 + 1500 * num_projects.
void TechnicianLeader::calculate_salary() {salary = 20000 + 1500*num_projects;}

//ID: id, Name: name, Gender: gender, Entry date: entry_date, Post: Technician Leader, Group: dept, Finished num_projects: num_projects
void TechnicianLeader::print_description() const {
    cout << "ID: " << id << ", Name: " << this->get_name() << ", Gender: " << gender 
    << ", Entry date: " << entry_date.year << "-" << entry_date.month << "-" << entry_date.day << ", Post: Technician Leader, Group: " << enum_to_str(dept) 
    << ", Finished num_projects: " << num_projects << endl;
}