package test_dao;

/**
 * @author Lenovo
 */
public class person implements Human {
    private  String name;
    private int age=-1;

    public void   setName(String name){
        this.name = name;
    }

    public void   setAge(int age){
        this.age = age;
    }


    public  String getName(){
        String name;
         name = this.name;
        return  name;
    }

    public int getAge(){
        int age;
        age = this.age;
        return age;
    }

    public void print(){
        System.out.println("father`s project ");
    }

    @Override
    public int getFood() {
        int food;
        food = Human.FOOD;
        return food;
    }


}
