import net.sf.json.JSONSerializer;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

@WebServlet(name = "front_rear_GetManyServlet",
        urlPatterns = "/getManyServlet")
public class front_rear_GetManyServlet extends HttpServlet {

    protected void service(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {

        List<Hero> heros = new ArrayList<>();

        for (int i = 0; i < 10; i++) {
            Hero hero = new Hero();
            hero.setName("name"+i);
            hero.setHp(500+i);
            heros.add(hero);
        }

        String result =JSONSerializer.toJSON(heros).toString();
        String result2 =JSONSerializer.toJSON(heros).toString();

        response.setContentType("text/html;charset=utf-8");

        response.getWriter().print(result);
        //response.getWriter().print(result2);
        //response.getWriter().
        //response.getWriter().printf("data2",result2);

        System.out.println("222222");

    }
//    public static void main(String[] args) {
//        System.out.println("222222----------");
//        List<Hero> heros = new ArrayList<>();
//        for (int i = 0; i < 10; i++) {
//            Hero hero = new Hero();
//            hero.setName("name"+i);
//            hero.setHp(500+i);
//            heros.add(hero);
//        }
//
//        System.out.println(JSONSerializer.toJSON(heros).toString());
//    }



//    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//
//    }
//
//    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//
//    }
}
