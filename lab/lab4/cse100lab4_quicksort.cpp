#include<iostream>

using namespace std;

void quicksort(int* ar1, int p, int r);
int partition(int* ar1, int p, int r);
int rand_partition(int* ar1, int p, int r);

int main(){

	int input;
	cin>>input;
	while(input!=0){

		int arr[input];
		for(int i=0;i<input;i++){
			cin>>arr[i];
		}

		quicksort(arr,1,input);
		for(int i=0;i<input;i++){
			cout<<arr[i]<<endl;
		}

		cin>>input;
	}
	return 0;
}
void quicksort(int* ar1, int p, int r){
	if(p<r){
		int q;
		q=rand_partition(ar1,p,r);
		quicksort(ar1,p,q-1);
		quicksort(ar1,q+1,r);
	}
}
int rand_partition(int* ar1, int p, int r){
	int i;int exchng;
	i=(rand()%(r-p))+p;
	exchng=ar1[r-1];
	ar1[r-1]=ar1[i-1];
	ar1[i-1]=exchng;
	return partition(ar1,p,r);
}
int partition(int* ar1, int p, int r){
	int x;int i;int exchng;
	x=ar1[r-1];
	i=p-1;
	for(int j=p;j<=r-1;j++){
		if(ar1[j-1]<=x){
		i=i+1;
		exchng=ar1[i-1];
		ar1[i-1]=ar1[j-1];
		ar1[j-1]=exchng;
		//exchange a[i] with a[j]
		}
	}
	exchng=ar1[r-1];
	ar1[r-1]=ar1[i+1-1];
	ar1[i+1-1]=exchng;
	//exchange a[r] with a[i+1]
	return i+1;
}
