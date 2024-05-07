package interface2;

public class tableplayer extends learner implements speakEnglish{

    @Override
    public void speaking() {
        System.out.println("speaking English...");
    }

    @Override
    public void study(){
        System.out.println("studying table tennis");
    }
    public tableplayer() {
    }

    public tableplayer(int age, String name) {
        super(age, name);
    }
}
