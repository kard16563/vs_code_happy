package test_dao;

public class student extends person {
    private int score =0;

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







    public int getScore() {
        return score;
    }
}


