#include <iostream>
#include <list>
using namespace std;
void chaining_hash_search(list<int>* T, int k, int m);
void chaining_hash_insert(list<int>* T, int k, int m);
void chaining_hash_delete(list<int>* T, int k, int m);
int hash_func(int k, int m);
void print_hash_table(list<int>* T, int m);
int main(){
int m;
cin>>m;
list<int> T[m];
int inputs;
cin>>inputs;
while(inputs!=-1){
	//insert
	chaining_hash_insert(T,inputs,m);
	cin>>inputs;
}
//print contents of hash table
print_hash_table(T, m);
cin>>inputs;
while(inputs!=-2){
	//search, print location
	chaining_hash_search(T,inputs,m);
	cin>>inputs;
}
cin>>inputs;
while(inputs!=-3){
	//delete
	chaining_hash_delete(T,inputs,m);
	cin>>inputs;
}
//print contents of hash table
print_hash_table(T, m);
}
void chaining_hash_search(list<int>* T, int k, int m){
	list<int>::iterator it;
	int h_k=hash_func(k,m);
	int i=0;
	for(it=T[h_k].begin();it!=T[h_k].end();++it){
		if(*it==k){
			cout<<h_k<<","<<i<<endl;
			return;
		}
		i=i+1;
	}
	cout<<"NOT_FOUND"<<endl;
	return;
}
void chaining_hash_insert(list<int>* T, int k, int m){
	int h_k=hash_func(k,m);
	T[h_k].push_front(k);

}
void chaining_hash_delete(list<int>* T, int k, int m){
	int h_k=hash_func(k,m);
	
	T[h_k].remove(k);
}
int hash_func(int k, int m){
	return k%m;
}
void print_hash_table(list<int>* T, int m){
	list<int>::iterator it;
	for(int i=0;i<m;i++){
		for(it=T[i].begin();it!=T[i].end();++it){
			cout<<*it<<"->";
		}
		cout<<endl;
	}
}
