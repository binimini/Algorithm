import static java.lang.Math.min;

class Solution {
    public int solution(String s) {
        int answer = s.length();

        for (int i = 1; i<=s.length(); i++){
            int cnt = 0;
            StringBuffer result = new StringBuffer();
            String before = "";
            for (int j = 0; j<s.length(); j+=i){
                if (j+i-1>=s.length()){
                    result.append(s.substring(j));
                    break;
                }
                String cur = s.substring(j, j+i);
                if (before.equals(cur)) {
                    cnt++;
                    if (cnt==2){
                        result.insert(result.toString().length()-1-i+1, Integer.toString(cnt));
                    }
                    else {
                        result.replace(result.toString().length()-i - Integer.toString(cnt-1).length(), result.toString().length() -i, Integer.toString(cnt));
                    }

                }
                else {
                    cnt = 1;
                    result.append(cur);
                    before = cur;
                }
            }

            answer = min(answer, result.length());
        }

        return answer;
    }
}