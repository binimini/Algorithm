import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {

    static String[] user, ban;
    static int[] use;
    static boolean[] visited;
    static Set<String> s = new HashSet<>();

    static boolean match(int uidx, int bidx) {
        if (user[uidx].length() != ban[bidx].length()) return false;
        for (int i = 0; i<user[uidx].length(); i++) {
            if (ban[bidx].charAt(i)!='*' && user[uidx].charAt(i)!=ban[bidx].charAt(i)) return false;
        }
        return true;
    }

    static void dfs(int m) {
        if (m==ban.length) {
            Arrays.sort(use);
            StringBuffer sb = new StringBuffer();
            for (int i = 0; i<visited.length; i++){
                if (visited[i]) sb.append(i);
            }
            s.add(sb.toString());
            return;
        }
        for (int i = 0; i<user.length; i++) {
            if (visited[i]) continue;
            if (!match(i, m)) continue;
            visited[i] = true;
            dfs(m+1);
            visited[i] = false;
        }
    }

    public int solution(String[] user_id, String[] banned_id) {
        user = user_id;
        ban = banned_id;
        use = new int[ban.length];
        visited = new boolean[user.length];

        dfs(0);
        return s.size();
    }
}