#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct Node{
	int freq;
	string character;
	Node *left;
	Node *right;


	Node(int newFreq, string newCharacter){
		freq=newFreq;
		character=newCharacter;
		left=NULL;
		right=NULL;
	}
	bool operator<(const Node &a) const{
		//return freq>=a.freq;
		return 1/(double)(freq)<1/(double)(a.freq);
	}

};
void print_traverse(Node *p,string cod, vector<string> &answers);
void Huffman(queue<int> &c_freq, queue<string> &c_chars, vector<string> &answers);
int main(){
	queue<string> queries;
	queue<string> queries2;
	vector<string> answers(6,"");
	queries.push("A");
	queries.push("B");
	queries.push("C");
	queries.push("D");
	queries.push("E");
	queries.push("F");

	queries2.push("A");
	queries2.push("B");
	queries2.push("C");
	queries2.push("D");
	queries2.push("E");
	queries2.push("F");

	vector<int> theFreq(6,0);
	queue<int> subst;

	int *codes;

	string input;
	int iter=0;
	cin>>input;
	char charInput[input.length()];
	for(int st=0;st<input.length();st++){
		charInput[st]=input[st];
	}

	for(int z=0;z<input.length();z++){
		if(charInput[z]=='A'){
			theFreq[0]+=1;
		}
		else if(charInput[z]=='B'){
			theFreq[1]+=1;
		}
		else if(charInput[z]=='C'){
			theFreq[2]+=1;
		}
		else if(charInput[z]=='D'){
			theFreq[3]+=1;
		}
		else if(charInput[z]=='E'){
			theFreq[4]+=1;
		}
		else if(charInput[z]=='F'){
			theFreq[5]+=1;
		}
		iter++;
	}
	for(int i=0;i<6;i++){
		subst.push(theFreq[i]);
	}

	Huffman(subst,queries,answers);
	for(int i=0;i<6;i++){

		cout<<queries2.front()<<" "<<answers[i]<<endl;
		queries2.pop();
	}
	
	return 0;
}
void Huffman(queue<int> &c_freq, queue<string> &c_chars, vector<string> &answers){

	priority_queue<Node> q;
	while(!c_freq.empty()){
		Node n(c_freq.front(),c_chars.front());
		q.push(n);
		c_freq.pop();
		c_chars.pop();
	}

	int siz=q.size();
	for(int i=1;i<siz;i++){

		Node z(-1,"");

		z.left= new Node(q.top());
		q.pop();
		z.right=new Node(q.top());
		q.pop();
		z.freq=z.left->freq+z.right->freq;

		q.push(z);
	}

	string code="";

	Node *pp;
	pp=new Node(q.top());
	print_traverse(pp,code,answers);

}
void print_traverse(Node *p,string cod, vector<string> &answers){
	if(p->left!=NULL){
		print_traverse(p->left,cod+'0',answers);
		print_traverse(p->right,cod+'1',answers);
	}
	else{
		//cout<<p->character<<" "<<p->freq<<endl;
		if(p->character.compare("A")==0){
			answers[0]=cod;
		}
		else if(p->character.compare("B")==0){
			answers[1]=cod;
		}
		else if(p->character.compare("C")==0){
			answers[2]=cod;
		}
		else if(p->character.compare("D")==0){
			answers[3]=cod;
		}
		else if(p->character.compare("E")==0){
			answers[4]=cod;
		}
		else{
			answers[5]=cod;
		}
	}
}
