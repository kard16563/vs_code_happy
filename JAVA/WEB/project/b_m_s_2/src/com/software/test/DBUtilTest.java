package com.software.test;

import java.sql.SQLException;

import com.software.util.NewDbutil;

/**
 * @author Lenovo
 */
public class DBUtilTest {
	public static void main(String[] args) {
		long startTime = System.nanoTime();


		try {
			System.out.println(NewDbutil.getConnection());
		} catch (SQLException e) {

			e.printStackTrace();
		}

		long endTime = System.nanoTime();

		System.out.println("程序运行时间：" + (endTime - startTime) / 1000 + "μs.");

	}
}
