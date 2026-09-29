#ifndef OPERATOR_EQUAL_D57_Q1_VEQUAL
#define OPERATOR_EQUAL_D57_Q1_VEQUAL

template <typename T>
bool CP::vector<T>::operator==(const vector<T> &other) const {
  //write your code only in this function

  // check size first 
  if (this->size() != other.size()) {
     return false ;
  }

  else if (this->size() == 0 && other.size() == 0) return true ;  

  else if (this->size() != 0 && other.size() != 0) { 
     // for loop check 
     for (int pos = 0 ; pos < other.size() ; pos++) { 
        // now we assume that vector should have same size 
        if ((*this)[pos] != other[pos]) { 
            // note that *this = mData (pointer to data)
            return false ;
        }
     }

     // after loop , if not found bug then return true
     return true ; 
  }
}

#endif
