import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int a,b,n;
        a=sc.nextInt();
        b=sc.nextInt();
        n=sc.nextInt();
        BigInteger y=BigInteger.valueOf(a);
        BigInteger x=BigInteger.valueOf(b);
        BigInteger z=x.multiply(x);
        BigInteger c=z.add(y);
       
        
        for(int i=1;i<=n-2;i++)
            {  
            c=z.add(y);
             
            
            y=x;x=c;z=x.multiply(x);
            
        }
        System.out.println(c);
        
    }
}
