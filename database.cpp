#include "database.h"

namespace NLXALE001 {


//Name (String), Surname (String), StudentNumber (String), ClassRecord (String)


void add_student(void){
//give more information
	std::cout << "Enter a student name:" << std::endl;
	std::string name;
	std::cin >> name;
	std::cout << "Enter a student surname:" << std::endl;
	std::string surname;
	std::cin >> surname;
	std::cout << "Enter a student number:" << std::endl;
	std::string stuno;
	std::cin >> stuno;
	std::cout << "Enter the class record:" << std::endl;
	std::string record;
	std::cin.ignore();
	getline(std::cin, record);

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
	std::cout << "Got here." << std::endl;

}


void grade_student(void){
//give more information
	std::cout << "Got here." << std::endl;
//once done
	system("clear");
	std::cout << "Student grading complete.." << std::endl;
}

}//end namespace

