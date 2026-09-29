#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::rotate(iterator first, iterator last, size_t k) {
  //write your code here

  // define CP:vector to get data in range 
  CP::vector<T> to_rotate_vector ; 

  // create to_rotate_vector first 
  for (auto it = first ; it != last ; it++) { 
      to_rotate_vector.push_back(*it) ; 
  }

  // CP::vector<T> rotated_vector = to_rotate_vector ; // copy constructor of vector 

  // use formula from rotate : (i - 1 + k) % n + 1
  size_t size_rotate = to_rotate_vector.size() ; 

  for (int i = 0 ; i < size_rotate ; i++) { 
      this->at( first + i - begin() ) = to_rotate_vector[ (i + k) % size_rotate ] ; 
  } 

}

#endif
