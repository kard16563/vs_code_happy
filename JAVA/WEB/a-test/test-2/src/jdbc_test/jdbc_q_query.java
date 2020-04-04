package jdbc_test;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class jdbc_q_query {

    public static void main(String[] args) {
        int i=0;
        try {
            Class.forName("com.mysql.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

        try (Connection c = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/test?characterEncoding=UTF-8",
                "root", "123456");
             Statement s = c.createStatement();) {

            String sql = "select * from cc";

            // 执行查询语句，并把结果集返回给ResultSet
            ResultSet rs = s.executeQuery(sql);

            while (rs.next()) {
                i=i+1;
                int id = rs.getInt("id");// 可以使用字段名
                String user=rs.getString("user");
                String pa=rs.getString("pa");
                System.out.printf("%d\t%s\t%s \n", id, user, pa);

//                String name = rs.getString(2);// 也可以使用字段的顺序
//                float hp = rs.getFloat("hp");
//                int damage = rs.getInt(4);
//                System.out.printf("%d\t%s\t%f\t%d%n", id, name, hp, damage);
            }

            System.out.println("total--> "+i);
            // 不一定要在这里关闭ReultSet，因为Statement关闭的时候，会自动关闭ResultSet
            // rs.close();

        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

}
