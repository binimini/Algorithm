

class Solution {
    static int LOCK_SIZE, KEY_SIZE;
    static int[][] locks, keys, rkey, clock;
    static boolean check_lock() {
        for (int i = 0; i<LOCK_SIZE; i++){
            for (int j = 0; j<LOCK_SIZE; j++){
                if (clock[i][j]!=1) return false;
            }
        }
        return true;
    }

    static void combine(int sx, int sy) {
        clock = new int[LOCK_SIZE][LOCK_SIZE];
        for (int i = 0; i<LOCK_SIZE; i++){
            for (int j = 0; j<LOCK_SIZE; j++){
                clock[i][j] = locks[i][j];
            }
        }
        for (int i = 0; i<LOCK_SIZE; i++){
            for (int j = 0; j<LOCK_SIZE; j++){
                if (sx+i>LOCK_SIZE-1 || sx+i<0 || sy+j>LOCK_SIZE-1 || sy+j<0) continue;
                if (i>KEY_SIZE-1 || j>KEY_SIZE-1) continue;
                clock[sx+i][sy+j] += rkey[i][j];
            }
        }
    }

    static void rotate(int[][] before) {
        int row = before.length;
        int col = before[0].length;
        rkey = new int[col][row];
        for (int i = col-1; i>=0; i--){
            for (int j = 0; j<row; j++){
                rkey[col-1-i][j] = before[j][i];
            }
        }
    }

    public boolean solution(int[][] key, int[][] lock) {
        LOCK_SIZE = lock.length;
        KEY_SIZE = key.length;
        locks = lock;
        keys = key;

        for (int i= 0; i<4; i++){
            rotate(keys);
            keys = rkey;
            for (int x = 0; x<2*LOCK_SIZE; x++){
                for (int y = 0; y<2*LOCK_SIZE; y++){
                    combine(x-LOCK_SIZE, y-LOCK_SIZE);
                    if (check_lock()) return true;
                }
            }
        }
        return false;
    }
}