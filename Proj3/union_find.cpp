#include <iostream>
#include <cmath> 

#include "union_find.hpp"

using std::cout;
using std::endl;

//find the component that p is, apply path compression
long int cs303::union_find::find (const long int &p){
	if( s[ p ] < 0 ){
		return p;
	}else{ return s[ p ] = find( s[p]); }  
}

//union the components that contain p and q by size.
void cs303::union_find::onion (const long int &p, const long int &q){
   
  //return the components that p and q belong too
  if(p < (long int) s.size() && q < (long int) s.size()){
    auto p_parent = find(p);
    auto q_parent = find(q);
    if(connected(p, q)) return; // prevents things from unioning in the same set
    else if( std::abs(s[p_parent]) < std::abs(s[q_parent])){	
      s[q_parent] += s[p_parent]; //add the number of components together
      s[p_parent] = q_parent; //make q parent of p
      ncomponents--;
    } else{
      s[p_parent] += s[q_parent]; //add the number of components together
      s[q_parent] = p_parent; //make p parent of q
      ncomponents--;
    }  
  }else{
    return;
  }

}