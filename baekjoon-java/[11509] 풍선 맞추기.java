import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    static Map<Integer, Integer> m = new HashMap<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int ANS = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i<N; i++){
            int temp = Integer.parseInt(st.nextToken());
            if (m.containsKey(temp)){
                getKey(temp);
                putKey(temp-1);
            }
            else {
                ANS++;
                putKey(temp-1);
            }
        }
        System.out.print(ANS);
    }
    static void putKey(int key) {
        if (m.containsKey(key)){
            m.put(key, m.get(key)+1);
        }
        else {
            m.put(key, 1);
        }
    }

    static void getKey(int key){
        if (m.get(key)!=1){
            m.put(key, m.get(key)-1);
        }
        else {
            m.remove(key);
        }
    }
}
