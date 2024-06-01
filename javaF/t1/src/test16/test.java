package test16;

import java.util.Arrays;
import java.util.Comparator;

public class test {
    public static void main(String[] args) {
        girlfriend g1=new girlfriend(12,144,"lisa");
        girlfriend g2=new girlfriend(16,155,"poll");
        girlfriend g3=new girlfriend(12,144,"Racial");
        girlfriend g4=new girlfriend(10,76,"Lelly");
        girlfriend g5=new girlfriend(17,167,"Fuck");
        girlfriend[] arr={g1,g2,g3,g4,g5};
        Arrays.sort(arr, new Comparator<girlfriend>() {
            @Override
            public int compare(girlfriend o1, girlfriend o2) {
                if(o1.getAge()==o2.getAge()){
                    if(o1.getHeight()==o2.getHeight()){
                        return o1.getName().compareTo(o1.getName());
                    }else return o1.getHeight()-o2.getHeight();
                }else return o1.getAge()-o2.getAge();
            }
        });
        System.out.println(Arrays.toString(arr));
    }
}
