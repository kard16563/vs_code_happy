package com.software.servlet;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.software.bean.Book;
import com.software.dao.IBookDao;
import com.software.dao.impl.BookDaoImpl;


/**
 * @author Lenovo
 */
@WebServlet("/BookUpdateServlet")
public class BookUpdateServlet extends HttpServlet {

	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html; charset=UTF-8");
		
		//1.获取用户传递的参数
		String bookISBN = request.getParameter("book_isbn");
		String bookName = request.getParameter("book_name");
		String bookPrice = request.getParameter("book_price");
		String bookAuthor = request.getParameter("book_author");
		String bookCount = request.getParameter("book_count");
		
		//2.封装对象
		Book book = new Book(bookISBN, 
				 bookName, 
				 Double.parseDouble(bookPrice), 
				 bookAuthor, 
				 Integer.parseInt(bookCount));
		
		//3.调用dao包里的相应方法
		IBookDao bookDao = new BookDaoImpl();
		bookDao.updateBook(book);
		
		response.sendRedirect("index.html");
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}
}