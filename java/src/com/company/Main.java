package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int t,v, e;
    static int[] colors = new int[200001];
    static int[] visit = new int[200001];
    static boolean bfs(List<List<Integer>> adj,int src){
        Queue<Integer> q = new LinkedList<>();
        q.add(src);
        colors[src]=1;
        visit[src]=1;
        while (q.size() > 0) {
            int now = q.poll();
            int color = colors[now];
            for (int i = 0; i < adj.get(now).size(); i++) {
                int next = adj.get(now).get(i);
                if (colors[next] ==color) {
                    return false;
                }
                colors[next]=(color==0? 1:0);
                if (visit[next] == 0) {
                    q.add(next);
                    visit[next] = 1;
                }
            }
        }
        return true;
    }
    static boolean isBipartite(List<List<Integer>> adj){
        Arrays.fill(colors, -1);
        Arrays.fill(visit,0);
        for(int i=1;i<=v;i++){
            if (visit[i] == 0 &&bfs(adj,i)==false) {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.parseInt(br.readLine());
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<t;i++){
            st = new StringTokenizer(br.readLine(), " ");
            v = Integer.parseInt(st.nextToken());
            e = Integer.parseInt(st.nextToken());
            List<List<Integer>> adj = new ArrayList<>();
            for(int k=0;k<=v;k++)
                adj.add(new ArrayList<>());
            for(int j=0;j<e;j++){
                int a,b;
                st = new StringTokenizer(br.readLine(), " ");
                a = Integer.parseInt(st.nextToken());
                b = Integer.parseInt(st.nextToken());
                adj.get(a).add(b);
                adj.get(b).add(a);
            }
            if(isBipartite(adj))
                sb.append("YES").append("\n");
            else
                sb.append("NO").append("\n");

        }
        br.close();
        System.out.println(sb);
    }
}
