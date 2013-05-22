#include <iostream>
#include <vector>

using namespace std;

int main(){

	int input=1;
	int integers;
	vector<int> numbas;
	vector<int> sizes;

	while(input!=0){
		cin>>input;
		numbas.resize(numbas.size()+input);
		sizes.resize(sizes.size()+1);
		sizes[sizes.size()-1]=input;
		for(int i=0;i<input;i++){
			cin>>integers;
			numbas[numbas.size()-1-i]=integers;
		}
	}

	//cout<<endl;
	int beginning=0;
	int end=0;
	int check=0;

	for(int j=0;j<sizes.size();j++){
		end+=sizes[j];
		for(int k=beginning;k<end-1;k++){
			if(numbas[k]<numbas[k+1]){
				cout<<"INCORRECT SEQUENCE"<<endl;
				check=1;
				break;
			}
		}
		if(check!=1){
			for(int s=beginning;s<end;s++){
				cout<<numbas[s]<<endl;
			}
		}
		else{
			check=0;
		}
		beginning=end;
	}
	return 0;
}
