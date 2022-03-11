import java.util.HashMap;

class Solution {

    static HashMap<String, Integer> kind = new HashMap<>();
    static int N, K, RES = 987654321, IDX;
    public int[] solution(String[] gems) {
        for (String gem : gems) {
            kind.putIfAbsent(gem, 1);
        }
        N = gems.length;
        K = kind.size();
        kind.clear();

        int s = 0, e = 0;
        while(s<N) {
            if (kind.size() == K && RES > (e-s+1) ) {
                RES = e-s+1;
                IDX = s;
            }
            if (kind.size() == K || e == N) {
                if (kind.containsKey(gems[s])) {
                    if (kind.get(gems[s])==1) kind.remove(gems[s]);
                    else kind.put(gems[s], kind.get(gems[s])-1);
                }
                s++;
            }
            else if (kind.size() < K ) {
                if (kind.containsKey(gems[e])) kind.put(gems[e], kind.get(gems[e])+1);
                else kind.put(gems[e], 1);
                e++;
            }
        }

        int[] result = {IDX+1, RES+IDX-1};
        return result;
    }
}