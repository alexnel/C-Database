//Author: NLXALE001
//Project: C++ Assignment 1

#include "database.h"

namespace NLXALE001 {

	//initialise vector
	std::vector<StudentRecord> s;

//add student record to database
void add_student(void){
//give more information	
	
	std::string nname;
	std::string nsurname;
	std::string nstuno;
	std::string nrecord;

	int i = s.size();
	
	//get data from user
	std::cout << "Enter a student name: " << std::endl;
	std::cin >> nname;
	std::cout << "Enter a student surname: " << std::endl;
	std::cin >> nsurname;
	std::cout << "Enter a student number: " << std::endl;
	std::cin >> nstuno;
	std::cout << "Enter the class record: " << std::endl;
	std::cin.ignore();	//handle spaces
	getline(std::cin, nrecord);
	
	int recnum = findstudent(nstuno);

	if (recnum == (-1))	//record not yet recorded
	{	saverec(nname, nsurname, nstuno, nrecord);	}
	else
	{	system("clear");
		std::cout << "Student '" << nstuno << "' already in record. Student not added." << std::endl << std::endl;	}


}
//add students from database to file
void save_data(void){
	
	//create file here
	std::ofstream out;
	std::string file;
	
	std::cout << "Enter a file name: " << std::endl;
	std::cin >> file;

	out.open(file.c_str());
	
	//add to file
	for (int i = 0; i < s.size(); i = i + 1)
	{
		std::string line = s[i].name + " " + s[i].surname + " " + s[i].stuno + " " + s[i].record;
		out << line << std::endl;
	}

}

//add students from file to database
void read_data(void){
//give more information
	
	std::string nname;
	std::string nsurname;
	std::string nstuno;
	std::string nrecord;
	std::string file;
	
	std::cout << "Enter a file name: " << std::endl;
	std::cin >> file;
	
	//read file
	std::ifstream infile;
	infile.open(file.c_str());
	
	if (infile.fail())
	{	system("clear");	
		std::cout << "File opening failed. Please ensure file exists and that permissions for the file are in order." << std::endl << std::endl;
		return;	}
	//while(hasnext) add to database
	std::string line;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		
		iss >> nname >> nsurname >> nstuno;
		std::string mark;
		std::string marks = "";
		while (!iss.eof()){
			iss >> mark;
			marks += mark;
			if (!iss.eof())
			{	marks += " ";	}	}
		
		int recnum = findstudent(nstuno);

		if (recnum == (-1))	//record not yet recorded
		{	saverec(nname, nsurname, nstuno, marks);	}
		else
		{	system("clear");
			std::cout << "Student '" << nstuno << "' already in record. Student not added." << std::endl << std::endl;	}
	}
	
//once done
	system("clear");
	std::cout << "Data capture complete." << std::endl << std::endl;
}

//find student and print out
void disp_student(void){
	std::cout << "Enter a student number:" << std::endl;
	std::string num;
	std::cin >> num;
	
	int recnum = findstudent(num);
	
	if (recnum != -1)	//student found
	{	system("clear");
		printrec(recnum);		}
	else			//student not found
	{	system("clear");
		std::cout << "Student " << recnum << " not found." << std::endl << std::endl;	}

}

//find student in records and return vecor index
int findstudent(std::string num){
	for (int i = 0; i < s.size(); i = i + 1)
	{
		if (s[i].stuno == num)
		{	return i;		}
	}
	return (-1);	//student not found
}

//save record in new vector instance
void saverec(std::string nname, std::string nsurname, std::string nstuno, std::string nrecord){
	int i = s.size();
	s.push_back(StudentRecord());
	s[i].name = nname;
	s[i].surname = nsurname;
	s[i].stuno = nstuno;
	s[i].record = nrecord;
	
	system("clear");
	std::cout << "Student '" << s[i].stuno << "' added. Number of records: " << s.size() << std::endl << std::endl;
}

//print out student record in nice format
void printrec(int i){
	std::cout << "Student name: " << s[i].name << std::endl;
	std::cout << "Student surname: " << s[i].surname << std::endl;
	std::cout << "Student number: " << s[i].stuno << std::endl;
	std::cout << "Class record: " << s[i].record << std::endl;
}

//find average of a given students grade
void grade_student(void){
//give more information
	std::cout << "Enter a student number:" << std::endl;
	std::string num;
	std::cin >> num;
	
	int recnum = findstudent(num);
	float av;
	
	if (recnum != -1)
	{	
		//find average
		std::string list = s[recnum].record;
		
		int next;
		int total = 0;
		int c = 0;
		
		std::istringstream iss(list);
		while(!iss.eof()) //split into numbers and add to total
		{	iss >> next;
			total += next;
			c++;		}
		
		av = total/c;
		
		system("clear");
		std::cout << "Student '" << num << "' has a class record of " << av << std::endl << std::endl;	}
	else
	{	system("clear");
		std::cout << "Student '" << num << "' not found." << std::endl << std::endl;	}

}

}//end namespace

