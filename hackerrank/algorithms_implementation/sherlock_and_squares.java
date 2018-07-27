import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
         Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        for(int j=0;j<t;j++)
            {
            int a,b;
            a=sc.nextInt();b=sc.nextInt();
            int x=(int)(Math.floor(Math.sqrt(b))-Math.ceil(Math.sqrt(a))+1);
            System.out.println(x);
        }
    }
}
