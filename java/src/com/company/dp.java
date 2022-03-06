package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class dp {
    final static int MAX=1001;
    static  int[] cache=new int[MAX];
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        cache[1]=1;
        cache[2]=2;
        for(int i=3;i<=n;i++)
            cache[i]=cache[i-1]+cache[i-2];
        System.out.println(cache[n]);
        br.close();
    }
}
