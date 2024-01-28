#include<bits/stdc++.h>
using namespace std;

void merges(int arr[],int l , int mid ,int r)
{
    int i,j,k;
    i = l;
    j = mid + 1;
    k = l;
    int temp[6];

    while(i <= mid && j <= r)
    {
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }else{
           temp[k]  = arr[j];
           j++;
           k++;
        }
    }
    if(i>mid){

        while(j<= r){
            temp[k] = arr[j];
            j++;
            k++;
        }
    }else{
       while(i<= mid){
        temp[k] = arr[i];
        i++;
        k++;
       }
     }
     for(k = l;k<=r;k++){
        arr[k] = temp[k];
     }
}

void mergeSort(int arr[],int l , int r)
{
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        merges(arr,l,mid,r);
    }
}
void printArray(int arr[], int s) {
  for (int i = 0; i < s; i++)
    cout << arr[i] << " ";
  cout << endl;
}
int main()
{
    int arr[] = { 34,2,7,21,12,3,5};


    mergeSort(arr,0,6);

    printArray(arr,7);

}
