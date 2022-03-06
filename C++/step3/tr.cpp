#include <iostream>

using namespace std;
int n,m,parent[100001]={0,},depth[100001];
int findCommonParent(int u,int v){
  int du=depth[u],dv=depth[v];
  if(du>dv){
    swap(u,v);
    swap(du,dv);
  }
  int gap=dv-du;
  for(int i=0;i<gap;i++)
    v=parent[v];
  while(u!=v){
    u=parent[u];
    v=parent[v];
  }
  return u;
}
int main(void){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  int u,v;
  cin>>n;
  parent[1]=1;
  depth[1]=0;
  for(int i=0;i<n-1;i++){
    cin>>u>>v;
    if(parent[u]!=0){
      parent[v]=u;
      depth[v]=depth[u]+1;
    }
    else{
      parent[u]=v;
      depth[u]=depth[v]+1;
    }
  }
  cin>>m;
  for(int i=0;i<m;i++){
    cin>>u>>v;
    cout<<findCommonParent(u,v)<<"\n";
  }
  
  return 0;
}