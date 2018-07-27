/*  Link:https://www.geeksforgeeks.org/painters-partition-problem/ */
#include <bits/stdc++.h>
using namespace std;

int sum(int* arr,int start,int end)
{
    int sum1=0;
    for(int i=start;i<=end;i++)
    {
        sum1+=arr[i];
    }
    return sum1;
}

int partition(int* arr,int p,int m)
{
    int dp[m+1][p+1]={0};
    
    for(int i=1;i<=p;i++)
    dp[1][i]=sum(arr,0,i-1);
    
    for(int i=1;i<=m;i++)
    dp[i][1]=arr[0];
    
    for(int i=2;i<=m;i++)
    {
        for(int j=2;j<=p;j++)
        {
            int res=INT_MAX;
            for(int k=1;k<=j;k++)
            res=min(res,max(dp[i-1][k],sum(arr,k,j-1)));
            dp[i][j]=res;
        }
    }
    return dp[m][p];
}

int main() {
	int m,p;
	cin>>m>>p;
	int arr[p];
	for(int i=0;i<p;i++)
	{
	    cin>>arr[i];
	}
	int result=partition(arr,p,m);
	cout<<result<<endl;
}

