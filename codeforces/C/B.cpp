#include <iostream>
using namespace std;
int T, N;
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		int cnt_8 = N / 4;
		if (N % 4 != 0)
			cnt_8++;
		for (int i = 0; i < N; i++) {
			if (i<N-cnt_8) {
				cout << 9;
			}
			else {
				cout << 8;
			}
		}
		cout << "\n";
	}
	return 0;
}