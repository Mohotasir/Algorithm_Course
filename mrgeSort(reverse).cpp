#include<bits/stdc++.h>
using namespace std;

void merges(int a[] , int l , int mid , int r , int s)
{
    int i,j,k;
    i = l;
    j = mid + 1;
    k = l;
    int temp[s];
    while(i <= mid && j <= r )
    {
        if(a[i]>=a[j]){
            temp[k] = a[i];
            i++;
            k++;
        }else{
            temp[k] = a[j];
            j++;
            k++;
        }
    }
    if(i>mid){
        while(j<=r){
            temp[k] = a[j];
            j++;
            k++;
        }
    }else{
        while(i<=mid){
            temp[k] =a[i];
            i++;
            k++;
        }
    }

    for(k = l ; k<=r;k++){
        a[k] = temp[k];
    }

}

void mergeSort(int a[], int l ,int r){
    if(l<r)
    {
        int sz = r +1;
        int mid = (l+r)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);

        merges(a,l,mid,r,sz);
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    mergeSort(a,0,n-1);

    for(int i=0;i<n;i++)
    {
         cout<<a[i]<<" ";
    }
}
