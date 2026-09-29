#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include "Tokenizer.h"

using namespace std;

// call function for defining later
void printUniqueWords1(string filename);
void printUniqueWords2(string filename);
void printUniqueWords3(string filename);
void printUniqueWords4(string filename);
void printWord(string filename);

int main() {
    string path_to_filename = "/Users/nubfightformydream/Documents/Intania 108 Courses/CP Grader Practices/2110211 Data Structure Grader Problems/2110211 Data Structure Lecture/Lecture 02 Vector Set Pair (Word Count Example)/mobydick.txt" ; 
    string filename = path_to_filename ;
    //printWord(filename);
    printUniqueWords1(filename);
    //printUniqueWords2(filename);
    //printUniqueWords3(filename);
    //printUniqueWords4(filename);
    return 0;
}
//-------------------------------------------------------
bool search(string words[], int n, string w) { // array words
    for (int i = 0; i < n; i++) {
        if (words[i] == w) return true;
    }
    return false;
}

//---------------------- base --------------------------
void printWord(string filename) {
    int n = 0;

    Tokenizer tokenizer(filename);
    while(tokenizer.hasNext()) { // check if tokenizer has next word 
        string token = tokenizer.next();
        n++;
    }
    tokenizer.close();
    cout << "A total of " << n << " words" << endl;
}
//-------------------------------------------------------
// big enough array : static array
void printUniqueWords1(string filename) {
    string words[100000]; // cons : waste of space reserved 
    int n = 0;

    Tokenizer tokenizer(filename);
    while(tokenizer.hasNext()) {
        string token = tokenizer.next();
        if (!search(words,n,token)) words[n++] = token;
        // if word not found , add word to index n then increment n 
    }
    tokenizer.close();
    cout << "A total of " << n << " words" << endl;
}
//-------------------------------------------------------
// expandable array : dynamic array 
void printUniqueWords2(string filename) {
    // pros : less memory
    // cons : super slow
    int cap = 1;
    string *words; // * for dynamic array 
    words = new string[cap]; // define new value with "new"
    int n = 0;
    Tokenizer tokenizer(filename);
    while(tokenizer.hasNext()) {
        string token = tokenizer.next();
        if (!search(words,n,token)) {
            // check if storage full
                if (n == cap) {
                    // define new array with double size of arr
                    string *a = new string[2*cap];
                    for (int i=0; i<n; i++) a[i] = words[i]; // copy data into a 
                    delete[] words; // delete data in words
                    words = a; // word point to a 
                    cap *= 2; // expand cap
                }
                words[n++] = token; // add word to words
        }
    }
    tokenizer.close();
    cout << "A total of " << n << " words" << endl;
}
//-------------------------------------------------------
// vector
void printUniqueWords3(string filename) {
    vector<string> words;
    Tokenizer tokenizer(filename);
    while(tokenizer.hasNext()) {
        string token = tokenizer.next();
        if (words.end() == find(words.begin(), words.end(), token))
            words.push_back(token);
    }
    tokenizer.close();
    cout << "A total of " << words.size() << " words" << endl;
}
//-------------------------------------------------------
// set
void printUniqueWords4(string filename) {
    // pros : good at checking data if exists
    // cons : bad at seeing data inside
    set<string> words;
    Tokenizer tokenizer(filename);
    while(tokenizer.hasNext()) {
        string token = tokenizer.next();
        //if (words.end() == find(words.begin(), words.end(), token)) -> too slow by using find algorithm
        if (words.end() == words.find(token)) // too fast -> using find in set
            words.insert(token);
    }
    tokenizer.close();
    cout << "A total of " << words.size() << " words" << endl;
}
//-------------------------------------------------------
