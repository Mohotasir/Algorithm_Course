#include<bits/stdc++.h>
using namespace std;

void lcs(string x ,string y, int l1,int l2){
    int L[l1+1][l2+1];
    for(int i=0;i<=l1;i++)
           L[i][0] = 0;
    for(int j=0; j<=l2;j++){
            L[0][j] = 0;
    }

    for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
            if(x[i-1] == y[j-1]){
                L[i][j] = L[i-1][j-1] + 1;
            }else{
                L[i][j] = max(L[i-1][j],L[i][j-1]);
            }
            cout<<L[i][j]<<" ";
        }
        cout<<endl;
    }
    int siz = L[l1][l2];
    int sz = siz;
    string res[sz];
    while(l1>0 && l2>0){
        if(x[l1-1] == y[l2-1]){
            res[sz-1] = x[l1-1];
            l1--;
            l2--;
            sz--;
        }else if(L[l1-1][l2]>L[l1][l2-1]){
           l1--;
        }else{
         l2--;
        }
    }
   for(int i=0;i<siz;i++){
    cout<<res[i];
   }
}

int main()
{
    string s2 = "BDCAB";
    string s1 = "ABCB";
    int l1 = s1.size();
    int l2 = s2.size();
    lcs(s1,s2,l1,l2);


}
