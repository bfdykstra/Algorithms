

//Ben Dykstra

//#include "mergesort.cpp"
#include "sort.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <chrono> 
#include <random>

using std::cout; // This makes "cout" a substitute for "std::cout".  The suffix std:: means the standard namespace.
using std::cin;

/**
* Test function for mergesort
* takes in a vector to be sorted using mergesort
*/
//template <typename Comparable>
bool test_merge( std::vector<short int> & testArray){
  
	auto t_start = std::chrono::high_resolution_clock::now(); 

	mergesort(testArray);
	auto t_end = std::chrono::high_resolution_clock::now();
	cout << "  Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t_end-t_start).count() <<  "ms\n";
	
	//subtract 2 from total size bc need to add one, don't want array out of bounds
	for(unsigned int i = 0; i < testArray.size() - 2; i++){
		if( testArray[i] > testArray[i + 1]){
			return false;
		}
	}
	/**
	for(unsigned int i = 0; i< testArray.size() - 1; i++){
	printf(", %d ", testArray[i]);
	}*/
	
	return true;
} 

int main(){

	unsigned long int n;
	cout << "Enter n: ";
	cin >> n;
	//need a vector filled with random numbers
	std::vector<short int> x(n); // This illustrates the explicit use of the std:: namespace suffix.
	//std::vector<short int> y(n);

	// Pseudo-random number generation was standardized in C++11.  There are two components to a C++ pseudo-random number generator (PRNG).
	//  - An engine, whose role is to return random bits.  For each bit, the probability of obtaining a 0 is the same as obtaining a 1.
  //    This means the engine returns uniformly distributed random bits.
  //  - A distribution, whose role is to return random numbers drawn from a particular distribution, such as a uniform distribution
  //    or a normal distribution.  C++ 

  std::mt19937 e(42); // America's favorite random number engine: the Mersenne twister.  The value of <seed> used to initialize the PRNG.  
					  // Setting the seed to the same value means the pseudo-random number sequence is the same for different runs.
					  // The 19937 refers to the Mersenne prime 2^19937 - 1.
  std::uniform_int_distribution<short int> u(-32768,+32767); // Convert the engine's output to a uniform distribution over the full range of short int.

  //auto t_start = std::chrono::high_resolution_clock::now(); // Get the current time.  The <auto> asks the compiler to infer the right type 
															// for t_start from the thing on the right.
  // Fill x and y with pseudo-random numbers.
  for (auto &w : x) { // A range-for loop (new in C++11).  No loop variables means less work and less likelihood of error!  
	w = u(e);
  }
  /*
  for (auto &w : y) {
	w = u(e);
  }*/

  //auto t_start = std::chrono::high_resolution_clock::now(); //start clock
  /**
  printf("This is before test: \n");
  for(unsigned int i = 0; i< x.size() - 1; i++){
    printf(", %d ", x[i]);
  }*/
  bool test = test_merge(x);

  if(test){
	printf("Merge worked! \n");
  }else{
	printf("Merge didn't work :( \n" );
  }
  //auto t_end = std::chrono::high_resolution_clock::now();
  //auto end = std::chrono::duration_cast<std::chrono::milliseconds>(t_end-t_start).count();
  //printf("Time elapsed: ", end);
  return 0;
}





