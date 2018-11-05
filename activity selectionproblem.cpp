#include<iostream>
using namespace std;
int partitiom(int arr[],int arr2[],int start,int high){
   int pivot=arr[high];
   int pindex=start;
   int temp,temp2,i;
   for(i=start;i<high;i++){
    if(arr[i]<=pivot){
        temp=arr[i];
        temp2=arr2[i];//
        arr2[i]=arr2[pindex];//
        arr2[pindex]=temp2;//
        arr[i]=arr[pindex];
        arr[pindex]=temp;
        pindex++;
    }
   }
   temp=arr[high];
   arr[high]=arr[pindex];
   arr[pindex]=temp;
   temp2=arr2[high];//
   arr2[high]=arr2[pindex];//
   arr2[pindex]=temp2;//
   return pindex;
}
void quick(int arr[],int arr2[],int start,int high){
   int pindex;
   if(start<high){
    pindex=partitiom(arr,arr2,start,high);
    quick(arr,arr2,start,pindex-1);
    quick(arr,arr2,pindex+1,high);
   }
}
int main(){
   int n;
   cin>>n;
   int start[n],finish[n];
   int i;
   for(i=0;i<n;i++)
   {
       cin>>start[i];
       cin>>finish[i];
   }
   quick(finish,start,0,n-1);
   int k=1;
   int prev=0;
   for(i=1;i<n;i++){
    if(start[i]>=finish[prev]){
        prev=i;
        k=k+1;
    }
   }
   cout<<k;
}
