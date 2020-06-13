public class student extends person {
    private int score;

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


    public static void main(String[] args){
        student a1 = new student("0.123",11);
        System.out.println("okk");
        a1.print();

    }

}


