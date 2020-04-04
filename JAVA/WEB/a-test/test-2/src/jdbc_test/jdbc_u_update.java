package jdbc_test;



import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;


public class jdbc_u_update {

    public static void main(String[] args) {

        try {
            Class.forName("com.mysql.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

        try (
                Connection c = DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/test?characterEncoding=UTF-8",
                        "root", "123456");
                Statement s = c.createStatement();
        )
        {//从cc表中 修改id为6的user
            String sql = "update cc set user= 'name--' where id = 6";
            s.execute(sql);
            System.out.println("ok");

        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

}
