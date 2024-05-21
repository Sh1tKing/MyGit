package test12;

import java.math.BigInteger;
import java.util.Random;

public class a1 {
    public static void main(String[] args) {
//        BigInteger bi1=new BigInteger(10000,new Random());
//        System.out.println(bi1);
//        BigInteger bi1=new BigInteger("134567865464321456754324567865466666666666666666666666666666666666666666666666666666666666666666666666666666666666666");
//        System.out.println(bi1);
//        BigInteger bi1=new BigInteger("100110",2);
//        System.out.println(bi1);
        BigInteger a1=new BigInteger("27670116110564327424",10);
        BigInteger a2=a1.pow(32);
        System.out.println(a1);
    }

}
