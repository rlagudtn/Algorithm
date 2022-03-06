package com.company;


import com.sun.source.tree.LiteralTree;

import java.io.IOException;
import java.lang.reflect.Array;
import java.util.*;

public class Programmers {
    static int[][] dist;
    static int N;
    public static void floyd(){
        for(int i=1;i<=N;i++)
            dist[i][i]=0;
        for(int k=1;k<=N;k++)
            for(int i=1;i<=N;i++)
                for(int j=1;j<=N;j++)
                    dist[i][j]=Math.min(dist[i][j],dist[i][k]+dist[k][j]);

    }
    public static int solution(int n, int s, int a, int b, int[][] fares) {
        final int INF=(int)1e9;
        N=n;
        dist=new int[n+1][n+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(dist[i],INF);
        }
        for(int i=0;i<fares.length;i++){
            int u=fares[i][0],v=fares[i][1],cost=fares[i][2];
            dist[u][v]=cost;
            dist[v][u]=cost;
        }
        floyd();

        int answer=dist[s][a]+dist[s][b];
        for(int i=1;i<=n;i++){
            int common=dist[s][i];
            if(common>=INF||dist[i][a]>=INF||dist[i][b]>=INF)
                continue;
            answer=Math.min(answer,common+dist[i][a]+dist[i][b]);
        }
//        for(int i=1;i<=n;i++){
//            for(int j=1;j<=n;j++){
//                System.out.print(dist[i][j]);
//                System.out.print(" ");
//            }
//            System.out.println();
//        }

        return answer;
    }
    public static void main(String[] args) throws IOException {
//        String[] cmd={"D 2","C","U 3","U 1","D 7"};
        int[][] fares= {{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}};

        System.out.println(solution(7,3,4,1,fares));


    }

}
///////합승 택시 요금
//static int last;
//    static int size;
//    static int answer;
//    static int[] gps;
//    static ArrayList<Integer> adj[];
//    static void dfs(int idx,ArrayList<Integer> picked){
//        if(picked.size()==size ){
//            if(picked.get(size-1)==last){
//                int cnt=0;
//                for(int i=0;i<size;i++){
//                    if(picked.get(i)!=gps[i])
//                        cnt++;
//                }
//                answer=Math.min(answer,cnt);
//
//            }
//            return;
//        }
//        for(int i=0;i<adj[idx].size();i++){
//            int next=adj[idx].get(i);
//            picked.add(next);
//            dfs(next,picked );
//            picked.remove(picked.size()-1);
//        }
//    }
//    public static int solution(int n, int m, int[][] edge_list, int k, int[] gps_log) {
//        ArrayList<Integer> picked=new ArrayList<>();
//        picked.add(gps_log[0]);
//        last=gps_log[k-1];
//        size=k;
//        answer=k;
//        adj=new ArrayList[n+1];
//        gps=new int[k];
//        for(int i=0;i<k;i++)
//            gps[i]=gps_log[i];
//        for(int i=1;i<=n;i++)
//            adj[i]=new ArrayList<>();
//        for(int i=1;i<=n;i++)
//            adj[i].add(i);
//        for(int i=0;i<m;i++){
//            int u=edge_list[i][0];
//            int v=edge_list[i][1];
//            adj[u].add(v);
//            adj[v].add(u);
//        }
//
//        dfs(gps_log[0],picked);
//
//        return answer;
//    }


//표 편집
//static class  Node{
//        public Node previous;
//        public int num;
//        public Node next;
//        public Node(int num){
//            this.previous=null;
//            this.num=num;
//            this.next=null;
//        }
//        public Node(Node previous,int num){
//            this.previous=previous;
//            this.num=num;
//            this.next=null;
//        }
//        public Node(int num,Node next){
//            this.previous=null;
//            this.num=num;
//            this.next=next;
//        }
//        public Node(Node previous,int num,Node next){
//            this.previous=previous;
//            this.num=num;
//            this.next=next;
//        }
//    }
//    static Node current;
//    static Node head;
//    static Stack<Node> st=new Stack<>();
//    public static void moveUp(int dist){
//        for(int i=0;i<dist;i++){
//            current=current.previous;
//        }
//    }
//    public static void moveDown(int dist){
//        for(int i=0;i<dist;i++){
//            current=current.next;
//        }
//    }
//    public static void remove(){
//        if(current.previous!=null)
//            current.previous.next=current.next;
//        else{
//            head=current.next;
//        }
//        st.add(current);
//
//        //current 갱신
//        if(current.next!=null){
//            current.next.previous=current.previous;
//            current=current.next;
//        }
//        else
//            current=current.previous;
//
//    }
//    public static void restore(){
//        Node node=st.pop();
//        if(node.previous!=null)
//            node.previous.next=node;
//        else{
//            head=node;
//        }
//        if(node.next!=null)
//            node.next.previous=node;
//    }
//
//
//    public static String solution(int n, int k, String[] cmd) {
//        head=new Node(0);
//        current=head;
//        for(int i=1;i<n;i++){
//            current.next=new Node(current,i);
//            current=current.next;
//        }
//        current=head;
//
//        for(int i=0;i<k;i++){
//            current=current.next;
//        }
//
//        StringTokenizer st;
//        for(String s:cmd){
//            st=new StringTokenizer(s," ");
//            switch (st.nextToken()){
//                case "U":
//                    moveUp(Integer.parseInt(st.nextToken()));
//                    break;
//                case "D":
//                    moveDown(Integer.parseInt(st.nextToken()));
//                    break;
//                case "C":
//                    remove();
//                    break;
//                case "Z":
//                    restore();
//                    break;
//                default:
//                    break;
//            }
//        }
//
//        StringBuilder sb=new StringBuilder("X".repeat(n));
//        current=head;
//        while(current!=null){
//            sb.setCharAt(current.num,'O');
//            current=current.next;
//        }
//        return sb.toString();
//}
/////////////셔틀 버스
//public static String solution(int n, int t, int m, String[] timetable) {
//    LinkedList<Integer> list=new LinkedList<>();
//    ListIterator<Integer> iterator=list.listIterator();
//    PriorityQueue<Integer> pq = new PriorityQueue<>();
//    StringTokenizer st;
//    for(String time:timetable){
//        st=new StringTokenizer(time,":");
//        int hour=Integer.valueOf(st.nextToken());
//        int minute=Integer.valueOf(st.nextToken());
//        pq.add(hour*60+minute);
//    }
//    int bus=540;
//    int cnt=0,last=bus;
//    for(int i=0;i<n;i++){
//        if(pq.isEmpty())
//            break;
//        cnt=0;
//        while(!pq.isEmpty()&&cnt<m){
//            int current=pq.peek();
//            if(current>bus)
//                break;
//            last=current;
//            pq.poll();
//            cnt++;
//        }
//        bus+=t;
//    }
//
//    if(cnt>=m){
//        last=last-1;
//    }
//    else{
//        last=bus-t;
//    }
//    String h="0"+String.valueOf(last/60);
//    h=h.substring(h.length()-2);
//    String mi="0"+String.valueOf(last%60);
//    mi=mi.substring(mi.length()-2);
//    String answer = h+":"+mi;
//    return answer;
//}

////순위
//static int[][] adj=new int[101][101];
//
//    public static int solution(int n, int[][] results) {
//        for(int i=0;i<results.length;i++)
//            adj[results[i][0]][results[i][1]]=1;
//
//        for(int k=1;k<=n;k++)
//            for(int i=1;i<=n;i++)
//                for(int j=1;j<=n;j++)
//                    if(adj[i][k]==1&&adj[k][j]==1)
//                        adj[i][j]=1;
//
//        int answer = 0;
//        for(int i=1;i<=n;i++){
//            int cnt=0;
//            for(int j=1;j<=n;j++)
//                if(adj[i][j]==1 || adj[j][i]==1)
//                    cnt++;
//            if(cnt==n-1)
//                answer++;
//        }
//        return answer;
//    }
//
//////////다단계 칫솔 판매
//static Map<String,Integer> resultMap=new HashMap<>();
//    static Map<String, String> ref = new HashMap<>();
//    static void  dfs(String name,int fee){
//        int currentTotalFee=resultMap.getOrDefault(name, 0);
//        if(name.equals("-")||fee<10){
//            resultMap.put(name, currentTotalFee + fee);
//            return;
//        }
//        String parent=ref.get(name);
//        int nextFee=fee/10;
//        resultMap.put(name,currentTotalFee+(fee-nextFee));
//        dfs(parent,nextFee);
//    }
//    public static int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
//        for(int i=0;i<referral.length;i++){
//            ref.put(enroll[i],referral[i]);
//        }
//        for(int i=0;i<amount.length;i++){
//            dfs(seller[i],amount[i]*100);
//        }
//        int[] answer = new int[enroll.length];
//
//        for(int i=0;i<enroll.length;i++){
//            answer[i]=resultMap.getOrDefault(enroll[i],0 );
//        }
//        return answer;
//    }
//////////////////무지의 먹방 라이브

//    public static int solution(int[] arr) {
//        int n=arr.length;
//        Arrays.sort(arr);
//        int min=0;
//        int max=256;
//        int mid= max;
//        int minValue=max;
//        if (arr[0] == arr[arr.length - 1]) {
//            return 0;
//        }
//        for(int i=max;i>=min;i--){
//            int cnt=0;
//            for(int j=0;j<n;j++){
//                if(arr[j]>=i)
//                    cnt++;
//            }
//            int gap=Math.abs(n-2*cnt);
//            if(gap<=minValue){
//                mid=i;
//                minValue=gap;
//            }
//        }
//        return mid;
//    }
//    public static String getCmd(String string) {
//        StringTokenizer st = new StringTokenizer(string, " ");
//        int n=st.countTokens();
//        for(int i=0;i<n-1;i++)
//            st.nextToken();
//        return st.nextToken();
//    }
//    public static  String getName(String string){
//        StringBuilder sb=new StringBuilder();
//        StringTokenizer st = new StringTokenizer(string, " ");
//        int n=st.countTokens();
//        for(int i=0;i<n-1;i++){
//            sb.append(st.nextToken()).append(" ");
//        }
//        String ret=sb.toString().trim();
//        return ret;
//    }
//    public static String stringFactory(String string) {
//        StringTokenizer st = new StringTokenizer(string);
//        StringBuilder sb=new StringBuilder();
//        String shared = "shared your post";
//        String comment = "commented on your post";
//
//        String name=getName(string);
//        String command=getCmd(string);
//        sb.append(name).append(" ");
//        if(command.equals("share"))
//            sb.append(shared);
//        else if(command.equals("comment"))
//            sb.append(comment);
//
//        return sb.toString();
//    }
//    public static String modifyString(String previous, String now) {
//        StringTokenizer st = new StringTokenizer(previous);
//        StringTokenizer nst=new StringTokenizer(now);
//        StringBuilder sb=new StringBuilder();
//        String name=st.nextToken();
//
//        sb.append(name).append(" ");
//        String command=getCmd(previous);
//        if (st.countTokens() == 1) {
//            sb.append("and ").append(getName(now))
//                    .append(" ");
//        }
//        else if(st.countTokens()==3){
//            sb.append("and 2 others ");
//        }
//        else if(st.countTokens()==4){
//            st.nextToken();
//            int cnt = Integer.parseInt(st.nextToken());
//            cnt++;
//            String temp=String.valueOf(cnt);
//            st.nextToken();
//            sb.append("and ").append(temp)
//                    .append(" others ");
//        }
//        sb.append(command);
//        return sb.toString();
//    }
//    public static String[] solution(String[] records) {
//        ArrayList<String> ret = new ArrayList<>();
//        Stack<String> st = new Stack<>();
//        StringTokenizer stz;
//        for (int i = 0; i < records.length; i++) {
//            if(st.empty()){
//                st.push(records[i]);
//                continue;
//            }
//            String top = st.peek();
//            if(records[i].equals("check notification")){
//                ret.add(stringFactory(top));
//                st.pop();
//                continue;
//            }
//            String tCommand = getCmd(top);
//            String currentCommand = getCmd(records[i]);
//            if(tCommand.equals(currentCommand)){
//                String command=modifyString(top,records[i]);
//                st.pop();
//                st.add(command);
//            }
//            else
//                st.push(records[i]);
//        }
//
//        String[] answer = new String[ret.size()];
//        for(int i=0;i<answer.length;i++)
//            answer[i]=ret.get(i);
//        return answer;
//    }
//    public static void main(String[] args) {
//        String[] records = {"john share", "mary comment", "jay share", "check notification", "check notification",
//                "sally comment", "james share", "check notification", "lee share", "laura share", "will share", "check notification", "alice comment", "check notification"};
//        String[] answer=solution(records);
//        for(int i=0;i<answer.length;i++)
//            System.out.println(answer[i]);
//    }
