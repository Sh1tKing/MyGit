package test15;

import java.util.Arrays;
import java.util.Comparator;

public class ss {
    public static void main(String[] args) {
        String[] arr={"asdf","3rfwe","a#$@#F","pa]","\"sadfaeofkmv",".,,ldflasdadfafadsf"};
        Arrays.sort(arr, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o1.length()-o2.length();
            }
        });
        //Arrays.sort(arr,(o1,o2)->o1.length()-o2.length());
        System.out.println(Arrays.toString(arr));
    }
}
