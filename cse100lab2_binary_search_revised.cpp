#include<iostream>
#include<math.h>
using namespace std;

void binary_search(int* ar1, int length, int search);

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
		binary_search(arr,input,searcher);
		cin>>input;
	}
	return 0;
}

void binary_search(int* ar1, int length, int search){
	int l=1;
	int r=length;
	int m;
	while(l<=r){
		m=ceil(((double)(r+l))/((double)(2)));
		if(ar1[m-1]==search){
			cout<<m-1<<endl;
			return;
		}
		else if(ar1[m-1]>search){
			r=m-1;
		}
		else{
			l=m+1;
		}
	}
	cout<<-1<<endl;
	return;
}
