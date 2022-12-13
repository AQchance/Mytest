package ��ϰ;
import java.util.Collection;
import java.util.ArrayList;
class Person{
	public String name;
	public String gender;
	public int age;
	public double height;
	public double weight;
	public String job;
	public Person(String name,String gender,int age,double height,double weight,String job) {
		this.name=name;
		this.gender=gender;
		this.age=age;
		this.height=height;
		this.weight=weight;
		this.job=job;
	}
	public String toString() {
		return "������"+name+"\n�Ա�"+gender+"\n���䣺"+age+"\n��ߣ�"+height+
				"/n���أ�"+weight+"\nְҵ��"+job;
	}
	public void setName(String newName) {
		name=newName;
	}
	public void setAge(int newAge) {
		age=newAge;
	}
	public void setJob(String newJob) {
		job=newJob;
	}
}
class Student extends Person{
	public int IDNumber;
	public double GPA;
	public String grade;
	public String college;
	Collection<String> course=new ArrayList<String>();
	public Student(String name,String gender,int age,double height,double weight,String job,
			int IDNumber,double GPA,String grade,String college,String course) {
		super(name,gender,age,height,weight,job);
		this.IDNumber=IDNumber;
		this.GPA=GPA;
		this.grade=grade;
		this.college=college;
		this.course.add(course);
	}
	public String toString() {
		return super.toString()+"ѧ�ţ�"+IDNumber+"\n�꼶��"+grade+"\nѧԺ��"+college+"\nGPA��"+GPA+
				"\nѡ�ο�Ŀ��"+course;
	}
	public void setGPA(double newGPA) {
		GPA=newGPA;
	}
	public void setGrade(String newGrade) {
		grade=newGrade;
	}
	public void addCourse(String newCourse) {
		if(this.course.contains(newCourse)==true) {
			System.out.println("This course has already existed");
		}
		else {
			this.course.add(newCourse);
		}
	}
	public void deleteCourse(String newCourse) {
		if(this.course.contains(newCourse)==false) {
			System.out.println("This course is not inside");
		}
		else {
			this.course.remove(newCourse);
		}
	}
}
public class practice {
	public static void main(String args[]) {
		
	}
}
