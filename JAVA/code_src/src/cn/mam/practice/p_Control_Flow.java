package cn.mam.practice;
//Control Flow
//流程控制

public class p_Control_Flow {
    public  static  void main(String[] args){

        int testA1 = 10 ;
        int testA2 = 20 ;
         if ( testA1 >= testA2 ){
             System.out.println("--->1");
         }else if ( (testA1-testA2)>=0 ){
             System.out.println("--->2");
         }else {
             System.out.println("--->3");
         }

         while ( testA1 <= testA2 ){//先判断后进行循环
             testA1 = testA1 + 1;
             System.out.println(testA1);
         }

//         do{ //先循环在进行判断
//
//         }whil()



    }
}
