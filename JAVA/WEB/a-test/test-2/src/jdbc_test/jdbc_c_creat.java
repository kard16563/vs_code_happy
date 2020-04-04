package jdbc_test;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;


public class jdbc_c_creat {

    public static void main(String[] args) {

        try {
            Class.forName("com.mysql.jdbc.Driver");

            Connection c = DriverManager
                    .getConnection(
                            "jdbc:mysql://127.0.0.1:3306/test?characterEncoding=UTF-8",
                            "root", "123456");

            Statement s = c.createStatement();

            // 准备sql语句
            // 注意： 字符串要用单引号' (5,"ss",555);
            //插入 数据
            String sql = "insert into cc values(7,"+"'achange'"+","+123006+")";
            s.execute(sql);

            System.out.println("执行插入语句成功");

        } catch (ClassNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }

    }


}
