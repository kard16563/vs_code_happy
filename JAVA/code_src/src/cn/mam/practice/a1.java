package cn.mam.practice;

public class a1 {
    public static  final  double cm_pre=2.54;//类常量 用于出现在 一个类的多个方法之中

    public static strictfp void main(String[] args){

        //。在默认情况下， 虚拟机设计者允许对中间计算结果采用扩展的精度。-->可能机器不同结果不同
        //但是， 对于使用 strictfp 关键字标记的方法必须使用严格的浮点计算来生成可再生的结果

        int a1=11;
        final  double a2=10;//常量的定义 只能赋值一次 final 表示的
        System.out.println("用加号进行连接" + a1+"常量"+cm_pre*5 );
        double a3= (double) a1;//强制转换
        a1+=4;//等价于 a1=a1+4  (一般地， 要把运算符放在 = 号左边，如 *= 或 ％=)
        //自增、 自减运算符： n++ 将变量 n 的当前值加 1, n-- 则将 n 的值减 1。-->后缀” 形式
        int a4=12;
        a4++;//后缀” 形式  but 前缀形式会先完成加 1; 而后缀形式会使用变量原来的值
        //int m = 7;
        //int n = 7;
        //int a = 2 * ++m; // now a is 16, m is 8
        //int b = 2 * n++; // now b is 14, n is 8

        if(a2<=a4){
            System.out.println("小于等于");
        }else {
            System.out.println("大于等于");
        }
        //&& 的优先级比 || 的优先级高







    }


}
