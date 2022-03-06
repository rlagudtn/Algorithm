#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n,m,visit[1001]={0,};
vector<int> adj[1001];

void bfs(int src){
  queue<int> q;
  q.push(src);
  visit[src]=1;
  while(!q.empty()){
    int now=q.front();
    q.pop();

    for(int i=0;i<adj[now].size();i++){
      int next=adj[now][i];
      if(visit[next]==0){
        q.push(next);
        visit[next]=1;
      }
    }
  }
}
int main(void){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int answer=0,u,v;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=1;i<=n;i++){
    if(visit[i]==0){
      bfs(i);
      answer++;
    }
  }
  cout<<answer<<"\n";
  return 0;
}