package interface2;

public class basketballcoach extends coach{
    @Override
    public void teach() {
        System.out.println("teaching basketball");
    }

    public basketballcoach() {
    }

    public basketballcoach(int age, String name) {
        super(age, name);
    }
}
