#include<iostream>
#include<limits.h>

using namespace std;

void countingSort(int* A, int *B, int n);

int main(){

	int input;
	cin>>input;
	while(input!=0){

		int A[input];
		int B[input];
		for(int i=0;i<input;i++){
			cin>>A[i];
		}

		countingSort(A, B, input);
		for(int i=0;i<input;i++){
			cout<<B[i]<<endl;
		}
		cin>>input;
	}
	return 0;
}


void countingSort(int* A, int *B, int n){
	int k=INT_MIN;
	for(int i=0;i<n;i++){
		if(A[i]>k){
			k=A[i];
		}
	}
	int C[k+1];
	for(int i=0;i<=k;i++){
		C[i]=0;
	}
	for(int j=1;j<=n;j++){
		C[A[j-1]]=C[A[j-1]]+1;
	}
	for(int i=1;i<=k;i++){
		C[i]=C[i]+C[i-1];
	}
	for(int j=n;j>=1;j--){
		B[C[A[j-1]]-1]=A[j-1];
		C[A[j-1]]=C[A[j-1]]-1;
	}
}
