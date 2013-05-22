#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

using namespace std;
void matrix_chain_order(int* p,int n, int** m, int** s);
int recursive_matrix_chain(int* p, int i, int j, int** m);
int lookup_chain(int** m, int* p, int i, int j);
int memoized_matrix_chain(int* p,int n, int** m);
int main(int argc,char **argv)
{
	double timez=0.0;
	int** m;
	int** s;
	int numbas[21];
	m=new int*[21];
	s=new int*[21];
	for (int i=0;i<21;i++){
		m[i] = new int[21];
	}
	for (int i=0;i<21;i++){
		s[i] = new int[21];
	}

	srand(time(NULL));
	for(int i=0;i<21;i++){
		numbas[i]=rand()%100+30;
	}
	int ansa;
	
	clock_t tStart, tStop;
		
	tStart=clock();
	matrix_chain_order(numbas,20,m,s);
	tStop=clock();
	timez=(double)(tStop-tStart);
	
	ansa=m[1][20];
	cout<<" sol "<<ansa<<" matrix chain order "<<timez<<" time"<<endl;
	m=new int*[21];
	s=new int*[21];
	for (int i=0;i<21;i++){
		m[i] = new int[21];
	}
	for (int i=0;i<21;i++){
		s[i] = new int[21];
	}

	tStart=clock();
	ansa=recursive_matrix_chain(numbas,1,20,m);
	tStop=clock();
	timez=(double)(tStop-tStart);

	cout<<" sol "<<ansa<<" recursive matrix chain "<<timez<<" time"<<endl;
	m=new int*[21];
	s=new int*[21];
	for (int i=0;i<21;i++){
		m[i] = new int[21];
	}
	for (int i=0;i<21;i++){
		s[i] = new int[21];
	}

	tStart=clock();
	ansa=memoized_matrix_chain(numbas,20,m);
	tStop=clock();
	timez=(double)(tStop-tStart);
	cout<<" sol "<<ansa<<" memoized matrix chain "<<timez<<" time"<<endl;
	
	return 0;
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
int lookup_chain(int** m, int* p, int i, int j){
	if(m[i][j]<INT_MAX){return m[i][j];}
	if(i==j){m[i][j]=0;}
	else{
		for(int k=i;k<=j-1;k++){
			int q=lookup_chain(m,p,i,k)+lookup_chain(m,p,k+1,j)+p[i-1]*p[k]*p[j];
			if(q<m[i][j]){
					m[i][j]=q;
			}
		}
	}
	return m[i][j];
}
int memoized_matrix_chain(int* p,int n, int** m){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			m[i][j]=INT_MAX;
		}
	}
	return lookup_chain(m,p,1,n);
}
