// =====================================================
// โจทย์นี้มีฟังก์ชัน Q1, Q2 -- std::stack
// stack คือ container แบบ "เข้าหลัง-ออกก่อน" (LIFO)
// คิดว่าเป็นจานซ้อนกัน: วางจานใหม่ทับลงบน ยกออกจากบนเสมอ
//
// คำสั่งหลัก:
//   s.push(x)  -- เพิ่ม x ด้านบน
//   s.top()    -- อ่านค่าด้านบน (ไม่ได้เอาออก)
//   s.pop()    -- เอาค่าด้านบนออก (ไม่ได้คืนค่า)
//   s.empty()  -- true ถ้าว่าง
//   s.size()   -- จำนวน element ที่อยู่ใน stack ตอนนี้
// =====================================================

// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Q1: รับ n จำนวนเต็ม push ทีละตัวลง stack
// แล้ว pop ทั้งหมดออกมา print ทีละบรรทัด
// เพราะ LIFO ตัวที่ push ทีหลังจะออกมาก่อน
void Q1() {
    int n;
    cin >> n;
    stack<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        // TODO: s.push(x)
        s.push(x) ; 
    }
    // TODO: while s ไม่ว่าง ให้ print s.top() แล้วเรียก s.pop()
    while (s.empty() != true) { 
        // call top element
        int top_ele = s.top() ; 
        cout << top_ele << endl ; 
        // then pop it out of stack
        s.pop() ; 
    }
}

// Q2: รับ n คำสั่ง แต่ละคำสั่งเป็น:
//   "push x"  -- push จำนวนเต็ม x ลง stack
//   "pop"     -- เอาค่าบนสุดออก (ถ้าว่างอยู่ให้ข้ามไป)
// หลังจบทุกคำสั่ง print ค่าบนสุดของ stack
// ถ้า stack ว่าง print "empty"
void Q2() {
    int n;
    cin >> n;
    stack<int> s;
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            // TODO: s.push(x)
            s.push(x) ; 
        } else {
            // op == "pop"
            // TODO: ถ้า s ไม่ว่าง ให้เรียก s.pop()
            if (!s.empty()) s.pop() ; 
        }
    }
    // TODO: ถ้าว่าง print "empty" ถ้าไม่ว่าง print s.top()
    if (s.empty()) cout << "empty" << endl ; 
    else cout << s.top() << endl ; 
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
