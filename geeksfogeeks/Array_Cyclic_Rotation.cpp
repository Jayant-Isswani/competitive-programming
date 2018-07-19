/* Link:https://www.geeksforgeeks.org/c-program-cyclically-rotate-array-one/ */
#include <bits/stdc++.h>
using namespace std;

void cyclic_rotation(int* arr,int n)
{
    int x=arr[n-1];
    for(int i=n-1;i>0;i--)
    arr[i]=arr[i-1];
    arr[0]=x;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    cyclic_rotation(arr,n);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
	return 0;
}
