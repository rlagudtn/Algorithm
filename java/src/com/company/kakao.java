package com.company;

import java.io.IOException;
import java.util.*;

public class kakao {
    static char arr[][]=new char[100][100];
    static int N,M;
    static class Pair{
        public int y;
        public int x;
        Pair(int y,int x){
            this.y=y;
            this.x=x;
        }
    }
    static class Candidate{
        public char alpha;
        public int uy,ux,vy,vx;

        Candidate(char alpha, int uy, int ux, int vy, int vx) {
            this.alpha=alpha;
            this.uy=uy;
            this.ux=ux;
            this.vy=vy;
            this.vx=vx;
        }
    }

    static Pair findPair(int y, int x) {
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++){
                if(!(y==i &&x==j) &&arr[i][j]==arr[y][x]){
                    return new Pair(i, j);
                }
            }

        return new Pair(0, 0);
    }

    static Boolean isPossible(int cy, int cx, int ny, int nx) {
        if (cy > ny) {
            int temp=ny;
            ny=cy;cy=temp;
            temp=nx;
            nx=cx;cx=temp;
        }
        int i,j;
        boolean r1=true,r2=true;
        if(cx<nx){
            for (i = cx + 1; i < nx; i++) {
                if (arr[cy][i] != '.')
                    r1 = false;
                if (arr[ny][i] != '.')
                    r2 = false;
            }
            if(ny==cy)
                return r1;

            for (i = cy+1; i < ny; i++) {
                if(arr[i][nx]!='.')
                    r1=false;
                if(arr[i][cx]!='.')
                    r2=false;
            }
            if(nx==cx)
                return r2;
            if(arr[cy][nx]!='.')
                r1=false;
            if(arr[ny][cx]!='.')
                r2=false;
        }
        else{
            for (i = cx - 1; i > nx; i--) {
                if (arr[cy][i] != '.')
                    r1 = false;
                if (arr[ny][i] != '.')
                    r2 = false;
            }
            if(ny==cy)
                return r1;

            for (i = cy+1; i < ny; i++) {
                if(arr[i][nx]!='.')
                    r1=false;
                if(arr[i][cx]!='.')
                    r2=false;
            }
            if(nx==cx)
                return r2;
            if(arr[cy][nx]!='.')
                r1=false;
            if(arr[ny][cx]!='.')
                r2=false;
        }
        return (r1 || r2);
    }

    public static List<Candidate> findCandidates() {
        Set<String> set=new HashSet<>();
        List<Candidate> answer = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if(!Character.isAlphabetic(arr[i][j]))
                    continue;
                Pair pair = findPair(i, j);
                if(set.contains(String.valueOf(arr[i][j])))
                    continue;
                if (isPossible(i, j, pair.y, pair.x)) {
                    answer.add(new Candidate(arr[i][j], i, j, pair.y, pair.x));
                    set.add(String.valueOf(arr[i][j]));
                }
            }
        }
        return answer;
    }
    public static String solution(int n, int m, String[] board) {
        int total=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                arr[i][j]=board[i].charAt(j);
                if(Character.isAlphabetic(arr[i][j]))
                    total++;
            }
        String answer = "";
        N=n;
        M=m;
        while (true) {
            List<Candidate> candidates = findCandidates();

            if(candidates.size()==0)
                break;
            Collections.sort(candidates, new Comparator<Candidate>() {
                @Override
                public int compare(Candidate o1, Candidate o2) {
                    return o1.alpha-o2.alpha;
                }
            });
            Candidate now = candidates.get(0);
            answer = answer.concat(String.valueOf(now.alpha));
            arr[now.uy][now.ux]='.';
            arr[now.vy][now.vx]='.';
        }
        if(answer.length()!=total/2)
            answer = new String("IMPOSSIBLE");
        return answer;
    }
    public static void main(String[] args) throws IOException {
        String[] arr = {"...EI", ".....", "...*.", "....I", "....E" };
        System.out.println(solution(5,5, arr));;
    }
}

//    public static int[] solution(String msg) {
//        HashMap<String, Integer> map = new HashMap<>();
//        ArrayList<Integer> ret = new ArrayList<>();
//        for(int i=0;i<26;i++)
//            map.put(String.valueOf((char)('A'+i)),i+1);
//
//        int i=0;
//        String next,current="";
//        while (i < msg.length()) {
//            next = String.valueOf(msg.charAt(i));
//            while (i < msg.length()&& map.containsKey(next)) {
//                current = new String(next);
//                i+=1;
//                if(i<msg.length())
//                    next += msg.charAt(i);
//            }
//            ret.add(map.get(current));
//            map.put(next, map.size()+1);
//        }
//        int[] answer = new int[ret.size()];
//        for(i=0;i<answer.length;i++)
//            answer[i]=ret.get(i);
//        return answer;
//    }
//////////압축
//public static class File{
//        public String s;
//        public String head;
//        public int number;
//        public int order;
//        File(String s,int order){
//            this.s=s;
//            this.order = order;
//            parse(s);
//        }
//        void parse(String s){
//            String h = "";
//            String num="";
//            int i=0;
//            while(i<s.length()){
//                if(Character.isDigit(s.charAt(i)))
//                    break;
//                h += s.charAt(i);
//                i++;
//            }
//
//            while (i < s.length()) {
//                if(Character.isDigit(s.charAt(i)))
//                    num += s.charAt(i);
//                else
//                    break;
//                i++;
//            }
//            this.head = h.toLowerCase(Locale.ROOT);
//            this.number = Integer.parseInt(num);
//        }
//    }
//    public static String[] solution(String[] files) {
//        ArrayList<File> parsedFiles=new ArrayList<>();
//        for (int i = 0; i < files.length; i++) {
//            parsedFiles.add(new File(files[i],i));
//        }
//        Collections.sort(parsedFiles,new Comparator<File>() {
//            @Override
//            public int compare(File o1, File o2) {
//                if (o1.head.compareTo(o2.head)==0 ) {
//                    if(o1.number==o2.number)
//                        return o1.order - o2.order;
//                    return o1.number-o2.number;
//                }
//                return o1.head.compareTo(o2.head);
//            }
//        });
//        String[] answer = new String[files.length];
//        for (int i = 0; i < files.length; i++) {
//            answer[i] = parsedFiles.get(i).s;
//        }
//        return answer;
//    }


/////////n진수
//public static String convert(int num,int digit){
//    String ret = "";
//    char[] arr={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
//    while (num != 0) {
//        ret = arr[num%digit] + ret;
//        num /= digit;
//    }
//    return ret;
//}
//    public static String solution(int n, int t, int m, int p) {
//        String answer = "";
//        String s = "0";
//        int i=1;
//        while (s.length()<=t*m) {
//            s += convert(i, n);
//            i++;
//        }
//        for (i = 0; i < t; i++) {
//            answer += s.charAt(m*i+(p-1));
//        }
//        return answer;
//    }
//////////////////주차 요금 계산
//public static int timeToInt(String time) {
//    String[] st = time.split(":");
//    int hour = Integer.parseInt(st[0]);
//    int minute= Integer.parseInt(st[1]);
//
//    return hour*60+minute;
//}
//
//    public static int calculateFee(int[] fee, int usageTime) {
//        if(usageTime<=fee[0])
//            return fee[1];
//        return (int)(fee[1] + (Math.ceil((double)(usageTime - fee[0]) / fee[2])) * fee[3]);
//    }
//    public static int[] solution(int[] fees, String[] records) {
//        HashMap<String, Integer> total = new HashMap<>();
//        HashMap<String, Integer> entrance = new HashMap<>();
//        int last = timeToInt("23:59");
//        List<String> cars = new ArrayList<>();
//        for (String record : records) {
//            String[] st = record.split(" ");
//            Integer time =timeToInt(st[0]) ;
//            String car = st[1];
//            String inout = st[2];
//            if(!cars.contains(car)) {
//                cars.add(car);
//                total.put(car, 0);
//            }
//            if (inout.compareTo("IN")==0) {
//                entrance.put(car, time);
//            }
//            else if (inout.compareTo("OUT") == 0) {
//                int gap = time-entrance.get(car);
//                entrance.remove(car);
//                total.put(car, total.get(car) + gap);
//            }
//        }
//        // 차번 순으로 정렬
//        Collections.sort(cars);
//
//        //////key 값들로 for문 도는데 key를 안에서 제거하여 컴파일 에러 발생
//        for (String temp : entrance.keySet()) {
//            int gap = last - entrance.get(temp);
//            total.put(temp, total.get(temp) + gap);
//        }
//        int[] answer = new int[cars.size()];
//
//        for (int i=0;i<cars.size();i++) {
//            answer[i]=calculateFee(fees, total.get(cars.get(i)));
//        }
//        return answer;
//    }
///////////////N개의 최소공배수
//public static int lcm(int a, int b) {
//    int gcd;
//    int divided = Math.max(a, b);
//    int divider = Math.min(a, b);
//    while (true) {
//        if (divided % divider == 0) {
//            gcd = divider;
//            break;
//        }
//        int nDivider = divided % divider;
//        divided = divider;
//        divider=nDivider;
//    }
//    return a * (b / gcd);
//}
//    public static int solution(int[] arr) {
//        int answer = lcm(arr[0], arr[1]);
//        for(int i=2;i<arr.length;i++){
//            answer=lcm(answer,arr[i]);
//        }
//        return answer;
//    }
////////////양궁대회
//static int gapMax=0;
//    static int N;
//    static ArrayList<Integer> answer = new ArrayList<>();
//    static ArrayList<Integer> picked = new ArrayList<>();
//    static void getScore(int[] info){
//        int a=0,l=0;
//        for(int i=0;i<11;i++){
//            if(info[i]==0 &&picked.get(i)==0)
//                continue;
//            else if(info[i]>=picked.get(i))
//                a+=10-i;
//            else
//                l+=10-i;
//        }
//        if (l - a > gapMax) {
//            gapMax = l - a;
//            answer = (ArrayList<Integer>) picked.clone();
//        }
//        else if (gapMax != 0 && l - a == gapMax) {
//            for(int i=10;i>=0;i--){
//                if(picked.get(i)==answer.get(i))
//                    continue;
//                else if (picked.get(i) > answer.get(i)) {
//                    answer = (ArrayList<Integer>) picked.clone();
//                }
//                break;
//            }
//        }
//    }
//
//    static void dfs(int[] info,int remain) {
//        if (picked.size()== 11 ) {
//            if(remain==0)
//                getScore(info);
//            return;
//        }
//
//        for (int i = 0; i <= remain; i++) {
//            picked.add(i);
//            dfs(info, remain - i);
//            picked.remove(picked.size() - 1);
//        }
//
//    }
//    public static int[] solution(int n, int[] info) {
//        N=n;
//        answer.add(-1);
//        dfs(info,N);
//        int[] ret = new int[answer.size()];
//        for(int i=0;i<answer.size();i++)
//            ret[i]=answer.get(i);
//        return ret;
//    }