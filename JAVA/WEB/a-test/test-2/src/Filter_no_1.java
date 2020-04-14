import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;


//Filter就像一个一个哨卡，用户的请求需要经过Filter 并且可以有多个过滤器
@WebFilter(filterName = "Filter_no_1",urlPatterns = "/*")
public class Filter_no_1 implements Filter {

    @Override
    public void destroy() {
        System.out.println("out---->");

    }

    @Override
    public void doFilter(ServletRequest req, ServletResponse res, FilterChain chain)
            throws IOException, ServletException {

        //doFilter方法的第一个参数req,是ServletRequest 类型的，
        // 不支持setCharacterEncoding，所以要先强制转换为HttpServletRequest

        HttpServletRequest request = (HttpServletRequest) req;
        // 先强制转化为HttpServletRequest
        HttpServletResponse response = (HttpServletResponse) res;

        String ip = request.getRemoteAddr();
        String url = request.getRequestURL().toString();
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        Date d = new Date();
        String date = sdf.format(d);

        request.setCharacterEncoding("UTF-8");//编码

        System.out.printf("%s %s 访问了 %s%n", date, ip, url);
        chain.doFilter(request, response);
        //他的作用是将请求转发给过滤器链上下一个对象。这里的下一个指的是下一个filter，如果没有filter那就是你请求的资源
    }

    @Override
    public void init(FilterConfig arg0) throws ServletException {
        System.out.println("ok---->");

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
