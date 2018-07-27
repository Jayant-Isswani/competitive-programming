import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        
        BigInteger fact=BigInteger.ONE;
        for(int i=n;i>0;i--)
            {
            fact=fact.multiply(BigInteger.valueOf(i));
        }
        System.out.println(fact);
    }
}
