#include "database.h"

namespace NLXALE001 {


	std::vector<StudentRecord> s;


void add_student(void){
//give more information	

	int i = s.size();
	
	s.push_back(StudentRecord());
	
	std::cout << "Enter a student name:" << std::endl;
	std::cin >> s[i].name;
	std::cout << "Enter a student surname:" << std::endl;
	std::cin >> s[i].surname;
	std::cout << "Enter a student number:" << std::endl;
	std::cin >> s[i].stuno;
	std::cout << "Enter the class record:" << std::endl;
	std::cin.ignore();	//handle spaces
	getline(std::cin, s[i].record);

//once done
	system("clear");
	std::cout << "Student addition complete." << std::endl;
}

void read_data(void){
//give more information
	std::cout << "Got here." << std::endl;

}

void save_data(void){
//give more information
	std::cout << "Got here." << std::endl;
//once done
	system("clear");
	std::cout << "Data capture complete." << std::endl;
}

void disp_student(void){
//give more information
	std::cout << "Enter a student number:" << std::endl;
	std::string stuno;
	std::cin >> stuno;

}


void grade_student(void){
//give more information
	std::cout << "Got here." << std::endl;
//once done
	system("clear");
	std::cout << "Student grading complete.." << std::endl;
}

}//end namespace

