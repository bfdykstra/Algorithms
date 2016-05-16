//sort.hpp

#if !defined(__SORT_HPP_CS303)
#define __SORT_HPP_CS303

#include <vector>
#include <iostream>

// For you to implement...
namespace my {
  //template <typename T> long int quicksort_lo (std::vector<T> &a);
  //template <typename T> void quicksort (std::vector<T> &a);
  //long q_count = 0; //counter for comparisons in regular ole quicksort
  long long lo_count = 0; //counter for comparisons in quicksort_lo



	//insertion sort
	template <typename T>
	void insertion_sort(std::vector<T> & a){
		std::cout << "In insertion_sort!!! \n";
		for(int p = 1; p < a.size(); ++p){
			T tmp = std::move(a[p]);

			int j;
			for(j = p; j >0 && tmp < a[j-1]; --j){
				lo_count++;
				a[j] = std::move(a[j - 1]);
			}
			a[j] = std::move(tmp);
		}
	}


	/**
	Return median of left, center, and right
	Order these and hide the pivot.
	*/
	template <typename T>
	T  median3(std::vector<T> & a, int left, int right){
		int center = (left + right) /2;

		if(a[center] < a[left]){
			std::swap(a[left], a[center]);
		}
		if(a[right] < a[left]){
			std::swap(a[left], a[right]);
		}
		if(a[right] < a[center]){
			std::swap(a[center], a[right]);
		}

		//place pivot at position right - 1
		std::swap( a[center], a[right - 1]);
		return a[right - 1];
	}



	/**
	internal quicksort method that makes recursive calls.
	Uses median3 partitioning and cutoff of 10. 
	a is an array of type T - ints, floating points, strings.
	left is the left most index of the subarray
	right is the right most index of the subarray
	*/
	template <typename T>
	void quicksort(std::vector<T> &a, int left, int right){
		if(left + 10 <= right){
			//std::cout << "In quicksort!!! \n";
			T pivot = median3( a, left, right);

			//partion dat thang
			int i = left;
			int j = right -1;
			for( ; ; ){
				while( a[++i] < pivot){ }
				while( pivot < a[--j]){ }

				if( i < j)
					std::swap(a[i], a[j]);
				else
					break;
			}
			std::swap(a[i], a[right - 1]); //restore pivot

			quicksort(a, left, i -1); //sorts small elements to left of pivot
			quicksort(a, i + 1, right); //sorts large elements to the right of the pivot
		}else{
			insertion_sort(a);
		}
	}

	//template <typename T>
	//int lomuto_partition
	template <typename T>
	void quicksort_lo(std::vector<T> &a, int lo, int hi){
		if(lo < hi){
			//std::cout << "In quicksort_lo with parameters "<< lo << " and " << hi << "\n";
			//std::cout << "a[lo] = " << a[lo] << " a[hi] = " << a[hi] << "\n"; 
			int pivot = a[lo];
			//std::cout << "This is the pivot: " << pivot << "\n";
			int i = lo+1; //where we are looking to swap
			for(int j = lo + 1; j <= hi; j++){
				if(a[j] < pivot){
					//std::cout << "These are the values being swapped: a[i = "<< i << " ] = " << a[i] << " and a[j = " << j << " ] = " << a[j] << "\n";
					std::swap(a[i], a[j]);
					i++;
				}
				lo_count++; //increment count for comparison up
			}
			//std::cout << "These are the values being swapped outside of the for loop: a[i - 1 = "<< i -1 << " ] = " << a[i -1 ] << "and a[ lo = " << lo << " ] = " << a[lo] << "\n";
			std::swap(a[i - 1], a[lo]);
			
			quicksort_lo(a, lo, i -1);
			//quicksort_lo(a, i+1, hi);
			quicksort_lo(a, i, hi);

		}
		/*else{
			insertion_sort(a);
		}*/
	}



	//driver for quicksort using median3 pivot
	template <typename T>
	void quicksort(std::vector<T> &a){
		quicksort(a, 0, a.size() - 1);

	}

	//driver for quicksort_lo that uses first element as the pivot and lomuto partitioning
	template <typename T>
	long long quicksort_lo(std::vector<T> &a){
		quicksort_lo(a, 0, a.size() - 1);
		std::cout << "number of comparisons for n = " << a.size() << " is: " << lo_count << "\n";
		return lo_count;
	}

}

#endif