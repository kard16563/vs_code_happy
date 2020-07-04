package com.software.servlet;

import java.io.IOException;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.software.bean.Book;
import com.software.dao.IBookDao;
import com.software.dao.impl.BookDaoImpl;

import sun.awt.RepaintArea;

/**
 * @author guojinan
 * @version 创建时间：2020-7-3  14:34:34
 */
@WebServlet("/BookListServlet")
public class BookListServlet extends HttpServlet {

	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html; charset=UTF-8");
		String showId = request.getParameter("idbook");
		System.out.println("ssss--->"+showId);
		String b= "a";


		IBookDao bookDao = new BookDaoImpl();
		List<Book> books = bookDao.findAllBooks();
		request.setAttribute("books", books);	// 将后台数据传递给前端

		if (showId.equals(b)){
			System.out.println("okk");
			request.getRequestDispatcher("book-list.jsp").forward(request, response);
		}else {
			System.out.println("noono");
			request.getRequestDispatcher("book-buy.jsp").forward(request, response);
		}
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}
}