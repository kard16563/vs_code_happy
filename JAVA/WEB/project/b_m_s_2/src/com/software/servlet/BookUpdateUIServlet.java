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
 * @author guojinan
 * @version 创建时间：2020-7-3  14:59:45
 */
@WebServlet("/BookUpdateUIServlet")
public class BookUpdateUIServlet extends HttpServlet {

	private static final long serialVersionUID = 1L;

	protected void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html; charset=UTF-8");

		String bookISBN = request.getParameter("bookISBN");
		IBookDao bookDao = new BookDaoImpl();
		Book book = bookDao.findBookByISBN(bookISBN);
		
		request.setAttribute("book", book);
		request.getRequestDispatcher("book-update.jsp").forward(request, response);

	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}
}