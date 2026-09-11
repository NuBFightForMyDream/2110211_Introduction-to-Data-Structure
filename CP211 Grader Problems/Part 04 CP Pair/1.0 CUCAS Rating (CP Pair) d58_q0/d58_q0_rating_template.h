#ifndef __D58_Q0_RATING_TEMPLATE_H__
#define __D58_Q0_RATING_TEMPLATE_H__

// define namespace first 
namespace CP {
    // start with template
    template <typename T1 , typename T2> 
    // define class of CP Pair
    class pair { 
        public : // able to access
            T1 first ;
            T2 second ; 
        
            // default & custom constructor
            pair() : first(0) , second(0) { } // default = 0,0
            pair(const T1 &a , const T2 &b) : first(a) , second(b) { } // T1 , T2 = type of value in pair

            // operator
            bool operator==(const pair<T1,T2> &other) { // compare with another CP::Pair
                return (first == other.first && second == other.second) ; // first = CP::Pair first 
            }
            bool operator<(const pair<T1,T2> &other) {
                return ( (first < other.first) || (first == other.first && second < other.second) ) ; 
            }
    };
}

#endif 
