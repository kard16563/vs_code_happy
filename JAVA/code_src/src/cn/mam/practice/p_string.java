package cn.mam.practice;

public class p_string {
    public  static  void main(String[] args){

        String a="hello,world!";
        String a1=a.substring(0,3);//从一个较大的字符串提取出一个子串 (begin,stop)
        //len =stop-begin
        String a2= "aaaa";
        String a3= a2+a1;//允许使用 + 号连接（拼接）两个字符串
        //String 类没有提供用于修改字符串的方法
        // 如果希望将 a 的内容修改为“ Help!”
        String a4= a.substring(0,3)+"p!";

        System.out.println("字符串是否相等"+a1.equals(a2)+" ---> "
        +"Hello".equalsIgnoreCase("hello"));//忽略大小写

        //空串 "" 是长度为 0 的字符串。可以调用以下代码检查一个字符串是否为空

        String a5 = "";

        if (  a5.length() == 0 ){System.out.println("kong");}

        //为 null, 这表示目前没有任何对象与该变量关联
        // 要检查一个字符串是否为 null, 要使用以下条件
        String a6;
        if ( a5 == null ){System.out.println("null");}

    }
}
