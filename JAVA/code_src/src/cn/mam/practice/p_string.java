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

        String testA5="hello";//存在有的字符占2个储存单元的
        int getLength = testA5.length();// 5 占用 5个储存单元
        int cpCount = testA5.codePointCount(0,testA5.length());// 5 表示5 个字符--》称之为码点
        //调用 s.charAt(n) 将返回位置 n 的代码单元，n 介于 0 ~ s.length()-l 之间。
        char firstChar = testA5.charAt(0);//"h"
        char lastChar = testA5.charAt(4);//"0"



        System.out.println(" 代码单元长度 "+getLength +" 码点"+cpCount);

        //需要由较短的字符串构建字符串， 例如， 按键或来自文件中的单词。采用字
        //符串连接的方式达到此目的效率比较低使用 StringBuildei•类就可以避免这个问题的发生。

        StringBuilder strBuild=new StringBuilder();
        strBuild.append("hello");//可以连续添加字符或者字符串
        strBuild.append("a");
        String completedString =strBuild.toString();//转过来就ok了
    }
}
