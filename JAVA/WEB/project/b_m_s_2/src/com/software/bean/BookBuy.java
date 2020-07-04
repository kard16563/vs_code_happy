package com.software.bean;

/**
 * @author Lenovo
 */
public class BookBuy {
    private int num;
    private int id;


    public BookBuy(int num, int id) {
        super();
        this.num = num;
        this.id = id;
    }


    public BookBuy() {

        super();

    }




    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
    }
}
