#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

/****************************************************************
 * CONSTRUCTOR #1 
 *   Creates an binary tree
 ****************************************************************/
BST::BST() {
  // Write your codes here
	root=NULL;
	//cout<<"hi"<endl;
}

/****************************************************************
 * DECONSTRUCTOR
 *   Empty constructor
 ****************************************************************/
BST::~BST() {
}

void BST::Insert(string toInsert) {
  // Write your codes here
	Node *x;
	x=root;
	Node *paren;
	if(x==NULL){
		root=new Node;
		root->left=NULL;
		root->right=NULL;
		root->val=toInsert;
		return;
	}
	//cout<<x->val.compare(toInsert)<<endl;
	while(x!=NULL){
		if(x->val.compare(toInsert)>0){
			//cout<<"to the left"<<endl;
			paren=x;
			x=x->left;
		}
		else{
			//cout<<"to the right"<<endl;
			paren=x;
			x=x->right;
		}
	}
	//cout<<"begin insert"<<endl;
	x=new Node;
	x->left=NULL;
	x->right=NULL;
	x->val=toInsert;
	x->parent=paren;
	if(paren->val.compare(toInsert)>0){
		paren->left=x;
	}
	else{
		paren->right=x;
	}
}

void BST::Delete(string toDelete) {
  // Write your codes here
	//cout<<"deleting "<<toDelete<<endl;
	Node *z;
	z=Search(toDelete);
	if(z==NULL){return;}
	if(z->left==NULL){Transplant(z,z->right);}
	else if(z->right==NULL){Transplant(z,z->left);}
	else{
		Node *y;
		y=Minimum(z->right);
		if(y->parent!=z){
			Transplant(y,y->right);
			y->right=z->right;
			y->right->parent=y;
		}
		Transplant(z,y);
		y->left=z->left;
		y->left->parent=y;
	}
}

void BST::Transplant(Node *u, Node *v) {
  // Write your codes here
	if(u->parent==NULL){
		root=v;
	}
	else if(u==u->parent->left){
		u->parent->left=v;
	}
	else{
		u->parent->right=v;
	}
	if(v!=NULL){
		v->parent=u->parent;
	}
}

Node *BST::Successor(Node *x) {
  // Write your codes here
	if(x->right!=NULL){
		return Minimum(x->right);
	}
	Node *y;
	y=x->parent;
	while(y!=NULL && x==y->right){
		x=y;
		y=y->parent;
	}
	return y;
}

Node *BST::Minimum(Node *x) {
  // Write your codes here
	//x=root;
	while(x->left!=NULL){
		x=x->left;
	}
	return x;
}

Node *BST::Maximum(Node *x) {
  // Write your codes here
	//x=root;
	while(x->right!=NULL){
		x=x->right;
	}
	return x;
}

Node *BST::Search(string toFind) {
  // Write your codes here
	Node *x;
	x=root;
	while(x!=NULL){
		//cout<<"found "<<x->val<<endl;
		if(x->val.compare(toFind)==0){
			return x;
		}
		if(x->val.compare(toFind)>0){
			//cout<<"went left"<<endl;
			x=x->left;
		}
		else{
			//cout<<"went right"<<endl;
			x=x->right;
		}
	}
	return x;

}

void BST::Print(string Order) {
  if(Order=="IN")
    InOrder(root);
  else if(Order=="PRE")
    PreOrder(root);
  else if(Order=="POST")
    PostOrder(root);
}

void BST::PreOrder(Node *x) {
  // Write your codes here
	if(x==NULL){
		return;
	}
	cout<<x->val<<endl;
	PreOrder(x->left);
	PreOrder(x->right);
}

void BST::InOrder(Node *x) {
  // Write your codes here
	if(x==NULL){
		return;
	}
	InOrder(x->left);
	cout<<x->val<<endl;
	InOrder(x->right);
}

void BST::PostOrder(Node *x) {
  // Write your codes here
	//cout<<"geta"<<endl;
	if(x==NULL){
		//cout<<"boo"<<endl;
		return;
	}
	PostOrder(x->left);
	PostOrder(x->right);
	cout<<x->val<<endl;
}
