package test14;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class test {
    public static void main(String[] args) {
        String s="{\"code\":0,\"data\":[{\"identifier\":\"circle\",\"time\":1716365156275,\"value\":\"0\",\"data_type\":\"int64\",\"access_mode\":\"读写\",\"name\":\"圈数\"},{\"identifier\":\"daycircle\",\"time\":1716365156668,\"value\":\"41\",\"data_type\":\"int64\",\"access_mode\":\"读写\",\"name\":\"今日圈数\"}],\"msg\":\"succ\",\"request_id\":\"59c06b4d5ebe4208a0bea58c45d9561c\"}";
        String s2="aaa1243aaaa";
        Pattern p = Pattern.compile("(((\\w)\\2*)\\w+\\1)");
        System.out.println(s2.matches("(((\\w)\\2*)\\w+\\1)"));
        Matcher m = p.matcher(s2);
        while(m.find()){

            String g = m.group();
            System.out.println(g);

        }

    }
}
