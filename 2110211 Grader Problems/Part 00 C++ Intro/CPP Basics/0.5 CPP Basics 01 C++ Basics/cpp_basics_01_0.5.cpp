// =====================================================
// โจทย์นี้มีฟังก์ชัน Q1, Q2, Q3 แต่ละอันทดสอบ concept เดียว
// เติมโค้ดข้างใน Qx() เท่านั้น ไม่ต้องแก้ main()
//
// วิธีตรวจ:
// รับตัวเลขแรกเป็น task number (1, 2, หรือ 3)
// แล้ว main() จะเรียก Q ที่ตรงกัน
// C++ เริ่มรันจาก main() เสมอ แม้ main() จะอยู่ท้ายไฟล์
// =====================================================

// #include <bits/stdc++.h> // เป็นการสั่งให้คอมไพเลอร์ C++ รวมไฟล์ header มาตรฐานเกือบทั้งหมดไว้ในบรรทัดเดียว
#include <iostream>
using namespace std;

// Q1: print ข้อความ "Hello, World!" ออกมา
// Hint: cout << "ข้อความ" << "\n"; ใช้พิมพ์ข้อความแล้วขึ้นบรรทัดใหม่
//       เทียบกับ Python คือ print("ข้อความ")
void Q1() {
    // TODO: print Hello, World!
    cout << "Hello, World!" << endl ; 
}

// Q2: รับตัวเลข int หนึ่งตัว แล้ว print ค่านั้นกลับออกมา
// Hint: "int x;" ประกาศตัวแปร x ชนิด int (จำนวนเต็ม)
//       ใน C++ ต้องระบุชนิดตัวแปรตอนประกาศ ต่างจาก Python
//       "cin >> x;" รับค่าจาก input เก็บใส่ x
//       เทียบกับ Python คือ x = int(input())
void Q2() {
    // TODO:
    // 1. ประกาศตัวแปร x
    // 2. รับค่า input เก็บใส่ x
    // 3. print ค่า x
    int x ; 
    cin >> x ; 
    cout << x << endl ; 
}

// Q3: รับจำนวนเต็ม n แล้วใช้ for loop หาผลรวม 1 + 2 + ... + n
// Hint: for loop ใน C++ เขียนแบบนี้
//   for (int i = 1; i <= n; i++) {
//       // i จะวิ่งจาก 1 ถึง n ทีละ 1
//   }
//   เทียบกับ Python คือ for i in range(1, n + 1):
void Q3() {
    int n;
    cin >> n;
    // TODO: ใช้ for loop คำนวณ sum = 1 + 2 + ... + n
    // TODO: print sum
    int sum = 0 ; 
    for (int i = 0 ; i <= n ; i++) { 
        sum += i ; 
    }
    cout << sum << endl ; 
}

// Q4: รับ n จำนวนเต็ม แล้ว print ทุกตัวในบรรทัดเดียวกัน คั่นด้วย space
// Hint: cout สามารถ chain ต่อกันได้ด้วย <<
//   cout << '1' << ' ' << '3';  // พิมพ์: 1 3
// ใช้ใน loop แบบนี้:
//   for (...) {
//       cin >> x;
//       cout << x << ' ';  // พิมพ์ x ตามด้วย space ในบรรทัดเดิม
//   }
void Q4() {
    int n;
    cin >> n;
    // TODO: ใช้ for loop รับ n จำนวนเต็ม แล้ว print แต่ละตัวตามด้วย space
    for (int i = 0 ; i < n ; i++) { 
        int num ; cin >> num ; 
        cout << num << " " ; 
    }
}

int main() {
    int task;
    cin >> task;
    // DEBUG TIP: ถ้าอยากทดสอบทีละ Q บน local ให้เปลี่ยนบรรทัดบนเป็น
    //   int task = 2;
    // แล้วอย่าลืมเปลี่ยนกลับก่อน submit
    if (task == 1) Q1();
    else if (task == 2) Q2();
    else if (task == 3) Q3();
    else if (task == 4) Q4();
    return 0;
}
