# include <iostream> 
# include <string>
using namespace std ; 

class Student { 
    public : 
        // constructor
        Student(float score) {
            gpax = score ; 
        }

        // methods
        bool is1stHonor() { 
            return gpax >= 3.6; 
        }
        void setFullName(string name , string surname) {
            this->name = name ;
            this->surname = surname ; 
        } 
        string getFullName() ; // define method outside class 

    private : 
        string name , surname ;
        double gpax ;  
};

string Student::getFullName() { // class:methodName
    return "[ Name : " + name + " , Surname : " + surname + "]" ;
}

int main() { 
    Student a(2.99) ;
    Student b(3.62) ; 
    a.setFullName("Chatrphol" , "Ovanonchai");
    cout << a.getFullName() << endl ; 
    cout << b.getFullName() << endl ; // [ , ]

    cout << a.is1stHonor() << endl ; // 0 =False 

}