#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
  //write your code here
  // if you use std::vector, your score will be half (grader will report score BEFORE halving)

  // one of these conditions are true , so i'll write trap case instead
  // note : a = this , b = other

  // condition 1 : a is empty & b have at least 1 element
  if ((this->empty() == true) && (other.size() >= 1)) return true ; 

  // condition 2 : a & b has at least 1 element and a[0] = b[0]
  if ((this->size() >= 1) && (other.size() >= 1) && (*this)[0] < other[0]) return true ; 
    // note that other is reference , so we can use other[x] for accessing mData directly
    // see operator[] const in cp_vector_template
    // other.operator[][0] = other.mData[0]

  // condition 3 : a & b has at least 1 element and a[0] = b[0] & va < vb
  if ((this->size() >= 1) && (other.size() >= 1) && (*this)[0] == other[0]) {
    // create new CP::vector va & vb with copy constructor
    CP::vector<T> va(*this) ; va.erase(va.begin());
    CP::vector<T> vb(other) ; vb.erase(vb.begin());

    // try cheat way first : use std::lexicographical_compare
      // return std::lexicographical_compare(va.begin() , va.end() , vb.begin() , vb.end()) ; 

    // range loop check element if not less than
    
    // now we're checking less than conditions

    // compare length first 
    size_t minLength = size() < other.size() ? this->size() : other.size(); 
    // std::min(this->size() , other,size())

    for (size_t i = 0; i < minLength; ++i) {
        if ((*this)[i] < other[i]) return true; // still in loop 
        if (other[i] < (*this)[i]) return false;
    }

    return this->size() < other.size();
  }

  return false ; // in case not in 4 conditions
    
} ; 

#endif
