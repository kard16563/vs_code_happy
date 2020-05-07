import net.sf.json.JSONObject;
import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.FileUploadException;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

@WebServlet(name = "VueUse",urlPatterns = "/vue")
public class VueUse extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//
        // 针对post请求，设置允许接收中文
        request.setCharacterEncoding("utf-8");
        response.setContentType("text/html;charset=utf-8");
        System.out.println("添加任务");
        PrintWriter out = response.getWriter();//用于输出

        try {
            DiskFileItemFactory factory = new DiskFileItemFactory();
            ServletFileUpload upload = new ServletFileUpload(factory);
            upload.setHeaderEncoding("UTF-8");

            String filepath="E:\\the_c_of_vs_code\\JAVA\\WEB\\a-test\\test-2\\web\\up2";
            File file = new File(filepath);
            if(!file.exists()) {
                file.mkdir();
            }

            Map params = new HashMap();

            List<FileItem> itemss= upload.parseRequest(request);

            for(Object object:itemss) {//obj类进行遍历

                FileItem item = (FileItem) object;//大类变小类

                System.out.println("----++++>"+filepath+"\\"+item.getName());
                if(!item.isFormField()) {//如果是文件那么添加 文件的目录
                    item.write(new File(filepath+"\\"+item.getName()));
                }
                if (item.isFormField()) {//如果不是文件 就解析
                    params.put(item.getFieldName(), item.getString("utf-8"));//如果你页面编码是utf-8的
                }

            }


            //使用params.get获取参数值
            String send_time = (String) params.get("name");
            String checkNum = (String) params.get("checkName");
            System.out.println("---->"+send_time+" and "+ checkNum );

            // 输出数据
            out.println("1");

        } catch (FileUploadException e1) {
            e1.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }
        out.close();







//        String testA1 = request.getParameter("name");
//            System.out.println("name->"+testA1+" ----> ");
//            response.getWriter().print(testA1);
    }



    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        String testA1="123456";
        System.out.println("vue");
        response.getWriter().print(testA1);//向请求方写入数据

    }
}

//request.setCharacterEncoding("utf-8");
//        response.setContentType("text/html;charset=utf-8");
//        System.out.println("添加任务");
//        PrintWriter out = response.getWriter();//用于输出
//
//        try {
//            DiskFileItemFactory factory = new DiskFileItemFactory();
//            ServletFileUpload upload = new ServletFileUpload(factory);
//            upload.setHeaderEncoding("UTF-8");
//
//            String filepath="./up2";
//            File file = new File(filepath);
//            if(!file.exists()) {
//                file.mkdir();
//            }
//            List<FileItem> itemss= upload.parseRequest(request);
//            for(FileItem item: itemss) {
//
//                System.out.println("----++++>"+filepath+"/"+item.getName());
//                if(!item.isFormField()) {
//                    item.write(new File(filepath+"/"+item.getName()));
//                }
//            }
//
//
//
//            List items = upload.parseRequest(request);
//
//            Map params = new HashMap();
//            for(Object object:items){
//                FileItem fileItem = (FileItem) object;
//
//
//                if (fileItem.isFormField()) {
//                    params.put(fileItem.getFieldName(), fileItem.getString("utf-8"));//如果你页面编码是utf-8的
//                }
//            }
//            //使用params.get获取参数值
//            String send_time = (String) params.get("name");
//            System.out.println("---->"+send_time);
//
//            // 输出数据
//            out.println("1");
//
//        } catch (FileUploadException e1) {
//            e1.printStackTrace();
//        } catch (Exception e) {
//            e.printStackTrace();
//        }
//        out.close();