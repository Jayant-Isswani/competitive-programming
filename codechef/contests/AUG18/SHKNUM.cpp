/*Link:https://www.codechef.com/problems/SHKNUM/
#include <bits/stdc++.h>
using namespace std;
 
long long int findNumberOfOneBinary(int n)
{
    long long int count=0;
    while(n>0)
    {
        if(n&1)
        count++;
        n=n>>1;
    }
    return count;
}
 
long long int power(long long int x, long long int y)
{
    if (y == 0)
        return 1;
    else if (y%2 == 0)
        return power(x, y/2)*power(x, y/2);
    else
        return x*power(x, y/2)*power(x, y/2);
}
 
long long int countBits(int n)
{
    long long int count=0;
    while(n>0)
    {
        n=n>>1;
        count++;
    }
    return count;
}
 
long long int addToValue(long long int n)
{
    long long int noOfOnes=findNumberOfOneBinary(n);
    //cout<<noOfOnes<<endl;
    long long int n1=n;
    long long int pos=0;
    while(noOfOnes!=1)
    {
        if(n&1)
        noOfOnes--;
        pos++;
        n=n>>1;
    }
    long long int totalBits=countBits(n1);
    //cout<<totalBits<<" "<<power(2,pos)<<" "<<pos<<endl;
    if(pos+1==totalBits)
    return power(2ll,totalBits)+1-n1;
    else
    return power(2ll,totalBits-1)+power(2,pos)-n1;
}
 
long long int subFromValue(long long int n)
{
   long long int noOfOnes=findNumberOfOneBinary(n);
   long long int result=0;
   long long int pos=0;
   while(noOfOnes!=2)
   {
       if(n&1)
       {
           noOfOnes--;
       }
       result=result+(n&1)*power(2ll,pos);
       n=n>>1;
       pos++;
   }
   return result;
}
 
int main() {
	long long int t;
	cin>>t;
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    if(n==1)
	    cout<<2<<endl;
	    else{
	    long long int noOfOnes=findNumberOfOneBinary(n);
	    if(noOfOnes==1)
	    cout<<1<<endl;
	    else if(noOfOnes==2)
	    cout<<0<<endl;
	    else
	    {
	        long long int sub=subFromValue(n);
	        long long int add=addToValue(n);
	        //cout<<add<<" "<<sub<<endl;
    	    long long int m=min(add,sub);
    	    cout<<m<<endl;
	    }
	    }
	}
	return 0;
} 
