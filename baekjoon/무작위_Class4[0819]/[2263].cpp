#include <iostream>
using namespace std;
int N, postOrder[100000], inOrder[100000], idx[100000];
void preOrder(int inBegin, int inEnd, int postBegin, int postEnd) {
    if (inEnd < inBegin || postEnd < postBegin) return;
    int root = postOrder[postEnd];//postOrder의 끝 == 루트
    cout << root << " ";
    int rootidx = idx[root];//루트의 inOrder에서 index
    preOrder(inBegin, rootidx - 1, postBegin, postBegin + (rootidx - inBegin) - 1);//inBegin~root까지의 개수 맞춰서 postidx 정하기 
    preOrder(rootidx + 1, inEnd, postBegin + (rootidx - inBegin), postEnd - 1);//나머지 개수 //postEnd 사용했으므로 제외
}
int main() {//트리의 순회
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> inOrder[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> postOrder[i];
    }
    for (int i = 0; i < N; i++) {
        idx[inOrder[i]] = i;
    }
    preOrder(0, N - 1, 0, N - 1);
    return 0;
}