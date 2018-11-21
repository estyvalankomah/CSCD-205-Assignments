#include <iostream>
using namespace std;

int arr[] = {34,57,12,5,8,43,17,67,41,20};
int arrSize = 10;
int temp;
int f = 0;
int l = arrSize - 1;
int x = 5;


int binsearch(int array[],int y,int first,int last){
	int mid = (first + last)/2;
	
	if(arr[mid] == y){
		return mid;
	}
		
	else if(arr[mid] > y){
		return binsearch(array,y,first,mid-1);
	}
		
	else if(arr[mid] < y){
		return binsearch(array,y,mid+1,last);
	}
	
	else
		return -1;	
}

int main(){
	
	for(int i=0;i<arrSize - 1;i++){
		for(int j=0;j<arrSize - i - 1;j++){
			if(arr[j+1] < arr[j]){
				temp =  arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp; 
			}
		}
	}
		
	cout << "The search item was found at "<< binsearch(arr,x,f,l);
	
	return 0;
}



	

