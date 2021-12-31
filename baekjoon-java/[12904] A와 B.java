import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Math.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        String str = st.nextToken();
        int S = str.length();

        st = new StringTokenizer(br.readLine());
        String strTo = st.nextToken();
        int T = strTo.length();

        int front = 0, back = T-1;
        boolean cur = true;
        while(abs(back-front)+1>S){
            if (cur) back--;
            else front++;

            if ((cur && strTo.charAt(back+1)=='B' )|| (!cur && strTo.charAt(front-1)=='B')){
                cur = !cur;
            }
        }

        String noDirectStr = strTo.substring(min(front, back), max(front,back)+1);
        StringBuffer sb = new StringBuffer(noDirectStr);
        String ans = cur ? noDirectStr : sb.reverse().toString();
        if (ans.equals(str)) System.out.println(1);
        else System.out.println(0);
    }
}
