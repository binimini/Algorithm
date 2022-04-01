class Solution {
    static String transform(int x) {
        StringBuilder sb = new StringBuilder();
        while(x>0) {
            sb.append(x%K);
            x/=K;
        }
        return sb.reverse().toString();
    }

    static boolean isPrime(long x) {
        if (x==1) return false;

        for (long i = 2; i<=Math.sqrt(x); i++) {
            if (x%i==0) return false;
        }
        return true;
    }

    static int N,K;
    public int solution(int n, int k) {
        N = n;
        K = k;

        String transformed = transform(N);
        String[] nums = transformed.split("0");

        int ans = 0;
        for (String num : nums) {
            if (num.equals("")) continue;
            if (isPrime(Long.parseLong(num))) ans++;
        }
        return ans;
    }
}