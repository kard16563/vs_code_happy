package com.software.dao;

import java.util.List;

import com.software.bean.Book;
import com.software.bean.BookBuy;

public interface IBookDao {
	//新增图书
	public void addBook(Book book);
	
	//更新图书
	public void updateBook(Book book);
	
	//查找图书
	public List<Book> findAllBooks();
	
	//根据ISBN号查找图书
	public Book findBookByISBN(String bookISBN);
	
	//删除图书
	public void delBook(String bookISBN);

	//购买图书
	public void buyBook(BookBuy buy);

}
