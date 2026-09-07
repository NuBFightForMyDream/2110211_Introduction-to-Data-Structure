#ifndef DA68_M_COUNT_VALUE_TEMPLATE_H_ // check if da68_m_count_value_template.h in main code already?
#define DA68_M_COUNT_VALUE_TEMPLATE_H_

// you can also include anything else here
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

std::vector<size_t> count_value(const std::map<long long,int> &data,const std::vector<std::pair<int,int>> &queries) {
  // const in parameter for not editing infos
    // data = map<long long , int>
    // queries = vector< pair<int,int> >

  // define result vector (which is count for each queries)
  std::vector<size_t> r; // size_t is one of type (which is max int value in each type)

  // main goal : count if value (in map:data) is in range of queries

  // Store data values first 
  std::vector<int> values_from_map ; 
  for (const auto &each_pair : data) { 
      values_from_map.push_back( each_pair.second ) ; 
  }
  // sort first 
  std::sort(values_from_map.begin() , values_from_map.end());

  // check each queries
  for (size_t i = 0 ; i < queries.size() ; i++) { // use size_t instead of int 
      // define bound for check value
      int lower_val = queries[i].first ;
      int upper_val = queries[i].second ; 

      /* Using For .. For may not be efficient ( O(n^2) ) , maybe using lb/ub
      for (auto &each_pair : data) {
        auto val_to_check = each_pair.second ; 
        
        if ( (lower_val <= val_to_check) && (val_to_check <= upper_val) ) { 
              count_in_interval++ ; 
        }
      }
      */

      // Try using Lower/Upper bound 
      // first , store all values in map first (done above)
      
      // now , use lower & upper bound iterator then find distance
      auto lb_itr = std::lower_bound( values_from_map.begin() , values_from_map.end() , lower_val);
      auto ub_itr = std::upper_bound( values_from_map.begin() , values_from_map.end() , upper_val);

      size_t count_in_interval = ub_itr - lb_itr ; 

      // append each count to result
      r.push_back( count_in_interval ) ; 
  }
  
  return r;
}

#endif
