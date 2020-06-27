//package web_c;
//
//import javax.servlet.ServletException;
//import javax.servlet.annotation.WebServlet;
//import javax.servlet.http.HttpServlet;
//import javax.servlet.http.HttpServletRequest;
//import javax.servlet.http.HttpServletResponse;
//import java.io.IOException;
//
//@WebServlet(name = "Servlet_login_jsp_test")
//public class Servlet_login_jsp_test extends HttpServlet {
//    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//        String userName = request.getParameter("userName");
//        String password = request.getParameter("password");
//        System.out.println("Servlet_login_jsp-》login username   "+userName+"password  "+password);
//        String aa=request.getContextPath();
//        System.out.println("getContextPath()-->  "+aa+"/loginDemo/hello.jsp");
//
//        System.out.println("1 "+request.getContextPath());
//        System.out.println("1 "+request.getServletPath());
//        System.out.println("1 "+request.getRequestURI());
//        System.out.println("1 "+request.getRealPath("/"));
//
//        //String aa=request.getContextPath();
//        //System.err.println(userName+";"+password);
//        String myUser = "kk";
//        String myPwd = "123";
//        if(userName.equals(myUser)&&password.equals(myPwd)) {
//            System.out.println("yes");
//            response.sendRedirect("./web_v/hello.jsp?userName="+userName);//路由改变
//        }else {
//            //request.setAttribute("message", "账密错误，请重新登录<br>");
//            System.out.println("no---");
//            request.getRequestDispatcher("./web_v/tt.jsp").forward(request,response);//路由不变
//            // request.getRequestDispatcher("/index.jsp").forward(request,response);
//        }
//    }
//
//    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//
//    }
//}
