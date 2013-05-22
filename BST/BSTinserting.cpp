#include <iostream>
#include <stdlib.h>
#include "BST.h"

using namespace std;

int main(int argc,char **argv)
{
  // Create an empty Binary Search Tree
  BST Tree;
  //Tree=new BST();
  string input;
  cin>>input;
  while(input!="ENDINSERT"){
	Tree.Insert(input);
	
	cin>>input;
  }
  Tree.Print("POST");
}
