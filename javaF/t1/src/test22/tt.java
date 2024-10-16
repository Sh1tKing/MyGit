package test22;

import java.util.TreeSet;

public class tt {
    public static void main(String[] args) {
        TreeSet<Integer> ts=new TreeSet<>();
        ts.add(1);
        ts.add(3);
        ts.add(7);
        ts.add(4);
       ts.forEach(i-> System.out.println(i));
    }
}
