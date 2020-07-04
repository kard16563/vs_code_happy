package com.software.bean;

/**
 * @author Lenovo
 */
public class Book {//数据库的类
	private int bookID;
	private String bookISBN;
	private String bookName;
	private double bookPrice;
	private String bookAuthor;
	private int bookCount;
	public int getBookID() {
		return bookID;
	}
	public void setBookID(int bookID) {
		this.bookID = bookID;
	}
	public String getBookISBN() {
		return bookISBN;
	}
	public void setBookISBN(String bookISBN) {
		this.bookISBN = bookISBN;
	}
	public String getBookName() {
		return bookName;
	}
	public void setBookName(String bookName) {
		this.bookName = bookName;
	}
	public double getBookPrice() {
		return bookPrice;
	}
	public void setBookPrice(double bookPrice) {
		this.bookPrice = bookPrice;
	}
	public String getBookAuthor() {
		return bookAuthor;
	}
	public void setBookAuthor(String bookAuthor) {
		this.bookAuthor = bookAuthor;
	}
	public int getBookCount() {
		return bookCount;
	}
	public void setBookCount(int bookCount) {
		this.bookCount = bookCount;
	}
	@Override
	public String toString() {
		return "Book [bookID=" + bookID + ", bookISBN=" + bookISBN + ", bookName=" + bookName + ", bookPrice="
				+ bookPrice + ", bookAuthor=" + bookAuthor + ", bookCount=" + bookCount + "]";
	}
	public Book(int bookID, String bookISBN, String bookName, double bookPrice, String bookAuthor, int bookCount) {
		super();
		this.bookID = bookID;
		this.bookISBN = bookISBN;
		this.bookName = bookName;
		this.bookPrice = bookPrice;
		this.bookAuthor = bookAuthor;
		this.bookCount = bookCount;
	}
	public Book(String bookISBN, String bookName, double bookPrice, String bookAuthor, int bookCount) {
		super();
		this.bookISBN = bookISBN;
		this.bookName = bookName;
		this.bookPrice = bookPrice;
		this.bookAuthor = bookAuthor;
		this.bookCount = bookCount;
	}
	public Book() {
		super();
		// TODO Auto-generated constructor stub
	}
	
}
