import java.util.ArrayList;
import java.util.List;

class Solution {
    // 목표 : left - right 100000 X ? 로 배열 찾아내기
    // (i,i) 까지 i+1
    // x = max(i,j)+1
    public int[] solution(int n, long left, long right) {
        List<Integer> answerList = new ArrayList<>();
        for (long i = left; i<=right; i++) {
            Long result = Long.max(i/n, i%n)+1;
            answerList.add(result.intValue());
        }
        int[] answer = answerList.stream().mapToInt(Integer::intValue).toArray();
        return answer;
    }
}