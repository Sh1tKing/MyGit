package interface2;

public class basketplayer extends learner{
    @Override
    public void study() {
        System.out.println("studying basketball");
    }

    public basketplayer() {
    }

    public basketplayer(int age, String name) {
        super(age, name);
    }

}
