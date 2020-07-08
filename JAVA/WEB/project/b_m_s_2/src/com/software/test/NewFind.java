package com.software.test;

import com.software.bean.Book;
import com.software.util.DBUtil;
import com.software.util.NewDbutil;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class NewFind {

    public static void main(String[] args){

        Connection conn = null;
        PreparedStatement pst = null;
        ResultSet rs = null;
        try {
            conn = NewDbutil.getConnection();
            String sql = "select * from test_1";
            pst = conn.prepareStatement(sql);
            rs = pst.executeQuery();
            while (rs.next()) {
                System.out.println(rs.getInt("id")+"--"+
                        rs.getString("name")+
                        rs.getInt("age"));



            }
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } finally {
            try {
                DBUtil.release(conn, pst, rs);
            } catch (SQLException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }




    }
}
