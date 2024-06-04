package test20;

import java.util.ArrayList;

public class test {
    public static void keepPet(ArrayList<? extends Animal> arr){
        arr.forEach(E-> E.eat());
    }
    public static void main(String[] args) {
        ArrayList<Boss> list1=new ArrayList<>();
        ArrayList<LiHua> list2=new ArrayList<>();
        ArrayList<Tidy> list3=new ArrayList<>();
        ArrayList<Husky> list4=new ArrayList<>();

        list1.add(new Boss(1234,"asdf"));
        list1.add(new Boss(4343,"poo;"));
        keepPet(list1);
    }
}
