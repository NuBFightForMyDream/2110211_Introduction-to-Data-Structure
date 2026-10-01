#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std ; 

int main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long count_event ; cin >> count_event ; 

    // create some data structure here
    queue< pair<long long,long long> > customer_queue ; // {popcorn_needed , customer_id}
    priority_queue< pair<long long , long long> > popcorn_queue ;  // {popcorn_sweetness , produced_amount}
    
    vector< long long > customer_output ; // check size() for customer id , then change value in vector 
                                          // (to make sure that 0 will appear in undone customer)
    long long customer_id = 0 ; 

    // loop input 
    for (long long i = 0 ; i < count_event ; i++) { 
        int type ; cin >> type ; 

        if (type == 1) { 
            long long popcorn_needed_amount ; cin >> popcorn_needed_amount ; 
            long long customer_id = (long long)customer_output.size() ; 
            customer_output.push_back(0) ; // dummy value 
            customer_queue.push( make_pair(popcorn_needed_amount , customer_id) ) ; // add to queue 
        }

        else if (type == 2) { 
            long long produced_amount , popcorn_sweetness ; 
            cin >> produced_amount >> popcorn_sweetness ; 

            popcorn_queue.push( make_pair(popcorn_sweetness , produced_amount) ) ; // sort with most value first
        }

        // we can sell anytime 
        // so we can check if any popcorn in stock 
        // condition : check both condition (popcorn not empty) & customer not empty

        while ( (popcorn_queue.empty() == false) && (customer_queue.empty() == false) ) { 
            // see first customer with most sweetness popcorn (front of queue)

            auto &[popcorn_need , customer_id] = customer_queue.front() ; // {popcorn_needed , customer_id}
            auto [sweetness , stock_amount] = popcorn_queue.top() ;// copy , not reference (bcz we need to edit value)
            
            // check if popcorn is more than customer_need or not 
            
            if (stock_amount >= popcorn_need) { // popcorn_need < amount -> some popcorn left 

                // add to customer_output
                customer_output[ customer_id ] += popcorn_need * sweetness ; 
                long long popcorn_left = stock_amount - popcorn_need ; 

                // pop old data out (to add new data)
                popcorn_queue.pop() ; 

                // check if popcorn left 
                if (popcorn_left > 0) {
                    // update new data to popcorn_queue
                    
                    popcorn_queue.push( make_pair(sweetness , popcorn_left) ) ;
                }

                else { // no more popcorn left 
                    // add updated popcorn 
                    // do nothing , we pop it out already 
                }

                // pop customer out (as they get full portion as they requested)
                customer_queue.pop() ; 

            }

            else { // stock_amount < popcorn_need -> customer have to wait (but stock_amount has all gone)
                // add to customer_output 
                customer_output[customer_id] += stock_amount * sweetness ; 
                // update data 
                popcorn_need -= stock_amount ; 
                // pop popcorn queue out (as it was given)
                popcorn_queue.pop() ; 
            }
        }
    }

    // output by id 
    for (auto &sweetness_got : customer_output) { 
        cout << sweetness_got << "\n" ; 
    }
    cout << endl ; 

}