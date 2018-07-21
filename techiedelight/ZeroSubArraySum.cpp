/* Link:http://www.techiedelight.com/check-subarray-with-0-sum-exists-not/ */
#include <bits/stdc++.h>
using namespace std;

int zeroSubarraySum(int* arr,int n)
{
    int curr_sum=0;
    int count=0;
    for(int i=0;i<n;i++)
    {
        curr_sum=arr[i];
        for(int j=i+1;j<=n;j++)
        {
            if(curr_sum==0)
            count++;
            if(j==n)
            break;
            curr_sum=curr_sum+arr[j];
        }
    }
    return count;
}

int zeroSubarraySum1(int* arr,int n)
{
    int sum=0,count=0;
    unordered_set<int> set;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(set.find(sum)!=set.end())
        {
            count++;
        }
        if(sum==0)
        count++;
        set.insert(sum);
    }
    return count;
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	cout<<zeroSubarraySum(arr,n)<<endl;
	cout<<zeroSubarraySum1(arr,n);
	return 0;
}
