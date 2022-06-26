/**
*	@file		heap_sort.c
*	@brief		ヒープソート Heap_sort
*	@author		GeeksforGeeks
*	@date		13 Jun, 2022
*	@details	https://www.geeksforgeeks.org/heap-sort/
*/

#include	<stdio.h>
#include	<time.h>
#include	"my_lib.h"

#define	NUMBER_OF_DATA		65536
#define NUM(a) (sizeof(a)/sizeof(a[0]))

void heap_sort(unsigned short ar[], int n);
void heapify(unsigned short  ar[], int n, int i);

static unsigned short data[NUMBER_OF_DATA];

int main(void)
{	
	create_data(data, NUM(data));
	
	heap_sort(data, NUM(data));
	
	save_array("heap_sort.txt", data,  NUM(data));
	check_the_order(data,  NUM(data));
	
	return 0;
}

// Main function to do heap sort
void heap_sort(unsigned short ar[], int n)
{
	int		i;
	clock_t	start = clock();

	// Build heap (rearrange array)
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(ar, n, i);
  
    // One by one extract an element 
    // from heap
    for (i = n - 1; i > 0; i--) {
        
        // Move current root to end
        swap(&ar[0], &ar[i]);
  
        // call max heapify on the reduced heap
        heapify(ar, i, 0);
    }
	printf("%.3lfsec\n", (double)(clock() - start) / CLOCKS_PER_SEC);

}

// To heapify a subtree rooted with node i
// which is an index in arr[]. 
// n is size of heap
void heapify(unsigned short  ar[], int n, int i)
{
  // Initialize largest as root
    int largest = i; 
    
  // left = 2*i + 1
    int l = 2 * i + 1; 
    
  // right = 2*i + 2
    int r = 2 * i + 2; 
  
    // If left child is larger than root
    if (l < n && ar[l] > ar[largest])
        largest = l;
  
    // If right child is larger than largest 
    // so far
    if (r < n && ar[r] > ar[largest])
        largest = r;
  
    // If largest is not root
    if (largest != i) {
        swap(&ar[i], &ar[largest]);
  
        // Recursively heapify the affected 
        // sub-tree
        heapify(ar, n, largest);
    }
}
