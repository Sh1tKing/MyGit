package test8;

public class worker {
    private String name;
    private String id;
    private int salary;

    public void work(){
        System.out.println("working...");
    }
    public worker() {
    }
    public worker(String name, String id, int salary) {
        this.name = name;
        this.id = id;
        this.salary = salary;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getId() {
        return id;
    }
    public void setId(String id) {
        this.id = id;
    }
    public int getSalary() {
        return salary;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }

    public String toString() {
        return "name = " + name + ", id = " + id + ", salary = " + salary;
    }
}
