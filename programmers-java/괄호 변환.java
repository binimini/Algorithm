class Solution {
    static boolean check(String str) {
        int left = 0, right = 0;
        for (int i = 0; i<str.length(); i++){
            if (str.charAt(i)==')'){
                if (left<=0) return false;
                else left--;
            }
            else if (str.charAt(i)=='('){
                left++;
            }
        }
        return true;
    }
    public String solution(String p) {
        if (p=="") return p;

        int left = 0, right = 0;
        for (int i = 0; i<p.length(); i++){
            if (p.charAt(i)=='(') left++;
            else if (p.charAt(i)==')') right++;
            if (left==right){
                String temp = p.substring(0, i+1);
                if (check(temp)) return temp+solution(p.substring(i+1));
                else {
                    String res = "";
                    for (int j= 1; j<temp.length()-1; j++){
                        if (temp.charAt(j)==')') res+='(';
                        else if (temp.charAt(j)=='(') res+=')';
                    }
                    return '('+solution(p.substring(i+1))+')'+res;
                }
            }
        }
        String answer = "";
        return answer;
    }
}