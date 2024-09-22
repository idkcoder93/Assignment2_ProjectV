#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#define PRE_RELEASE

using namespace std;


struct STUDENT_DATA {
	string firstname;
	string lastname;
};


void readStudentEmails(string fileName) {

	ifstream inputFile(fileName);
	vector<string> studentsEmailData;

	if (!inputFile.is_open()) {
		cout << "Error opening the file!" << endl;
		return;
	}

	string line;

	while (getline(inputFile, line)) {

		stringstream ss(line);
		string firstname, lastname, email;

		getline(ss, lastname, ',');
		getline(ss, firstname, ',');
		getline(ss, email, ',');

		studentsEmailData.push_back(email);
	}

	inputFile.close();

}


int main() {

	ifstream inputFile("StudentData.txt");
	vector<STUDENT_DATA> students;

	if (!inputFile.is_open()) {
		cout << "Error opening the file!" << endl;
		return 1;
	}

	string line;

	while (getline(inputFile, line)) {
		
		std::stringstream ss(line);
		string firstName, lastName;

		getline(ss, lastName, ',');
		getline(ss, firstName, ',');

		STUDENT_DATA student;
		student.firstname = firstName;
		student.lastname = lastName;

		students.push_back(student);

	}

	inputFile.close();

	#ifdef _DEBUG
		for (const auto& student : students) {
			std::cout << "First Name: " << student.firstname
				<< ", Last Name: " << student.lastname << std::endl;
		}
	#endif

	#ifdef PRE_RELEASE
			std::cout << "application is running standard or pre-release source code" << endl;
			readStudentEmails("StudentData_Emails.txt");
	#else
			std::cout << "This is the production version." << endl;
	#endif


	return 1;
}