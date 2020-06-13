/**
 * @author Lenovo
 */
public class person {
    private  String name;
    private int age;

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





}
