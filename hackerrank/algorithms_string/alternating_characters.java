import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
       Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        for(int i=1;i<=t;i++)
            { int count=0;
            int j;
        String str=sc.next();
        String str1=""+str.charAt(0);
        for(j=1;j<str.length();j++)
            {
            if(str.charAt(j)==str.charAt(j-1))
               count++;
        }
            System.out.println(count);
        }
    }
}
