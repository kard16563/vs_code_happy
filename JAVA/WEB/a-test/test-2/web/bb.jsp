<%@ page import="java.util.Date" %><%--
  Created by IntelliJ IDEA.
  User: Lenovo
  Date: 2020/6/19
  Time: 9:26
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>

    <script src="https://unpkg.com/vue/dist/vue.js"></script>
    <script src="./vue-js/axios.min.js"></script>
</head>
<body>
<div id="app">
    123
    <%=new Date().toLocaleString()%>

    <%
        session.setAttribute("name", "123456");
    %>
    123456
</div>
</body>
<script type="text/javascript">

    // new Vue({
    //     el: '#app',
    //     data:
    //         {
    //
    //             value:"kard",
    //             currentDate: new Date(),
    //             //percentage:"70"
    //
    //         },
    //
    //
    //     methods: {
    //         handleClose(done) {
    //             this.$confirm('确认关闭？')
    //                 .then(_ => {
    //                     done();
    //                 })
    //                 .catch(_ => {});
    //         }
    //     }
    //
    // })
</script>
</html>
