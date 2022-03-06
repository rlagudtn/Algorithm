#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;
int solution(vector<int> &D, int X) {
    // write your code in C++14 (g++ 6.2.0)
    int i,j,answer,max_v,min_v,n;
    i=answer=0;
    n=D.size();
    while(i<n){
        max_v=D[i]+X;
        min_v=D[i]-X;
        j=i+1;
        while(j<n){
            if(D[j]>max_v||D[j]<min_v)
                break;
            max_v=min(max_v,D[j]+X);
            min_v=max(min_v,D[j]-X);
            j++;
        }
        answer++;
        i=j;
    }
    return answer;
}
int main(void){
    vector<int> tmp={1,1,1,2,3};
    cout<<solution(tmp,2)<<"\n";
    vector<int> tmp1={2,5,9,2,1,4};
    cout<<solution(tmp1,4)<<"\n";
    vector<int> tmp2={1,12,10,4,5,2};
    cout<<solution(tmp2,2)<<"\n";
    return 0;
}

// void solution(int N) {
//     int enable_print = N % 10;
//     while (N > 0) {
//         if (enable_print == 0 && N % 10 != 0) {
//             enable_print = 1;
//         }
//         if (enable_print != 0) {
//             cout << N % 10;
//         }
//         N = N / 10;
//     }
// }
// int main(void){
//     solution(12345);
//     cout<<"\n";
//     solution(10);
//     cout<<"\n";
// solution(11001);
//     cout<<"\n";
//     solution(1);
//     cout<<"\n";
//     solution(1000000000);
//     return 0;
// }




// // you can use includes, for example:
// // #include <algorithm>
// #include <iostream>
// using namespace std;
// // you can write to stderr for debugging purposes, e.g.
// // cerr << "this is a debug message" << endl;

// int main() {
//     // write your code in C++14 (g++ 6.2.0)
//     for(int i=999;i>=100;i--)
//         cout<<i<<"\n";
//     return 0;
// }


// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// const int MAX_V=100001;
// int V,E;
// vector<pair<int,int>> adj[MAX_V];

// struct DisjointSet{
//     vector<int> parent;
//     DisjointSet(int n):parent(n){
//         for(int i=0;i<n;i++)
//             parent[i]=i;
//     }
//     int find(int u){
//         if(parent[u]==u)
//             return u;
//         return parent[u]=find(parent[u]);
//     }
//     void merge(int u,int v){
//         u=find(u);v=find(v);
//         if(u==v)
//             return;
//         if(u>v)
//             swap(u,v);
//         parent[v]=u;
//     }

// };

// int kruskal(){
//     vector<pair<int,pair<int,int>>> edges;
//     for(int u=1;u<=V;u++){
//         for(int j=0;j<adj[u].size();j++){
//             int v=adj[u][j].first;
//             int cost=adj[u][j].second;
//             edges.push_back({cost,{u,v}});
//         }
//     }

//     sort(edges.begin(),edges.end());
//     int answer=0,cnt=0;
    
//     DisjointSet sets(V+1);
//     for(int i=0;i<edges.size();i++){
//         int cost=edges[i].first;
//         int u=edges[i].second.first;
//         int v=edges[i].second.second;
//         if(sets.find(u)==sets.find(v))
//             continue;
//         sets.merge(u,v);
//         answer+=cost;
//         cnt++;
//         if(cnt==V-2)
//             break;
//     }
//     return answer;
// }

// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int a,b,c;
//     cin>>V>>E;
//     for(int i=0;i<E;i++){
//         cin>>a>>b>>c;
//         adj[a].push_back({b,c});
//         adj[b].push_back({a,c});
//     }
//     cout<<kruskal()<<"\n";
//     return 0;
// }
// // int kruskal(){
// //     int answer=0;
// //     vector<pair<int,pair<int,int>>> edges;

// //     for(int u=1;u<=V;u++){
// //         for(int j=0;j<adj[u].size();j++){
// //             int v=adj[u][j].first;
// //             int cost=adj[u][j].second;
// //             edges.push_back({cost,{u,v}});
// //         }
// //     }
// //     sort(edges.begin(),edges.end());

// //     DisjointSet sets(V+1);
// //     for(int i=0;i<edges.size();i++){
// //         int cost=edges[i].first;
// //         int u=edges[i].second.first;
// //         int v=edges[i].second.second;
// //         if(sets.find(u)==sets.find(v))
// //             continue;
// //         sets.merge(u,v);
// //         answer+=cost;
// //     }
// //     return answer;
// // }
// // int main(void){
// //     ios_base::sync_with_stdio(0);
// //     cin.tie(0);
    
// //     int a,b,c;

// //     cin>>V>>E;
// //     for(int i=0;i<E;i++){
// //         cin>>a>>b>>c;
// //         adj[a].push_back({b,c});
// //         adj[b].push_back({a,c});
// //     }

// //     cout<<kruskal()<<"\n";
// //     return 0;
// // }
