package web_c;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;
import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;
import web_tools.test_jdbc;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@WebServlet(name = "Servlet_normal_user",urlPatterns = "/Servlet_normal_user")
public class Servlet_normal_user extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        response.setContentType("text/html;charset=utf-8");

        DiskFileItemFactory factory = new DiskFileItemFactory();
        ServletFileUpload upload = new ServletFileUpload(factory);
        upload.setHeaderEncoding("UTF-8");
        PrintWriter out = response.getWriter();
        Map params = new HashMap();
        //String names="12346";
//        HttpSession session = request.getSession(true);
//        session.setAttribute("555",6666);

        try {

            List<FileItem> itemss= upload.parseRequest(request);

            for(Object object:itemss) {

                FileItem item = (FileItem) object;

                if (item.isFormField()) {
                    params.put(item.getFieldName(), item.getString("utf-8"));
                }
            }
            //使用params.get获取参数值

            //JsonArray jsonArray = (JsonArray) new JsonParser().parse(json字符串);//
            String note =(String)params.get("note");
            String tt="admin";
            String msg = (String) params.get("data");
            test_jdbc buyBook=new test_jdbc(msg);
            if (note.equals(tt)){
                System.out.println("书籍补充 ");
                buyBook.bookNumChange(1);
            }else {
                System.out.println("书籍购买 ");

                buyBook.bookNumChange(0);
            }

//            JSONArray json = JSONArray.fromObject(data);
//            int num =json.size();
//            System.out.println("--->j"+json.get(0)+"数量"+ num);
//            JSONObject obj = JSONObject.fromObject(json.get(0));
//
          System.out.println("data-> " +msg);
            out.println("12");


            System.out.println("end --123");

        } catch (Exception e1) {
            e1.printStackTrace();
        }

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        request.setCharacterEncoding("UTF-8");
        PrintWriter out = response.getWriter();
        String aa = "\"../../upimg/222.jpg\"";

        test_jdbc getBooks = new test_jdbc();
        String book=getBooks.bookList();

                out.write(book);

        //String bookList =

//        out.write("{" +
//                "\"pic1\":\"p1\""+","+
//                "\"pic2\":\"p2\""+","+
//                "\"pic3\":\"p3\"" +
//                "}");


//        out.write("["+
//                "{"+ "\"id\":0" +","+
//                "\"idView\":"+"\"../../upimg/222.jpg\"" +","+
//                " \"remain\":60"+","+"\"name\":"+"\"book_1\""+","+"\"price\":10"+ ","+"\"recommendation\":"+"\"世卫组织称世界处于新的危险阶段\""+
//
//                "}"+","
//                +
//                "{"+ "\"id\":1" +","+
//                "\"idView\":"+"\"../../upimg/222.jpg\"" + ","+
//                " \"remain\":60"+","+"\"name\":"+"\"book_1\""+","+"\"price\":10"+  ","+"\"recommendation\":"+"\"世卫组织称世界处于新的危险阶段\""+
//                "}"+","
//                +
//                "{"+ "\"id\":2" +","+
//                "\"idView\":"+"\"../../upimg/222.jpg\"" +","+
//                " \"remain\":60"+","+"\"name\":"+"\"book_1\""+","+"\"price\":10"+  ","+"\"recommendation\":"+"\"世卫组织称世界处于新的危险阶段\""+
//
//                "}"+","
//                +
//                "{"+ "\"id\":3" +","+
//                "\"idView\":"+aa +","+
//                " \"remain\":60"+","+"\"name\":"+"\"book_1\""+","+"\"price\":10"+ ","+"\"recommendation\":"+"\"世卫组织称世界处于新的危险阶段\""+
//
//                "}"
//
//                +']');

//        out.write("["+
//                "{"+ "\"id\":0" +","+
//                         "\"idView\":"+"\"../../upimg/222.jpg\"" +
//
//                "}"+","
//                +
//                "{"+ "\"id\":1" +","+
//                "\"idView\":"+"\"../../upimg/222.jpg\"" +
//                "}"+","
//                +
//                "{"+ "\"id\":2" +","+
//                "\"idView\":"+"\"../../upimg/222.jpg\"" +
//                "}"+","
//                +
//                "{"+ "\"id\":3" +","+
//                "\"idView\":"+aa +
//                "}"
//
//                +']');

    }
}
