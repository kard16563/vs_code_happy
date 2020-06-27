package web_c;

import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.FileUploadException;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;
import web_tools.test_register;


import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@WebServlet(name = "Servlet_register",urlPatterns = "/register")
public class Servlet_register extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.setCharacterEncoding("utf-8");
        response.setContentType("text/html;charset=utf-8");

        DiskFileItemFactory factory = new DiskFileItemFactory();
        ServletFileUpload upload = new ServletFileUpload(factory);
        upload.setHeaderEncoding("UTF-8");
        PrintWriter out = response.getWriter();
        Map params = new HashMap();
        String names="12346";
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

            String username = (String) params.get("name");
            String pass = (String) params.get("pass");
            String sel = (String) params.get("select");
            int select = Integer.parseInt(sel);

            test_register addCount =new test_register(username,pass,select);
            int ans = addCount.accountAdd();
            System.out.println("ans1-->"+ans);
            if (ans == 1){
                out.println("1");

            }else {
                out.println("0");

            }


        //System.out.println("name-> " +username+" pass-> "+pass+" select-> "+select);
        //out.println("12");


        //System.out.println("end --123");

        } catch (Exception e1) {
            e1.printStackTrace();
        }
        out.close();
        //response.sendRedirect("./web_v/normal_user/normal_welcome.html");

        System.out.println("end 233"+names);



    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {

        System.out.println("get");
        req.setCharacterEncoding("utf-8");
        resp.setContentType("text/html;charset=utf-8");
            //创建session
            HttpSession session=req.getSession(true);
             session.setAttribute("name", "周博");
    }
}
