package interface5;

public class test {
    public static void method(animal a){
        a.eat();
    }
    public static void main(String[] args) {

        method(
               new animal(){
                   @Override
                   public void eat(){
                       System.out.println("eat bones");
                   }
               }
        );

    }
}
