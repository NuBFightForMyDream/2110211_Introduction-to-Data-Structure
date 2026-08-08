// =====================================================
// โจทย์นี้มีฟังก์ชัน Q1 ถึง Q4
// std::priority_queue และ operator overloading
//
// priority_queue ให้ element ที่ "สำคัญที่สุด" ออกมาก่อนเสมอ
// โดย default คือค่ามากสุดออกก่อน (max-heap)
//
// คำสั่งหลัก (เหมือน stack):
//   pq.push(x)  -- ใส่ x
//   pq.top()    -- อ่านค่าที่ priority สูงสุด
//   pq.pop()    -- เอาค่าที่ priority สูงสุดออก
//   pq.empty()  -- true ถ้าว่าง
// =====================================================
//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

// Q3 และ Q4 ใช้ struct นี้
// struct คือการรวมหลายค่าไว้ด้วยกัน คล้าย class ใน Python แต่เรียบง่ายกว่า
struct Item {
    int id, val;

    // operator< บอก sort() ว่าจะเรียงยังไง
    // "return val < o.val" หมายถึง Item นี้มาก่อน o เมื่อ val น้อยกว่า
    // ทำให้ sort() เรียงจากน้อยไปมากตาม val
    bool operator<(const Item& o) const {
        // TODO: return val < o.val
        return val < o.val ; 
    }
};

// functor คือ struct ที่มี operator() ทำให้เรียกได้เหมือนฟังก์ชัน
// priority_queue รับ functor เป็น argument ที่ 3 เพื่อกำหนด priority
// กฎ: ถ้า CmpByVal(a, b) คืน true หมายถึง a มี priority ต่ำกว่า b (b ออกก่อน)
// ดังนั้น "return a.val < b.val" หมายถึง val น้อย = priority ต่ำ
//                                  val มาก = priority สูง = ออกก่อน (max-heap by val)
struct CmpByVal {
    bool operator()(Item a, Item b) const {
        // TODO: return a.val < b.val
        return a.val < b.val ; 
    }
};

// Q1: รับ n จำนวนเต็ม ใส่ลง MAX priority_queue แล้ว pop ทั้งหมด print ทีละบรรทัด
// ค่ามากสุดออกก่อน
// ประกาศด้วย: priority_queue<int> pq;
void Q1() {
    int n;
    cin >> n;
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        // TODO: pq.push(x)
        pq.push(x);
    }
    // TODO: while ไม่ว่าง print pq.top() แล้ว pq.pop()
    while (!pq.empty()) { 
        cout << pq.top() << endl;
        pq.pop() ; 
    }
}

// Q2: รับ n จำนวนเต็ม ใส่ลง MIN priority_queue แล้ว pop ทั้งหมด print ทีละบรรทัด
// ค่าน้อยสุดออกก่อน
// เพิ่ม greater<int> เป็น comparator:
//   priority_queue<int, vector<int>, greater<int>> pq;
// greater<int>(a, b) คืน true เมื่อ a > b ทำให้ค่าน้อยอยู่บนสุด
void Q2() {
    int n;
    cin >> n;
    // TODO: ประกาศ pq เป็น min priority_queue ด้วย greater<int>
    priority_queue<int , vector<int> , greater<int>> pq ; 

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        // TODO: pq.push(x)
        pq.push(x) ; 
    }
    // TODO: while ไม่ว่าง print pq.top() แล้ว pq.pop()
    while(!pq.empty()) { 
        cout << pq.top() << endl ; 
        pq.pop() ; 
    }
}

// Q3: รับ n items (แต่ละ item คือสองตัวเลข: id และ val)
// sort ด้วย sort() ซึ่งจะใช้ operator< ที่นิยามไว้ใน struct Item
// print id ของแต่ละ item ทีละบรรทัด (เรียงจาก val น้อยไปมาก)
void Q3() {
    int n;
    cin >> n;
    vector<Item> v;
    for (int i = 0; i < n; i++) {
        Item it;
        cin >> it.id >> it.val;
        v.push_back(it);
    }
    // TODO: sort(v.begin(), v.end())
    // TODO: print it.id ทีละบรรทัดด้วย range-based for
    sort(v.begin() , v.end()) ; 
    for (auto &it : v) cout << it.id << endl ; 
}

// Q4: input เหมือน Q3 แต่ใช้ priority_queue กับ CmpByVal functor แทน sort
// ประกาศด้วย: priority_queue<Item, vector<Item>, CmpByVal> pq;
// pop แล้ว print id ของแต่ละ item ทีละบรรทัด
// เพราะ CmpByVal ทำให้ val มาก = priority สูง ลำดับที่ออกมาจะเป็น val มากไปน้อย
// (ตรงข้ามกับ Q3)
void Q4() {
    int n;
    cin >> n;
    // TODO: ประกาศ pq ด้วย CmpByVal
    for (int i = 0; i < n; i++) {
        Item it;
        cin >> it.id >> it.val;
        // TODO: pq.push(it)
    }
    // TODO: while ไม่ว่าง print pq.top().id แล้ว pq.pop()
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
