import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String st = in.next();
        st=st.replaceAll("\\s+","");
        int r,c;
        int l=st.length();
        r=(int)Math.floor(Math.sqrt(l));
        c=(int)Math.ceil(Math.sqrt(l));
        if((r*c)<l)
            r=c;
        String x[]=new String[r];
        int pos=0;
        for(int i=0;i<r;i++)
            {
            if((pos+c)<=l)
            x[i]=st.substring(pos,pos+c);
            else
            x[i]=st.substring(pos,l);
            pos=pos+c;
        }
        for(int i=0;i<c;i++)
            {
            for(int j=0;j<r;j++)
                {if(x[j].length()>i)
                System.out.print(x[j].charAt(i));
            }System.out.print(" ");
        }
           
        
    }
}
