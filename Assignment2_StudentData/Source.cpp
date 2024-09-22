#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


struct STUDENT_DATA {
	string firstname;
	string lastname;
};


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


	return 1;
}