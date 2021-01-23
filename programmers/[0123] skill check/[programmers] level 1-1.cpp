
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i != i)
                answer += i, answer += n / i;
            else
                answer += i;
        }
    }

    return answer;
}
