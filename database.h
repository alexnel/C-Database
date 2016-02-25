/**
*.h file:
*/
#ifndef DATABASE_H
#define DATABASE_H
//any includes here 
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
namespace NLXALE001 {
	
	struct StudentRecord {
		std::string name;
		std::string surname;
		std::string stuno;
		std::string record;
	};
	
	void add_student(void);
	void read_data(void);
	void save_data(void);
	void disp_student(void);
	int findstudent(std::string);
	void saverec(std::string, std::string, std::string, std::string);
	void printrec(int);
	void grade_student(void);
}
#endif

