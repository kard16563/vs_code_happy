package com.software.util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class DBUtilTmp {
	public static void main(String[] args) {
		// 准备链接数据库的资源
		// 1.用户名
		String  username = "root";
		// 2.密码
		String password = "123456";
		// 3.连接地址
		String url = "jdbc:mysql://127.0.0.1:3306/test"; //127.0.0.1==localhost
		// 4.连接驱动
		String driver = "com.mysql.jdbc.Driver"; //老版本的驱动（jar包）
		//String driver = "com.mysql.cj.jdbc.Driver"; //新版本的驱动（jar包）
		
		try {
			// 1.加载驱动
			Class.forName(driver);
			
			// 2.获取链接
			Connection conn = DriverManager.getConnection(url, username, password);
			
			// 3.创建 Statement 对象（st）
			//Statement st = conn.createStatement();
			
			// 3.创建 SQL 指令
			//String sql = "select * from book";
			
			// 4.创建 PreparedStatement 对象（pst）
			//PreparedStatement pst = conn.prepareStatement(sql);
			
			// 5.通过 st 对象执行 sql 指令
			//ResultSet rs = st.executeQuery(sql);
			
			// 6.遍历结果集，打印每一条记录
			/*
			while (rs.next()) {
				System.err.println("图书ISBN：" + rs.getString("book_isbn"));
				System.err.println("图书名称：" + rs.getString("book_name"));
				System.err.println("图书价格：" + rs.getString("book_price"));
				System.err.println("图书作者：" + rs.getString("book_author"));
				System.err.println("图书数量：" + rs.getString("book_count"));
			}
			*/
			
			// 7.释放资源
			/*
			if (rs != null) {
				rs.close();
			}
			if (st != null) {
				st.close();
			}
			if (conn != null) {
				conn.close();
			}
			*/
		} catch (ClassNotFoundException | SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}
