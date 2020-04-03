import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "Response",urlPatterns = "/response")
public class Response extends HttpServlet {
//    public   void  init(){//禁止使用缓存
//        try {
//            response.setDateHeader("Expires", 0);
//            response.setHeader("Cache-Control", "no-cache");
//            response.setHeader("pragma", "no-cache");
//            response.getWriter().println("<h1>Hello Servlet!</h1>");
//            response.getWriter().println(new Date().toLocaleString());
//        } catch (IOException e) {
//
//            e.printStackTrace();
//        }
//    }
//
 //   }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        String name = request.getParameter("name");

        if ("admin".equals(name) ) {

            try {
                System.out.println("post--");
                PrintWriter pw = response.getWriter();
                pw.println("<h1>下载啦</h1>");

                response.setContentType("pp/lol");//设定格式 浏览器不能识别  这样的手段也就常常用于实现下载功能
            } catch (IOException e) {

                e.printStackTrace();
            }


           // request.getRequestDispatcher("success.html").forward(request, response);
        } else {
            response.setStatus(301);// 返回301 错误
            response.setHeader("Location", "login_fail.html");
        }




    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        System.out.println("get--");

        response.setContentType("text/html; charset=UTF-8");//不仅发送到浏览器的内容会使用UTF-8编码，而且还通知浏览器使用UTF-8编码方式进行显示。所以总能正常显示中文
//          response.setCharacterEncoding("UTF-8"); //仅仅是发送的浏览器的内容是UTF-8编码的，至于浏览器是用哪种编码方式显示不管。 所以当浏览器的显示编码方式不是UTF-8的时候，就会看到乱码，需要手动再进行一次设置。
// 编码在处理治之前

        PrintWriter pw = response.getWriter();
        pw.println("<h1>第一次 使用 Servlet</h1>");

    }
    }

