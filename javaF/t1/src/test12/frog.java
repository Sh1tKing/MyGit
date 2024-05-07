package test12;

public class frog extends animal implements Swim{
    @Override
    public void eat() {
        System.out.println("eat bugs");
    }
    public frog(int age,String name) {
        super(age, name);
    }
    @Override
    public void swim(){
        System.out.println("wayong");
    }
}
