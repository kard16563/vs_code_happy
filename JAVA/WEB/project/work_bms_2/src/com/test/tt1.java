package com.test;

import com.bean.Cook;
import com.dao.impl.CookDaoImpl;

import java.util.List;

public class tt1 {
    public static void main(String[] args){
        Cook cook = new Cook(1,2,3,"土豆");
        CookDaoImpl cc= new CookDaoImpl();

        List<Cook>  dd= cc.cookShow();
        System.out.println(dd);


    }
}
