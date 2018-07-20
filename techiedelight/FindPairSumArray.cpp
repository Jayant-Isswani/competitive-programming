/* Link:http://www.techiedelight.com/find-pair-with-given-sum-array/ */
#include <bits/stdc++.h>
using namespace std;

int findPairs(int *arr,int n,int sum)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==sum)
            count++;
        }
    }
    return count;
}

int findPairs1(int* arr,int n,int sum)
{
    sort(arr,arr+n);
    int low=0,high=n-1;
    int count=0;
    while(low<high)
    {
        //cout<<arr[low]+arr[high]<<" ";
        if(arr[low]+arr[high]==sum)
        {
            count++;
            low++;
        }
        else if(arr[low]+arr[high]<sum)
        low++;
        else
        high--;
    }
    return count;
}

int findPairs2(int* arr,int n,int sum)
{
    unordered_map<int,int> map;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(map.find(sum-arr[i])!=map.end())
        {
            count++;
        }
        map[arr[i]]=sum-arr[i];
    }
    return count;
}

int main() {
    int n;
    cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int sum;
	cin>>sum;
	cout<<findPairs(arr,n,sum)<<endl;
	cout<<findPairs1(arr,n,sum)<<endl;
	cout<<findPairs2(arr,n,sum)<<endl;
	return 0;
}
