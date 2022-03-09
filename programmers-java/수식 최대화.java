import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.StringTokenizer;

import static java.lang.Math.abs;
import static java.lang.Math.max;

class Solution {
    static String operate(String operator, String n1, String n2) {
        if (Objects.equals(operator, "*")) return Long.toString(Long.parseLong(n1)*Long.parseLong(n2));
        else if (Objects.equals(operator, "+")) return Long.toString(Long.parseLong(n1)+Long.parseLong(n2));
        else if (Objects.equals(operator, "-")) return Long.toString(Long.parseLong(n1)-Long.parseLong(n2));
        return n1+operator+n2;
    }

    static void oper(String key) {
        StringTokenizer st = new StringTokenizer(str, "*/-/+", true);

        List<String> v = new ArrayList<>();
        while (st.hasMoreTokens()) {
            String cur = st.nextToken();
            if (cur.matches("\\*|\\+|-") &&(v.size()==0 || v.get(v.size()-1).matches("\\*|\\+|-"))) {
                v.add(cur+st.nextToken());
                continue;
            }
            if (Objects.equals(cur, key)) {
                String next = st.nextToken();
                if (next.matches("\\*|\\+|-")) next = next+st.nextToken();
                v.set(v.size()-1, operate(cur, v.get(v.size()-1), next));
            }
            else v.add(cur);
        }

        StringBuffer sb = new StringBuffer();
        for (String s : v) {
            sb.append(s);
        }
        str = sb.toString();
    }

    static void order(int cnt) {
        if (cnt==3) {
            for (int i = 0; i<3; i++) {
                if (o[i]==0) oper("+");
                else if (o[i]==1) oper("-");
                else if (o[i]==2) oper("*");
            }
            RES = max(RES, abs(Long.parseLong(str)));
            str = ex;
            return;
        }
        for (int i= 0; i<3; i++){
            if (visited[i]) continue;
            o[cnt] = i;
            visited[i] = true;
            order(cnt+1);
            visited[i] = false;
        }
    }

    static String str, ex;
    static boolean[] visited = new boolean[3];
    static int[] o = new int[3];
    static long RES = 0;
    public long solution(String expression) {
        ex = expression;
        str = expression;
        order(0);
        return RES;
    }
}
