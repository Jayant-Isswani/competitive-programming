/* Link:https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/ */
#include <bits/stdc++.h>
using namespace std;

int modularExponentiation(int x,int y,int p)
{
    x=x%p;
    int res=1;
    while(y>0)
    {
        if(y&1)
        res=(res*x)%p;
        y=y>>1;
        x=(x*x)%p;
    }
    return res;
}

int main() {
	int x,y,p;
	cin>>x>>y>>p;
	int res=modularExponentiation(x,y,p);
	cout<<res<<endl;
	return 0;
}
