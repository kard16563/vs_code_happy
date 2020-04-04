import net.sf.json.JSONObject;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet(name = "GetOneServlet",urlPatterns = "/getOneServlet")
public class GetOneServlet extends HttpServlet {
    protected void service(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        Hero hero = new Hero();
        hero.setName("盖伦");
        hero.setHp(353);

        JSONObject json= new JSONObject();

        json.put("hero", JSONObject.fromObject(hero));//转为json
        //{"hero":{"hp":353,"name":"盖伦"}} 以hero只名来封装

        response.setContentType("text/html;charset=utf-8");
        response.getWriter().print(json);
    }


    //    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//
//    }
//
//    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//
//    }
}
