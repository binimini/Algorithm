import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import static java.lang.Math.abs;

class Pair {
    int x;
    int y;
    public Pair (int x, int y) {
        this.x = x;
        this.y = y;
    }
}
class Solution {
    static boolean[][] visited;
    static String[][] arr;
    static int[][] d = {{1,0},{0,1},{-1,0},{0,-1}};
    static boolean check(int r, int c, int p) {
        Queue<Pair> q = new LinkedList<>();
        visited = new boolean[5][5];
        q.add(new Pair(r, c));
        visited[r][c] = true;
        while(!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            q.poll();

            for (int i = 0; i<4; i++){
                int nx= x+d[i][0];
                int ny= y+d[i][1];
                if (nx<0||nx>4 || ny<0|| ny>4) continue;
                if (abs(r-nx)+abs(c-ny)> 2) continue;
                if (visited[nx][ny]) continue;
                if (arr[p][nx].charAt(ny) == 'P') return false;
                if (arr[p][nx].charAt(ny) == 'X') continue;
                visited[nx][ny] = true;
                q.add(new Pair(nx, ny));
            }
        }
        return true;
    }

    public int[] solution(String[][] places) {
        arr = places;
        List<Integer> res = new ArrayList<>();
        for (int p = 0; p<places.length; p++){
            boolean flag = false;
            for (int i=0; i<places[p].length; i++){
                if (flag) break;
                for (int j =0 ; j<places[p][i].length(); j++){
                    if (places[p][i].charAt(j)=='P' && !check(i, j, p)){
                        flag = true;
                        res.add(0);
                        break;
                    }
                }
            }
            if (!flag) res.add(1);
        }

        return res.stream().mapToInt(i->i).toArray();
    }
}