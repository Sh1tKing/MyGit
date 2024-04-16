package test2;

import java.util.ArrayList;

public class studentutil {
    public static int getMaxage(ArrayList<student> list){
        int age=-1;
        for(int i=0;i<list.size();i++){
            if(list.get(i).getAge()>age) age=list.get(i).getAge();
        }
        return age;
    }
}
