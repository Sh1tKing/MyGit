package interface5;

public class animal {
    private int age;
    private String name;
    public void eat(){
        System.out.println("eat");
    }
    public animal(int age, String name) {
        this.age = age;
        this.name = name;
    }

    public animal() {
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
