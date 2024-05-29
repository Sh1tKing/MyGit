package test13;

import java.math.BigDecimal;

public class asdf {
    public static void main(String[] args) {
        String r1="13074255551";
        System.out.println(r1.matches("1[3-9]\\d{9}"));
        String r2="020-1234424";
        System.out.println(r2.matches("0\\d{2,3}-?[^0]\\d{4,9}"));
        String r3="1234124@qq.com";
        System.out.println(r3.matches("\\w+@[\\w&&[^_]]{2,6}(\\.[a-zA-Z]{2,3}){1,2}"));
        String r4="^[1-9]\\d{5}(?:18|19|20)\\d{2}(?:0[1-9]|10|11|12)(?:0[1-9]|[1-2]\\d|30|31)\\d{3}[\\dXx]$";
        System.out.println("".matches(r4));
    }
}
