<%--
  Created by IntelliJ IDEA.
  User: Lenovo
  Date: 2020/6/19
  Time: 17:54
  To change this template use File | Settings | File Templates.
--%>
<%--<%@ page contentType="text/html;charset=UTF-8" language="java" %>--%>
<%--<html>--%>
<%--<head>--%>
<%--    <title>Title</title>--%>
<%--</head>--%>
<%--<body>--%>

<%--</body>--%>
<%--</html>--%>

<%@ page language="java" contentType="text/html; charset=UTF-8"

         pageEncoding="UTF-8"%>

<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>欢迎</title>
</head>
<body>



完整日期: <fmt:formatDate value="${now}" pattern="G yyyy年MM月dd日 E"/><br>
完整时间: <fmt:formatDate value="${now}" pattern="a HH:mm:ss.S z"/><br>
常见格式: <fmt:formatDate value="${now}" pattern="yyyy-MM-dd HH:mm:ss"/>

Hello:<br>
<font color="green" size="22">
    <%
        out.print(request.getParameter("userName")+"<br>");
    %>
</font>
<a href="./normal_user/normal_welcome.html">重新登录</a>
</body>

</html>
