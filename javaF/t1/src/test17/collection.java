package test17;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.function.Consumer;

public class collection {
    public static void main(String[] args) {
        Collection<student> arr=new ArrayList<>();
        student s1=new student(12,"asdg");
        student s2=new student(45,"oop");
        student s3=new student(34,"lkkj");
        student s4=new student(23,"pou");
        arr.add(s1);
        arr.add(s2);
        arr.add(s3);
        arr.add(s4);
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
        arr.forEach(student->System.out.println(student.toString()));
    }
}
