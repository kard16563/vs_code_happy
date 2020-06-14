package test_dao;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

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

    public void listCheckSize(int index){
        System.out.println(this.list1.get(index));
        System.out.println("输出有序列表的数量"+this.list1.size());
    }

    public void loopList(){
        for (String s:this.list1){
            System.out.println("foreach->"+s);
        }
    }

    public void listRemove(int index){
        this.list1.remove(index);
        for (String s:this.list1){
            System.out.println("after remove ->foreach->"+s);
        }
    }

    public void listChange(){
        List<Integer> list2 = Stream.of(1, 2, 3).collect(Collectors.toList());
        Number[] array = list2.toArray(new Number[3]);
        for (Number n : array) {
            System.out.println("初始化+转换为数字"+n);
        }
    }

    @Override
    public boolean equals(Object o) {
        boolean ageEquals = false;
        if (o instanceof student){
            student s =(student)o;
            ageEquals = this.getAge() == s.getAge();
            System.out.println("比较处理返回结果-》"+ageEquals);
            return ageEquals;
        }else {
        System.out.println("比较处理返回结果-》"+ageEquals);
        return ageEquals;
    }
    }






        public int getScore() {

        return score;
    }
}


