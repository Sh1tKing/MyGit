package test11;

public class t {
    static {
        System.out.println("asf");
    }
    public static void main(String[] args) {
        Dog a=new Dog(12,"as");
        Cat b=new Cat(14,"ndg");
        Person p=new Person(23,"adafa");
        p.keepPet(a,"shi");
        p.keepPet(b,"shfai");

    }
}
