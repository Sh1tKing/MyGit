package test20;

public class Tidy extends Dog{
    @Override
    public void eat() {
        System.out.println("一只叫做"+getName()+"的，"+getAge()+"的泰迪狗，正在吃吃骨头，边吃边蹭");
    }

}
