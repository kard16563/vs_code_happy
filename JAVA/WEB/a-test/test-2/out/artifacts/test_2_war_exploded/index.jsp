<%--
  Created by IntelliJ IDEA.
  User: Lenovo
  Date: 2020/3/17
  Time: 9:30
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
  <head>
    <title>$Title$</title>
  </head>
  <body>
  <h1>hello world666 </h1>

  <%
    String name = (String)session.getAttribute("name");
  %>
  session中的name: <%=name%>
  </body>
</html>
