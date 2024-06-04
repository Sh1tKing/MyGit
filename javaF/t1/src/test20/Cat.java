package test20;

public abstract class Cat extends Animal{
    public Cat(int age,String name){
        super(age,name);
    }
    @Override
    public void eat() {
        System.out.println("吃鱼");
    }
}
