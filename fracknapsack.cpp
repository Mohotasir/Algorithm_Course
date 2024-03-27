#include<bits/stdc++.h>
using namespace std;
struct Item{
    int profit;
    int weight;
};
bool cmp(Item i1,Item i2)
{
  double r1 = (double)i1.profit / (double)i1.weight;
  double r2 = (double)i2.profit / (double)i2.weight;
  return r1 > r2;
}

int main()
{
 int sz,W;
 cin>>sz>>W;
 Item items[sz];
 for(int i=0;i<sz;i++){
    cin>>items[i].weight>>items[i].profit;
 }
 sort(items,items+sz,cmp);
 double finalVal = 0.0;
 for(int i=0; i< sz;i++){
    if(items[i].weight <= W){
        W = W - items[i].weight;
        finalVal += items[i].profit;
    }else{
        finalVal += items[i].profit * ((double)W / (double)items[i].weight);
        break;
    }


 }
 cout<<finalVal<<endl;
}

