#include <iostream>
#include <list>
#include <limits.h>
using namespace std;
void open_hash_search(list<int>* T, int k, int m);
void open_hash_insert(list<int>* T, int k, int m);
void open_hash_delete(list<int>* T, int k, int m);
int hash_func(int k, int i);
int hash_func_1(int k);
int hash_func_2(int k);
void print_hash_table(list<int>* T, int m);
int main(){
int m;
m=13;
list<int> T[m];
int inputs;
cin>>inputs;
while(inputs!=-1){
	//insert
	open_hash_insert(T,inputs,m);
	cin>>inputs;
}
//print contents of hash table
print_hash_table(T, m);
cin>>inputs;
while(inputs!=-2){
	//search, print location
	open_hash_search(T,inputs,m);
	cin>>inputs;
}
cin>>inputs;
while(inputs!=-3){
	//delete
	open_hash_delete(T,inputs,m);
	cin>>inputs;
}
//print contents of hash table
print_hash_table(T, m);
}
void open_hash_search(list<int>* T, int k, int m){
	//list<int>::iterator it;
	int i=0;
	int j=0;
	do{
		j=hash_func(k,i);
		if(T[j].front()==k){
			cout<<j<<endl;
			return;
		}
		i=i+1;
	}while(!T[j].empty() && i!=m);
	cout<<"NOT_FOUND"<<endl;

	return;
}
void open_hash_insert(list<int>* T, int k, int m){

	int i=0;
	int j=0;
	do{
		//cout<<"j "<<j<<endl;
		j=hash_func(k,i);
		if(T[j].empty() ){
			T[j].push_front(k);
			return;
		}
		else if(T[j].front()==INT_MAX){
			T[j].remove(INT_MAX);
			T[j].push_front(k);
			return;
		}
		else{
			i=i+1;
		}
	}while(i!=m);
	cout<<"HASH TABLE OVERFLOW"<<endl;
}
void open_hash_delete(list<int>* T, int k, int m){
	int i=0;
	int j=0;
	do{
		j=hash_func(k,i);
		if(T[j].front()==k){
			T[j].remove(k);
			T[j].push_front(INT_MAX);
			return;
		}
		i=i+1;
	}while(!T[j].empty() && i!=m);
}
int hash_func_1(int k){
	return k%13;
}
int hash_func_2(int k){
	return 1+k%11;
}
int hash_func(int k, int i){
	return (hash_func_1(k)+i*hash_func_2(k))%13;
}
void print_hash_table(list<int>* T, int m){
	list<int>::iterator it;
	for(int i=0;i<m;i++){
		for(it=T[i].begin();it!=T[i].end();++it){
			//cout<<*it<<"->";
			if(*it!=INT_MAX){
				cout<<*it;
			}
		}
		cout<<endl;
	}
}
