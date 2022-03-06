package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class bs {
    static int n,m;
    static int[] arr=new int[100000];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        int start,end,mid,cnt,answer;
        start= Arrays.stream(arr).max().getAsInt();
        answer=end=(int)1e9;
        while(start<=end) {
            mid=(start+end)/2;
            cnt=0;
            int moneyOnMe;
            int i=0;
            while(i<n){
                moneyOnMe=mid;
                cnt++;
                while(i<n && arr[i]<=moneyOnMe){
                    moneyOnMe-=arr[i];
                    i++;
                }

            }

            if(cnt>m){
                start=mid+1;
            }
            else if (cnt <= m) {
                end=mid-1;
                answer=mid;
            }
        }
        System.out.println(answer);

        br.close();
    }
}
