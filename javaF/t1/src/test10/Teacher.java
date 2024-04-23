package test10;

public class Teacher extends Person{
    public Teacher(int age, String name) {
        super(age,name);
    }
    @Override
    public void show() {
        System.out.println("teacher " +
                "age=" + getAge() +
                ", name='" + getName() + '\'');
    }
    public void teach(){
        System.out.println("teach");
    }
}
