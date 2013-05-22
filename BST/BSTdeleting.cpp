#include <iostream>
#include <stdlib.h>
#include "BST.h"

using namespace std;

int main(int argc,char **argv)
{
  // Create an empty Binary Search Tree
  BST Tree;
  string input;
  cin>>input;
  while(input!="ENDINSERT"){
	Tree.Insert(input);
	
	cin>>input;
  }
  Tree.Print("POST");
  cout<<"transition"<<endl;
  cin>>input;
  while(input!="ENDDELETE"){
		Tree.Delete(input);
	  cin>>input;
  }
  Tree.Print("POST");
}
