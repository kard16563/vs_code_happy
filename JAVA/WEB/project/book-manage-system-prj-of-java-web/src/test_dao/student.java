package test_dao;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class student extends person {
    private int score =0;
    /**
     * list  有序列表
     * */
    List<String> list1 = new ArrayList<>();
    /**
     * 建立映射表 方便查找
     */
    Map<String,student> map = new HashMap<>();


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
/**
 * 用于比较大小的
 * */
    @Override
    public boolean equals(Object o) {//无论是 list 还是 哈希 都要到这个
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

    public void listMapPush(String key,student value){
        //将key和Student实例映射并关联--->哈希安排
            map.put(key,value);
    }

    HashMap<String,student> hashmap = new HashMap<>();

    public void hashPut(String key, student value){
        this.hashmap.put(key,value);//get remove
    }
    /**
     * https://blog.csdn.net/wdays83892469/article/details/79615609
     * */

    @Override//自己重写哈希的加密算法
    public int hashCode(){

        System.out.println("哈希加密自定义");
        int h = 0;
        h = 31 * h + this.getAge();
        h = 31 * h + this.getName().hashCode();
        h = 31 * h + this.getScore();
        return h;
    }



    public student  listMapFind(String key){
        return map.get(key);
    }






        public int getScore() {

        return score;
    }
}


