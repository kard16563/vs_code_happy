package jdbc_test;

import java.sql.*;

public class jdbc_c2_creat {
    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

        String sql = "insert into cc values(?,?,?)";
        //String sql2="select * from cc where id = ?";//查询操作
        try (Connection c = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/test?characterEncoding=UTF-8","root", "123456");
             // 根据sql语句创建PreparedStatement
             PreparedStatement ps = c.prepareStatement(sql);

//             PreparedStatement ps2= c.prepareStatement(sql2);//查询操作

             //PreparedStatement ps = c.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
             //后面加了个Statement.RETURN_GENERATED_KEYS参数，
             // 以确保会返回自增长ID。 通常情况下不需要加这个，有的时候需要加，
             // 所以先加上，保险一些

        ) {
           // PreparedStatement 使用参数设置，可读性好，不易犯错
            // 设置参数  从1开始的
            ps.setInt(1, 8);
            ps.setString(2, "c2");
            ps.setString(3,"8522");
            //ps.setFloat(2, 313.0f);

//            ps2.setInt(1,6);//查询操作
//            ResultSet ans=ps2.executeQuery();//查询操作
//            if (ans.next()){//查询操作
//                System.out.println(ans.getString("id")+ans.getString("user")+ans.getString("pa"));
//
//            }

            // 执行
            ps.execute();
            System.out.println("添加的第二中方式..");

        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

    }
}
