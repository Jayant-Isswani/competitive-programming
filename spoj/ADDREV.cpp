/* Link:https://www.spoj.com/problems/ADDREV/ */
#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    int rev=0;
    while(x>0)
    {
        rev=(rev*10)+(x%10);
        x=x/10;
    }
    return rev;
}

int main() {
	int n;
	scanf("%d",&n);
	int a,b,c;
	while(n--)
	{
	    scanf("%d %d",&a,&b);
	    a=reverse(a);
	    b=reverse(b);
	    c=a+b;
	    c=reverse(c);
	    printf("%d\n",c);
	}
	return 0;
}
