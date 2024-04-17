package test8;

public class test {
    public static void main(String[] args) {
        manager m1=new manager("jb","shi",1233,99);
        manager m2=new manager("j3b","shsafi",567567,0);
        cook c1=new cook("ppp","asdf",123);
        System.out.println(m1.getName());
        m1.work();
        c1.work();
        System.out.println(m1);
        System.out.println(c1);
    }
}
