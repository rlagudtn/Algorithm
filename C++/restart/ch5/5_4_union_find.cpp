// ////////////////10775(4)
// #include <iostream>
// #include <vector>
// using namespace std;
// struct DisjointSet{
//     vector<int> parent;
//     DisjointSet(int n):parent(n){
//         for(int i=0;i<n;i++)
//             parent[i]=i;
//     }
//     int find(int u){
//         if(u==parent[u])
//             return u;
//         return parent[u]=find(parent[u]);
//     }
//     void merge(int u, int v){
//         u=find(u);v=find(v);
//         if(u==v)
//             return;
//         if(u>v)
//             swap(u,v);
//         parent[v]=u;
//     }
// };
// int main(void){

//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int G,P,idx,cnt=0;
//     cin>>G>>P;
//     struct DisjointSet ds(G+1);

//     bool possible=true;
//     for(int i=0;i<P;i++){
//         cin>>idx;
//         int pIdx=ds.find(idx);
//         if(pIdx==0)
//             possible=false;
//         if(possible){
//             ds.merge(pIdx - 1, pIdx);
//             cnt++;
//         }
//     }
//     cout<<cnt<<"\n";
//     return 0;
// }


// ////////////1976(1)
// #include <iostream>
// #include <vector>

// using namespace std;
// struct DisjointSet{
//     vector<int> parent;
//     DisjointSet(int n):parent(n){
//         for(int i=0;i<n;i++)
//             parent[i]=i;
//     }
//     int find(int u){
//         if(u==parent[u])
//             return u;
//         return parent[u]=find(parent[u]);
//     }
//     void merge(int u, int v){
//         u=find(u);v=find(v);
//         if(u==v)
//             return;
//         if(u>v)
//             swap(u,v);
//         parent[v]=u;
//     }
// };
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int n,m,u,v,c,arr[201][201];
//     int path[1000];
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//         for(int j=1;j<=n;j++)   
//             cin>>arr[i][j];
//     for(int i=0;i<m;i++)
//         cin>>path[i];
//     struct DisjointSet ds(n+1);
//     for(int i=1;i<n;i++)
//         for(int j=i+1;j<=n;j++)
//             if(arr[i][j]==1)
//                 ds.merge(i,j);
    
//     int first=ds.find(path[0]);
    
//     for(int i=1;i<m;i++){
//         if(ds.find(path[i])!=first){
//             cout<<"NO\n";
//             return 0;
//         }
//     }
//     cout<<"YES\n";
//     return 0;
// }

///////////////4195(2)
// #include <iostream>
// #include <map>
// #include <string>
// using namespace std;
// int t,n;
// struct DisjointSet{
//     map<string,string> parent;
//     map<string,int> count;
//     string find(string s){
//         if(parent.count(s)==0){
//             parent.insert(make_pair(s,s));
//             count.insert(make_pair(s,1));
//             return s;
//         }
//         if(s==parent[s])
//             return s;
//         return parent[s]=find(parent[s]);
//     }
//     void merge(string u,string v){
//         u=find(u);v=find(v);
//         if(u==v)
//             return;
//         if(u>v){
//             string temp=v;
//             v=u;
//             u=temp;
//         }
//         parent[v]=u;
//         count[u]+=count[v];
        
//     }
//     int getCount(string u){
//         return count[find(u)];
//     }
// };
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cin>>t;
//     string u,v;

//     for(int i=0;i<t;i++){
//         cin>>n;
//         struct DisjointSet ds;
//         for(int j=0;j<n;j++){
//             cin>>u>>v;
//             ds.merge(u,v);
//             if(u<=v)
//                 cout<<ds.getCount(u)<<"\n";
//             else
//                 cout<<ds.getCount(v)<<"\n";
//         }
//     }
//     return 0;
// }
// ////////////////1717 (1)
// #include <iostream>
// #include <vector>

// using namespace std;
// struct DisjointSet{
//     vector<int> parent;
//     DisjointSet(int n):parent(n){
//         for(int i=0;i<n;i++)
//             parent[i]=i;
//     }
//     int find(int u){
//         if(u==parent[u])    
//             return u;
//         return parent[u]=find(parent[u]);
//     }
//     void merge(int u,int v){
//         u=find(u);v=find(v);
//         if(u==v)
//             return ;
//         if(u<v)
//             parent[v]=u;
//         else
//             parent[u]=v;
//     }
// };
// int main(void){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     int n,m,cmd,u,v;
//     cin>>n>>m;
//     struct DisjointSet disjointSet(n+1);
//     for(int i=0;i<m;i++){
//         cin>>cmd>>u>>v;
//         switch (cmd)
//         {
//         case 0:
//             disjointSet.merge(u,v);
//             break;
//         case 1:
//             if(disjointSet.find(u)==disjointSet.find(v))
//                 cout<<"YES"<<"\n";
//             else    
//                 cout<<"NO"<<"\n";
//             break;
//         default:
//             break;
//         }
//     }
//     return 0;
// }