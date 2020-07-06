package com.dao;

import com.bean.Cook;
import com.bean.CookOrder;

import java.util.List;

public interface imCookDao {

    // add
    public void cookAdd(Cook cook);

    //update
    public void cookUpdate(Cook cook);

    // show
    public List<Cook> cookShow();

    //order
    public void cookOrder(CookOrder order);

    //del
    public void cookDel(String dishName);

    //find
    public Cook findCook(String dishName);


}
