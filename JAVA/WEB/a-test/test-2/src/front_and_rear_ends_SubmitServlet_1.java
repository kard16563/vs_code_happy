import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

import net.sf.json.JSONObject;

@WebServlet(name = "front_and_rear_ends_SubmitServlet_1",
        urlPatterns = "/submitServlet")
public class front_and_rear_ends_SubmitServlet_1 extends HttpServlet {
    protected void service(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        String data =request.getParameter("data");//接受名为data的东西

        System.out.println("服务端接收到的数据是：" +data);

        JSONObject json=JSONObject.fromObject(data);//对象解析

        System.out.println("转换为JSON对象之后是："+ json);

        Hero hero = (Hero)JSONObject.toBean(json,Hero.class);//对象转换
        System.out.println("转换为Hero对象之后是："+hero);
    }


//    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//
//    }
//
//    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//
//    }
}
