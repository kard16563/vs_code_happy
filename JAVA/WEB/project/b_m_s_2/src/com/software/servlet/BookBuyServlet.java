package com.software.servlet;

import com.software.bean.BookBuy;
import com.software.dao.IBookDao;
import com.software.dao.impl.BookDaoImpl;
import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.io.IOException;

/**
 * @author Lenovo
 */
@WebServlet("/BookBuyServlet")
public class BookBuyServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        request.setCharacterEncoding("UTF-8");
        response.setCharacterEncoding("UTF-8");
        response.setContentType("text/html; charset=UTF-8");
        System.out.println("ok");

        String data =request.getParameter("data");//接受名为data的东西

        System.out.println("服务端接收到的数据是：" +data);
        String tt ="%s";
        data = String.format(tt,data);
        System.out.println("服务端接收到的数据是：2 ->" +data);


        //String aa ="[{\"id\":11111,\"num\":3},{\"id\":5555,\"num\":2}]";
        JSONArray json = JSONArray.fromObject(data);
        System.out.println(json);
        for (Object in : json){
            JSONObject obj = JSONObject.fromObject(in);
            System.out.println("id:-->" + obj.get("id"));
            System.out.println("转换为JSON对象之后是：---->"+ obj);
            BookBuy buy = (BookBuy) JSONObject.toBean(obj,BookBuy.class);
            IBookDao bookDao = new BookDaoImpl();
            bookDao.buyBook(buy);

        }



//        System.out.println("转换为JSON数组之后是：");
//        JSONArray json = JSONArray.fromObject(data);
//        System.out.println("转换为JSON数组之后是："+ json);
//        for (Object in : json){
//            JSONObject obj = JSONObject.fromObject(in);
//            BookBuy buy = (BookBuy) JSONObject.toBean(obj,BookBuy.class);
//
//            System.out.println("转换为JSON对象之后是：---->"+ buy);
//        }
//       // JSONArray json = JSONArray.fromObject(data);
//
//
//        System.out.println("转换为JSON数组之后是："+ json);
//

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

//        String bookISBN = request.getParameter("book");
//        System.out.println("---->"+bookISBN);
//        Cookie mycookies[] = request.getCookies();
//        System.out.println(mycookies.length);
//        // 获取session
//        HttpSession session = request.getSession();
//// 获取session传过来的值
//        String s=(String)session.getAttribute("books");
//        System.out.println("session的字段名 " +s);
//
//
//        for (int i = 0; i < mycookies.length; i++) {
//            System.out.println(mycookies[i].getName());
//        }
////             if ("uid".equalsIgnoreCase(mycookies[i].getName())) {
////                    uid=mycookies[i].getValue();
////                }
////        }

    }
}
