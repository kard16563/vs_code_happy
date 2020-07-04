<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>展示所有图书信息</title>
</head>

<style>
    #aa{
        width:450px;
        /*height: 200px;*/
        /*background:green;*/
        position: absolute;
        left:42%;
        top:50%;
        margin-left:-100px;
        margin-top:-100px;

    }
</style>
<body>

    <div id="aa">
    <table border="1" cellspacing="0">
        <tr>
            <th>图书ISBN</th>
            <th>图书名称</th>
            <th>图书价格</th>
            <th>图书作者</th>
            <th>图书数量</th>
        </tr>
        <c:forEach items="${books }" var="book">
        <tr>
            <td>${book.bookISBN }</td>
            <td>${book.bookName }</td>
            <td>${book.bookPrice }</td>
            <td>${book.bookAuthor }</td>
            <td>${book.bookCount }</td>
            <td><a href="BookUpdateUIServlet?bookISBN=${book.bookISBN }">更新</a> | <a href="BookDelServlet?bookISBN=${book.bookISBN }">删除</a></td>
        </tr>
        </c:forEach>
    </table>

    </div>
    
        
    
</body>
</html>