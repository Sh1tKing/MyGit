package test8;

import javax.management.DescriptorKey;

public class cook extends worker{
    @Override
    public void work(){
        System.out.println("cooking...");
    }
    public cook(){
        super(null,null,0);
    }
    public cook(String name,String id,int salary){
        super(name,id,salary);
    }
    @Override
    public String toString() {
        return "name = " + this.getName() + ", id = " + this.getId() + ", salary = " + this.getSalary();
    }
}
