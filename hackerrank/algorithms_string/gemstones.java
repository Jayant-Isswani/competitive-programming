import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();int x[]=new int[26];
        for(int j=0;j<26;j++)
                {
                x[j]=0;
            }
        for(int i=1;i<=t;i++)
            {
            String str=sc.next();
            
            
            for(int j=0;j<26;j++)
                {
                for(int k=0;k<str.length();k++)
                    {
                    if(str.charAt(k)==j+65||str.charAt(k)==j+97)
                        {
                        x[j]++; 
                        break;
                    }
                    }
            }
        }
        int count=0;
        for(int i=0;i<26;i++)
            {
            if(x[i]==t)
                count++;
        }
        System.out.println(count);
    }
}
