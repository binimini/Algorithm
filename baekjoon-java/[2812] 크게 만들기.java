import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        String input = st.nextToken();

        Stack<Integer> s = new Stack<>();
        for (int i = 0; i<N; i++){
            int temp = input.charAt(i)-'0';
            if (s.empty()){
                s.push(temp);
            }
            else if (s.peek()<temp){
                while(!s.empty()&& s.peek()<temp && s.size()+N-1-i>=N-K){
                    s.pop();
                }
                s.push(temp);
            }
            else if (s.size()<N-K){
                s.push(temp);
            }
        }

        int[] ans = new int[N-K];
        int idx= N-K-1;
        while (!s.empty()){
            ans[idx--] = s.peek();
            s.pop();
        }
        for (int i = 0; i<N-K; i++){
            bw.write(Integer.toString(ans[i]));
        }
        bw.flush();
        bw.close();
    }
}
