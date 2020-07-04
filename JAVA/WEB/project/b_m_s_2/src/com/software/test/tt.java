package com.software.test;

import com.software.bean.BookBuy;
import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

import java.util.List;

public class tt {
    public static void main(String[] args){



        String bb="\n" +
                "[{\"age\":1,\"id\":1,\"name\":\"first\"},\n" +
                "\n" +
                "{\"age\":2,\"id\":2,\"name\":\"second\"},\n" +
                "\n" +
                "{\"age\":3,\"id\":3,\"name\":\"third\"}]\n";

// 将List的Json字符串转化为List<T>集合

        String listStr = "[{\"age\":1,\"id\":1,\"name\":\"first\"},{\"age\":2,\"id\":2,\"name\":\"second\"},{\"age\":3,\"id\":3,\"name\":\"third\"}]";




        String jsonStr = "{\"age\":1,\"id\":0}";

// json字符串转为JSONObject 对象

        JSONObject jsonObject = JSONObject.fromObject(jsonStr);
        //System.out.println("name:" + jsonObject.get("name"));
        System.out.println("age:" + jsonObject.get("age"));
        System.out.println("id:" + jsonObject.get("id"));

// JSONObject转为javaBean

        People people = (People)JSONObject.toBean(jsonObject, People.class);
        System.out.println(people);




        String dd ="{\"id\":11111,\"num\":3}";
        JSONObject jsonObject2 = JSONObject.fromObject(dd);
        BookBuy buy2 = (BookBuy) JSONObject.toBean(jsonObject2,BookBuy.class);
        System.out.println(buy2.getId());


        String aa ="[{\"id\":11111,\"num\":3},{\"id\":5555,\"num\":2}]";
        JSONArray json = JSONArray.fromObject(aa);
        System.out.println(json);
        for (Object in : json){
            JSONObject obj = JSONObject.fromObject(in);
            System.out.println("id:-->" + obj.get("id"));
            System.out.println("转换为JSON对象之后是：---->"+ obj);
            BookBuy buy = (BookBuy) JSONObject.toBean(obj,BookBuy.class);


        }

    }

}
