import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Enumeration;

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

        //处理从服务器来的数据
        System.out.println("浏览器发出请求时的完整URL，包括协议 主机名 端口(如果有): " + request.getRequestURL());
        System.out.println("浏览器发出请求的资源名部分，去掉了协议和主机名: " + request.getRequestURI());
        System.out.println("请求行中的参数部分: " + request.getQueryString());
        System.out.println("浏览器所处于的客户机的IP地址: " + request.getRemoteAddr());
        System.out.println("浏览器所处于的客户机的主机名: " + request.getRemoteHost());
        System.out.println("浏览器所处于的客户机使用的网络端口: " + request.getRemotePort());
        System.out.println("服务器的IP地址: " + request.getLocalAddr());
        System.out.println("服务器的主机名: " + request.getLocalName());
        System.out.println("得到客户机请求方式: " + request.getMethod());
        Enumeration<String> headerNames= request.getHeaderNames();
        while(headerNames.hasMoreElements()){
            String header = headerNames.nextElement();
            String value = request.getHeader(header);
            System.out.printf("%s\t%s%n",header,value);
        }


        if ("admin".equals(name) && "123".equals(password))
            html = "<div style='color:green'>登录success</div>";
        else
            html = "<div style='color:red'>---登录fail</div>";

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
