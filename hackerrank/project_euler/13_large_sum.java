/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.util.*;
import java.math.*;
/**
 *
 * @author ultimate
 */
public class LargeSum {
    public static void main(String arg[])
    {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();BigInteger sum=BigInteger.ZERO;
        for(int i=0;i<n;i++)
        {
            BigInteger b=sc.nextBigInteger();
            sum=sum.add(b);
        }
        String str=sum.toString();
        System.out.println(str.substring(0,10));
    }
}
