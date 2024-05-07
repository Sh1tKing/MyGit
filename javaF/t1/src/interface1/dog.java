package interface1;

public class dog extends animal implements Swim{
    @Override
    public void eat(){
        System.out.println("eat bones");
    }
    public dog(int age,String name){
        super(age,name);
    }

    @Override
    public void swim() {
        System.out.println("goupa");
    }
}
