package cn.mam.practice;

public class p_Array {

    public static void main(String[] args) {

        int [] testA1 = new int[10];

        System.out.println("len -> "+testA1.length);

        for ( int i = 0 ; i < testA1.length ; i = i + 1 ){
            testA1[i]=i;
            System.out.println("aa-->"+i);
        }

        int [] testA2 = { 1,2,3,4 }; //初始值的简化书写形式



        for ( int ele : testA1 ){//定义一个变量 ele 用于暂存集合testA1中的每一个元素

            System.out.println("-->"+ele);

        }

    }

}
