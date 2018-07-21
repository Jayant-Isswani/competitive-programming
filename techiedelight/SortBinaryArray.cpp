/* Link:http://www.techiedelight.com/sort-binary-array-linear-time/ */
#include <bits/stdc++.h>
using namespace std;

void sortBinaryArray(int* arr,int n)
{
    int count0=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        count0++;
    }
    for(int i=0;i<count0;i++)
    arr[i]=0;
    for(int i=count0;i<n;i++)
    arr[i]=1;
}

void sortBinaryArray1(int* arr,int n)
{
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        arr[k++]=0;
    }
    for(int i=k;i<n;i++)
    arr[i]=1;
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	sortBinaryArray(arr,n);
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
	sortBinaryArray1(arr,n);
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	return 0;
}
