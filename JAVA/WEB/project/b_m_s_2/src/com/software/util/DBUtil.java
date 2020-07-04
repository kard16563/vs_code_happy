package com.software.util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

// 工具类
public class DBUtil {
	// 准备链接数据库的资源
	// 1.用户名
	private static String  username = "root";
	// 2.密码
	private static String password = "123456";
	// 3.连接地址
	private static String url = "jdbc:mysql://127.0.0.1:3306/test"; //127.0.0.1==localhost
	// 4.连接驱动
	private static String driver = "com.mysql.jdbc.Driver"; //老版本的驱动（jar包）
	//private String driver = "com.mysql.cj.jdbc.Driver"; //新版本的驱动（jar包）

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
