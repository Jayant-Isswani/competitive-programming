import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for(int a0 = 0; a0 < t; a0++){
            int n = in.nextInt();
            int s=n-n%3;
            int i;int flag=0;
            for(i=n%3;i<=n;i+=3)
               {
                if(i%5==0){
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                {
                int j;
                for(j=1;j<=n-i;j++)
                    {
                    System.out.print("5");
                }
                for(j=1;j<=i;j++)
                    {
                     System.out.print("3");
                }
                System.out.println();
            }
            else
                 System.out.println("-1");
            
        }
    }
}
