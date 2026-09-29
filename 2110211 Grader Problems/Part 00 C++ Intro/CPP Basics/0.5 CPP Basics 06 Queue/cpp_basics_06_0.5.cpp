// =====================================================
// โจทย์นี้มีฟังก์ชัน Q1, Q2 -- std::queue
// queue คือ container แบบ "เข้าก่อน-ออกก่อน" (FIFO)
// คิดว่าเป็นคิวรอคิว: คนที่มาก่อนได้รับบริการก่อน
//
// คำสั่งหลัก:
//   q.push(x)   -- เพิ่ม x ที่ด้านหลัง
//   q.front()   -- อ่านค่าด้านหน้า (ไม่ได้เอาออก)
//   q.pop()     -- เอาค่าด้านหน้าออก (ไม่ได้คืนค่า)
//   q.empty()   -- true ถ้าว่าง
//   q.size()    -- จำนวน element ที่อยู่ใน queue ตอนนี้
//
// เปรียบกับ stack:
//   stack: top() และ pop() ทำงานที่ปลายด้านเดียวกัน (LIFO)
//   queue: push() เพิ่มด้านหลัง, front()+pop() ทำงานด้านหน้า (FIFO)
// =====================================================

// #include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// Q1: รับ n จำนวนเต็ม push ทีละตัวลง queue
// แล้ว dequeue ทั้งหมดออกมา print ทีละบรรทัด
// เพราะ FIFO ตัวที่ push แรกจะออกมาก่อน
void Q1() {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        // TODO: q.push(x)
        q.push(x) ; 
    }
    // TODO: while q ไม่ว่าง ให้ print q.front() แล้วเรียก q.pop()
    while (!q.empty()) {
        int top_ele = q.front() ; 
        cout << top_ele << endl ; 
        q.pop() ; 
    }
}

// Q2: รับ n คำสั่ง แต่ละคำสั่งเป็น:
//   "push x"  -- เพิ่มจำนวนเต็ม x ที่ด้านหลัง queue
//   "pop"     -- เอาค่าด้านหน้าออก (ถ้าว่างอยู่ให้ข้ามไป)
// หลังจบทุกคำสั่ง print ค่าด้านหน้าของ queue
// ถ้า queue ว่าง print "empty"
void Q2() {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            // TODO: q.push(x)
            q.push(x) ;
        } else {
            // op == "pop"
            // TODO: ถ้า q ไม่ว่าง ให้เรียก q.pop()
            if (!q.empty()) q.pop() ; 
        }
    }
    // TODO: ถ้าว่าง print "empty" ถ้าไม่ว่าง print q.front()
    if (!q.empty()) cout << q.front() << endl ; 
    else cout << "empty" << endl ; 
}

int main() {
    int task;
    cin >> task;
    // DEBUG TIP: เปลี่ยน "cin >> task;" เป็นเลขตรง ๆ เช่น "int task = 2;"
    // เพื่อทดสอบทีละ Q บน local แล้วเปลี่ยนกลับก่อน submit
    if (task == 1) Q1();
    else if (task == 2) Q2();
    return 0;
}
