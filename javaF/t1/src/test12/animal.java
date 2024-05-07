package test12;

public abstract class animal {
    private int age;
    private String name;

    public animal() {
    }

    public animal(int age, String name) {
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

    public abstract void eat();
    public void drink(){
        System.out.println("drink water");
    }

}
