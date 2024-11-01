#include<iostream>
using namespace std;
void merge(int arr[],int l,int mid,int h)
{
  int n1=mid-l+1;
  int  n2=h-mid;
  int a[n1],b[n2];
 for(int i=0;i<n1;i++)
 {
    a[i]=arr[l+i];
 }
 for(int i=0;i<n2;i++)
 {
    b[i]=arr[mid+1+i];
 }
 int i=0,j=0,k=l;
 while(i<n1&&j<n2)
 {
    if(a[i]<=b[j])
    {
        arr[k]=a[i];
        i++,k++;
    }
    else{
        arr[k]=b[j];
        k++,j++;
    }
 }
 while(i<n1)

 {
    arr[k++]=a[i++];
 }
 while(j<n2)
 {
    arr[k++]=b[j++];
 }
}
void mergeSort(int arr[],int l,int h)
{
   if(l>=h)return ;
   int mid=l+(h-l)/2;
   mergeSort(arr,l,mid);
   mergeSort(arr,mid+1,h);
   merge(arr,l,mid,h);
}
int binarySearch(int arr[],int size,int target)
{
    int left=0,right=size-1;
    while(left<=right)
    {
        int mid=left+(right-left)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        if(arr[mid]<target)
        {

            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;
}
int main()
{
    int arr[]={2,8,9,3,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,size-1);
    cout<<"Merge sort is:"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int target;
    cout<<"Enter element to search:";
    cin>>target;

    int index=binarySearch(arr,size,target);
    if(index!=-1)
    {
        cout<<"Element found at index : "<<index+1<<endl;
    }
    else{
        cout<<"Element not found!"<<endl;
    }
    return 0;
}