/*Link:https://www.codechef.com/problems/GCDMOD
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
 
long long int moduloProduct(long long int a,long long int b,long long int c)
{
    long long int res=0ll;
    a=a%c;
    while(b>0)
    {
        if(b&1)
        {
            res=(res%c+a%c)%c;
        }
        a=(a%c+a%c)%c;
        b=b>>1;
    }
    return res;
}
 
long long int moduloExp(long long int a,long long int b,long long int c)
{
   long long int res=1ll;
   a=a%c;
   while(b>0)
   {
       if(b&1)
       {
           res=moduloProduct(res,a,c);
       }
       b=b>>1;
       a=moduloProduct(a,a,c);
   }
   return res;
}
 
long long int gcd(long long int a,long long int b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
}
 
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long int a,b,n;
	    cin>>a>>b>>n;
	    if(a==b)
	    cout<<(moduloExp(a,n,mod)%mod+moduloExp(b,n,mod)%mod)%mod<<endl;
	    else
	    {
	        long long int diff=a-b;
	        cout<<gcd(diff,(moduloExp(a,n,diff)%diff+moduloExp(b,n,diff)%diff)%diff)%mod<<endl;
	    }
	}
	return 0;
}  
