package test20;

public class Boss extends Cat{
    public Boss(int age, String name) {
        super(age,name);
    }

    @Override
    public void eat() {
        System.out.println("一只叫做"+getName()+"的，"+getAge()+"的波斯猫，正在吃小饼干");
    }
}
