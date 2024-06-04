package test19;

import java.lang.Object;
import java.util.Arrays;

public class MyArraylist<E> {
    Object[] arr=new Object[10];
    int size;
    public boolean add(E e){
        arr[size]=e;
        size++;
        return true;
    }
    public E get(int index){
        return (E)arr[index];
    }
    @Override
    public String toString() {
        return Arrays.toString(arr);
    }
}
