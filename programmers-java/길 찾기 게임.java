import java.util.Arrays;

class Node {
    int left;
    int right;
    public Node() {
        this.left = 0;
        this.right = 0;
    }
}

class Solution {
    static void findParent(int idx) {
        int x = nodes[idx-1][0];
        int y = nodes[idx-1][1];
        int start = START;
        while(true) {
            if (nodes[start-1][1]<=y) break;
            if (nodes[start-1][0]>x) {
                if (tree[start].left==0) {
                    tree[start].left = idx;
                    return;
                }
                else {
                    start = tree[start].left;
                    continue;
                }
            }
            else {
                if (tree[start].right==0) {
                    tree[start].right = idx;
                    return;
                }
                else {
                    start = tree[start].right;
                    continue;
                }
            }
        }
    }

    static void preorder(int n) {
        pre[PRE_IDX++] = n;
        if (tree[n].left!=0) {
            preorder(tree[n].left);
        }
        if (tree[n].right!=0) {
            preorder(tree[n].right);
        }

    }

    static void postorder(int n) {
        if (tree[n].left!=0) {
            postorder(tree[n].left);
        }
        if (tree[n].right!=0) {
            postorder(tree[n].right);
        }
        post[POST_IDX++] = n;
    }

    static int PRE_IDX = 0, POST_IDX = 0, START = 0, START_V = -1;
    static int[] pre, post;
    static int[][] nodes, sorted;
    static Node[] tree;
    public int[][] solution(int[][] nodeinfo) {
        int[][] answer = new int[2][nodeinfo.length];
        nodes = nodeinfo;
        sorted = new int[nodeinfo.length][3];
        for (int i = 0; i<nodeinfo.length; i++){
            for (int j = 0; j<nodeinfo[i].length; j++){
                sorted[i][j] = nodeinfo[i][j];
            }
            sorted[i][2] = i+1;
        }
        Arrays.sort(sorted, (int[] a, int[] b) -> b[1] - a[1]);
        tree = new Node[nodeinfo.length+1];
        for (int i = 0; i<nodeinfo.length; i++ ){
            tree[i+1] = new Node();
        }

        for (int i = 0; i < nodes.length; i++) {
            if (START_V < nodes[i][1]){
                START_V = nodes[i][1];
                START = i+1;
            }
        }

        for (int i = 0; i<nodes.length; i++) {
            findParent(sorted[i][2]);
        }

        pre = new int[nodeinfo.length];
        post = new int[nodeinfo.length];
        preorder(START);
        postorder(START);
        answer[0] = pre;
        answer[1] = post;
        return answer;
    }
}