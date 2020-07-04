<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>更新图书信息</title>
</head>

<style>
    #aa{
        width:450px;
        position: absolute;
        left:45%;
        top:50%;
        margin-left:-100px;
        margin-top:-100px;

    }
</style>
<body>

    <div id="aa">
    <form action="BookUpdateServlet" method="post">
        <div>
            <label for="book_isbn">图书ISBN:</label>
            <input type="text" id="book_isbn" name="book_isbn" value="${book.bookISBN }" readonly="readonly">
        </div>
        <div>
            <label>图书名称:</label>
            <input type="text" name="book_name" value="${book.bookName }">
        </div>
        <div>
            <label>图书价格:</label>
            <input type="text" name="book_price" value="${book.bookPrice }">
        </div>
        <div>
            <label>图书作者:</label>
            <input type="text" name="book_author" value="${book.bookAuthor }">
        </div>
        <div>
            <label>图书数量:</label>
            <input type="text" name="book_count" value="${book.bookCount }">
        </div>
        <input type="submit" value="提交">
    </form>

    </div>
</body>
</html>