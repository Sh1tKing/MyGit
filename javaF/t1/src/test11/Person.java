package test11;

public class Person {
    private int age;
    private String name;
    public void keepPet(Animal animal,String stuff){
        if(animal instanceof Dog){
            System.out.println("feeding dog"+stuff);
        }else if(animal instanceof Cat){
            System.out.println("feeding cat"+stuff);
        }
    }
    public Person() {
    }

    public Person(int age, String name) {
        this.age = age;
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
