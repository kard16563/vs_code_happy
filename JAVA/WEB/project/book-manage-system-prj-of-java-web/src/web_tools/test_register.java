package web_tools;

import org.apache.commons.lang.StringUtils;

import java.security.PrivateKey;
import java.sql.*;

public class test_register {
    private String nameAdd;
    private String passAdd;
    private int select;

    public test_register(String nameAdd,String passAdd,int select) {

        this.nameAdd=nameAdd;
        this.passAdd=passAdd;
        this.select=select;

    }
    public test_register(String nameAdd,String passAdd) {

        this.nameAdd=nameAdd;
        this.passAdd=passAdd;


    }

    public int accountCheck(){
        String namea=this.nameAdd;
        String pass=this.passAdd;


        try {
            Class.forName("com.mysql.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

        try (Connection c = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/test?characterEncoding=UTF-8",
                "root", "123456");
             Statement s = c.createStatement();) {
            String sql;



            String sq = "SELECT * from book_user_2 WHERE aname='%s';";
            sql=String.format(sq,namea);
            String ansName="";
            String ansPass="";
            int ansSelect=0;


            ResultSet rs = s.executeQuery(sql);


            while (rs.next()) {


                ansName =rs.getString("aname");
                ansPass =rs.getString("pass");
                ansSelect=rs.getInt("issuper");

            System.out.println("accountCheck---"+ansName+"---"+ansPass);
            }



            if (ansName == null || ansName.length() <= 0) {

                System.out.println("empty");

                return 0;

            }else {

                if(ansPass.equals(pass)){
                    System.out.println("code true"+pass+"--"+ansName+"---"+ansSelect);
                        return ansSelect;
                }else {
                    System.out.println("code false"+pass+"--"+ansName);
                    return 0;
                }
            }







            // 执行查询语句，并把结果集返回给ResultSet
            //ResultSet rs = s.executeQuery(sql);
        } catch(SQLException e){

            e.printStackTrace();
        }

        return 0;


    }

    public int accountAdd() {
        String nameAdd = this.nameAdd;
        String passAdd = this.passAdd;
        int select = this.select;


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

            sql = "select * from book_user_2";


            ResultSet rs = s.executeQuery(sql);

            while (rs.next()) {

                String namea = rs.getString("aname");
                System.out.println("aname-->"+namea+"  nameadd--->"+nameAdd);


                if (namea.equals(nameAdd) ) {
                    System.out.println("wwrong");
                    flag =0;
                    return  0;

                }
            }

            if (select == 2 && flag ==1) {
                System.out.println("amd");

                String s1 = "insert into book_user_2 (aname,pass,issuper) values('%s','%s',%d)";
                sql = String.format(s1, nameAdd, passAdd, 2);
            } else if(flag == 1) {
                System.out.println("--");
                String s2 = "insert into book_user_2 (aname,pass,issuper) values('%s','%s',%d)";
                sql = String.format(s2, nameAdd, passAdd, 1);
            }

            s.execute(sql);//s.executeUpdate(sql);
            System.out.println("ok");




                // 执行查询语句，并把结果集返回给ResultSet
                //ResultSet rs = s.executeQuery(sql);
            } catch(SQLException e){

                e.printStackTrace();
            }


            return 1;


        }
    }


