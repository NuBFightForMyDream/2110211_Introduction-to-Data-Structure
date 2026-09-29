// =====================================================
// โจทย์นี้มีฟังก์ชัน Q1 ถึง Q4
// แต่ละอันทดสอบ concept คนละเรื่อง:
// vector, set, pair, function, iterator
// เติมโค้ดข้างใน Qx() เท่านั้น ไม่ต้องแก้ main()
// =====================================================
// #include <bits/stdc++.h>
# include <iostream>
# include <vector>
# include <set>
using namespace std;

// Q4 ใช้ function ที่ประกาศไว้นอก main()
// ใน Python ฟังก์ชันรับค่าชนิดอะไรก็ได้อัตโนมัติ
// ใน C++ ปกติต้องเขียนฟังก์ชันแยกสำหรับแต่ละชนิด (int, double, ...)
//      (**นอกเหนือขอบเขตที่เรียน:** สามารถใช้ template ช่วยให้เขียนครั้งเดียวแล้วใช้ได้หลายชนิด)
// TODO: เขียนฟังก์ชัน myMax ที่รับ a, b แล้วคืนค่าที่มากกว่า
int myMax(int a, int b) {
    // TODO: return a ถ้า a มากกว่า ไม่งั้น return b
    if (a > b) return a ; else return b ; 
}

// Q1: รับ n ตัวเลข เก็บลง vector แล้ว print ผลรวม
// vector<int> คล้ายกับ list ใน Python แต่เก็บได้เฉพาะ int
// v.push_back(x) เพิ่ม x ต่อท้าย เทียบกับ v.append(x) ใน Python
void Q1() {
    int n;
    cin >> n;
    vector<int> v;
    // TODO: รับ n ตัวเลข แล้ว push_back แต่ละตัวลง v
    // TODO: บวกค่าทั้งหมดใน v
    // TODO: print ผลรวม

    int sum = 0 ; 
    for (int i = 0 ; i < n ; i++) { 
        int num ; cin >> num ; 
        v.push_back(num);
        sum += num ; 
    }

    cout << sum << endl ; 
}

// Q2: รับ n ตัวเลข เก็บลง set แล้ว print จำนวนค่าที่ไม่ซ้ำกัน
// พร้อมทั้งค่าเหล่านั้นเรียงลำดับจากน้อยไปมาก
//
// std::set<int> คล้ายกับ set ใน Python
//   Python: s.add(x)      <-> C++: s.insert(x)
//   Python: len(s)        <-> C++: s.size()
//
// ความแตกต่างสำคัญคือ
//   - ทั้งคู่เก็บข้อมูลไม่ซ้ำ
//   - std::set ใน C++ จะเรียงข้อมูลจากน้อยไปมากโดยอัตโนมัติ
//     - เหตุผลจะได้เรียนต่อไปในรายวิชา
//
// การวนสมาชิกใน set มี 2 วิธี
//
// 1) ใช้ iterator (แนะนำให้รู้ เพราะใช้ได้กับ Standard Template Library (STL) ทุก container เช่น vector, map)
//
//      for (auto it = s.begin(); it != s.end(); ++it) {
//          cout << *it << " ";
//      }
//
//    begin() คือ iterator ที่ชี้ไปสมาชิกตัวแรก
//    end()   คือ iterator ที่ชี้ "หลังสมาชิกตัวสุดท้าย"
//    *it     คือค่าที่ iterator กำลังชี้อยู่
//    ++it    เลื่อนไปสมาชิกตัวถัดไป
//
// 2) ใช้ range-based for (เขียนสั้นกว่า)
//
//      for (int x : s) {
//          cout << x << " ";
//      }
//
//    ซึ่งจริง ๆ แล้วเบื้องหลังใช้ iterator เช่นเดียวกัน
//
void Q2() {
    int n;
    cin >> n;
    set<int> s;
    // TODO: รับ n ตัวเลข แล้ว insert แต่ละตัวลง s
    // TODO: print s.size()
    // TODO: print ค่าใน s
    for (int i = 0 ; i < n ; i++) { 
        int num ; cin >> num ; 
        s.insert(num) ;
    }

    cout << s.size() << endl ; 
    for (int each_num : s) { 
        cout << each_num << " " ; 
    }
}

// Q3: รับสองจำนวนเต็ม a และ b เก็บใน pair แล้ว print ทั้งคู่คั่นด้วย space
// pair<int, int> รวมสองค่าไว้ด้วยกัน คล้าย tuple (a, b) ใน Python
// แต่อ่านค่ากลับด้วย .first และ .second แทน [0] และ [1]
void Q3() {
    int a, b;
    cin >> a >> b;
    // TODO: เก็บ a, b ลง pair<int, int>
    // TODO: print .first แล้ว space แล้ว .second
    pair<int , int> my_pair = make_pair(a,b) ; 
    cout << my_pair.first << " " << my_pair.second << " " << endl ; 
}

// Q4: รับ a และ b แล้ว print ค่าที่มากกว่าโดยใช้ myMax function
void Q4() {
    int a, b;
    cin >> a >> b;
    // TODO: print myMax(a, b)

    cout << myMax(a,b) << endl ; 
}

int main() {
    int task;
    cin >> task;
    // DEBUG TIP: เปลี่ยน "cin >> task;" เป็นเลขตรง ๆ เช่น "int task = 3;"
    // เพื่อทดสอบทีละ Q บน local แล้วเปลี่ยนกลับก่อน submit
    if (task == 1) Q1();
    else if (task == 2) Q2();
    else if (task == 3) Q3();
    else if (task == 4) Q4();
    return 0;
}
