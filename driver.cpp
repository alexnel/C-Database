//Author: NLXALE001
//Project: C++ Assignment 1

#include "database.h"


int main(void) {

for (;;)
{

	
	std::cout << "0:  Add student" << std::endl;
	std::cout << "1:  Read file to databse" << std::endl;
	std::cout << "2:  Save database to file" << std::endl;
	std::cout << "3:  Display given student number" << std::endl;
	std::cout << "4:  Grade student" << std::endl;
	std::cout << "q:  Quit" << std::endl;
	std::cout << "Enter a number (or q to quit) and press return" << std::endl;
	
	char choice;
	std::cin >> choice;
	
	switch(choice){
		case '0':
			NLXALE001::add_student();
			break;
		case '1':
			NLXALE001::read_data();
			break;
		case '2':
			NLXALE001::save_data();
			break;
		case '3':
			NLXALE001::disp_student();
			break;
		case '4':
			NLXALE001::grade_student();
			break;
		case 'q':
			char ans;			
			std::cout << "Are you sure you want to quit? Any data not saved will be lost. y/n " << std::endl;
			std::cin >> ans;
			if (ans == 'y'){
				return 0;	}
			else{
				break;	}

	  
		default:
			std::cout << "Invalid input." << std::endl;
	}

}//end for
return 0;
}

