package web_c;

import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.FileUploadException;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;
import web_tools.test_jdbc;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@WebServlet(name = "Servlet_admain",urlPatterns = "/admain")
public class Servlet_admain extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        // 针对post请求，设置允许接收中文
        request.setCharacterEncoding("utf-8");
        response.setContentType("text/html;charset=utf-8");
        System.out.println("添加任务");
        PrintWriter out = response.getWriter();//用于输出
        String idView="" ;

        try {
            DiskFileItemFactory factory = new DiskFileItemFactory();
            ServletFileUpload upload = new ServletFileUpload(factory);
            upload.setHeaderEncoding("UTF-8");


            String filepath="E:\\the_c_of_vs_code\\JAVA\\WEB\\project\\book-manage-system-prj-of-java-web\\web\\upimg";
            File file = new File(filepath);

            if(!file.exists()) {
                file.mkdir();
            }
            SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd-HH-mm-ss");
            String time1 =df.format(new Date());
            //String tims= String.valueOf(System.currentTimeMillis());
            String tim=time1;

            Map params = new HashMap();

            List<FileItem> itemss= upload.parseRequest(request);


            for(Object object:itemss) {//obj类进行遍历

                FileItem item = (FileItem) object;//大类变小类

                System.out.println("----++++>"+filepath+"\\"+tim+item.getName());
                if(!item.isFormField()) {//如果是文件那么添加 文件的目录
                    item.write(new File(filepath+"\\"+tim+item.getName()));
                    idView = tim+item.getName();
                }
                if (item.isFormField()) {//如果不是文件 就解析
                    params.put(item.getFieldName(), item.getString("utf-8"));//如果你页面编码是utf-8的
                }

            }


            //使用params.get获取参数值
            String sendTime = (String) params.get("name");
            String note = (String) params.get("note");
            String remain = (String) params.get("remain");
            String price = (String) params.get("price");
            String recommendation=(String)params.get("recommendation");

            System.out.println("---->"+sendTime+" and "+
                    note+"-- src--->"+idView +
                    "-remain-"+remain+"-price-"+price+"-recommendation-"+recommendation
            );

            test_jdbc bookA= new test_jdbc(sendTime,idView, remain,price,recommendation);

                      int res= bookA.bookAdd();
            // 输出数据
            out.println(res);

        } catch (FileUploadException e1) {
            e1.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
        out.close();




    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {



    }
}
