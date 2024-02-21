#include<bits/stdc++.h>
using namespace std;

void coinChange(int amount , int c[],int coin){
    int res[coin+1][amount+1];
    for(int i=0; i<=coin;i++){
        res[i][0] = 1;
    }
    for (int i = 1; i <= amount; ++i)
        res[0][i] = 0;

    for(int i=1 ; i<= coin ;i++){
        for(int j=1 ;j <= amount ; j++){

                if(c[i-1] > j){
                    res[i][j] = res[i-1][j];
                }else{
                    res[i][j] = res[i-1][j] + res[i][j - c[i-1]];
                }

            cout<<res[i][j] <<" ";
        }
        cout<<endl;
    }
   // cout<<res[coin-1][amount-1]<<endl;
}



int main()
{
    int coin,amount;
    cin>>coin>>amount;
    int c[coin];
    for(int i=0; i < coin ;i++){
        cin>>c[i];
    }
    coinChange(amount,c,coin);

}
