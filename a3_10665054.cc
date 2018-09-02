#include <iostream>

using namespace std;

int main(int argc,char **argv)
{
	int score;
	
	cout<< "Enter your score" <<endl;
	
	cin >> score;
	
	if (score >= 80 && score <= 100)
	{
		cout << "Your grade is A";
		
	}
	
	else if (score >= 75 && score <= 79)
	{
		cout << "Your grade is B+";
		
	}
	
	else if (score >= 70 && score <= 74)
	{
		cout << "Your grade is B";
		
	}
	
	else if (score >= 65 && score <= 69)
	{
		cout << "Your grade is C+";
		
	}
	
	else if (score >= 60 && score <= 64)
	{
		cout << "Your grade is C";
		
	}
	
	else if (score >= 55 && score <= 59)
	{
		cout << "Your grade is D+";
		
	}
	
	else if (score >= 50 && score <= 54)
	{
		cout << "Your grade is D";
		
	}
	
	else if (score >= 45 && score <= 49)
	{
		cout << "Your grade is E";
		
	}
	
	else if (score >= 0 && score <= 44)
	{
		cout << "Your grade is F";
		
	}
	
	else
	{
		cout << "Invalid input";
	}	


	return 0;
	
	}

