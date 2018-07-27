import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
       Scanner sc=new Scanner(System.in);
       String str=sc.nextLine();
       
       int x[]=new int[26];int i;
        for(i=0;i<26;i++)
            {
            x[i]=0;
        }
        
       for( i=0;i<26;i++)
           {
           for(int j=0;j<str.length();j++)
               {
               if(str.charAt(j)==(i+65)||str.charAt(j)==(i+97))
                   x[i]++;
           } 
       }
        for(i=0;i<26;i++)
            {
            if(x[i]==0)
                break;
        }
        if(i==26)
            System.out.println("pangram");
        else
            System.out.println("not pangram");
    }
}
