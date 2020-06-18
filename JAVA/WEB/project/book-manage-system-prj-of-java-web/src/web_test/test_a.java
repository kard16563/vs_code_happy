package web_test;

import test_dao.Colora;
import test_dao.student;

import java.util.HashMap;

public class test_a {
    public static void main(String[] args){
        student a1 = new student("0.123",11);
        a1.setAge(10);

        student a2 = new student("0.00",25);
        boolean comp =a1.equals(a2);

        Colora cc = Colora.GREEN;
        String ans=cc.getNam();
        a1.listMapPush("aa-1",a1);
        student bb = a1.listMapFind("aa-1");
        //bb.hashCode();

        bb.hashPut("bb", bb);

        a1.listAdd("000");
        a1.listAdd("111");
        a1.listAdd("222");

        a1.listCheckSize(1);
        a1.loopList();
        a1.listRemove(2);
        a1.listChange();

        System.out.println("okk-------->end");
        a1.print();

    }
}

/**
 * 看到treemap
 *
 * */
