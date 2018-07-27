#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef int bool;
#define true 1
#define false 0
int comb(int x,int y)
    {
    int comb1[x+1][y+1];
    int i,j;
    for(i=1;i<=x;i++)
        {
        for(j=0;j<=y;j++)
            {
            if(i==j||j==0)
                comb1[i][j]=1;
            else
                comb1[i][j]=comb1[i-1][j]+comb1[i-1][j-1];
        }
    }
    return comb1[x][y];
}
int sieveprime(int n)
    {
    bool isPrime[n+1];
    int i,j;
    int sum=0;
    isPrime[0]=isPrime[1]=false;
    for(i=2;i<=n;i++)
        isPrime[i]=true;
    for(i=2;i*i<=n;i++)
        {
        if(isPrime[i]==true)
            {
            for(j=i*2;j<=n;j+=i)
                isPrime[j]=false;
        }
    }
    for(i=0;i<=n;i++)
        {
        if(isPrime[i])
            sum++;
    }
    return sum;
}
int main() {
     int t;
    scanf("%d",&t);
    while(t>0)
        {
        int n;
        scanf("%d",&n);
        int j=4,sum=1;
        while(j<n)
            {
            sum+=comb(n-j+j/4,j/4);
            j=j+4;
        }
        if(n%4==0)
            sum+=1;
        sum=sieveprime(sum);
        printf("%d\n",sum);
        t--;
    }
    return 0;
}
