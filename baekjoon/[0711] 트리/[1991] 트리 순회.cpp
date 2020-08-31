#include <iostream>
using namespace std;
int N;
pair<int, int> tree[26];
void preorder(int node) {
    cout << char(node + 65);
    if (tree[node].first != -1)
        preorder(tree[node].first);
    if (tree[node].second != -1)
        preorder(tree[node].second);
}
void inorder(int node) {
    if (tree[node].first != -1)
        inorder(tree[node].first);
    cout << char(node + 65);
    if (tree[node].second != -1)
        inorder(tree[node].second);
}
void postorder(int node) {
    if (tree[node].first != -1)
        postorder(tree[node].first);
    if (tree[node].second != -1)
        postorder(tree[node].second);
    cout << char(node + 65);
}
int main() {
    cin >> N;
    char a, b, c;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c;
        if (b == '.')
            tree[a - 65].first = -1;
        else tree[a - 65].first = b - 65;
        if (c == '.')
            tree[a - 65].second = -1;
        else tree[a - 65].second = c - 65;
    }
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << '\n';
    postorder(0);
    return 0;
}