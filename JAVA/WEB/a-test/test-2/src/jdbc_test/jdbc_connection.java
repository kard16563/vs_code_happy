package jdbc_test;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

public class jdbc_connection {

    public static void main(String[] args) {
//        Connection c = null;
//        Statement s = null;

        try {
            Class.forName("com.mysql.jdbc.Driver");

            // 建立与数据库的Connection连接
            // 这里需要提供：
            // 数据库所处于的ip:127.0.0.1 (本机)
            // 数据库的端口号： 3306 （mysql专用端口号）
            // 数据库名称 test
            // 编码方式 UTF-8
            // 账号 root
            // 密码 123456

            Connection c = DriverManager
                    .getConnection(
                            "jdbc:mysql://127.0.0.1:3306/test?characterEncoding=UTF-8",
                            "root", "123456");

            System.out.println("连接成功，获取连接对象： " + c);

            Statement s = c.createStatement();
            System.out.println("获取 Statement对象： " + s);



        } catch (ClassNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

    }


}
