#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m) {
  //write your code here

  // just return true/false if interval are able to do block swap 

  // [a , ... , a+m-1] , [b , ...... , b+m-1]

  // cd1 : valid iterator (not before begin and mot after end in every case)
  if (a < begin()) return false ; 
  if (a >= end()) return false ; 

  if (b < begin()) return false ; 
  if (b >= end()) return false ; 

  if (a+m-1 < begin()) return false ; 
  if (a+m-1 >= end()) return false ; 

  if (b+m-1 < begin()) return false ; 
  if (b+m-1 >= end()) return false ; 

  // cd2 : m must more than 0 
  if (m <= 0) return false ; 

  // cd3 : musn't overlap 
  if (b <= a+m-1) return false ; 
  if (a <= b+m-1) return false ; 

  // no more contrapositive case , swap data 
  for (size_t i = 0 ; i < m ; i++) {
      std::iter_swap(a+i , b+i) ;
  }
  return true ; 
}

#endif
