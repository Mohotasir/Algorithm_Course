
#include<bits/stdc++.h>
using namespace std;


void knapsack(int c ,int w[],int p[],int n){
    int K[n+1][c+1];
    for(int i=0;i<=n;i++)
           K[i][0] = 0;
    for(int j=0; j<=c;j++){
            K[0][j] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=c;j++){
          if (w[i - 1] <= j)
            K[i][j] = max(p[i - 1] + K[i - 1][j - w[i - 1]], K[i - 1][j]);
         else
            K[i][j] = K[i - 1][j];
        cout<<K[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<< K[n][c];
}

int main()
{
  int numOfItem,capacity;
  cin>>numOfItem>>capacity;
  int w[numOfItem], p[numOfItem];
  for(int i = 0;i<numOfItem;i++){
    cin>>w[i];
  }
  for(int i = 0;i<numOfItem;i++){
    cin>>p[i];
  }

  knapsack(capacity,w,p,numOfItem);

}
