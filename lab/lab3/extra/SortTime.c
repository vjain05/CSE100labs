// SEE @@@ BELOW FOR THE PLACE TO USE YOUR SORTING FUNCTION

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <limits.h>
void insertionSort(int* ar1, int ar1_size){
	int key;
	int i;
	int j;
	for( j=2;j<=ar1_size;j++){
		key=ar1[j-1];
		i=j-1;
		while(ar1[i-1]>key & i>0){
			ar1[i+1-1]=ar1[i-1];
			i=i-1;
		}
		ar1[i+1-1]=key;
	}
}
void merge(int* ar1, int ar1_size, int p, int q, int r){
	int n_1=q-p+1;
	int n_2=r-q;
	//int L[n_1+1];
	//int R[n_2+1];
	int* L;int* R;
	L=(int*)malloc(sizeof(int)*(n_1+1));
	R=(int*)malloc(sizeof(int)*(n_2+1));

	int i;
	for( i=1;i<=n_1;i++){
		L[i-1]=ar1[p+i-1-1];
	}
	int j;
	for( j=1;j<=n_2;j++){
		R[j-1]=ar1[q+j-1];
	}
	L[n_1+1-1]=INT_MAX;
	R[n_2+1-1]=INT_MAX;
	 i=1;
	 j=1;
	int k;
	for( k=p;k<=r;k++){
		if(L[i-1]<R[j-1]){
			ar1[k-1]=L[i-1];
			i=i+1;
		}
		else{
			ar1[k-1]=R[j-1];
			j=j+1;	
		}
	}
	free(L);
	free(R);
}
void mergeSort(int* ar1, int ar1_size, int p, int r){
        if(p<r){
                int q=(p+r)/2;//floor is implicit
                mergeSort(ar1,ar1_size,p,q);
                mergeSort(ar1,ar1_size,q+1,r);
                merge(ar1,ar1_size,p,q,r);
        }
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

 //print out the array
 //for(i=0; i<n; i++) fprintf(stdout,"%d\n",array[i]);

 fprintf(stderr,"Sorting...\n");

 // Get starting time
 gettimeofday(&start,NULL);

 // @@@ PUT YOUR SORT CODE HERE
	//insertionSort(array,n);
	mergeSort(array,n,1,n);
	//int checker;
	//for(checker=0;checker<n;checker++){
	//	printf("arr contents %d\n",array[checker]);
	//}

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
