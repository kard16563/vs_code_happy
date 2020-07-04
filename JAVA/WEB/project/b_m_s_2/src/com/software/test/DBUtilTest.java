package com.software.test;

import java.sql.SQLException;

import com.software.util.DBUtil;

/**
 * @author Lenovo
 */
public class DBUtilTest {
	public static void main(String[] args) {
		long startTime = System.nanoTime();

		try {
			System.out.println(DBUtil.getConnection());
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		long endTime = System.nanoTime();

		System.out.println("程序运行时间：" + (endTime - startTime) / 1000 + "μs.");

	}
}
