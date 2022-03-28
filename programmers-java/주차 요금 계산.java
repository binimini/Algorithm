import com.sun.source.tree.Tree;

import java.util.*;

class Car {
    int in;
    int sum;
    public Car(String inTime) {
        in = Solution.timeToMinute(inTime);
        sum = 0;
    }
}

class Solution {
    static int timeToMinute(String time) {
        int hour = Integer.parseInt(time.substring(0, 2));
        int min = Integer.parseInt(time.substring(3,5));
        return hour*60+min;
    }

    static int getCost(int time) {
        int overDefault = (time - fee[0])>0 ? (int)Math.ceil((time - fee[0]) / (double)fee[2]) : 0;
        return fee[1] + overDefault * fee[3];
    }

    static int MAX_TIME = timeToMinute("23:59");
    static int[] fee;
    static Map<String, Car> m = new TreeMap<>();
    public int[] solution(int[] fees, String[] records) {
        fee = fees;

        for (String record : records) {
            String[] arr = record.split(" ");
            if (arr[2].equals("IN")) {
                if (m.containsKey(arr[1])) m.get(arr[1]).in = timeToMinute(arr[0]);
                else m.put(arr[1], new Car(arr[0]));
            }
            else {
                m.get(arr[1]).sum += timeToMinute(arr[0]) - m.get(arr[1]).in;
                m.get(arr[1]).in = -1;
            }
        }

        List<Integer> res = new ArrayList<>();
        for (Map.Entry<String, Car> e : m.entrySet()) {
            if (e.getValue().in==-1) res.add(getCost(e.getValue().sum));
            else res.add(getCost(MAX_TIME-e.getValue().in+e.getValue().sum));
        }
        return res.stream().mapToInt(i->i).toArray();
    }
}

class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] fees = {180, 5000, 10, 600};
        String[] records = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};
        s.solution(fees, records);
    }
}