import java.util.HashSet;
import java.util.Set;

class Solution {
    static void select(int n, int status, int cnt) {
        if (n==cnt){
            for (int candidate : candidates){
                if ((candidate|status)==status) return;
            }

            set.clear();
            for (int i = 0; i<ROW_SIZE; i++){
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j<COL_SIZE; j++){
                    if ((status&(1<<j))==0) continue;
                    sb.append(str[i][j]);
                }
                if (set.contains(sb.toString())){
                    return;
                }
                set.add(sb.toString());
            }
            ANS++;
            candidates.add(status);
            return;
        }
        for (int i = 0; i<COL_SIZE; i++){
            if ((status&(1<<i))!=0) continue;
            select(n+1,status|(1<<i), cnt);
        }
    }

    static Set<Integer> candidates = new HashSet<>();

    static int COL_SIZE, ROW_SIZE, ANS = 0;
    static String[][] str;
    static Set<String> set = new HashSet<>();
    public int solution(String[][] relation) {
        str = relation;

        ROW_SIZE = str.length;
        COL_SIZE = str[0].length;
        for (int i = 1; i<=COL_SIZE; i++){
            select(0, 0, i);
        }

        return ANS;
    }
}
