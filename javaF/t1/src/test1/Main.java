package test1;

public class Main {
    public static void main(String[] args) {
        int []arr1={1,2,3,4,5,6,7,8};
        double []arr2={1,2.4,3,4,5,6,7,8};
        String s = ArrayUtil.printArr(arr1);
        double a=ArrayUtil.getAverage(arr2);
        System.out.println(s);
        System.out.println(a);
    }
}