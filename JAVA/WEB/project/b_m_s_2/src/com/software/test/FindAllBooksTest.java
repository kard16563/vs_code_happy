package com.software.test;

import java.util.List;

import com.software.bean.Book;
import com.software.dao.IBookDao;
import com.software.dao.impl.BookDaoImpl;

public class FindAllBooksTest {
	public static void main(String[] args) {
		long startTime = System.nanoTime();

		IBookDao bookDao = new BookDaoImpl();
		List<Book> books = bookDao.findAllBooks();
		for (Book book : books) {
			System.err.println("图书ISBN：" + book.getBookISBN());
			System.err.println("图书名称：" + book.getBookName());
			System.err.println("图书价格：" + book.getBookPrice());
			System.err.println("图书作者：" + book.getBookAuthor());
			System.err.println("图书数量：" + book.getBookCount());
		}

		long endTime = System.nanoTime();

		System.out.println("程序运行时间：" + (endTime - startTime) / 1000 + "μs.");

	}
}
