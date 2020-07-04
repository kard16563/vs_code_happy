package com.software.test;



public class People {





    private int id;
    private int age;
    //private String name;


    public People(int id, int age) {

        super();

        this.id = id;

        this.age = age;



    }



    public People() {

        super();

    }





    public int getId() {

        return id;

    }

    public void setId(int id) {

        this.id = id;

    }

    public int getAge() {

        return age;

    }

//    public String getName() {
//
//        return name;
//
//    }

    public void setAge(int age) {

        this.age = age;

    }

//    public void setName(String name) {
//
//        this.name = name;
//
//    }

    @Override

    public String toString() {

        return "People [id=" + id + ", age=" + age +  "]";

    }



}
