/* Link:https://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/ */
#include <bits/stdc++.h>
using namespace std;

void reverse(int* arr,int start,int end)
{
    while(start<end)
    {
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

void rotate(int* arr,int n, int d)
{
    reverse(arr,0,d%n-1);
    reverse(arr,d%n,n-1);
    reverse(arr,0,n-1);
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
    rotate(arr,n,d);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
	return 0;
}
