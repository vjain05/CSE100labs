#include<iostream>

using namespace std;

void heapsort(int* ar1, int length, int heapsize);
void build_max_heap(int* ar1, int heapsize);
void max_heapify(int* ar1, int heapsize, int i);
int parent( int i);
int left( int i);
int right( int i);
int main(){
	int heap_size;
	int input;
	cin>>input;
	while(input!=0){

		int arr[input];
		for(int i=0;i<input;i++){
			cin>>arr[i];
		}
		heap_size=input;
		heapsort(arr,input,heap_size);
		for(int i=0;i<input;i++){
			cout<<arr[i]<<endl;
		}

		cin>>input;
	}
	return 0;
}
void heapsort(int* ar1, int length, int heapsize){
	int exchng;
	build_max_heap(ar1, heapsize);
	for(int i=length;i>=2;i--){
		exchng=ar1[1-1];
		ar1[1-1]=ar1[i-1];
		ar1[i-1]=exchng;
		heapsize=heapsize-1;
		max_heapify(ar1, heapsize, 1);
	}
}
void build_max_heap(int* ar1, int heapsize){
	int n;
	n=heapsize;
	for(int i=parent(n);i>=1;i--){
		max_heapify(ar1, heapsize, i);
	}
}
void max_heapify(int* ar1, int heapsize, int i){
	int n;int l;int r;int largest;int exchng;
	n=heapsize;
	l=left(i);
	r=right(i);
	if(ar1[i-1]<ar1[l-1] && l<=n){
		largest=l;
	}
	else{
		largest=i;
	}
	if(ar1[largest-1]<ar1[r-1] && r<=n){
		largest=r;
	}
	if(largest!=i){
		exchng=ar1[i-1];
		ar1[i-1]=ar1[largest-1];
		ar1[largest-1]=exchng;
		max_heapify(ar1, heapsize, largest);
	}
}
int parent( int i){
	return i/2;//floor is implicit
}
int left( int i){
	return 2*i;
}
int right( int i){
	return 2*i+1;
}

