#include <iostream>
#include <string>
using namespace std;
int M, D, day = 0;
int main() {
    string arr[8] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
    cin >> M >> D;
    for (int i = 2; i < M; i++) {
        if (i == 2)
            day += 28;
        else if (i == 4 || i == 6 || i == 9 || i == 11)
            day += 30;
        else
            day += 31;
    }
    if (M >= 2)
        day += D + 30;
    else
        day += D - 1;
    cout << arr[day % 7];
    return 0;
}