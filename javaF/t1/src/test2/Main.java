package test2;
import java.util.ArrayList;
public class Main {
    public static void main(String[] args) {
        ArrayList<student> list=new ArrayList<>();
        student a=new student("JB",123,"s");
        student b=new student("asdf",23,"p");
        student c=new student("as",345,"p");
        student d=new student("et",1,"f");
        list.add(a);
        list.add(b);
        list.add(c);
        list.add(d);
        System.out.println(studentutil.getMaxage(list));
    }

}
