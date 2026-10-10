/*
10. (10 คะแนน) Popcorn on the Cloud!!! หลังจากที่ร้าน Popcorn ขายดีมาก เราจึงพัฒนาให้ร้าน Popcorn ของเราดียิ่งขึ้นโดยการ
เพิ่มรสชาติของ Popcorn และให้ลูกค้าสามารถสั่งแบบด่วนได้โดยการเพิ่มเงินค่าความ “ด่วน” ในโจทย์ข้อนี้ เราจะขาย popcorn
เป็นถุง โดยเราจะทำ popcorn เสร็จทีละถุงและลูกค้าจะสั่งทีละ 1 ถุงเสมอ จงเขียนคลาส PopcornDispatcher ซึ่งช่วยในการขาย
Popcorn โดยคลาสนี้จะต้องมีฟังก์ชันดังต่อไปนี้

• void order(string flavor, string id, int priority) ซึ่งจะถูกเรียกเมื่อมีลูกค้า (ที่ระบุด้วยรหัสลูกค้า id) สั่ง popcorn รส
flavor จำนวน 1 ถุง โดยยินดีจ่ายเงินค่าความด่วน priority บาท (รับประกันว่าในการเรียก order แต่ละครั้งนั้น ค่า id จะไม่
ซ้ากันเลย)

• string serve(string flavor) ซึ่งจะถูกเรียกเมื่อร้านท า popcorn รส flavor เสร็จเป็นจ านวน 1 ถุง โดยฟังก์ชันนี้จะต้องคืน
ค่ารหัสลูกค้าที่จะได้รับ popcorn รสดังกล่าว โดยเราจะให้บริการกับลูกค้าที่จ่ายค่าความด่วนสูงสุดเสมอ หากมีลูกค้าหลายคนที่จ่ายค่าความด่วนสูงสุดเท่ากันยังรอ popcorn อยู่ เราจะให้บริการกับลูกค้าที่สั่งมาก่อน รับประกันว่าฟังก์ชันนี้จะไม่ถูก
เรียกหากไม่มีลูกค้าที่รอ popcorn รสชาติ flavor อยู่ ณ ขณะนั้น

• pair<string,size_t> longest() const ซึ่งทำหน้าที่ตอบว่า popcorn รสชาติไหน มีจ านวนถุงที่ลูกค้ายังรออยู่มากที่สุด และยังรออยู่อีกกี่ถุง หากมีหลายรสชาติที่จ านวนคนรอเท่ากัน ให้คืนรสชาติที่มีชื่อน้อยที่สุดก่อน และหากไม่มีรสชาติไหนก าลัง
รอเลย ให้คืนค่า {"",0}

ในข้อนี้ นิสิต “อาจจะ” ต้องการเขียน comparator ขึ้นมาใช้งานด้วย

10.1. จงระบุชื่อและประเภทของ Data Member ที่ใช้ในคลาสนี้ พร้อมทั้งระบุวัตถุประสงค์ของ Data Member ดังกล่าว หาก data
member เป็นประเภทที่ประกอบด้วยข้อมูลย่อยต่าง ๆ (เช่น pair<x,y>) จะต้องระบุประเภทและวัตถุประสงค์ของข้อมูลย่อย
ด้วย นิสิตสามารถสร้างคลาสต่าง ๆ เพิ่มเติมได้ โดยต้องระบุประเภทและวัตถุประสงค์ของ member ของคลาสด้วย

10.2 write class
*/

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <utility> // pair
#include <functional> // greater
#include <algorithm>
using namespace std ; 








class PopcornDispatcher { 
    protected :
    

        
         
        

}


int main() {
    PopcornDispatcher shop;

    shop.order("cheese", "A", 10);
    shop.order("cheese", "B", 30);
    shop.order("cheese", "C", 30);
    shop.order("sweet", "D", 20);

    auto result = shop.longest();
    cout << result.first << " " << result.second << '\n';

    cout << shop.serve("cheese") << '\n'; // B: จ่ายสูงสุด สั่งก่อน C
    cout << shop.serve("cheese") << '\n'; // C

    result = shop.longest();
    cout << result.first << " " << result.second << '\n';

    cout << shop.serve("cheese") << '\n'; // A
    cout << shop.serve("sweet") << '\n';  // D

    result = shop.longest();
    cout << '"' << result.first << "\" " << result.second << '\n';
}
