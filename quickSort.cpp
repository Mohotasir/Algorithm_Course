#include<bits/stdc++.h>
using namespace std;


//swap function
 void swaping(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

 int partitions(int a[] , int l , int r)
 {
     int i , j , pivot;
     pivot = a[l];
     i = l;
     j = r;
     while(i < j)
     {
         while(a[i] <= pivot){
            i++;
         }
         while(a[j]> pivot){
            j--;
         }
         if(i<j)
            swaping(&a[i],&a[j]);
     }
     swaping(&a[l],&a[j]);
     return j;
 }

 void quickSort(int a[] , int l, int r)
 {

     if(l<r){
        int j =  partitions(a,l,r);
        quickSort(a,l,j - 1);
        quickSort(a,j + 1, r);
     }

 }


int main()
{
    int n;
    cin>>n;
    int arr[n];
    // input array values
    for(int i=0;i < n ; i++){
       cin>>arr[i];
    }
    //quick sort function call
    quickSort(arr,0,n-1);

    // print sorted array
    for(int i = 0; i < n ; i++)
    {
        cout<< arr[i] <<"  ";
    }
}
