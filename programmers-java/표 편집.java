import java.util.Stack;

class Node {
    int up;
    int down;
    public Node(int up, int down) {
        this.up = up;
        this.down = down;
    }
}

class Tuple {
    int up;
    int down;
    int value;
    public Tuple(int up, int down, int value) {
        this.up = up;
        this.down = down;
        this.value = value;
    }
}

class Solution {
    static Node[] pointer;
    static int N,K, select;
    static Stack<Tuple> s = new Stack<>();

    static void move(char dir, int x) {
        if (dir=='U') {
            for (int i = 0; i<x; i++) {
                select = pointer[select].up;
            }
        }
        else {
            for (int i = 0; i<x; i++) {
                select = pointer[select].down;
            }
        }
    }

    static void recovery() {
        Tuple t = s.peek(); // 지웠던 노드 정보
        s.pop();

        if (t.up!=-1) pointer[t.up].down = t.value;
        if (t.down!=-1) pointer[t.down].up = t.value;
    }

    static void remove() {
        if (pointer[select].down == -1) {
            pointer[pointer[select].up].down = -1;
            s.add(new Tuple(pointer[select].up, pointer[select].down, select));
            select = pointer[select].up;
        }
        else {
            if (pointer[select].up != -1) pointer[pointer[select].up].down = pointer[select].down;
            pointer[pointer[select].down].up = pointer[select].up;
            s.add(new Tuple(pointer[select].up, pointer[select].down, select));
            select = pointer[select].down;
        }
    }

    public String solution(int n, int k, String[] cmd) {
        N = n;
        K = k;
        pointer = new Node[N];
        pointer[0] = new Node(-1, 1);
        for (int i = 1; i<N-1; i++) {
            pointer[i] = new Node(i-1, i+1);
        }
        pointer[N-1] = new Node(N-2, -1);
        select = K;

        for (String comm : cmd) {
            if (comm.charAt(0) == 'C') {
                remove();
            }
            else if (comm.charAt(0) == 'Z') {
                recovery();
            }
            else {
                move(comm.charAt(0), Integer.parseInt(comm.substring(2)));
            }
        }

        boolean[] res = new boolean[N];
        int up = select;
        while(up!=-1) {
            res[up] = true;
            up = pointer[up].up;
        }
        int down = select;
        while(down!=-1) {
            res[down] = true;
            down = pointer[down].down;
        }
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i<N; i++) {
            if (res[i]) sb.append("O");
            else sb.append("X");
        }
        return sb.toString();
    }
}
