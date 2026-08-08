// =====================================================
// โจทย์นี้มีฟังก์ชัน Q1 ถึง Q5
// std::map, std::sort, lower_bound, upper_bound,
// max_element, min_element, max, min
// =====================================================

// #include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Q1: รับ n คู่ (key, value) ใส่ map แล้วรับ query key แล้ว print ค่านั้น
// map<string, int> เก็บคู่ key-value โดย key เป็น string, value เป็น int
// เรียงตาม key อัตโนมัติ
// m[key] = val;  ใส่หรืออัปเดตค่าใน map
// m[key]         อ่านค่าที่ key นั้น
void Q1() {
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        string key;
        int val;
        cin >> key >> val;
        // TODO: ใส่ key -> val ลง m
        m[key] = val ; 
    }
    string query;
    cin >> query;
    // TODO: print m[query]
    cout << m[query] << endl ; 
}

// Q2: setup เหมือน Q1 แต่ใช้ m.find() แทน m[key] ในการค้นหา
// m.find(key) คืน iterator:
//   ถ้าเจอ: iterator ชี้ที่ entry นั้น อ่านได้ด้วย it->first (key) และ it->second (value)
//                                          หรือสามารถเขียนแบบ (*it).first ก็ได้ ให้ผลเช่นเดียวกัน
//   ถ้าไม่เจอ: คืน m.end()
// ต้องเช็คก่อนเสมอ: if (it != m.end()) { ... }
// ทำไมไม่ใช้ m[key]?  เพราะถ้า key ไม่มีอยู่ m[key] จะสร้าง entry ใหม่ค่า 0 โดยอัตโนมัติ
// ทำไมไม่ใช้ std::find? เพราะ std::find วิ่งทีละ element O(n) -> พูดง่าย ๆ คือช้ากว่ามาก
//                        ส่วน m.find() ใช้ tree structure ค้นหาได้ O(log n) -> พูดง่าย ๆ คือเร็วกว่ามาก
void Q2() {
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        string key;
        int val;
        cin >> key >> val;
        // TODO: ใส่ key -> val ลง m
        m[key] = val ; 
    }
    string query;
    cin >> query;
    // TODO: ใช้ m.find(query) แล้ว print it->second หรือ "not found"
    auto found_itr = m.find(query) ; 
    if (found_itr != m.end()) { 
        cout << (*found_itr).second << endl ; 
    }
    else { 
        cout << "not found" << endl ; 
    }
}

// Q3: รับ n จำนวนเต็ม เรียงจากน้อยไปมาก แล้ว print ทีละบรรทัด
// std::sort(v.begin(), v.end()) เรียงจากน้อยไปมากโดย default (เรียนรู้เพิ่มเติม: สามารถทำให้เรียงจากมากไปน้อยได้)
void Q3() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    // TODO: sort v
    // TODO: print ทีละบรรทัด

    sort(v.begin() , v.end()) ; 
    for (auto each_element : v) cout << each_element << " " << endl ; 
}

// Q4: รับ n จำนวนเต็ม (ยังไม่เรียง) และ query q แล้ว print สองบรรทัด:
// บรรทัด 1: index ของ element แรกที่ >= q (lower_bound)
// บรรทัด 2: index ของ element แรกที่ >  q (upper_bound)
// ต้อง sort ก่อนเรียก lower_bound หรือ upper_bound เสมอ
// แปลง iterator เป็น index ด้วยการลบ v.begin():
//   int lb = (int)(lower_bound(v.begin(), v.end(), q) - v.begin());
// ตัวอย่าง: v = [1, 2, 2, 3, 5], q = 2
//   lower_bound -> index 1 (element แรกที่ >= 2)
//   upper_bound -> index 3 (element แรกที่ >  2)
void Q4() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int q;
    cin >> q;
    // TODO: คำนวณ lb ด้วย lower_bound แล้ว print
    // TODO: คำนวณ ub ด้วย upper_bound แล้ว print
    auto lb_itr = lower_bound(v.begin() , v.end() , q) ; cout << distance(v.begin() , lb_itr) << endl ; // or using lb_itr - v.begin() 
    auto ub_itr = upper_bound(v.begin() , v.end() , q) ; cout << distance(v.begin() , ub_itr) << endl ; // or using ub_itr - v.begin() 

}

// Q5: รับ n จำนวนเต็ม แล้ว print สี่บรรทัด:
// บรรทัด 1: ค่ามากสุดใน v  (ใช้ max_element)
// บรรทัด 2: ค่าน้อยสุดใน v (ใช้ min_element)
// จากนั้นรับอีกสองตัว a และ b:
// บรรทัด 3: ค่ามากกว่าระหว่าง a กับ b (ใช้ max)
// บรรทัด 4: ค่าน้อยกว่าระหว่าง a กับ b (ใช้ min)
// max_element คืน iterator ต้อง dereference ด้วย *:
//   cout << *max_element(v.begin(), v.end()) << "\n";
// std::max และ std::min รับแค่ 2 argument:
//   cout << max(a, b) << "\n";
void Q5() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    // TODO: print *max_element(v.begin(), v.end())
    cout << *max_element(v.begin(), v.end()) << endl ; 
    // TODO: print *min_element(v.begin(), v.end())
    cout << *min_element(v.begin(), v.end()) << endl ;

    int a, b;
    cin >> a >> b;
    // TODO: print max(a, b)
    cout << max(a,b) << endl ; 
    // TODO: print min(a, b)
    cout << min(a,b) << endl ; 
}

int main() {
    int task;
    cin >> task;
    // DEBUG TIP: เปลี่ยน "cin >> task;" เป็นเลขตรง ๆ เช่น "int task = 4;"
    // เพื่อทดสอบทีละ Q บน local แล้วเปลี่ยนกลับก่อน submit
    if (task == 1) Q1();
    else if (task == 2) Q2();
    else if (task == 3) Q3();
    else if (task == 4) Q4();
    else if (task == 5) Q5();
    return 0;
}
