package test5;

public class test {
    public static void main(String[] args) {
        Z z=new Z();
        z.shit();
    }
}
class Z extends FU{
    String name="31234";
    String game="qwer";
    @Override
    public void shit(){
        System.out.println("asdfer");
    }



}
class FU{
    String name="134";
    public void shit(){
        System.out.println("1341243");
    }

}
