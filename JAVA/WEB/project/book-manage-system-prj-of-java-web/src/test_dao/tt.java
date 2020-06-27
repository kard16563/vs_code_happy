package test_dao;




import net.sf.json.JSONArray;
import net.sf.json.JSONObject;
import web_tools.test_jdbc;
import web_tools.test_register;

import java.text.SimpleDateFormat;
import java.util.Date;


public class tt  {


    public static void main(String[] args) throws InterruptedException {
        cc kk= new cc("123",4);

        String a = "[{\"name\":\"电话卡\",\"id\":\"1\"},{\"name\":\"电话卡2\",\"id2\":\"12\"}]";

        JSONArray json = JSONArray.fromObject(a );
        int dd=json.size();

        System.out.println(json.get(1));
        JSONObject obj = JSONObject.fromObject(json.get(1));

        int aa =Integer.parseInt(obj.get("id2").toString())  ;
        aa=aa+1;

        System.out.println("name is : " + obj.get("name")+"==="+aa);
        System.out.println("id is : " + obj.get("id2")+"==="+aa);


        test_register addCount =new test_register("kard","123456",0);
        //int ans1= addCount.accountAdd();
        int ans2=addCount.accountCheck();
        System.out.println("ans1-->"+"---->"+ans2);

        test_jdbc bookA= new test_jdbc("namea-","idView-", "10","20","55588899");
        int ans3=bookA.bookAdd();
        System.out.println("ans3-->"+"---->"+ans3);

        SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd-HH-mm-ss");
        String time1 =df.format(new Date());
        System.out.println( "time1 -->"+time1 );
        String time2 = time1;
        Thread.sleep(2000);
        //String time2 = time1;


        System.out.println("time2-->"+time2);








    }
}