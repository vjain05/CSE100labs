// SEE @@@ BELOW FOR THE PLACE TO USE YOUR SORTING FUNCTION

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

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
int parent(int i){
        return i/2;//floor is implicit
}
int left(int i){
        return 2*i;
}
int right(int i){
        return 2*i+1;
}
void max_heapify(int* ar1, int heapsize, int i){
        //printf("heapsize max heapify %d\n",heapsize);
	//fflush(NUiLL);
	//printf("segment 1\n");
        int n;int l;int r;int largest;int exchng;
        n=heapsize;
        l=left(i);
        r=right(i);
	//printf("segment 2\n");
	//fflush(stdout);
	//printf("ar1[i-1] %d ",ar1[i-1]);
	//fflush(stdout);
	//printf("ar1[l-1] %d ",ar1[l-1]);
	//fflush(stdout);
	//printf("i %d ",i);
	//fflush(stdout);
	//printf("");
	//printf("l %d\n",l);
	//fflush(stdout);
	//printf("ar1 %d %d i %d l %d",ar1[i-1],ar1[l-1],i,l);
        //if(ar1[i-1]<ar1[l-1] && l<=n){
	if(l<=n && ar1[i-1]<ar1[l-1]){
                largest=l;
        }
        else{
                largest=i;
        }
	//fflush(stdout);
	//printf("segment 3\n");
	//fflush(stdout);
        //if(ar1[largest-1]<ar1[r-1] && r<=n){
	if(r<=n && ar1[largest-1]<ar1[r-1]){
                largest=r;
        }
	//printf("segment 4\n");
        if(largest!=i){
                exchng=ar1[i-1];
                ar1[i-1]=ar1[largest-1];
                ar1[largest-1]=exchng;
		//printf("recurse call max heapify from max_heapify\n");
                max_heapify(ar1,heapsize,largest);
        }
	//printf("ends\n");
}
void build_max_heap(int* ar1, int heapsize){
        int n;
        //printf("build max hea heapsize %d\n",heapsize);
        n=heapsize;
        int i;
        for(i=parent(n);i>=1;i--){
		//printf("max_heapify recurse call from build_max_heap %d\n",i);
                max_heapify(ar1,heapsize,i);
        }
}
void heapsort(int* ar1, int length, int heapsize){
	int exchng;
	build_max_heap(ar1,heapsize);
	int i;
	//printf("heapsort heapsize %d\n",heapsize);
	for(i=length;i>=2;i--){
		exchng=ar1[1-1];
		ar1[1-1]=ar1[i-1];
		ar1[i-1]=exchng;
		heapsize=heapsize-1;
		//printf("max_heapify recurse from heapsort %d\n",i);
		max_heapify(ar1,heapsize,1);
	}
}
void quicksort(int* ar1, int p, int r){
	//printf("quicksort\n");
	if(p<r){
		int q;
		q=rand_partition(ar1,p,r);
		quicksort(ar1,p,q-1);
		quicksort(ar1,q+1,r);
	}
}
int rand_partition(int* ar1, int p, int r){
	int i;int exchng;
	i=(rand()%(r-p))+p;
	exchng=ar1[r-1];
	ar1[r-1]=ar1[i-1];
	ar1[i-1]=exchng;
	return partition(ar1,p,r);
}
int partition(int* ar1, int p, int r){
	//printf("partition \n");
	int x;int i;int exchng;
	x=ar1[r-1];
	i=p-1;
	int j;
	for(j=p;j<=r-1;j++){
		if(ar1[j-1]<=x){
			i=i+1;
			exchng=ar1[i-1];
			ar1[i-1]=ar1[j-1];
			ar1[j-1]=exchng;
		}
	}
	exchng=ar1[r-1];
	ar1[r-1]=ar1[i+1-1];
	ar1[i+1-1]=exchng;
	return i+1;
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

int heap_size;
heap_size=n;
//heapsort(array,n, heap_size);
//quicksort(array,1,n);
 // Get starting time
//printf("heapsize %d\n",heap_size);
//int bn;
//for(bn=0;bn<n;bn++){
//	printf("%d\n",array[bn]);
//}
 gettimeofday(&start,NULL);

 // @@@ PUT YOUR SORT CODE HERE
// My_MergeSort(array,n);
//heapsort(array,n,heap_size);
quicksort(array,n,heap_size);
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
