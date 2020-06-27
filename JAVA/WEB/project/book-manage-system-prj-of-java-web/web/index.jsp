<%@ page import="java.util.Date" %><%--
  Created by IntelliJ IDEA.
  User: Lenovo
  Date: 2020/6/11
  Time: 20:17
  To change this template use File | Settings | File Templates.
--%>
<%--<%@ page contentType="text/html;charset=UTF-8" language="java" %>--%>
<%--<html>--%>
<%--  <head>--%>
<%--    <title>$Title$</title>--%>
<%--  </head>--%>
<%--  <body>--%>
<%--  abcedeadsd--%>
<%--  </body>--%>
<%--</html>--%>



<%@ page language="java" contentType="text/html; charset=UTF-8"

         pageEncoding="UTF-8"%>

<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/fmt"  prefix='fmt' %>



<!DOCTYPE html>

<html>

<head>

    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">

    <title>标题</title>

    <style type="text/css">
        *{margin: 0;padding: 0;}
        form{margin: 0 auto;padding:15px; width: 300px;height:100px;text-align: center;}
        #submit{padding: 10px}

        #submit input{width: 50px;height: 24px;}


        body{

            background: url("./b_index.jpg") ;
            background-position: center center;

            background-repeat: no-repeat;

            background-attachment: fixed;

            background-size: cover;




        }


    </style>

</head>

<style type="text/css">


    .min{
        margin:0 auto;
        text-align:center;
    }
</style>

<body style="text-align: center">







<div class="wrapper">
    <%
        Date now = new Date();
        pageContext.setAttribute("now",now);
    %>
    <p>当前的时间</p> <fmt:formatDate value="${now}" pattern="a HH:mm:ss.S z"/><br>

    <form action="<%=request.getContextPath()%>/loginDemo" method="post">
        <label>用户名:</label>
        <input type="text" name="userName" value="${param.userName}"/>

        <br><br>

        <label>密码：</label>
        <input type="password" name="password"/><br>
        <font color="red">
            <%
                if(request.getAttribute("message")!= null){
                    out.print(request.getAttribute("message"));
                }
            %>
        </font>

        <div id="submit">
            <input type="submit" value="登录"/>
        </div>
    </form>
    <p>没有就点击注册吧<p>
    <button  onclick="window.location.href='./web_v/register.html'">注册</button>
<%--    <button onclick="window.location.href='./web_v/tt.jsp'">点击跳bai转</button>--%>


</div>

</body>



</html>

