#include <string>
#include <sstream>
#include <iostream>

#include "union_find.hpp"

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main (int argc, char **argv)
{
  std::string line;
  unsigned long int N;
  unsigned long int p, q;

  // Read in the number of nodes from the first line of the file.
  getline(cin, line); 
  std::stringstream(line) >> N;
  
  cs303::union_find uf(N);

  // Read the file one at a time.  Each line contains a pair of nodes to union.
  while (getline(cin, line)) {
    std::stringstream(line) >> p >> q;
    uf.onion(p, q);
  }
  
  cout << "number of components: " << uf.num_components() << endl;
  cout << uf;

  return 0;
}