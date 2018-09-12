#include <iostream>

using namespace std;

int gcd(int,int);

int main(int argc, char **argv)
{
	int g,h,c;
	
	cout << "Enter the first number" << endl;
	
	cin >> g;
	
	cout << "Enter the second number" << endl;
	
	cin >> h;
	
	if (g < h)
	{
		c=h;
		h=g;
		g=c;
	}
	cout << "The greatest common divisor of " << g << " and " << h << " is " << gcd(g,h);
	 
	return 0;
	
}

int gcd(int a,int b)
{
	if (b != 0)
       return gcd(b, a % b);
       
    else 
       return a;
}

