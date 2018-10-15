#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct Student{
	int studID;
	string studName;
	int age;
	char gender;
	float score;
	char grade;
};
char getGrade(float);

int main()
{
	int totalScore = 0;
	int totalAge = 0;
	float averageScore;
	float averageAge;
	int maleCount = 0;
	int femaleCount = 0;
	
	Student student[5]; 
	
	fstream in;
	in.open("gradeScheme.txt");
	
	in << "*************************************************************************************************************" << endl;
	
	in << "IDNumber" << setw(12) << "Name" << setw(15) << "Age" << setw(18) << "Gender" <<setw(15) << "Score" <<setw(18) <<"Grade" << endl;
	
	for(int i=0;i<5;i++)
	{
		cout << "Student " << (i+1) << endl;
		cout << "Enter your ID number : " ;
		cin >> student[i].studID;
		in << left << setw(15) << student[i].studID;
		cout << endl;
		
		cout << "Enter your first name : ";
		cin >> student[i].studName;
		in <<left<< setw(17) << student[i].studName;
		cout << endl;
		
		cout << "Enter your age : ";
		cin >> student[i].age;
		totalAge = totalAge + student[i].age;
		in <<left<< setw(13) << student[i].age;
		cout << endl;
		
		cout << "Enter your gender (M/F): ";
		cin >> student[i].gender;
		in <<left<< setw(18) << student[i].gender;
		cout << endl;
		
		cout << "Enter your score : ";
		cin >> student[i].score;
		totalScore = totalScore + student[i].score;
		in <<left<< setw(18) << student[i].score;
		cout << endl;
		
		student[i].grade = getGrade(student[i].score);
		in <<left<< setw(16) << student[i].grade << endl;
		cout << endl;
		
		if(student[i].gender == 'M' || student[i].gender == 'm')
			maleCount++;
		else if(student[i].gender == 'F' || student[i].gender == 'f')
			femaleCount++;
			
		cout <<"-------------------------------------------"<<endl;
	}
	
	in << "***********************************************************************************************************" << endl;
	
	averageAge = totalAge/5.0;
	averageScore = totalScore/5.0;
	
	
	in << "Average Age : " << averageAge << endl;
	in << "Average Score : " << averageScore << endl;
	in << "No. of Males : " << maleCount << endl;
	in << "No. of females : " << femaleCount << endl; 
	
	return 0;
}

char getGrade(float marks)
{
	char Grade;
	
	if(marks >= 80 && marks <=100)
		Grade = 'A';
		
	else if(marks >=70 && marks <=79)
		Grade = 'B';
		
	else if(marks >=60 && marks <=69)
		Grade = 'C';
		
	else if(marks >=50 && marks <=59)
		Grade = 'D';
		
	else if(marks >=40 && marks <=49)
		Grade = 'E';
		
	else if(marks >=0 && marks <=39)
		Grade = 'F';
		
	return Grade;
		
}
