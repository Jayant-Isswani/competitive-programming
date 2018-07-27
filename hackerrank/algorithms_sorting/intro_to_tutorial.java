import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int v=sc.nextInt();
        int n=sc.nextInt();
        int x[]=new int[n];
        for(int i=0;i<n;i++)
            {
            x[i]=sc.nextInt();
            if(v==x[i])
                System.out.println(i);
        }
    }
}
