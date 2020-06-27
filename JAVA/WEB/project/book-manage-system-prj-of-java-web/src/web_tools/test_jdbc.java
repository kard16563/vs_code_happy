package web_tools;
//test_jdbc

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

import java.sql.*;

public class test_jdbc {
//    public void bookBuy(String msg)
    private String msgBuy;


    private String name0;
    private String note0 ;
    private String remain0;
    private String price0;
    private String recommendation0;
    private String idView0;

    public test_jdbc(){

    }
    public test_jdbc(String msgBuyJson){
        this.msgBuy=msgBuyJson;

    }


    public void bookBuy(){
        String msg = this.msgBuy;
        //String msg="[{\"id\":0,\"num\":4},{\"id\":1,\"num\":4}]";
        //String data = (String) params.get("data");
        JSONArray json = JSONArray.fromObject(msg);
        int numJson =json.size();
        for(Object in : json){
            System.out.println("in ---->"+in);
            JSONObject obj = JSONObject.fromObject(in);
            int numBuy = Integer.parseInt(obj.get("num").toString());
            int idBuy = Integer.parseInt(obj.get("id").toString());


            try {
                Class.forName("com.mysql.jdbc.Driver");
            } catch (ClassNotFoundException e) {
                e.printStackTrace();
            }

            try (Connection c = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/test?characterEncoding=UTF-8",
                    "root", "123456");
                 Statement s = c.createStatement();) {



                String sql = "update books set remain=remain-"+numBuy+" where id ="+idBuy;
                s.execute(sql);
                System.out.println("ok");

                // 执行查询语句，并把结果集返回给ResultSet
                //ResultSet rs = s.executeQuery(sql);
            } catch (SQLException e) {

                e.printStackTrace();
            }

//                while (rs.next()) {
//
//                    int id = rs.getInt("id");// 可以使用字段名
//                    String idView=rs.getString("idView");
//                    String name = rs.getString("name");
//                    int remain=rs.getInt("remain");
//                    int price=rs.getInt("price");
//                    String recommendation = rs.getString("recommendation");
//
//                    if(id == idBuy){
//                        System.out.println("find-1"+id+"***"+remain);
//                        remain = remain - numBuy;
//                        System.out.println("find-2"+id+"***"+remain);
//                    }
//
//
//
//                }

                // 不一定要在这里关闭ReultSet，因为Statement关闭的时候，会自动关闭ResultSet
                // rs.close();




             }
        System.out.println("--->j"+json.get(0)+"数量"+ numJson);
        JSONObject obj = JSONObject.fromObject(json.get(0));




    }

    public test_jdbc(String name,String idView, String remain,String price,String recommendation){
        this.idView0=idView;
        this.name0=name;
        this.price0=price;
        this.recommendation0=recommendation;
        this.remain0=remain;


    }


    public int bookAdd(){
        String name0 = this.name0;
        String note0 = "note";
        String remain0 =this.remain0;
        String price0= this.price0;
        String recommendation0=this.recommendation0;
        String idView0=this.idView0;

        int remain = Integer.parseInt(remain0);
        int price = Integer.parseInt(price0);
        int back=-1;

        String tt= " \"%s\" ";
        String temp="../../upimg/";
        String idView1=temp.concat(idView0) ;
        String idView= String.format(tt,idView1);
        String name =String.format(tt,name0);
        String recommendation = String.format(tt,recommendation0);

        System.out.println("---->"+idView+"-->"+name+"--->"+recommendation);


        try {
            Class.forName("com.mysql.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

        try (Connection c = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/test?characterEncoding=UTF-8",
                "root", "123456");
             Statement s = c.createStatement();) {
            String sql;
            int flag =1;
            int max=0;

            sql = "select * from books";


            ResultSet rs = s.executeQuery(sql);

            while (rs.next()) {

                String namea = rs.getString("name");
                String id0= rs.getString("id");
                int id =Integer.parseInt(id0);
                if (id>max){
                    max=id;
                }

                System.out.println("aname-->"+namea);



                if (namea.equals(name) ) {

                    System.out.println("wwrong");
                    flag =0;
                    //return  0;

                }
            }
            System.out.println("max--->"+max);

            if (flag ==1) {
                System.out.println("in");
                max= max+1;
                String s1 = "insert into books (id,idView,remain,name,price,recommendation) values(%d,'%s',%d,'%s',%d,'%s')";
                sql = String.format( s1,max,idView,remain,name,price,recommendation);
                back= 1;
            } else {
                System.out.println("已存在该书目");
                back= 0;
            }
//            else if(flag == 1) {
//                System.out.println("--");
//                String s2 = "insert into book_user_2 (aname,pass,issuper) values('%s','%s',%d)";
//                sql = String.format(s2, nameAdd, passAdd, 1);
//            }

            s.execute(sql);//s.executeUpdate(sql);
            System.out.println("ok");




            // 执行查询语句，并把结果集返回给ResultSet
            //ResultSet rs = s.executeQuery(sql);
        } catch(SQLException e){

            e.printStackTrace();
        }


        return back;


    }




    public  String bookList() {
        int i=0;

        String a="["+
                "{"+ "\"id\":0" +","+
                "\"idView\":"+"\"../../upimg/222.jpg\"" +","+
                " \"remain\":60"+","+"\"name\":"+"\"book_1\""+","+"\"price\":10"+ ","+"\"recommendation\":"+"\"世卫组织称世界处于新的危险阶段\""+

                "}"+","
                +
                "{"+ "\"id\":1" +","+
                "\"idView\":"+"\"../../upimg/222.jpg\"" + ","+
                " \"remain\":60"+","+"\"name\":"+"\"book_1\""+","+"\"price\":10"+  ","+"\"recommendation\":"+"\"世卫组织称世界处于新的危险阶段\""+
                "}"+","
                +
                "{"+ "\"id\":2" +","+
                "\"idView\":"+"\"../../upimg/222.jpg\"" +","+
                " \"remain\":60"+","+"\"name\":"+"\"book_1\""+","+"\"price\":10"+  ","+"\"recommendation\":"+"\"世卫组织称世界处于新的危险阶段\""+

                "}"+","
                +']';
        String bb = null;




        try {
            Class.forName("com.mysql.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

        try (Connection c = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/test?characterEncoding=UTF-8",
                "root", "123456");
             Statement s = c.createStatement();) {

            String sql = "select * from books";

            // 执行查询语句，并把结果集返回给ResultSet
            ResultSet rs = s.executeQuery(sql);

            while (rs.next()) {
                i=i+1;
                int id = rs.getInt("id");// 可以使用字段名
                String idView=rs.getString("idView");
                String name = rs.getString("name");
                int remain=rs.getInt("remain");
                int price=rs.getInt("price");
                String recommendation = rs.getString("recommendation");


                if(i==1){
                    bb="["+ "{"+ "\"id\":"+id +","+
                            "\"idView\":"+idView +","+
                            " \"remain\":"+remain+","+
                            "\"name\":"+name+","+
                            "\"price\":"+price+ ","+
                            "\"recommendation\":"+recommendation+
                            "}";
                }else {
                    bb=bb+","+"{"+ "\"id\":"+id +","+
                            "\"idView\":"+idView +","+
                            " \"remain\":"+remain+","+
                            "\"name\":"+name+","+
                            "\"price\":"+price+ ","+
                            "\"recommendation\":"+recommendation+
                            "}";
                }


                System.out.println("bb-->"+bb);
                System.out.printf("%d\t%s\t%d \t%s \t%s \n", id,idView,price,name,recommendation);


            }
            bb=bb+"]";
            System.out.println("bb-->"+bb);
            System.out.println("aa-->"+a);

            System.out.println("total--> "+i);
            // 不一定要在这里关闭ReultSet，因为Statement关闭的时候，会自动关闭ResultSet
            // rs.close();

        } catch (SQLException e) {

            e.printStackTrace();
        }

        return bb;
    }

}








