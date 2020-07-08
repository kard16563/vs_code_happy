package com.software.dao.impl;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import com.software.bean.Book;
import com.software.bean.BookBuy;
import com.software.dao.IBookDao;
import com.software.util.DBUtil;

/**
 * @author Lenovo
 */
public class BookDaoImpl implements IBookDao {

	@Override
	public void addBook(Book book) {
		// TODO Auto-generated method stub
		Connection conn = null;
		PreparedStatement pst = null;
		ResultSet rs = null;
		try {
			conn = DBUtil.getConnection();
			// 使用占位符？来占据要插入数据的位置，表示该数据目前尚不能确定，但此处一定会有数据，
			// 所以使用占位符先占据位置，后续再确定数值
			String sql = "insert into book(book_isbn,book_name,book_price,book_author,book_count) values(?,?,?,?,?)";
			pst = conn.prepareStatement(sql);
			
			// 在真正执行 sql 指令前，一定要确定 sql 指令中占位符的具体值
			pst.setString(1, book.getBookISBN());
			pst.setString(2, book.getBookName());
			pst.setDouble(3, book.getBookPrice());
			pst.setString(4, book.getBookAuthor());
			pst.setInt(5, book.getBookCount());
			
			int num = pst.executeUpdate();
			
			if (num >= 0) {
				System.err.println("新增图书成功！！！");
			} else {
				System.err.println("新增图书失败...");
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				DBUtil.release(conn, pst, rs);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

	@Override
	public void updateBook(Book book) {
		// TODO Auto-generated method stub
		Connection conn = null;
		PreparedStatement pst = null;
		ResultSet rs = null;
		try {
			conn = DBUtil.getConnection();
			// 使用占位符？来占据要插入数据的位置，表示该数据目前尚不能确定，但此处一定会有数据，
			// 所以使用占位符先占据位置，后续再确定数值
			String sql = "update book set book_name=?,book_price=?,book_author=?,book_count=? where book_isbn=?";
			pst = conn.prepareStatement(sql);
			
			// 在真正执行 sql 指令前，一定要确定 sql 指令中占位符的具体值
			pst.setString(1, book.getBookName());
			pst.setDouble(2, book.getBookPrice());
			pst.setString(3, book.getBookAuthor());
			pst.setInt(4, book.getBookCount());
			pst.setString(5, book.getBookISBN());
			
			int num = pst.executeUpdate();//执行
			
			if (num >= 0) {
				System.err.println("更新图书成功！！！");
			} else {
				System.err.println("更新图书失败...");
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				DBUtil.release(conn, pst, rs);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

	@Override
	public List<Book> findAllBooks() {
		// TODO Auto-generated method stub
		Connection conn = null;
		PreparedStatement pst = null;
		ResultSet rs = null;
		List<Book> books = new ArrayList<Book>();
		try {
			conn = DBUtil.getConnection();
			String sql = "select * from book";
			pst = conn.prepareStatement(sql);
			rs = pst.executeQuery();
			while (rs.next()) {
				Book book = new Book(rs.getString("book_isbn"), 
									 rs.getString("book_name"), 
									 rs.getDouble("book_price"), 
									 rs.getString("book_author"), 
									 rs.getInt("book_count")
							);
				books.add(book);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				DBUtil.release(conn, pst, rs);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return books;
	}

	@Override
	public void delBook(String bookISBN) {
		// TODO Auto-generated method stub
		Connection conn = null;
		PreparedStatement pst = null;
		ResultSet rs = null;
		try {
			conn = DBUtil.getConnection();
			String sql = "delete from book where book_isbn=?";
			pst = conn.prepareStatement(sql);
			
			// 在真正执行 sql 指令前，一定要确定 sql 指令中占位符的具体值
			pst.setString(1, bookISBN);
			
			int num = pst.executeUpdate();
			
			if (num >= 0) {
				System.err.println("删除图书成功！！！");
			} else {
				System.err.println("删除图书失败...");
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				DBUtil.release(conn, pst, rs);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

	@Override
	public Book findBookByISBN(String bookISBN) {
		// TODO Auto-generated method stub
		Connection conn = null;
		PreparedStatement pst = null;
		ResultSet rs = null;
		Book book = null;
		try {
			conn = DBUtil.getConnection();
			// 使用占位符？来占据要插入数据的位置，表示该数据目前尚不能确定，但此处一定会有数据，
			// 所以使用占位符先占据位置，后续再确定数值
			String sql = "select * from book where book_isbn=?";
			pst = conn.prepareStatement(sql);
			
			// 在真正执行 sql 指令前，一定要确定 sql 指令中占位符的具体值
			pst.setString(1, bookISBN);
			
			rs = pst.executeQuery();
			
			rs.next();
			book = new Book(rs.getString("book_isbn"), 
								 rs.getString("book_name"), 
								 rs.getDouble("book_price"), 
								 rs.getString("book_author"), 
								 rs.getInt("book_count"));
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				DBUtil.release(conn, pst, rs);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return book;
	}


	@Override
	public void buyBook(BookBuy buy){
		//sql = "update books set remain=remain-"+numBuy+" where id ="+idBuy;

		// TODO Auto-generated method stub
		Connection conn = null;
		PreparedStatement pst = null;
		ResultSet rs = null;
		try {
			conn = DBUtil.getConnection();
			// 使用占位符？来占据要插入数据的位置，表示该数据目前尚不能确定，但此处一定会有数据，
			// 所以使用占位符先占据位置，后续再确定数值
			String sql = "update book set book_count=book_count- ? where book_isbn=?";
			pst = conn.prepareStatement(sql);

			// 在真正执行 sql 指令前，一定要确定 sql 指令中占位符的具体值
			String tt= String.valueOf(buy.getNum());
			pst.setString(1,tt );
			pst.setDouble(2, buy.getId());


			int num = pst.executeUpdate();//执行

			if (num >= 0) {
				System.err.println("更新图书成功！！！");
			} else {
				System.err.println("更新图书失败...");
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			try {
				DBUtil.release(conn, pst, rs);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
