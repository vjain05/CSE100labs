#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits.h>

using namespace std;
void matrix_chain_order(int* p,int n, int** m, int** s);
void print_opt_parens(int i, int j,int n, int** s);
int main(int argc,char **argv)
{
	int input;
	int** m;
	int** s;
	cin>>input;
	while(input!=0){
		int numbas[input+1];
		m=new int*[input+1];
		s=new int*[input+1];
		for (int i=0;i<input+1;i++){
			m[i] = new int[input+1];
		}
		for (int i=0;i<input+1;i++){
			s[i] = new int[input+1];
		}
		for(int i=0;i<input+1;i++){
			cin>>numbas[i];
		
		}

		matrix_chain_order(numbas,input,m,s);
		//cout<<m[1][input]<<endl;
		cin>>input;
	}

}
void print_opt_parens(int i, int j, int n, int** s){
	if(i==j){
		cout<<"A"<<i-1;
	}
	else{
		cout<<"(";
		print_opt_parens(i,s[i][j],n,s);
		print_opt_parens(s[i][j]+1,j,n,s);
		cout<<")";
	}
}
void matrix_chain_order(int* p,int n, int** m, int** s){
	for(int i=1;i<=n+1;i++){
		m[i-1][i-1]=0;
	}
	for(int l=2;l<=n+1;l++){
		for(int i=1;i<=n-l+1+1;i++){
			int j=i+l-1;
			m[i-1][j-1]=INT_MAX;
			for(int k=i;k<=j-1;k++){
				int q=m[i-1][k-1]+m[k+1-1][j-1]+p[i-1-1]*p[k-1]*p[j-1];
				if(q<m[i-1][j-1]){
					m[i-1][j-1]=q;
					s[i-1][j-1]=k-1;
				}
			}
		}
	
	}
	
	print_opt_parens(1,n,n+1,s);
}
