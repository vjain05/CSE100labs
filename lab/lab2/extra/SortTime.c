// SEE @@@ BELOW FOR THE PLACE TO USE YOUR SORTING FUNCTION

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

void binary_search(int* ar1, int length, int search){
	int l=1;
	int r=length;
	int m;
	while(l<=r){
		m=ceil(((double)(r+l))/((double)(2)));
		if(ar1[m-1]==search){
			printf("%d\n",m-1);
			return;
		}
		else if(ar1[m-1]>search){
			r=m-1;
		}
		else{
			l=m+1;
		}
	}
	printf("%d\n",-1);
	return;
}
void linear_search(int* ar1, int length, int search){
	int i;
	for(i=0;i<length;i++){
		if(ar1[i]==search){
			//cout<<i<<endl;
			printf("%d\n",i);
			return;
		}
	}
	printf("%d\n",-1);
	return;
}
void rndarray(int *array, char s, int k, int n, int seed) {
 int i,temp;

 // set seed for random number generation
 srand(seed);

 // generate the random array of integers
 for(i=0; i<n; i++) {
   array[i] = (int) ((k+1)*(rand()/(RAND_MAX+1.0)));
 }

 // sort the random array
 switch(s) {
   case 'a':
     xsort(array, n);	// sort the array in increasing order      
     break;      
   case 'd':    
     xsort(array, n);	// sort the array in decreasing order
     // reverse the sequence
     for(i=0; i<floor(n/2); i++) {        
       temp = array[i];
       array[i] = array[n-i-1];
       array[n-i-1] = temp;
     }
     break;
   case 'u':		// leave unsorted
     break;  
 }

}

int main(int argc,char **argv) {
 char s;
 int k, n, seed;
 int i;  
 int *array;			// point to a random array
 int *unsortedarray;		// point to an unsorted array NEW
 int Biggest = 0;		// NEW
 struct timeval start,end;	// time structure for starting and ending time

 if (argc!=5) {
     /* We print argv[0] assuming it is the program name */
     printf( "usage: %s s k n seed\n", argv[0] );      
     return 0;
 }

 // Generate the random array
 s = *argv[1]; 
 k = atoi(argv[2]);
 n = atoi(argv[3]);
 seed = atoi(argv[4]);

 fprintf(stderr,"Calling rndarray(s='%c',k=%d,n=%d,seed=%d)...\n",s,k,n,seed);
 // Allocate enough memory to store "SizeOfSequence" integers
 array = (int*)malloc(sizeof(int)*n);
 unsortedarray = (int*)malloc(sizeof(int)*n);
 rndarray(array, s, k, n, seed);

 // The following codes are specifically for CountingSort and RadixSort
 for(i=0; i<n; i++) {
   unsortedarray[i] = array[i];
   if(unsortedarray[i] > Biggest)
     Biggest = unsortedarray[i];
 }
int search=(int)((k+1)*(rand()/(RAND_MAX+1.0)));
 //print out the array
 //for(i=0; i<n; i++) fprintf(stdout,"%d\n",array[i]);

 fprintf(stderr,"Sorting...\n");

 // Get starting time
 gettimeofday(&start,NULL);

 // @@@ PUT YOUR SORT CODE HERE
// My_MergeSort(array,n);
//linear_search(array,n,search);
binary_search(array,n,search);
 // @@@ THEN COMPILE AS: gcc -lm -o SortTime xsort.o My_MergeSort.c SortTime.c

 // Get ending time
 gettimeofday(&end,NULL);

 fprintf(stdout,"%f\n",(end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0);

 // print out the array
 //for(i=0; i<n; i++) fprintf(stdout,"%d\n",array[i]);

 free(array);
 free(unsortedarray);  

 return 1;

}
