package test20;

public class LiHua extends Cat{
    public LiHua(int age, String name) {
        super(age, name);
    }

    @Override
    public void eat() {
        System.out.println("一只叫做"+getName()+"的，"+getAge()+"的狸花猫，正在吃鱼");
    }
}
