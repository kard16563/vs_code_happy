import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(name = "MY-self-init",urlPatterns = "/init",loadOnStartup=1)
public class MYselfinit extends HttpServlet {

    public void init() throws ServletException{
        System.out.println("== 初始化 用于数据库啥的 ==");
    }

    protected void service(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        System.out.println("== 工作区 ==");

    }

    //    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//
//    }
//
//    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//
//    }
}
