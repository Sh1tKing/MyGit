package test15;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

public class aa  {
    public static void main(String[] args) {
//        method(()->{
//                System.out.println("sssss......");
//            }
//        );
//    }
//    public static void method(swim s){
//        s.swimming();
//    }
//    @FunctionalInterface//函数式接口，且只有一个函数
//    interface swim{
//        public abstract void swimming();

        Integer[] arr={2,3,4,65,7,86,0,8};
        Arrays.sort(arr,new Comparator<Integer>(){
            @Override
            public int compare(Integer o1,Integer o2){
                return o1-o2;
            }
        });

//        Arrays.sort(arr,(Integer o1,Integer o2)->{
//            return o1 - o2;
//        });
//        Arrays.sort(arr,(o1,o2)->{
//            return o1-o2;
//        });
        Arrays.sort(arr,(o1,o2)->o1-o2);
        System.out.println(Arrays.toString(arr));
    }
}
