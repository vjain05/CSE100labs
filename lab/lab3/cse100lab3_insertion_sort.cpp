#include<iostream>

using namespace std;

void insertionSort(int* ar1, int ar1_size);

int main(){

	int input;
	cin>>input;
	while(input!=0){

		int arr[input];
		for(int i=0;i<input;i++){
			cin>>arr[i];
		}

		insertionSort(arr, input);
		for(int i=0;i<input;i++){
			cout<<arr[i]<<endl;
		}
		cin>>input;
	}
	return 0;
}


void insertionSort(int* ar1, int ar1_size){

	int key;
	int i;
	for(int j=2;j<=ar1_size;j++){
		key=ar1[j-1];
		i=j-1;
		while(ar1[i-1]>key & i>0){
			ar1[i+1-1]=ar1[i-1];
			i=i-1;
		}
		ar1[i+1-1]=key;
	}

}
