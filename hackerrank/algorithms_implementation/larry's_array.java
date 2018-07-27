import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        for(int i=0;i<t;i++)
            {
            int n=sc.nextInt();
            int x[]=new int[n];
            for(int j=0;j<n;j++)
                {
                x[j]=sc.nextInt();
            }
            int pos=0;int j;
            while(pos<n)
                {
            for(j=n-1;j>=pos;j--)
                {
                while((j-2)>=pos&&(x[j-2]>x[j]||x[j-2]>x[j-1]))
                    {
                    int r=x[j];x[j]=x[j-2];x[j-2]=x[j-1];x[j-1]=r;
                }
            }
              pos++;  
            }
            int k;
            for(k=0;k<n;k++)
                {
                if(x[k]!=(k+1))
                  break; 
                
            }
            if(k==n)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
