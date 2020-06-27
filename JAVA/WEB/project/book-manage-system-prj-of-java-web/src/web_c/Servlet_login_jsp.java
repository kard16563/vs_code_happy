package web_c;

import web_tools.test_register;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;


@WebServlet(name = "Servlet_login_jsp",urlPatterns = "/loginDemo")
public class Servlet_login_jsp extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        String userName = request.getParameter("userName");
        String password = request.getParameter("password");

        HttpSession session = request.getSession();
        session.setAttribute("username-login",userName);

        System.out.println("Servlet_login_jsp-》login username   "+userName+"password  "+password);
        String aa=request.getContextPath();
        System.out.println("getContextPath()-->  "+aa+"/loginDemo/hello.jsp");

//        System.out.println("1 "+request.getContextPath());
//        System.out.println("1 "+request.getServletPath());
//        System.out.println("1 "+request.getRequestURI());
//        System.out.println("1 "+request.getRealPath("/"));


//        String myUser = "kk";
//        String myPwd = "123";
        test_register count =new test_register(userName,password);
        int ans = count.accountCheck();
        System.out.println("ans  "+ans);

        if(ans>0) {

            if(ans == 1){
                response.sendRedirect("./web_v/normal_user/normal_welcome.html");

            }else {
                System.out.println("yes");

                response.sendRedirect("./web_v/admin/admain_welcome.html");//路由改变
            }
        }else {

            System.out.println("no---");
            request.setAttribute("message", "账密错误，请重新登录<br>");

            request.getRequestDispatcher("./web_v/tt.jsp").forward(request,response);//路由不变


        }


    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
