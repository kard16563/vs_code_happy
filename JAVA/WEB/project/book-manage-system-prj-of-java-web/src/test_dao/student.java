package test_dao;

import java.util.ArrayList;
import java.util.List;

public class student extends person {
    private int score =0;
    /**
     * list  有序列表
     * */
    List<String> list1 = new ArrayList<>();

    public void  setScore(int num){
        this.score = num;
    }

    public student(String name, int age){
        super.setName(name);
        super.setAge(age);
    }

    @Override//重写父类的方法
    public void print(){
        System.out.println("son`s project ");
    }

    /**
     * list  有序列表
     * */
    public void listAdd(String value){
        this.list1.add(value);
    }

    public void listCheckSize(){
        System.out.println("输出有序列表的数量"+this.list1.size());
    }





    public int getScore() {
        return score;
    }
}


