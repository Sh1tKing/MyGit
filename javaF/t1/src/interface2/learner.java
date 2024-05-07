package interface2;

public abstract class learner extends person{
    public abstract void study();

    public learner() {
    }

    public learner(int age, String name) {
        super(age, name);
    }
}
