#include "database.h"

namespace NLXALE001 {


	std::vector<StudentRecord> s;


void add_student(void){
//give more information	
	
	std::string nname;
	std::string nsurname;
	std::string nstuno;
	std::string nrecord;

	int i = s.size();
	
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

	if (recnum == (-1))
	{	saverec(nname, nsurname, nstuno, nrecord);	}
	else
	{	system("clear");
		std::cout << "Student '" << nstuno << "' already in record. Student not added." << std::endl;	}


}

void read_data(void){
	
	//create file here
	std::ofstream out;
	out.open("data.txt");
	
	for (int i = 0; i < s.size(); i = i + 1)
	{
		std::string line = s[i].name + " " + s[i].surname + " " + s[i].stuno + " " + s[i].record;
		out << line << endl;
	}

}


void save_data(void){
//give more information
	
	std::string nname;
	std::string nsurname;
	std::string nstuno;
	std::string nrecord;
	
	//read file
	std::ifstream infile("thefile.txt");						//change to filename they input
	//while(hasnext)
	std::string line;
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		
		iss >> nname >> nsurname >> nstuno;
		std::string mark;
		std::string marks = "";
		while (!iss.eof()){
			iss >> mark;
			marks += mark + " ";	}
		saverec(nname, nsurname, nstuno, marks);
	}
	
//once done
	system("clear");
	std::cout << "Data capture complete." << std::endl;
}

void disp_student(void){
//give more information
	std::cout << "Enter a student number:" << std::endl;
	std::string num;
	std::cin >> num;
	
	int recnum = findstudent(num);
	
	if (recnum != -1)
	{	system("clear");
		printrec(recnum);		}
	else
	{	system("clear");
		std::cout << "Student " << recnum << " not found." << std::endl;	}

}

int findstudent(std::string num){
	for (int i = 0; i < s.size(); i = i + 1)
	{
		if (s[i].stuno == num)
		{	return i;		}
	}
	return (-1);
}

void saverec(std::string nname, std::string nsurname, std::string nstuno, std::string nrecord){
	int i = s.size();
	s.push_back(StudentRecord());
	s[i].name = nname;
	s[i].surname = nsurname;
	s[i].stuno = nstuno;
	s[i].record = nrecord;
	
	system("clear");
	std::cout << "Student '" << s[i].stuno << "' added. Number of records: " << s.size() << std::endl;
}

void printrec(int i){
	std::cout << "Student name: " << s[i].name << std::endl;
	std::cout << "Student surname: " << s[i].surname << std::endl;
	std::cout << "Student number: " << s[i].stuno << std::endl;
	std::cout << "Class record: " << s[i].record << std::endl;
}


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
		std::cout << "Student '" << num << "' has a class record of " << av << std::endl;	}
	else
	{	system("clear");
		std::cout << "Student '" << num << "' not found." << std::endl;	}

}

}//end namespace

