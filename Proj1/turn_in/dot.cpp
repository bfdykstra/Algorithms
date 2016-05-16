#include <vector>
#include <chrono>   // Needed for timing utilities.
#include <iostream> // Needed for i/o.
#include <random>   // Needed for random number generation.
#include <vector>   // Needed for C++ vector type.

using std::cout; // This makes "cout" a substitute for "std::cout".  The suffix std:: means the standard namespace.
using std::cin;
using std::cerr;
using std::endl;

long int dot(std::vector<short int> x, std::vector<short int> y);
  
int main (int argc, char **argv)
{
  unsigned long int n;
  cout << "Enter n: ";
  cin >> n;

  std::vector<short int> x(n); // This illustrates the explicit use of the std:: namespace suffix.
  std::vector<short int> y(n);

  // Pseudo-random number generation was standardized in C++11.  There are two components to a C++ pseudo-random number generator (PRNG).
  //  - An engine, whose role is to return random bits.  For each bit, the probability of obtaining a 0 is the same as obtaining a 1.
  //    This means the engine returns uniformly distributed random bits.
  //  - A distribution, whose role is to return random numbers drawn from a particular distribution, such as a uniform distribution
  //    or a normal distribution.  C++ 

  std::mt19937 e(42); // America's favorite random number engine: the Mersenne twister.  The value of <seed> used to initialize the PRNG.  
                      // Setting the seed to the same value means the pseudo-random number sequence is the same for different runs.
                      // The 19937 refers to the Mersenne prime 2^19937 - 1.
  std::uniform_int_distribution<short int> u(-32768,+32767); // Convert the engine's output to a uniform distribution over the full range of short int.

  auto t_start = std::chrono::high_resolution_clock::now(); // Get the current time.  The <auto> asks the compiler to infer the right type 
                                                            // for t_start from the thing on the right.
  // Fill x and y with pseudo-random numbers.
  for (auto &w : x) { // A range-for loop (new in C++11).  No loop variables means less work and less likelihood of error!  
    w = u(e);
  }
  for (auto &w : y) {
    w = u(e);
  }

  cout << "Computing inner product...\n";
  auto t_end = std::chrono::high_resolution_clock::now();
  auto d = dot(x, y);
  cout << "  Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t_end-t_start).count() <<  "ms\n"; // 'Zounds!
  cout << "  Result: " << d << endl; // endl is an output command that addes a newline but also flushes the output buffer.
}

// Compute the inner product of two vectors of type short int.
long int dot(std::vector<short int> x, std::vector<short int> y)
{
  long int sum = 0;
  for (unsigned long int k = 0; k < x.size(); k++) {
    sum += x[k] * y[k];
  }
  return sum;
}
