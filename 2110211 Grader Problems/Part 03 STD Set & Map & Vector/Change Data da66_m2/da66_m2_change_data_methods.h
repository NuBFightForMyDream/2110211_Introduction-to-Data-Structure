#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <string>

using std::string;

void change_1(std::stack<std::vector<std::queue<int>>> &a, int from, int to)
{
    // create temporary storage 
    std::stack<std::vector<std::queue<int>>> temp ; // to be stored with edited vector 

    // your code here
    while (a.empty() == false) { // stack 
        auto each_vector = a.top() ; // vector 
        for (int i = 0 ; i < each_vector.size() ; i++) { 
            // queue 
            auto &each_queue = each_vector[i] ; 
            auto queue_size = each_vector[i].size() ; // because queue always change size

            for (int j = 0 ; j < queue_size ; j++) {
                int each_element = each_queue.front() ; 
                // pop the old one back every time
                each_queue.pop() ; 

                if (each_element == from) each_element = to ; 

                // push each element every time 
                each_queue.push(each_element) ; 
            }
        }
        
        // push data to temp (wait until end loop)
        temp.push( each_vector ) ; 
        a.pop() ; 
    }
    
    // push temp back to a 
    while (temp.empty() == false) { 
        a.push( temp.top() ) ; 
        temp.pop() ; 
    }
}

void change_2(std::map<string, std::pair<std::priority_queue<int>, int>> &a, int from, int to)
{
    // your code here
    for (auto it = a.begin() ; it != a.end() ; ++it) { 
        // define data
        auto &each_string = it->first ; 
        auto &each_pair = it->second ; 

        // define data in pair
        auto &each_pq = (it->second).first ; 
        auto &each_int = (it->second).second ; 

        if (each_int == from) each_int = to ; 

        // change value in pq (but need to create temp pair)
        std::priority_queue<int> temp_pq ; 

        while (each_pq.empty() == false) { 

            int element_to_add = each_pq.top() ; 
            if (element_to_add == from) element_to_add = to ;  

            temp_pq.push( element_to_add ) ; 
            each_pq.pop() ; 
        }

        // pop all element in temp_pq out then put back to each_pq
        while (temp_pq.empty() == false) { 
            each_pq.push( temp_pq.top() ) ; 
            temp_pq.pop() ; 
        }
    }
}

void change_3(std::set< std::pair <std::list<int>, std::map<int, std::pair<int, string>> >> &a, int from, int to)
{

    // define temp_set
    std::set< std::pair <std::list<int>, std::map<int, std::pair<int, string>> >> temp_set ; 

    // your code here
    for (auto it = a.begin() ; it != a.end() ; ++it) { // set 
        // each dat ainside is "pair" (set of pair)
        auto each_data = *it ; 
        auto &each_list = each_data.first ;
        auto &each_map = each_data.second ; 

        for (auto &e : each_list) { // change data in list<int>
            if (e == from) e = to ; 
        }

        std::map<int , std::pair<int , string> > temp_map ; 

        for (auto it2 = each_map.begin() ; it2 != each_map.end() ; ++it2) { 
            int each_int = it2->first;
            auto each_pair = it2->second;

            if (each_pair.first == from) {
                each_pair.first = to;
            }

            if (each_int == from) {
                each_int = to;
            }

            temp_map[each_int] = each_pair;
        }

        each_data.second = temp_map;

        temp_set.insert(each_data);
        
    }

    a = temp_set ; 

}

#endif
