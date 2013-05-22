#include<iostream>

using namespace std;

void mergeSort(int* ar1, int ar1_size, int p, int r);
void merge(int* ar1, int ar1_size, int p, int q, int r);

int main(){

	int input;
	cin>>input;
	while(input!=0){

		int arr[input];
		for(int i=0;i<input;i++){
			cin>>arr[i];
		}

		mergeSort(arr, input,1,input);
		for(int i=0;i<input;i++){
			cout<<arr[i]<<endl;
		}

		cin>>input;
	}
	return 0;
}


void mergeSort(int* ar1, int ar1_size, int p, int r){

	if(p<r){
		int q=(p+r)/2;//floor is implicit
		mergeSort(ar1,ar1_size,p,q);
		mergeSort(ar1,ar1_size,q+1,r);
		merge(ar1,ar1_size,p,q,r);
	}


}
void merge(int* ar1, int ar1_size, int p, int q, int r){
	int n_1=q-p+1;
	int n_2=r-q;
	int L[n_1+1];
	int R[n_2+1];

	for(int i=1;i<=n_1;i++){
		L[i-1]=ar1[p+i-1-1];
		
	}
	for(int j=1;j<=n_2;j++){
		R[j-1]=ar1[q+j-1];
	
	}
	L[n_1+1-1]=INT_MAX;
	R[n_2+1-1]=INT_MAX;
	int i=1;
	int j=1;
	for(int k=p;k<=r;k++){
		
		if(L[i-1]<R[j-1]){
			ar1[k-1]=L[i-1];
			i=i+1;
		}
		else{
			ar1[k-1]=R[j-1];
			j=j+1;	
		}
	}
}
