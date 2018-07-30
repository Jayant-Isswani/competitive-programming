/* Link:https://www.spoj.com/problems/AE00/ */
#include <bits/stdc++.h>
using namespace std;


int main() {
	    int n;
	    scanf("%d",&n);
	    int count_rectangles;
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=i;i*j<=n;j++)
	        {
	            count_rectangles++;
	        }
	    }
	    printf("%d\n",count_rectangles);
	return 0;
}
