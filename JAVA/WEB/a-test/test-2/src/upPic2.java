import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.*;
import java.util.List;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.commons.fileupload.FileItem;
import org.apache.commons.fileupload.FileUploadException;
import org.apache.commons.fileupload.disk.DiskFileItemFactory;
import org.apache.commons.fileupload.servlet.ServletFileUpload;
@WebServlet(name = "upPic2",urlPatterns = "/upPic2")
public class upPic2 extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {


        String filename = null;
        //String ps;
        try {
            DiskFileItemFactory factory = new DiskFileItemFactory();
            ServletFileUpload upload = new ServletFileUpload(factory);
            // 设置上传文件的大小限制为1M
            factory.setSizeThreshold(30240 * 30240);

            List items = null;
            try {
                items = upload.parseRequest(request);//准备封装为 item
            } catch (FileUploadException e) {
                e.printStackTrace();
            }

            Iterator iter = items.iterator();//把item变为链表
            while (iter.hasNext()) {//遍历item
                FileItem item = (FileItem) iter.next();
                if (!item.isFormField()) {

                    // 根据时间戳创建头像文件
                    filename = System.currentTimeMillis() + ".jpg";
                    System.out.println(filename);

                    //通过getRealPath获取上传文件夹，如果项目在e:/project/j2ee/web,那么就会自动获取到 e:/project/j2ee/web/uploaded

                    String photoFolder =request.getServletContext().getRealPath("uploaded");
                    System.out.println("photoFolder -- "+photoFolder);
                    System.out.println("request.getServletContext() -- "+request.getServletContext());

                    String pf="E:\\the_c_of_vs_code\\JAVA\\WEB\\a-test\\test-2\\web\\uploaded\\";
                    //ps=pf;
                    pf=pf+filename;

                    System.out.println(photoFolder);
                    System.out.println(pf);

                    File f = new File(pf);

                    f.getParentFile().mkdirs();
                    System.out.println("f.getParentFile()-"+f.getParentFile());

                    // 通过item.getInputStream()获取浏览器上传的文件的输入流
                    InputStream is = item.getInputStream();

                    // 复制文件
                    FileOutputStream fos = new FileOutputStream(f);
                    byte b[] = new byte[30240 * 30240];
                    int length = 0;
                    while (-1 != (length = is.read(b))) {
                        fos.write(b, 0, length);
                    }
                    fos.close();//文件件正式复制完毕

                    System.out.println("ok close--->");


                } else {
                    System.out.println("83-"+item.getFieldName());
                    String value = item.getString();
                    value = new String(value.getBytes("ISO-8859-1"), "UTF-8");
                    System.out.println("86-"+value);
                }
            }


            //String html = "<img width='300' height='250' src='./uploaded/1585909912253.jpg' />";
            String html = "<img width='300' height='250' src='./uploaded/%s' />";
            response.setContentType("text/html");
            PrintWriter pw= response.getWriter();
            System.out.println("filename-> "+filename);
            String tem=String.format(html,filename);
            System.out.println("tem-> "+tem);


            pw.write(tem);

            //pw.format(html, filename);

        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (Exception e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }


    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("application/json");
        response.setCharacterEncoding("UTF-8");
        request.setCharacterEncoding("UTF-8");
        PrintWriter out = response.getWriter();

        String testA1="<img width='937' height='495' src='./uploaded/1585910545398.jpg' alt='123'/>";
        System.out.println("vue------>get");
        //out.write(testA1);
        out.write("{" +
                "\"pic1\":\"p1\""+","+
                "\"pic2\":\"p2\""+","+
                "\"pic3\":\"p3\"" +","+
                "}");
        /*

        out.write("{" +
                "pic1:p1" +
                "pic2:p2" +
                "pic3:p3" +
                "}");
         *out.write("{" +
                "pic1:p1" +
                "pic2:\"p2" +
                "\"pic3\":\"p3\"" +
                "}");
         * 向请求方写入数据
         * */

    }
}
