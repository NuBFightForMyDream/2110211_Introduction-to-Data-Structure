#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

// Letter class represent for each person sending letter 
class Letter{
    public:
    string name; string address; string province; string district; int zip;
    bool operator < (const Letter& other) const { 
        // note : other is referenced , not pointer so using other.zip to get attributes

        // --> TODO : sort letter by postal code (zip) ascending , then sort with address ascending , then sort with name ascending
        // Note that data can be wrong , we'll correct it in another function 

        if (this->zip == other.zip) {
            // check address then name
            if (this->address == other.address) return this->name < other.name ; 
            else return this->address < other.address ; 
        }
        else return this->zip < other.zip ; 
    }
};

// zipInfo class represents for postal code (correct info)
class ZipInfo{
    public:
        int zip;
        string province;
        string district;
};

void correctZipAndSortLetters(vector<ZipInfo>& zipinfo, vector<Letter>& letters) {
    // we need to sent correct data , so we store data as map to auto correct postal code 
    map< pair<string , string> , int> district_info ;
    for (auto &eachzip : zipinfo) { // eachzip = Zipinfo type
        // define key & value 
        pair<string , string> district_province = {eachzip.district , eachzip.province} ;
        district_info[district_province] = eachzip.zip ;
    }

    // update postal code for each letter (because old info is wrong)
    for (auto &eachLetter : letters) { 
        // check if zip existed in database
        pair<string , string> key = {eachLetter.district , eachLetter.province} ;

        if (district_info.count(key) > 0) { 
            eachLetter.zip = district_info[ key ] ; // get data from created map 
        }
    }

    // sort vector of letters ascendingly
    stable_sort( letters.begin() , letters.end() );
}

int main() {
    int nzip;
    cin>>nzip;
    vector<ZipInfo> zipinfo;
    for (int i = 0; i < nzip; i++) {
        ZipInfo z;
        cin>>z.zip>>z.district>>z.province;
        zipinfo.push_back(z);
    }
 
    int n;
    cin>>n;
    vector<Letter> letters;
    for (int i = 0; i < n; i++) {
        Letter l;
        cin>>l.name>>l.address>>l.district>>l.province>>l.zip;
        letters.push_back(l);
    }
    correctZipAndSortLetters(zipinfo, letters);
    for (auto& l:letters) {
        cout<<l.name<<" "<<l.address<<" "<<l.district<<" "<<l.province<<" "<<l.zip<<endl;
    }
}