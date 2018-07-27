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
            {
            String str=sc.next();int flag=1;
            StringBuilder st=new StringBuilder(str);
            String r=st.reverse().toString();
            for(int j=1;j<str.length();j++)
                { 
                if(Math.abs(str.charAt(j)-str.charAt(j-1))!=Math.abs(r.charAt(j)-r.charAt(j-1)))
                {   flag=0;break; }
            }
            if(flag==1)
                System.out.println("Funny");
            else
                System.out.println("Not Funny");
        }
    }
}
