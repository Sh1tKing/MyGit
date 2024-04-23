package test10;

public class Student extends Person{
    public Student(int age, String name) {
        super(age,name);
    }
    @Override
    public void show() {
        System.out.println("student " +
                "age=" + getAge() +
                ", name='" + getName() + '\'');
    }
    public void study(){
        System.out.println("study");
    }
}
