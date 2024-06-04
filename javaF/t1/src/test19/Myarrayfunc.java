package test19;

import java.util.ArrayList;

public class Myarrayfunc {
    public static<E> void addall(ArrayList<E> arr,E...e){
        for (E ptr:e) {
            arr.add(ptr);
        }
    }
}
