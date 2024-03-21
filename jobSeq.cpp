#include<bits/stdc++.h>
using namespace std;
struct Job{
   string id;
   int deadline;
   int profit;
};
bool comp(Job j1 , Job j2){
  return (j1.profit > j2.profit);
}

int main(){
  cout<<"enter Size"<<endl;
  int sz;
  cin>>sz;
  Job jobs[sz];
  for(int i=0;i<sz;i++){
    cin>>jobs[i].id>>jobs[i].deadline>>jobs[i].profit;
  }
  sort(jobs,jobs+sz,comp);
  int jobseq[sz];
  bool gntChart[sz-1];

  for(int i=0;i<sz-1;i++){
    gntChart[i] = false;
  }
  for(int i=0;i<sz;i++){
    for(int j = (jobs[i].deadline)-1 ;j>=0;j--){
        if(gntChart[j]== false){
            gntChart[j] = true;
            jobseq[j] = i;
            break;
        }

    }

  }


  for(int i=0;i<sz;i++){

    if(gntChart[i]){
        cout<<jobs[jobseq[i]].id<< " ";
    }
  }

}
