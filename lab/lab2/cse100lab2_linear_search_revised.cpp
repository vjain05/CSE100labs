#include<iostream>

using namespace std;

void linear_search(int* ar1, int length, int search);

int main(){
	int searcher;
	int input;
	cin>>input;
	while(input!=0){
		cin>>searcher;
		int arr[input];
		for(int i=0;i<input;i++){
			cin>>arr[i];
		}
		linear_search(arr,input,searcher);
		cin>>input;
	}
	return 0;
}

void linear_search(int* ar1, int length, int search){
	for(int i=0;i<length;i++){
		if(ar1[i]==search){
			cout<<i<<endl;
			return;
		}
	}
	cout<<-1<<endl;
	return;
}
