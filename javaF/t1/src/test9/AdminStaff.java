package test9;

public class AdminStaff extends Employee{
    @Override
    public void work(){
        System.out.println("charging");
    }

    public AdminStaff() {
    }

    public AdminStaff(String id, String name) {
        super(id, name);
    }
}
