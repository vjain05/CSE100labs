#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


void binary_search(vector<int> arr, int search);

int main(){

	int input=1;
	vector<int> num2search2;
	int integers;
	vector<int> numbas2;
	vector<int> sizes2;
	int sz=0;

	int counter=0;
	while(input!=0){//take the inputs
		cin>>input;
		if(input!=0){
			num2search2.resize(num2search2.size()+1);
			cin>>num2search2[counter];
			counter++;
			numbas2.resize(numbas2.size()+input);
			sizes2.resize(sizes2.size()+1);
			sizes2[sizes2.size()-1]=input;
		}
		for(int i=0;i<input;i++){
			cin>>integers;
			numbas2[i+sz]=integers;
		}
		sz=numbas2.size();
	}
	int beginning=0;
	int end=0;
	for(int j=0;j<sizes2.size();j++){//execute algorithm
		end+=sizes2[j];
		vector<int> arr2pass2(&numbas2[beginning],&numbas2[end]);
		binary_search(arr2pass2,num2search2[j]);
		beginning=end;
	}	
	return 0;
}
void binary_search(vector<int> arr, int search){
	int l=0;
	int m;
	int r=arr.size();
	while(l<=r){
		m=floor((double)(r+l)/(double)(2));
		if(arr[m]==search){
			cout<<m<<endl;
			return;
		}
		else if(arr[m]>search){
			r=m-1;
		}
		else{
			l=m+1;
		}
	}
	cout<<-1<<endl;
	return;
}
