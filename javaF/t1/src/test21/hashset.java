package test21;

public class hashset {
    public static void main(String[] args) {
        Student s1=new Student(12,"asdf");
        Student s2=new Student(12,"asdf");
        System.out.println(s1.hashCode());
        System.out.println(s2.hashCode());

    }
}
