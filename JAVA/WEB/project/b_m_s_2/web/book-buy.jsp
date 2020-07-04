<%@ page import="java.util.List" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="com.software.bean.Book" %><%--
  Created by IntelliJ IDEA.
  User: Lenovo
  Date: 2020/7/3
  Time: 22:28
  To change this template use File | Settings | File Templates.
--%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8" import="javax.servlet.http.Cookie"%>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<html>
<head>
    <title>购买图书</title>
    <script src="https://cdn.staticfile.org/jquery/1.10.2/jquery.min.js">
    </script>

</head>
<style>


    #aa{
        width:450px;
        /*height: 300px;*/
        /*background:green;*/
        position: absolute;
        left:40%;
        top:50%;
        margin-left:-100px;
        margin-top:-100px;

    }
    #bb{
        position:absolute;
        left:50%;
        top:50%;
    }
</style>
<body>



<div id="aa">


    <table border="1" cellspacing="0" >
        <tr>
            <th>图书ISBN</th>
            <th>图书名称</th>
            <th>图书价格</th>
            <th>图书作者</th>
            <th>图书数量</th>
            <th><button onclick="up()">上传</button> </th>
        </tr>
        <c:forEach items="${books}" var="book">
            <tr>
                <td>${book.bookISBN }</td>
                <td>${book.bookName }</td>
                <td>${book.bookPrice }</td>
                <td>${book.bookAuthor }</td>
                <td>${book.bookCount }</td>
                <td>
<%--                    <a href="BookUpdateUIServlet?bookISBN=${book.bookISBN }">更新</a>--%>
                    <input id="" type="button" onclick="a(${book.bookISBN},${book.bookPrice });" value="订阅"/></td>
            </tr>
        </c:forEach>
    </table>



</div>

</body>

<script language="JavaScript">
    var sum=0;
    var bookid = new Array();
    var book = new Object();

    var flag =0;
    var temp =0;
    var jsonStr=0;

    function a(id,price){

        sum += price;
        document.cookie = "sum" + "=" +sum;

        console.log("beg -> ",bookid);
        var num=1;


        for(j = 0,len=bookid.length; j < len; j++) {
            console.log('1 for->',bookid[j],"id-->",j,
                "**",bookid[j].id,"id ", id,"tp2 ",typeof bookid[j].id);

            if ((bookid[j].id - id)==0){
                console.log("id ",bookid[j].id,id);
                console.log("okk");
                temp=j;
                flag = 1;
                break;
            }else {
                console.log("no");
                flag =0;

            }

        }

        if(flag == 0){

            bookid.push({ 'id':id,'num':num});
            flag =1;
        }else {

            bookid[temp].num +=1;
            console.log("2nonono")
        }
        jsonStr = JSON.stringify(bookid);
        localStorage.setItem("book",jsonStr);
        console.log("loc--> ",localStorage.getItem("book"));//输出


        console.log(typeof price,"---> ",sum,"-->",bookid);

    }


    function up(){
        var url="/BookBuyServlet";


        $.post(
            url,
            {

                "data":jsonStr
            });

        console.log("66666");


    }
</script>

</html>
