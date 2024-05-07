package interface2;

public class tablecoach extends coach implements speakEnglish{

    @Override
    public void speaking() {
        System.out.println("speaking english...");
    }

    @Override
    public void teach() {
        System.out.println("teaching table tennis");
    }

    public tablecoach() {
    }

    public tablecoach(int age, String name) {
        super(age, name);
    }
}
