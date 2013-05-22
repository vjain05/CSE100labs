#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits.h>

using namespace std;
void matrix_chain_order(int* p,int n, int** m, int** s);
int recursive_matrix_chain(int* p, int i, int j, int** m);
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

		//matrix_chain_order(numbas,input,m,s);
		//int ansa=m[1][input];
		int ansa=recursive_matrix_chain(numbas,1,input,m);
		cout<<ansa<<endl;
		cin>>input;
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
	
	//print_opt_parens(1,n,n+1,s);
}
int recursive_matrix_chain(int* p, int i, int j, int** m){
	if(i==j){
		return 0;
	}
	m[i][j]=INT_MAX;
	for(int k=i;k<=j-1;k++){
		int q=recursive_matrix_chain(p,i,k,m)+recursive_matrix_chain(p,k+1,j,m)+p[i-1]*p[k]*p[j];
		if(q<m[i][j]){
			m[i][j]=q;
		}
	}
return m[i][j];
}

