/* Link : https://www.geeksforgeeks.org/array-rotation/ */
#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
}

void rotate(int* arr,int n, int d)
{
    for(int i=0;i<gcd(d,n);i++)
    {
        int j=i;
        int temp=arr[i];
        while(1)
        {
            int k=(j+d)%n;
            if(k==i)
            break;
            arr[j]=arr[k];
            j=k;
        }
        arr[j]=temp;
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
    rotate(arr,n,d);
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
	return 0;
}
