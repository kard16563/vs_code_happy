package com.software.util;

import java.sql.*;

/**
 * @author Lenovo
 */
public class NewDbutil {

    // 准备链接数据库的资源
    // 1.用户名
    private static String  username = "root";
    // 2.密码
    private static String password = "password";
    // 3.连接地址
    private static String url = "jdbc:mysql://192.168.175.128:3306/test?characterEncoding=utf8&useSSL=false&serverTimezone=UTC&rewriteBatchedStatements=true"; //127.0.0.1==localhost
    // 4.连接驱动

    private static String driver = "com.mysql.cj.jdbc.Driver"; //新版本的驱动（jar包）



    /*
     *staic 经常用的 多个经常用的 这样效率高
     * 不用去建立那么咄咄对象
     * 直接使用就可以
     *
     * */
    static {
        try {
            Class.forName(driver);
        } catch (ClassNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    public static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(url, username, password);
    }

    public static void release(Connection conn, PreparedStatement pst, ResultSet rs) throws SQLException {
        if (rs != null) {
            rs.close();
        }
        if (pst != null) {
            pst.close();
        }
        if (conn != null) {
            conn.close();
        }
    }


}
