/* Link:https://www.hackerearth.com/problem/algorithm/magic-fractions/description/  */
#include <bits/stdc++.h>
using namespace std;

void findAllPrimes(bool* isPrime)
{
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=2;i<=500;i++)
    {
        if(isPrime[i]==true)
        {
            //cout<<i<<" ";
            for(int j=2*i;j*j<=500;j+=i)
            {
                //cout<<j<<" ";
                isPrime[j]=false;
            }
        }
    }
}

int main() {
	int n;
	cin>>n;
	int noOfPrimes=0;
	bool isPrime[501];
	memset(isPrime,true,501);
	findAllPrimes(isPrime);
	int dp[501];
	dp[1]=0;
	int value;
	for(int i=2;i<=500;i++)
	{
	    if(isPrime[i]==true)
	    noOfPrimes++;
	    value=1ll<<(noOfPrimes-1);
	    dp[i]=dp[i-1]+value;
	}
	cout<<dp[n]<<endl;
	return 0;
}
