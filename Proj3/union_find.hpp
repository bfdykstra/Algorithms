
#if !defined(__UNION_FIND_HPP)
#define __UNION_FIND_HPP

#include <ostream>
#include <vector>

namespace cs303 {
  class union_find {
  public:
    // Overload the << operator using a friend function.  A friend function is not a member of the class, 
    // but can access all the data and function members of the class.
    // If uf is a union_find object, then std::cout << uf writes uf.s to the screen.
    friend std::ostream &operator<<(std::ostream &os, const union_find &uf) {
      for (auto &i : uf.s) { 
	os << i << " ";
      }
      os << std::endl;
      return os;
    }

    // Constructor to create and initialize a union-find object for N vertices.
    // The simplest way to initialize s[] is in the class member initialization list.
    // Initially s[] is all -1, and there are N components.
    union_find(long int N) : ncomponents(N), s(N,-1) {}

    // Are p and q are in the same component?
    inline bool connected (const long int &p, const long int &q) {return (find(p) == find(q));}

    // Return the number of components.
    inline long int num_components() {return ncomponents;}

    // Check whether two union-find objects are the same.
    bool operator==(const union_find &uf) const
    {
      if (s.size() != uf.s.size()) return false;

      for (unsigned long int i = 0; i < s.size(); i++) {
	if (s[i] != uf.s[i]) return false;
      }

      return true;
    }

    // The following two functions are only defined to be virtual because I am deriving my own
    // version of union_find from this one.  In my derived version, I need to use my own find()
    // and onion().
    
    // Find operation: return the component id of p, applying path compression.
    virtual long int find (const long int &p);

    // Union operation: union the components containing p and q.
    virtual void onion (const long int &p, const long int &q); 
  
  protected:
    long int ncomponents; // Number of connected components.
    std::vector<long int> s;
  };
}

#endif