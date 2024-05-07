package interface2;

public class test {
    public static void main(String[] args) {
        tablecoach tc1=new tablecoach(1234,"mike");
        tableplayer tp1=new tableplayer(45,"ppp");
        basketballcoach bc1= new basketballcoach(245,"pokir");
        basketplayer bp1= new basketplayer(545,"sdf");

        System.out.println(tc1.getAge()+" "+tc1.getName());
        System.out.println(tp1.getAge()+" "+tp1.getName());
        System.out.println(bp1.getAge()+" "+bp1.getName());

        tc1.teach();
        tp1.study();
        bc1.teach();
        bp1.study();
    }
}
