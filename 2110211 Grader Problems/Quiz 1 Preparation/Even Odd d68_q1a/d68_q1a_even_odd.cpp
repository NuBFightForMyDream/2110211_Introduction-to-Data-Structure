#include <iostream>
#include <map> 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, int> remainder_count;
    int N; cin >> N;
    
    int even_count = 0;
    int odd_count = 0;

    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        
        if (remainder_count.count(num) > 0) {
            // check if exist , update status 
            if (remainder_count[num] % 2 == 0) even_count--;
            else odd_count--;
        }

        // 2. อัปเดตจำนวนใน Map
        remainder_count[num]++;

        // 3. อัปเดตสถานะ "หลังอัปเดต"
        if (remainder_count[num] % 2 == 0) even_count++;
        else odd_count++;

        // พิมพ์ผลลัพธ์ทันที (ใช้ \n เร็วกว่า endl)
        cout << even_count << " " << odd_count << "\n";
    }
}