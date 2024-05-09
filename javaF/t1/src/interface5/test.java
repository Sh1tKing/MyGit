package interface5;

public class test {
    public static void main(String[] args) {
        animal a=new animal() {
            @Override
            public void eat() {
                System.out.println("shit");
            }
        };
        a.eat();
    }
}
