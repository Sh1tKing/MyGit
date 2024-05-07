package interface1;
public class t {
    public static void main(String[] args) {
        dog d1=new dog(12,"shi");
        frog f1=new frog(43,"asdfa");
        sheep s1=new sheep(18,"tryhtjy");
        System.out.println(s1.getAge()+" "+s1.getName());
        System.out.println(d1.getAge()+" "+d1.getName());
        System.out.println(f1.getAge()+" "+f1.getName());
        d1.swim();
        f1.swim();

    }
}
