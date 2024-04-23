package test10;

public class t {
    public static void main(String[] args) {
        Person s1=new Student(43,"3413");
        Person t1=new Teacher(33,"awf");
        Person a1=new Student(54,"wer");

        register(s1);
        register(t1);
        register(a1);

       if(a1 instanceof Admin d){
           d.manage();
       }else if(a1 instanceof Teacher d){
           d.teach();
       }else if(a1 instanceof Student d){
           d.study();
       }
    }
    public static void register(Person person){
        person.show();
    }
}
