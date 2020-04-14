import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
                                     //urlPatterns = "/a/*"
@WebFilter(filterName = "Filter_no_2",urlPatterns = "/a/*")
public class Filter_no_2 implements Filter {

    @Override
    public void destroy() {

    }

    @Override
    public void doFilter(ServletRequest req, ServletResponse res, FilterChain chain)
            throws IOException, ServletException {

        System.out.println("fliter 2");
        HttpServletRequest request = (HttpServletRequest) req;
        HttpServletResponse response = (HttpServletResponse) res;

        String uri = request.getRequestURI();

        //首先判断是否是访问的login.html和loginHero，
        // 因为这两个页面就是在还没有登陆之前就需要访问的
        //http://localhost:8080/a/login.html hu
        if (uri.endsWith("login.html") || uri.endsWith("login")) {
            chain.doFilter(request, response);
            System.out.println("fie 2-2");
            //response.sendRedirect("login.html");

            return;
        }

        //从Session中获取userName，如果没有，就表示不曾登陆过，跳转到登陆页面。
        //http://localhost:8080/a

        String userName = (String) request.getSession().getAttribute("userName");
        if (null == userName) {
            System.out.println("fie 2-3");
            //response.sendRedirect("/login.html");//重定向跳转
            //--?http://localhost:8080/a/login.html--->无该文件
            System.out.println(request.getContextPath()+"--/Test.jsp  与下面的一样");//服务器跳转
            request.getRequestDispatcher("/login.html").forward(request, response);
            return;
        }

        chain.doFilter(request, response);
    }

    @Override
    public void init(FilterConfig arg0) throws ServletException {

    }

//    public void destroy() {
//    }
//
//    public void doFilter(ServletRequest req, ServletResponse resp, FilterChain chain) throws ServletException, IOException {
//        chain.doFilter(req, resp);
//    }
//
//    public void init(FilterConfig config) throws ServletException {
//
//    }

}
