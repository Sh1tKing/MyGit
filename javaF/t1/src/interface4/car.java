package interface4;

public class car{
     private int carnum;
     private String carname;

    public car() {
    }
    public car(int carnum, String carname) {
        this.carnum = carnum;
        this.carname = carname;
    }
    public void show(){
        System.out.println(carnum+" "+carname);
    }
    class engine{
        String engineName;
        int engineNum;
        public void show(){
            System.out.println(engineName);
            System.out.println(carnum);
        }
    }
}
