<%--
  Created by IntelliJ IDEA.
  User: Lenovo
  Date: 2020/4/5
  Time: 21:31
  To change this template use File | Settings | File Templates.
--%>

<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>

<html>
<head>
    <title>Title</title>
</head>
<body>


<%
    application.setAttribute("test", 1);
    application.setAttribute("test", 2);
    application.removeAttribute("test");
%>


</body>
</html>
