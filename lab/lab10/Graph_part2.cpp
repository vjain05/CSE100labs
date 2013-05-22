#include <map>
#include <list>
#include <iostream>
#include <string>
#include <queue>
#include <limits.h>

using namespace std;

struct Graph {
    list<string> vertices;
    map<pair<string,string>,int> edges;
    void PrintOut(void);
    void AddEdge(string,string,int);
    bool FindVertex(string);
    int FindEdgeCost(string vert1, string vert2);
    int IsReachable(string vert1, string vert2);
};

void Graph::PrintOut(void) {
    list<string>::iterator it;
    map<pair<string,string>,int>::iterator eit;
    
    for(it=vertices.begin(); it!=vertices.end(); it++) {
        cout << *it << endl;
    }
    
    for(eit = edges.begin(); eit != edges.end(); eit++) {
        cout << (*eit).first.first << " " << (*eit).first.second << " " << (*eit).second << endl;
    }
}

void Graph::AddEdge(string vert1,string vert2,int weight) {
	edges.insert(make_pair(make_pair(vert1,vert2),weight));
}

bool Graph::FindVertex(string vert1) {
	list<string>::iterator it;
	for(it=vertices.begin();it!=vertices.end();it++){
		if(*it==vert1){
			return true;
		}
	}
	return false;
}

int Graph::FindEdgeCost(string vert1, string vert2) {
	map<pair<string,string>,int>::iterator eit;
	eit=edges.find(make_pair(vert1,vert2));
	if(eit!=edges.end()){
		return (*eit).second;
	}
	else{
		return -1;
	}
}

int Graph::IsReachable(string vert1, string vert2) {
	queue<string> q;
	string u;
	string v;
	map<pair<string,string>,int>::iterator adj;
	list<string>::iterator it;
	map<string,int> color;
	map<string,int> distance;
	map<string,string> predecessor;
	
	if(vert1==vert2){
		return 0;
	}
	for(it=vertices.begin();it!=vertices.end();it++){
		color[(*it)]=0;
		distance[(*it)]=INT_MAX;
		predecessor[(*it)]="NONE";
	}
	color[vert1]=1;
	distance[vert1]=0;
	q.push(vert1);
	while(!q.empty()){
		u=q.front();
		q.pop();
		for(adj = edges.begin(); adj != edges.end(); adj++){
			if((*adj).first.first==u){
				if(color[(*adj).first.second]==0){
					color[(*adj).first.second]=1;
					distance[(*adj).first.second]=distance[u]+1;
					predecessor[(*adj).first.second]=u;
					q.push((*adj).first.second);
					if((*adj).first.second==vert2){
						return distance[(*adj).first.second];
					}
				}
			}
		}
		color[u]=2;
	}
	return -1;
}

int main() {
    Graph G;
	string input;
	int opcode;
	string ver1;
	string ver2;
	int weigh;
	cin>>input;
	while(input!="END"){
		G.vertices.push_back(input);
		cin>>input;
	}
	cin>>input;
	while(input!="END"){
		ver1=input;
		cin>>input;
		ver2=input;
		cin>>weigh;
		if(G.FindVertex(ver1)==1 && G.FindVertex(ver2)==1){
			G.AddEdge(ver1,ver2,weigh);
		}
		cin>>input;
	}
	//G.PrintOut();
	cin>>opcode;
	while(opcode!=0){
		if(opcode==1){
			cin>>ver1;
			cout<<G.FindVertex(ver1)<<endl;
		}
		else{
			cin>>ver1;
			cin>>ver2;
			if(opcode==2){
				cout<<G.FindEdgeCost(ver1,ver2)<<endl;
			}
			else{
				cout<<G.IsReachable(ver1,ver2)<<endl;
			}
		}
		cin>>opcode;
	}
}
