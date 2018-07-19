/* Link:https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/ */
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *arr,int x,int start,int end)
{
    if(end<start)
    return -1;
    int mid=(start+end)/2;
    if(arr[mid]==x)
    return mid;
    else if(arr[mid]<x)
    return binarySearch(arr,x,mid+1,end);
    return binarySearch(arr,x,start,mid-1);
}

int findPivot(int* arr,int low,int high)
{
    if(low>high)
    return -1;
    
    if(high==low)
    return low;
    
    int mid=(low+high)/2;
    if(mid<high && arr[mid]>arr[mid+1])
    return mid;
    
    if(mid>low && arr[mid]<arr[mid-1])
    return mid-1;
    
    if(arr[low]>=arr[mid])
    return findPivot(arr,low,mid-1);
    
    return findPivot(arr,mid+1,high);
}

int pivotedBinarySearch(int* arr,int n,int key)
{
    int pivot=findPivot(arr,0,n-1);
    if(pivot==-1)
    return binarySearch(arr,key,0,n-1);
    
    if(arr[pivot]==key)
    return pivot;
    
    if(arr[0]<=key)
    return binarySearch(arr,key,0,pivot-1);
    
    return binarySearch(arr,key,pivot+1,n-1);
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<pivotedBinarySearch(arr,n,key);
	return 0;
}
