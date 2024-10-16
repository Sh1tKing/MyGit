package test23;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class asdf {
    public static void main(String[] args) {
        Map<String,Integer> map=new HashMap<>();
        map.put("asdf",1234);
        map.put("qwer7654",134);
        map.put("dfghgn",1299);
        map.put("qertytrt",9999999);
        Set<String> s=map.keySet();
        s.forEach(str-> System.out.println(map.get(str)));
    }
}
