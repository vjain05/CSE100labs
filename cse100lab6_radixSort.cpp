#include<iostream>
#include<limits.h>

using namespace std;

void countingSort(int* A, int *B, int n, int d, int r);
void radixSort(int* A,int *B,int n,int r);

int main(){

	int input;
	cin>>input;
	while(input!=0){

		int *A;
		int *B;
		A= new int[input];
		B= new int[input];
		for(int i=0;i<input;i++){
			cin>>A[i];
		}
		int d=0;
		int r=3;
		//countingSort(A, B, input,d,r);
		//radixSort(A,B,input,r);


	while(d*r<=32){
		B=new int[input];
		countingSort(A,B,input,d,r);
		//delete [] A;
		A=B;
		//B=new int[input];
		//delete[] B;
		
		d+=1;
	}
		for(int i=0;i<input;i++){
			cout<<B[i]<<endl;
		}
		cin>>input;
	}
	return 0;
}


void countingSort(int* A, int *B, int n, int d, int r){
	int k=0;
	int ones=0;
	int a_i;
	int a_j_minus_1;
	for(int z=1;z<=r;z++){
		ones=ones<<1;
		ones+=1;	
	}
	//cout<<"ones "<<ones<<endl;
	for(int i=0;i<n;i++){
		a_i=(A[i]>>(r*d)) & ones;
		if(a_i>k){
			k=a_i;
		}
		//cout<<"bits "<<(A[i]>>(r*d))<<endl;
	}
	//cout<<"k "<<k<<endl;
	int C[k+1];
	for(int i=0;i<=k;i++){
		C[i]=0;
	}
	for(int j=1;j<=n;j++){
		a_j_minus_1=(A[j-1]>>(r*d)) & ones;
		C[a_j_minus_1]=C[a_j_minus_1]+1;
	}
	for(int i=1;i<=k;i++){
		C[i]=C[i]+C[i-1];
	}
	for(int j=n;j>=1;j--){
		a_j_minus_1=(A[j-1]>>(r*d)) & ones;
		B[C[a_j_minus_1]-1]=A[j-1];
		C[a_j_minus_1]=C[a_j_minus_1]-1;
	}
}
void radixSort(int *A,int *B,int n,int r){
int d=0;
	while(d*r<=32){
		B=new int[n];
		countingSort(A,B,n,d,r);
		//delete [] A;
		A=B;
		//delete[] B;
		
		d+=1;
	}
}
