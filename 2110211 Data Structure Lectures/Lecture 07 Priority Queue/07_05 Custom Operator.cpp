#include <iostream>
#include <string>
#include <queue>
using namespace std;

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
    
class StudentByNameComparator {
    public:
        // method for sorting : overload()
        bool operator()(const Student& lhs, const Student& rhs) {
            return lhs.name < rhs.name;
        }
};

class GpaxThenName {
    public:
        // method for sorting : overload()
        bool operator()(const Student& lhs,const Student& rhs) {
            if (lhs.gpax == rhs.gpax) return lhs.name < rhs.name; // if same gpax , sort priority by name 
            return lhs.gpax < rhs.gpax;
        }
};

int main() {
    Student a(2.95,"nattee","niparnan");
    Student b(4.00,"attawith","sudsang");
    Student c(4.00,"vishnu","kotrajaras");
    cout << (a < b) << endl; // 1 = TRUE

    // define object 
    StudentByNameComparator comp1;
    GpaxThenName comp2;

    // store type Student , container "vector<Student>" , sort with StudentByNameComparator Class 
    priority_queue <Student , vector<Student> , StudentByNameComparator> pq(comp1); // sort with comp1
    pq.push(a);
    pq.push(b);
    cout << pq.top().name << endl; // a.name() = "nattee" (nattee come first)

    // store type Student , container "vector<Student>" , sort with GPaxThenNmae Class 
    priority_queue<Student , vector<Student> , GpaxThenName> pq2(comp2); // sort with comp2

    pq2.push(a);
    pq2.push(b);
    pq2.push(c);
    cout << pq2.top().name << endl; // b.name() = "vishnu" (attawith same grade as vishnu so vishnu come first)
        // vishnu = most priority
}