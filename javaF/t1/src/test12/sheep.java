package test12;

public class sheep extends animal{
    @Override
    public void eat(){
        System.out.println("eat grass");
    }
    public sheep(int age,String name){
        super(age,name);
    }
}
