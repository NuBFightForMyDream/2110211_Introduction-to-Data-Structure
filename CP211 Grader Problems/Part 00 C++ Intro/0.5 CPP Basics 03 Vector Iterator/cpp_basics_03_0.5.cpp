// =====================================================
// โจทย์นี้มีฟังก์ชัน Q1 ถึง Q3 -- vector iterator
// iterator คือ object ที่ชี้ไปยัง element หนึ่งใน container
// คิดว่าเป็น cursor ที่เดินผ่าน vector ได้
//
// v.begin()  ชี้ที่ element แรก
// v.end()    ชี้ "เลย" element สุดท้ายไปหนึ่งก้าว (ใช้เป็นตัวบอกว่าหมดแล้ว)
// loop แบบ iterator:
//   for (auto it = v.begin(); it != v.end(); it++) {
//       cout << *it << "\n";   // * อ่านค่าที่ iterator ชี้อยู่
//   }
// =====================================================
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Q1: รับ n ตัวเลขใส่ vector แล้ว print ทุกตัวด้วย explicit iterator
// ต้องใช้รูปแบบ for (auto it = v.begin(); it != v.end(); it++)
// แล้ว print ด้วย *it
// * คือการ dereference: "อ่านค่าที่ iterator ชี้อยู่"
void Q1() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    // TODO: วน from v.begin() to v.end() แล้ว print *it
    for (auto it = v.begin() ; it != v.end() ; it++) { 
        cout << *it << endl ; 
    }
}

// Q2: รับ n ตัวเลขใส่ vector แล้วรับ index idx
// ลบ element ที่ตำแหน่ง idx ออก แล้ว print ที่เหลือทีละบรรทัด
// Hint: v.erase() รับ iterator ไม่รับ index ตรง ๆ
//       แปลง index เป็น iterator ด้วย v.begin() + idx
//       แล้วเรียก v.erase(v.begin() + idx)
//       print ที่เหลือด้วย range-based for: for (auto x : v)
//       เทียบกับ Python คือ for x in v:
void Q2() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int idx;
    cin >> idx;
    // TODO: erase element ที่ตำแหน่ง idx
    // TODO: print ที่เหลือด้วย range-based for

    v.erase(v.begin() + idx);
    for (auto &each_element : v) cout << each_element << endl ; 

}

// Q3: รับ n ตัวเลขใส่ vector แล้วรับค่า target
// หา target ตัวแรกด้วย std::find แล้วลบออก จากนั้น print ที่เหลือ
// std::find(v.begin(), v.end(), target) คืน iterator ที่ match แรก
// ถ้าไม่เจอจะคืน v.end()
// ต้องเช็คก่อนเสมอว่า it != v.end() ก่อนจะ erase:
//   auto it = find(v.begin(), v.end(), target);
//   if (it != v.end()) { v.erase(it); }
void Q3() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int target;
    cin >> target;
    // TODO: ใช้ find() หา target
    // TODO: ถ้าเจอให้ erase
    // TODO: print ที่เหลือด้วย range-based for

    auto found_itr = find( v.begin() , v.end() , target );
    if (found_itr != v.end()) { // found , erase element
        v.erase( found_itr ) ; 
    }
    for (auto each_ele : v) cout << each_ele << endl ; // do in both case
}

int main() {
    int task;
    cin >> task;
    // DEBUG TIP: เปลี่ยน "cin >> task;" เป็นเลขตรง ๆ เช่น "int task = 3;"
    // เพื่อทดสอบทีละ Q บน local แล้วเปลี่ยนกลับก่อน submit
    if (task == 1) Q1();
    else if (task == 2) Q2();
    else if (task == 3) Q3();
    return 0;
}
