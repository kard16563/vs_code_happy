import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "Login2",urlPatterns = "/login2")
public class Login2 extends HttpServlet {

    //这个实际上，在执行doGet()或者doPost()之前，都会先执行service()
    //由service()方法进行判断，到底该调用doGet()还是doPost()
    //所以，有时候也会直接重写service()方法，在其中提供相应的服务，就不用区分到底是get还是post了。

    protected void service(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        String name = request.getParameter("name");
        String password = request.getParameter("password");

        String html = null;

        if ("admin".equals(name) && "123".equals(password)) {
            request.getRequestDispatcher("success.html").forward(request, response);
        }
        else{
            response.sendRedirect("login_fail.html");
        }

    }


//    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//
//    }  默认为get方法
//
//    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//
//    }一般传递大文件为post方法
}
