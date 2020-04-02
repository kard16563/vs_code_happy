import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(urlPatterns = "/login")
public class Login extends HttpServlet {

//    public Login(){
//        System.out.println("Login 构造方法 被调用 0 实例化");
//    }



    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
    //request  从HTML来的数据  response 给HTML的
        System.out.println(" 2 接下来就是执行service()方法，然后通过浏览器传递过来的信息进行判断，是调用doGet()还是doPost()方法\n" +
                            "\n" + "在service()中就会编写我们的业务代码，在本例中就是判断用户输入的账号和密码是否正确");

        String name = request.getParameter("name");

         byte[] bytes = name.getBytes("ISO-8859-1");//解码
         name = new String(bytes, "UTF-8");//再进行编码

        String password = request.getParameter("password");
        String html = null;

        if ("admin".equals(name) && "123".equals(password))
            html = "<div style='color:green'>登录success</div>";
        else
            html = "<div style='color:red'>登录fail</div>";

        response.setContentType("text/html; charset=UTF-8");//utf-8 编码发送中文
        PrintWriter pw = response.getWriter(); /*传回数据*/
        pw.println(html);

        System.out.println("name:" + name);
        System.out.println("password:" + password);
    }

    public void init(ServletConfig config) {
        System.out.println("1  init(ServletConfig)"+"1 初始化");
    }

    public void destroy() {
        System.out.println(" 3 end -- destroy()");
    }





}
