package ÆßÏ¦×¨Êô;

import java.util.Scanner;
public class Demo_Girlfriend {
	public static void main(String[] args) {
		Girlfriend mygirlfriend=new Girlfriend();
		int age;
		String name;
		Scanner in=new Scanner(System.in);
		age=in.nextInt();
		name=in.next();
		mygirlfriend.setAge(age);
		mygirlfriend.setName(name);
		mygirlfriend.tell_you_something_about_your_girlfriend();
	}
}
class Girlfriend {
	private int age;
	private String name;
	public void setName(String name){
		this.name=name;
	}
	public void setAge(int age) {
		this.age=age;
	}
	public void tell_you_something_about_your_girlfriend() {
		System.out.println("You know nothing about her!\nYou have been greened by your girlfriend!\nYou are really an SB!\nhhhhhh");
	}
}

