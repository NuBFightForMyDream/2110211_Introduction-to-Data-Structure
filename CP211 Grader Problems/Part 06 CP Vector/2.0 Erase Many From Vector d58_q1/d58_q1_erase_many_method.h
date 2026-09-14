#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) { // pos_to_delete
  //write your code here

  // dumb solution : loop erase -> error from index changed (can be out of range)

  // nice solution (maybe cheat??) -> erase pos by reverse
  /*
  for (int k = pos.size() - 1 ; k > -1 ; k--) { 
     // call single erase
     this->erase( this->begin() + pos[k] ) ;
  }
  */

  // clear solution : 

  // step 1 : create std::vector to store bool to_remove or not
  size_t current_size = this->size() ; 
  std::vector<bool> to_remove(this->size() , false) ; // create with size and value 
  for (const int &each_pos_to_remove : pos) { 
      to_remove[each_pos_to_remove] = true ; // change value in array 
      current_size-- ; 
  }

  // step 2 : add non-remove value to array 
  std::vector<T> cleaned_data(current_size) ; // std vector with size 

  size_t pos_cleaned = 0 ; // pos after cleaned data 
  for (size_t i = 0 ; i < to_remove.size() ; i++) {
      if (to_remove[i] == false) {
          cleaned_data[pos_cleaned] = mData[i] ; // replace data 
          pos_cleaned++ ; 
      } 
  }

  // step 3 : copy data back to mData (cant change mData directly)
  // note that mData return T* (pointer to array of Type T) but cleaned_data is vector<T>

  for (int i = 0 ; i < cleaned_data.size() ; i++) { 
    mData[i] = cleaned_data[i] ; 
  }
  // dont forget to reize mSize 
  this->mSize = current_size ; // mSize 


}

#endif
