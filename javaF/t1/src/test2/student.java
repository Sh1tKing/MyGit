package test2;

import java.util.ArrayList;

public class student {
    private String name;
    private int age;
    private String gender;

    public student() {
    }

    public student(String name, int age, String gender) {
        this.name = name;
        this.age = age;
        this.gender = gender;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }
    public String toString() {
        return "name = " + name + ", age = " + age + ", gender = " + gender;
    }
}
