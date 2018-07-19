/* Link:https://www.geeksforgeeks.org/block-swap-algorithm-for-array-rotation/ */
#include <bits/stdc++.h>
using namespace std;

void swap(int* arr,int fi,int si,int d)
{
    for(int i=0;i<d;i++)
    {
        int temp=arr[fi+i];
        arr[fi+i]=arr[si+i];
        arr[si+i]=temp;
    }
}

void rotate(int* arr,int d,int n)
{
    if(d==0 || d==n)
    return;
    
    if(n-d==d)
    {
        swap(arr,0,n-d,d);
        return;
    }
    
    if(d<n-d)
    {
        swap(arr,0,n-d,d);
        rotate(arr,d,n-d);
    }
    
    else
    {
        swap(arr,0,d,n-d);
        rotate(arr+n-d,2*d-n,d);
    }
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    int d;
    cin>>d;
    d=d%n;
    rotate(arr,d,n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
	return 0;
}
