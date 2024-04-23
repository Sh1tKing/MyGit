package test11;

public class Animal {
    private int age;
    private String color;

    public Animal() {
    }

    public Animal(int age, String color) {
        this.age = age;
        this.color = color;
    }
    public void eat(String stuff){
        System.out.println(stuff);
    }
}
