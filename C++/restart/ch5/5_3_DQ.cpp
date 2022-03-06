#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
using namespace std;
struct Point
{
    int x;
    int y;
    bool operator<(const Point &b) const
    {
        if (x == b.x)
            return y < b.y;
        else
            return x < b.x;
    }
};
int Distance(Point a, Point b) { return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y); }
bool CompareY(Point a, Point b) { return a.y < b.y; }
// int SearchAll(vector<Point> &v, int s, int e)
// {
//     int minDist = -1;
//     for (int i = s; i <= e - 1; i++)
//     {
//         for (int j = i + 1; j <= e; j++)
//         {
//             int dist = Distance(v[i], v[j]);
//             if (minDist == -1 || minDist > dist)
//                 minDist = dist;
//         }
//     }
//     return minDist;
// }
int SearchPoint(vector<Point> &v, int start, int end)
{
    int count = end - start + 1;
    if (count == 1)
        return 1e9;
    else if(count==2)
        return Distance(v[start],v[end]);
    int mid = (start + end) / 2;
    int left = SearchPoint(v, start, mid);
    int right = SearchPoint(v, mid + 1, end);
    int answer;
    if (left > right)
        answer = right;
    else
        answer = left; // 중앙 근처 값을 계산할 예정 
    vector<Point> final;
    for (int i = start; i <= end; i++)
    {
        int xDistance = v[i].x - v[mid].x;
        if (xDistance * xDistance < answer)
            final.push_back(v[i]);
    } // y 기준 정렬
    int maxIndex = final.size();
    sort(final.begin(), final.end(), CompareY);
    for (int i = 0; i < maxIndex - 1; i++)
    {
        for (int j = i + 1; j < maxIndex; j++)
        {
            int y = final[j].y - final[i].y;
            if (y * y < answer)
            {
                int dist = Distance(final[j], final[i]);
                if (dist < answer)
                    answer = dist;
            }
            else
                break;
        }
    }
    return answer;
}
int main()
{
    int n;
    char temp;
    // 쉼표 제거용
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++)
        cin >> points[i].x >> points[i].y;
    sort(points.begin(), points.end());
    int answer = SearchPoint(points, 0, n - 1);
    cout << answer << '\n';
}

// // /////////////2261
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <math.h>
// using namespace std;

// int n;
// pair<int,int> arr[100000];
// const int INF=int(1e9);
// int dist(pair<int,int> a,pair<int,int> b){
//     int x=a.first-b.first;
//     int y=a.second-b.second;
//     return x*x+y*y;
// }
// bool compareY(pair<int,int> a,pair<int,int> b){
//     return a.second<b.second;
// }
// int dq(int start,int end,int cnt){
//     if(cnt==1)
//         return INF;
//     else if(cnt==2)
//         return dist(arr[start],arr[end]);

//     int mid=(start+end)/2;
//     int answer=dq(start,mid,mid-start+1);
//     answer=min(answer,dq(mid+1,end,end-mid));

//     vector<pair<int,int>> candidate;
//     for(int i=start;i<=end;i++){
//         int x=arr[mid].first-arr[i].first;
//         if(x*x<answer)
//             candidate.push_back(arr[i]);
//     }
    
//     sort(candidate.begin(),candidate.end(),compareY);

//     for(int i=0;i<candidate.size()-1;i++){
//         for(int j=i+1;j<candidate.size();j++){
//             int y=candidate[j].second-candidate[i].second;
//             if(y*y<answer){
//                 answer=min(answer,dist(candidate[i],candidate[j]));
//             }
//         }
//     }
//     return answer;
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin>>n;
//     for(int i=0;i<n;i++)
//         cin>>arr[i].first>>arr[i].second;
//     sort(arr,arr+n);
//     cout<<dq(0,n-1,n)<<"\n";
//     return 0;
// }

// ////////////10827
// #include <iostream>
// #include <vector>
// #include <math.h>
// using namespace std;
// void normalize(vector<int>& num){
//     for(int i=0;i<num.size();i++){
//         num[i+1]+=num[i]/10;
//         num[i]%=10;
//     }
// }
// vector<int> multiply(vector<int>& a,vector<int>& b){
//     vector<int> ret(a.size()+b.size(),0);
//     for(int i=0;i<a.size();i++){
//         for(int j=0;j<b.size();j++){
//             ret[i+j]+=a[i]*b[j];
//         }
//     }
//     normalize(ret);
//     if(ret[ret.size()-1]==0)
//         ret.pop_back();
//     return ret;
// }
// vector<int> exponent(vector<int>& num,int cnt){
//     if(cnt==1)
//         return num;
//     if(cnt%2==1){
//         vector<int> prev=exponent(num,cnt-1);
//         return multiply(num,prev);
//     }
//     vector<int> ret =exponent(num,cnt/2);
//     return multiply(ret,ret);
// }
// int main(void){
//     string a;
//     int b,pos;
//     cin>>a>>b;
//     vector<int> num(a.size()-1);
//     int index=0;
//     for(int i=a.size()-1;i>=0;i--){
//         if(a[i]=='.'){
//             pos=a.size()-i-1;
//             continue;
//         }
//         num[index]=a[i]-'0';
//         index++;
//     }
//     vector<int> ret=exponent(num,b);
//     int dotPos=ret.size()-pos*b;
//     string retS="";
//     int i=ret.size()-1;
//     for(int j=0;j<dotPos;j++){
//         retS+=ret[i]+'0';
//         i--;
//     }
//     retS+=".";
//     for(i;i>=0;i--)
//         retS+=ret[i]+'0';
//     cout<<retS<<"\n";
//     return 0;
// }

//////////////////11729 하노이탑
// 제일 밑에 있는 판을 3번째로 옮기려면 n-1개를 2번째에 옮기고 3번째 판에 옮겨야한다.
/// 그 다음 제일 밑 판을 옮기고 
///다시 n-1개를 3번째에 옮긴다
// #include <iostream>
// using namespace std;
// void hanoi(int cnt,int from,int to){
//     if(cnt==1){
//         cout<<from<<" "<<to<<"\n";
//         return;
//     }
//     hanoi(cnt-1,from,6-(from+to));
//     cout<<from<<" "<<to<<"\n";
//     hanoi(cnt-1,6-(from+to),to);
// }
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cout.tie(0);
//     int n;
//     cin>>n;
//     cout<< (1<<n)-1<<"\n";
//     hanoi(n,1,3);
//     return 0;
// }

// ///////////////1992
// #include <iostream>

// using namespace std;
// int n,arr[64][64];
// string dq(int l,int t,int size){
//     int first=arr[l][t];
//     if(size==1)
//         return to_string(first);
//     bool allSame=true;
//     for(int i=0;i<size;i++){
//         for(int j=0;j<size;j++){
//             if(arr[l+i][t+j]!=first)
//                 allSame=false;
//         }
//     }
//     if(allSame==true)
//         return to_string(first);
    
//     string ret="(";
//     int nSize=size/2;
//     ret+=dq(l,t,nSize);
//     ret+=dq(l,t+nSize,nSize);
//     ret+=dq(l+nSize,t,nSize);
//     ret+=dq(l+nSize,t+nSize,nSize);
//     ret+=")";
//     return ret;
    
    
// }
// int main(void){
//     cin>>n;
//     string temp;
//     for(int i=0;i<n;i++){
//         cin>>temp;
//         for(int j=0;j<n;j++){
//             arr[i][j]=temp[j]-'0';
//         }
//     }
//     cout<<dq(0,0,n)<<"\n";
//     return 0;
// }