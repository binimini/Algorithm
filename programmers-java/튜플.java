import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

class Solution {
    static Map<Integer, Integer> m = new HashMap<>();
    public int[] solution(String s) {
        String[] temp = s.split("\\{|\\}");

        List<String> arr  = Arrays.stream(temp)
                .filter((String st) -> !(st.equals("") || st.equals(",")))
                .sorted((String s1, String s2) -> s1.length() < s2.length() ? -1 : 1)
                .collect(Collectors.toList());

        for (String str: arr) {
            for (String num : str.split(",")){
                m.putIfAbsent(Integer.parseInt(num), m.size());
            }
        }
        int[] result = m.entrySet().stream()
                .sorted((e1, e2) -> e1.getValue() < e2.getValue() ? -1 : 1)
                .collect(Collectors.toList())
                .stream()
                .mapToInt(Map.Entry::getKey)
                .toArray();
        return result;
    }
}