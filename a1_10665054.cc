#include <iostream>

using namespace std;

void check_prime(int);

int main()
{
	int num;
	 
	cout << "Enter a number" << endl;
	
	cin >> num;
	
	check_prime(num);
	
		
	return 0;
}

void check_prime(int value){
	
	int x=1;
	int count = 0;
	
	while (x <= value){
		
		if (value % x ==0){
			
			count ++;
		}
	
		x++;
	}
	
	if (count == 2){
	
		cout << value << " is a prime number!" << endl;
	}
	
	else{
		
		cout << value << " is not a prime number." << endl;
	
	}
}
