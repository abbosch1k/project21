#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int i=l,j=m+1,k=0;
    int temp[100];

    while(i<=m && j<=r)
        temp[k++] = (arr[i]<arr[j])?arr[i++]:arr[j++];

    while(i<=m) temp[k++]=arr[i++];
    while(j<=r) temp[k++]=arr[j++];

    for(int t=0;t<k;t++)
        arr[l+t]=temp[t];
}

void mergeSort(int arr[], int l, int r){
    if(l>=r) return;
    int m=(l+r)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

int main(){
    int arr[]={5,2,8,1,3};
    mergeSort(arr,0,4);
    for(int i:arr) cout<<i<<" ";
}
