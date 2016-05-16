#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <sstream>

#include "union_find.hpp"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main (int argc, char **argv)
{
  if (argc == 1) {
    cout << argv[0] << " calls union(p,q) on randomly chosen p and q." << endl;
    cout << "Usage:  " << argv[0] << " n m  "
	 << "where n is the number of nodes and m is the number of random connections." << endl;
    cout << "Thus,  " << argv[0] << " 1000 6000  makes 6000 random connections between 1000 nodes." << endl;
    return 0;
  }
  
  long int m, n;
  std::istringstream(argv[1]) >> n;
  std::istringstream(argv[2]) >> m;

  cout << "No. of nodes: " << n << endl;
  cout << "No. of random connections: " << m << endl;

  // Use a random seed to initialize the PRNG.  If you want repeatable behavior, change
  //   std::mt19937 e(s);
  // to (say)
  //   std::mt19937 e(42);
  auto s = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 e(s); // Everyone's favorite pseudo-random number engine: the Mersenne twister.
  std::uniform_int_distribution<long int> u(0,n-1); // Convert engine output to a uniform integer distribution.

  auto t_start = std::chrono::high_resolution_clock::now();
  cs303::union_find uf(n);

  for (int i = 0; i < m; i++) {
    auto p = u(e);
    auto q = u(e);
    uf.onion(p,q);
  }
  auto t_end = std::chrono::high_resolution_clock::now();
      std::cout << "    Elapsed time for size n = " << n << " : " << std::chrono::duration_cast<std::chrono::milliseconds>(t_end-t_start).count() <<  "ms\n";
  cout << "number of components: " << uf.num_components() << endl;
}
