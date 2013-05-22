#include <iostream>
#include <list>
using namespace std;

void bucket_sort(double* ar1, int n);
int main(){
	
	int input;
	cin>>input;
	while(input!=0){

		double arr[input];
		for(int i=0;i<input;i++){
			cin>>arr[i];
		}

		bucket_sort(arr,input);
		for(int i=0;i<input;i++){
			cout<<arr[i]<<endl;
		}

		cin>>input;
	}
	return 0;
}
void bucket_sort(double* ar1, int n){//n is ar1's length
	list<double> B[n];//B's indices go from 0 to n-1
	for(int i=1;i<=n;i++){
		B[(int)(n*ar1[i-1])].push_front(ar1[i-1]);//floor is implicit
	}
	for(int i=0;i<=n-1;i++){
		B[i].sort();
	}
	int index=0;
	for(int i=0;i<=n-1;i++){
		while(!B[i].empty()){
			ar1[index]=B[i].front();
			B[i].pop_front();
			index++;
		}
	}


}
