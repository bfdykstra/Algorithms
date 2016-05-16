

#include <iostream>
#include <vector>
#include <stdlib.h> 


//can declare type of var using decltype(a.size()) n; or auto n = a.size();
// have try and catch for memory


/**
 * Internal method that merges two sorted halves of a subarray.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * leftPos is the left-most index of the subarray.
 * rightPos is the index of the start of the second half.
 * rightEnd is the right-most index of the subarray.
 */

using ulint = unsigned long int;

//template <typename Comparable>
void merge( std::vector<short int> & a, std::vector<short int> & tmpArray, ulint leftPos, ulint rightPos, ulint rightEnd){
  
	ulint leftEnd = rightPos - 1;
	ulint tmpPos = leftPos;
	ulint numElements = rightEnd - leftPos + 1;

	//Main Loop
	while( leftPos <= leftEnd && rightPos <= rightEnd){
		if(a[leftPos] <= a[rightPos]){
		  tmpArray[tmpPos++] = std::move( a[leftPos++]);
		}else{
		  tmpArray[tmpPos++] = std::move(a[rightPos++]);
		}
	}
	
	while( leftPos <= leftEnd ){
		// Copy rest of first half
		tmpArray[ tmpPos++ ] = std::move( a[ leftPos++] );
	}

	while( rightPos <= rightEnd ){
		// Copy rest of right half
		tmpArray[ tmpPos++ ] = std::move(a[ rightPos++] );
	}

	//Copy tmpArray back
	for( ulint i = 0; i < numElements; ++i, --rightEnd){
		a[ rightEnd ] = std::move( tmpArray[ rightEnd] );
	}
}


/**
 * Internal method that makes recursive calls.
 * a is an array of Comparable items.
 * tmpArray is an array to place the merged result.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */

//template <typename Comparable>
void merge_sort( std::vector<short int> & a,  std::vector<short int> & tmpArray, ulint left, ulint right){
	if( left < right){
		ulint center = (left + right) / 2;
		merge_sort(a, tmpArray, left, center);
		merge_sort(a, tmpArray, center + 1, right);
		merge(a, tmpArray, left, center + 1, right);
	}
}


/**
 * Mergesort algorithm (driver)
 */
//template <typename Comparable>
void mergesort( std::vector<short int> & a){
	/*
	for(unsigned int i = 0; i< (a.size() -1); i++){
	  printf(", %d ", a[i]);
	}*/
	if(a.size() > 0){
	std::vector<short int> tmpArray( a.size( ));
	merge_sort( a, tmpArray, 0, a.size() - 1);
	}
	/*
	try{
	  
	}catch(const std::bad_alloc & e){
	    printf("Out of memory: exiting \n");
	    exit(EXIT_FAILURE);
	}*/
	
	
}







