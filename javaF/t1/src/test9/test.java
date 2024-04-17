package test9;

public class test {
    public static void main(String[] args) {
        Lecturer t1=new Lecturer("123","dajiba");
        Tutor tu1=new Tutor("456","shabi");
        Maintainer m1=new Maintainer("789","diaonima");
        Buyer b1=new Buyer("098","laji");
        System.out.println(b1);
        System.out.println(t1);
        System.out.println(tu1);
        System.out.println(m1);
        tu1.work();
        m1.work();
        b1.work();
        t1.work();
        //
    }
}
