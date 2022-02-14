import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Pair {
    int x;
    int y;
    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
class Solution {
    public int solution(String word, String[] pages) {
        word = word.toLowerCase();
        Pattern pattern = Pattern.compile("<meta.*\"https://(\\S*)\"/>");
        Pattern patternLink = Pattern.compile("<a href=\"https://(\\S*)\">");
        Map<String, Pair> info = new HashMap<>();
        Map<String, ArrayList<String>> links = new HashMap<>();
        String[] tokens;
        String[] arr = new String[pages.length];
        for (int i =0; i<pages.length; i++){
            int linkCnt = 0;
            Matcher m = patternLink.matcher(pages[i]);
            Matcher u = pattern.matcher(pages[i]);
            String url = "";
            if (u.find()){
                url = u.group(1);
            }
            System.out.println("url "+url);
            while(m.find()){
                linkCnt++;
                links.putIfAbsent(m.group(1), new ArrayList<>());
                links.get(m.group(1)).add(url);
                System.out.println("link "+m.group());
            }

            int basic = 0;
            tokens = pages[i].split("[^a-zA-Z]");
            for (int j = 0; j<tokens.length; j++){
                if (tokens[j]=="") continue;
                tokens[j] = tokens[j].toLowerCase();
                if (tokens[j].equals(word)){
                    basic++;
                }
            }
            info.put(url, new Pair(basic, linkCnt));
            arr[i] = url;
        }

        double maxi = -1;
        int idx = 0;
        for (int i = 0; i< pages.length; i++){
            int match = info.get(arr[i]).x;
            double link = 0;
            if (links.containsKey(arr[i])) {
                List<String> linkToMe = links.get(arr[i]);
                for (int j = 0; j < linkToMe.size(); j++){
                    if (!info.containsKey(linkToMe.get(j))) continue;
                    if (info.get(linkToMe.get(j)).x==0) continue;
                    link+=(info.get(linkToMe.get(j)).x/(double)info.get(linkToMe.get(j)).y);
                }

            }
            if (link+match>maxi){
                maxi = link+match;
                idx = i;
            }
        }
        return idx;
    }
}