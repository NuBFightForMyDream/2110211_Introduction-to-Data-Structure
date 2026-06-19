# include <iostream> 
# include <string> 
# include <algorithm> 
# include <queue> 
using namespace std ; 

class Student {
    public:
        Student(float score, string a, string b) { // constructor
            name = a;
            surname = b;
            gpax = score;
        }
        bool is1stHonor() { return gpax >= 3.6; } // method

        //not good, now our data is public
        string name,surname;
        float gpax;
        
        //method : overloading <
        bool operator<(const Student& other) const { // 1 parameter (Student object)
            return gpax < other.gpax;
        }
};


int main() {
    Student a(2.95,"nattee","niparnan");
    Student b(4.00,"attawith","sudsang");
    cout << (a < b) << endl; // 1 = TRUE 
        // a.operator<( b ) ==> a < b

    priority_queue<Student> pq;
    pq.push(a);
    pq.push(b); // more priority -> go on top 

    cout << pq.top().name << endl; // attawith 
}