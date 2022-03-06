package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class dc {
    static int answer=-1,n,r,c;
    public static void dfs(int t,int l,int size){
        if(size==1){
            answer+=1;
            if (t == r && l == c) {
                System.out.println(answer);
            }
            return;
        }
        int nSize=size/2;
        dfs(t, l, nSize);
        dfs(t, l + nSize, nSize);
        dfs(t + nSize, l, nSize);
        dfs(t + nSize, l + nSize, nSize);

    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");

        n=Integer.parseInt(st.nextToken());
        r=Integer.parseInt(st.nextToken());
        c=Integer.parseInt(st.nextToken());

        n=(int)Math.pow(2,n);
        dfs(0,0,n);
        br.close();
    }
}
