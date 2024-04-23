package test10;

public class Admin extends Person{
    public Admin(int age, String name) {
        super(age,name);
    }
    @Override
    public void show() {
        System.out.println("Admin " +
                "age=" + getAge() +
                ", name='" + getName() + '\'');
    }
    public void manage(){
        System.out.println("manage");
    }
}
