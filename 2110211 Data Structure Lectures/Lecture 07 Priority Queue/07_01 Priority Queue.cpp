# include <iostream> 
# include <vector> 
# include <queue>
using namespace std ;

int main() {
    // define priority queue 
    priority_queue<int> pq ; 

    pq.push(10) ; pq.push(30); pq.push(20) ; 
        // pq = top [30 20 10] btm
        // value with most value of priority will be on top (have algorithm to sort top)

    cout << "Current Priority Queue size " << pq.size() << " having top element as " << pq.top() << endl ; 

    pq.pop() ; // 30 (most priority) out 
    pq.push(15);
    pq.pop() ; // 20 out , now pq = top [15 10] btm 

    cout << "Current Priority Queue size " << pq.size() << " having top element as " << pq.top() << endl ;

    // structure similar to stack 
    // .back() can't be used 
    // data must be comparable
}