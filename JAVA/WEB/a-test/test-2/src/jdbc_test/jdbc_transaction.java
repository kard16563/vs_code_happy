package jdbc_test;
//数据库事务 要处理 就一起处理否则就一个都不处理

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

//在Mysql中，只有当表的类型是INNODB的时候，才支持事务，
// 所以需要把表的类型设置为INNODB,否则无法观察到事务
//show table status from how2java;  查看表的类型的SQL

public class jdbc_transaction {

    public static void main(String[] args) {
        try {
            Class.forName("com.mysql.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

        try (Connection c = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/test?characterEncoding=UTF-8","root", "123456");
             Statement s = c.createStatement();) {

            // 有事务的前提下
            // 在事务中的多个操作，要么都成功，要么都失败

            c.setAutoCommit(false);

            //事务1
            String sql1 = "update cc set user = 'cas' where id = 3";
            s.execute(sql1);
            //事务2
            String sql2 = "update cc set user = 'cb' where id = 5";
            s.execute(sql2);

            // 手动提交
            c.commit();

        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

    }

}
