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
	string email;
};


		/*  PRINTS STUDENT INCLUDING EMAILS -- NOT A REQUIREMENT */
void displayStudentInfo(vector<STUDENT_DATA> students) {

	for (const auto& student : students) {
		std::cout << "First Name: " << student.firstname
			<< ", Last Name: " << student.lastname << 
				", email: " << student.email << endl;
	}

}

void readStudentEmails(string fileName) {

	ifstream inputFile(fileName);
	vector<STUDENT_DATA> studentsEmailData;

	if (!inputFile.is_open()) {
		cout << "Error opening the file!" << endl;
		return;
	}

	string line;

	while (getline(inputFile, line)) {

		stringstream ss(line);
		string firstname, lastname, email;

		STUDENT_DATA student;

		getline(ss, lastname, ',');
		getline(ss, firstname, ',');
		getline(ss, email, ',');

		student.lastname = lastname;
		student.firstname = firstname;
		student.email = email;

		studentsEmailData.push_back(student);

	}

	displayStudentInfo(studentsEmailData);

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

	/*   CONSOLES ALL STUDENT INFORMATION  */
	#ifdef _DEBUG
		for (const auto& student : students) {
			std::cout << "First Name: " << student.firstname
				<< ", Last Name: " << student.lastname << std::endl;
		}
	#endif


	/*   PRE_RELEASE VERSION ADDITIONAL: PRINTS OUT STUDENT INFO  */
	#ifdef PRE_RELEASE
			std::cout << "application is running standard or pre-release source code" << endl;
			readStudentEmails("StudentData_Emails.txt");
	#endif


	return 1;
}