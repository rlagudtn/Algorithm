/////////11652
#include <iostream>
#include <map>
using namespace std;

string arr[100000];
int n;
bool isSmaller(string s1,string s2){
  if(s1[0]!='-'&&s2[0]!='-'){
    if(s1.size()==s2.size())
      return s1<s2;
    return s1.size()<s2.size();
  }
  else if(s1[0]!='-')
    return false;
  else if(s2[0]!='-')
    return true;
  else{
    if(s1.size()==s2.size()){
      s1=s1.substr(1);
      s2=s2.substr(1);
      return s1>s2;
    }
    return s1.size()>s2.size();
  }
}
int main(void){
  
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n;
  for(int i=0;i<n;i++)
    cin>>arr[i];

  map<string,int> dic;
  for(int i=0;i<n;i++){
    if(dic.count(arr[i])==0)
      dic[arr[i]]=1;
    else
      dic[arr[i]]++;
  }
  string answerNum=arr[0];
  int answerCnt=dic[answerNum];
  map<string,int>::iterator it;
  for(it=dic.begin();it!=dic.end();it++){
    if(it->second>answerCnt){
      answerNum=it->first;
      answerCnt=it->second;
    }
    else if(it->second==answerCnt&& isSmaller(it->first,answerNum)){
      answerNum=it->first;
    }
  }

  cout<<answerNum<<"\n";
  return 0;
}



// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// struct Info{
//   string name;
//   int age;
//   int order;
// };
// bool compare(Info a,Info b){
//   if(a.age==b.age)
//     return a.order<b.order;
//   return a.age<b.age;
// }
// int main(void){
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);cout.tie(0);
  
//   int n,age;
//   string name;
//   cin>>n;

//   vector<Info> infos(n);
//   for(int i=0;i<n;i++){
//     cin>>age>>name;
//     infos[i].age=age;
//     infos[i].name=name;
//     infos[i].order=i;
//   }

//   sort(infos.begin(),infos.end(),compare);
//   for(int i=0;i<n;i++){
//     cout<<infos[i].age<<" "<<infos[i].name<<"\n";
//   }
//   return 0;
// }