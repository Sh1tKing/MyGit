package test11;

public class Cat extends Animal{
    public Cat() {
    }

    public Cat(int age, String color) {
        super(age,color);
    }
    public void catchMouse(){
        System.out.println("catching Mouse...");
    }
}
