package test18;

import test17.student;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.ListIterator;

public class asdf {
    public static void main(String[] args) {
        List<student> list=new ArrayList<>();
        test17.student s1=new test17.student(12,"asdg");
        test17.student s2=new test17.student(45,"oop");
        test17.student s3=new test17.student(34,"lkkj");
        test17.student s4=new student(23,"pou");
        list.add(s1);
        list.add(s2);
        list.add(s3);
        list.add(s4);
//        Iterator<student> it =arr.iterator();
//        while(it.hasNext()){
//            student tmp=it.next();
//            if(tmp.getAge()==34){
//                it.remove();
//            }else
//            System.out.println(tmp.toString());
//        }
//        for(student it:arr){
//            System.out.println(it.toString());
//        }
        list.add(2,new student(444,"asdfasdf"));
        System.out.println(list.get(2).toString());
        list.forEach(student->System.out.println(student.toString()));
        list.remove(2);
        System.out.println("-------------------------------");
        list.forEach(s-> System.out.println(s.toString()));
        System.out.println("-------------------------------");
        list.remove(s2);
        list.forEach(s-> System.out.println(s.toString()));
        System.out.println("-------------------------------");
        list.set(1,new student(1234,"ppp"));
        list.forEach(s-> System.out.println(s.toString()));
        //列表迭代器;
        System.out.println("-------------------------------");
        ListIterator<student> ii= list.listIterator();
        while(ii.hasNext()){
            student tmp=ii.next();
            if(tmp.getAge()==1234) ii.remove();
            else
            System.out.println(tmp.toString());
        }
    }
}
