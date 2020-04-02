package cn.mam.test;

import java.util.HashMap;
import java.util.Set;
/*https://blog.csdn.net/IT_Migrant_worker/article/details/104743218*/
/*https://blog.csdn.net/u010999809/article/details/101922489?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task*/
/*https://blog.csdn.net/dataiyangu/article/details/105011703?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task*/
public class hash {

    public static void main(String[] args) {
        HashMap<String, String> map = new HashMap<>();

        map.put("aaa", "AAA");
        map.put("bbb", "BBB");
        map.put("ccc", "CCC");

        Set<String> keys = map.keySet();
        for (String key : keys) {
            System.out.println(key + "===>" + map.get(key));
        }
    }

}
