package web;

import test_dao.Colora;
import test_dao.student;

public class test_a {
    public static void main(String[] args){
        student a1 = new student("0.123",11);
        Colora cc = Colora.GREEN;
        String ans=cc.getNam();

        System.out.println("okk");
        a1.print();

    }
}
