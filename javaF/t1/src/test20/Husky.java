package test20;

public class Husky extends Dog{
    @Override
    public void eat() {
        System.out.println("一只叫做"+getName()+"的，"+getAge()+"的哈士奇，正在吃吃骨头，边吃边拆家");
    }
}
