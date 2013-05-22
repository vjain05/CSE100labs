#include <iostream>
#include <list>
using namespace std;

int main(){
	list<int> billy[5];
	list<int>::iterator it;
	billy[3].push_front(69);
	billy[3].push_front(71);
	it=billy[3].begin();
	cout<<*it<<endl;
	cout<<*(++it)<<endl;
	billy[3].remove(75);
	list<int>::iterator it2;
	it2=billy[3].begin();
	cout<<*it2<<endl;
	cout<<*(++it2)<<endl;
	return 0;
}
