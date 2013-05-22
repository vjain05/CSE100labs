#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


void linear_search(vector<int> arr, int search);

int main(){

	int input=1;
	vector<int> num2search;
	int integers;
	vector<int> numbas;
	vector<int> sizes;
	int sz=0;

	int counter=0;
	while(input!=0){//take the input
		cin>>input;
		if(input!=0){
			num2search.resize(num2search.size()+1);
			cin>>num2search[counter];
			counter++;
			numbas.resize(numbas.size()+input);
			sizes.resize(sizes.size()+1);
			sizes[sizes.size()-1]=input;
		}
		for(int i=0;i<input;i++){
			cin>>integers;
			numbas[i+sz]=integers;
		}
		sz=numbas.size();
	}
	int beginning=0;
	int end=0;
	for(int j=0;j<sizes.size();j++){//execute the algorithm
		end+=sizes[j];
		vector<int> arr2pass(&numbas[beginning],&numbas[end]);
		linear_search(arr2pass,num2search[j]);
		beginning=end;
	}	
	return 0;
}
void linear_search(vector<int> arr, int search){
	for(int s=0;s<arr.size();s++){
		if(arr[s]==search){
			cout<<s<<endl;
			return;
		}
	}
	cout<<-1<<endl;
	return;	
}
