package interface2;

public abstract class coach extends person{
    public abstract void teach();

    public coach() {
    }

    public coach(int age, String name) {
        super(age, name);
    }
}
