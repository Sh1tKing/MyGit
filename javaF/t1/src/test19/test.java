package test19;

import java.util.ArrayList;

public class test {
    public static void main(String[] args) {
        MyArraylist<String> arr1=new MyArraylist<>();
        arr1.add("1234");
        arr1.add("gdf");
        arr1.add("g45t");
        System.out.println(arr1.get(2));
        ArrayList<String> arr2=new ArrayList<>();
        Myarrayfunc.addall(arr2,"asfdsf","asdfasd","q3r3","asdf34}}}{","asf4332");
        arr2.forEach(s-> System.out.println(s));
    }
}
