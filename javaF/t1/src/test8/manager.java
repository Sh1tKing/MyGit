package test8;

public class manager extends worker {
    private int reward;

    public int getReward() {
        return reward;
    }

    public void setReward(int reward) {
        this.reward = reward;
    }

    @Override
    public void work() {
        System.out.println("managing...");
    }
    public manager(){
    }
    public manager(String name, String id, int salary,int reward) {
        super(name,id,salary);
        this.reward=reward;
    }
    public String toString() {
        return "name = " + this.getName() + ", id = " + this.getId() + ", salary = " + this.getSalary()+", reward = " + this.getReward();
    }
}
