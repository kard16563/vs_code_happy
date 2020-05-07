package cn.mam.practice;

import java.util.Date;
import java.util.Scanner;

public class p_input_and_output {

    public static  void main(String[] args){
        Scanner testIn = new Scanner(System.in);//用给定的输人流创建一个 Scanner 对象。
        System.out.println("what is your name ?");
        String testName = testIn.nextLine();
        System.out.println("get your name "+testName);

        double testNumX = 1000/3;
        System.out.printf("%6.2f your name is %s time %tc",testNumX,testName,new Date());

        //Scanner in = new Scanner(Paths.get("c:\\mydirectory\\myfile.txt"), "UTF-8")
        // 要想对文件进行读取，就需要一个用 File 对象构造一个 Scanner 对象







    }

}
