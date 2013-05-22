#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits.h>
#include <cfloat>
#include <stack>

using namespace std;

double err_func(int i, int j, double *x, double *y);
void bottom_up_LSQ(int n, double **errs, double *r, int *s, double c);
//void print_partition(int n, int *s);
void print_numLines_optErr(int n, double *r, int *s);
int main(int argc,char **argv)
{
        int input=1000;
        double c=1/(10.0*10.0*10.0*10.0*10.0);
        //cin>>input;
        //cerr<<"input "<<input<<endl;
        double **err;
        double *x;
        double *y;
        double *r;
        int *s;

		err=new double*[input];
		x=new double[input];
        y=new double[input];
		for(int i=0;i<input;i++){
			x[i]=i+1;
			y[i]=(rand()%1000 + 1)/1000.0;
			err[i]=new double[input];
			//cout<<y[i]<<" ";
		}
		for(int i=0;i<input;i++){
                 for(int j=0;j<input;j++){
                         err[i][j]=DBL_MAX;
                 }
        }
		for(int j=1;j<=input;j++){
                 for(int i=1;i<=j;i++){
                         err[i-1][j-1]=err_func(i,j,x,y);
                         //cerr<<err[i-1][j-1]<<" ";
                 }
                 //cerr<<endl;
         }
		//cout<<endl;
		cout<<"c\tnumLines\topt_err"<<endl;
        for(int k=1;k<=7;k++){
                
               
                r=new double[input+1];
                s=new int[input+1];

                for(int i=0;i<input;i++){

                        r[i]=DBL_MAX;
                        s[i]=INT_MAX;
                }
                r[input]=DBL_MAX;
                s[input]=INT_MAX;
                //algorithm goes here
                
                
                //get recursive algorithm
                bottom_up_LSQ(input,err,r,s,c);
                
				
				cout<<c<<"\t";
				print_numLines_optErr(input,r,s);
				cout<<endl;

                delete [] r;
                delete [] s;
				
				c=c*10;

		}
		for(int i=0;i<input;i++){
                delete [] err[i];

        }
        delete [] err;
		delete [] x;
        delete [] y;
        
        return 0;
}
double err_func(int i, int j, double *x, double *y){
        double a,b;
        double errorz=0.0;
        double x_bar=0.0;
        double y_bar=0.0;
        double xy_bar=0.0;
        double x_2_bar=0.0;
        for(int k=i;k<=j;k++){
                x_bar=x_bar+x[k-1];
                y_bar=y_bar+y[k-1];
                xy_bar=xy_bar+x[k-1]*y[k-1];
                x_2_bar=x_2_bar+x[k-1]*x[k-1];
        }
        x_bar=x_bar/((double)(j-i+1));
        y_bar=y_bar/((double)(j-i+1));
        xy_bar=xy_bar/((double)(j-i+1));
        x_2_bar=x_2_bar/((double)(j-i+1));
        a=(xy_bar-x_bar*y_bar)/(x_2_bar-(x_bar*x_bar));
        b=y_bar-a*x_bar;
        for(int k=i;k<=j;k++){
                errorz=errorz+(y[k-1]-(a*x[k-1]+b))*(y[k-1]-(a*x[k-1]+b));
        }
        return errorz;
}
void bottom_up_LSQ(int n, double **errs, double *r, int *s, double c){
        double min=DBL_MAX;
        int min_indx=0;
        r[0]=0;
        s[0]=0;
        for(int j=1;j<=n;j++){
                min=DBL_MAX;
                min_indx=0;
                for(int i=1;i<=j;i++){
                        double q=r[i-1]+errs[i-1][j-1]+c;
                        if(min-q>0.0){
                                min=q;
                                min_indx=i;
                        }
                }
                r[j]=min;
                //if(j==0){
                //      r[j]=0;
                //}
                s[j]=min_indx;
        }
}
/*
void print_partition(int n, int *s){
        stack<int> temp;
        int i=n;
        while(i>1){
                i=s[i];
                temp.push(i);
        }
        while(!temp.empty()){
                cout<<temp.top()<<endl;
                temp.pop();
        }
}*/
void print_numLines_optErr(int n, double *r, int *s){
	int numLines=0;
	int i=n;
	while(i>1){
		numLines+=1;
		i=s[i];
	}
	cout<<numLines<<"\t"<<r[n];
}
