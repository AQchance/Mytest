package Test;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
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
		return "姓名："+name+"\n性别："+gender+"\n年龄："+age+"\n身高："+height+
				"/n体重："+weight+"\n职业："+job;
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
	static List<String> course = new ArrayList<String>();
	public Student(String name,String gender,int age,double height,double weight,String job,
			int IDNumber,double GPA,String grade,String college) {
		super(name,gender,age,height,weight,job);
		this.IDNumber=IDNumber;
		this.GPA=GPA;
		this.grade=grade;
		this.college=college;
	}
	public String toString() {
		return super.toString()+"学号："+IDNumber+"\n年级："+grade+"\n学院："+college+"\nGPA："+GPA+
				"\n选课科目："+this.course;
	}
	public void setGPA(double newGPA) {
		GPA=newGPA;
	}
	public void setGrade(String newGrade) {
		grade=newGrade;
	}
	static public void addCourse(String newCourse) {
		if(course.contains(newCourse)) {
			System.out.println("This course has already existed");
		}
		else {
			course.add(newCourse);
			System.out.println("选课成功!");
		}
	}
	static public void deleteCourse(String newCourse) {
		if(!course.contains(newCourse)) {
			System.out.println("This course is not inside");
		}
		else {
			course.remove(newCourse);
			System.out.println("退课成功!");
		}
	}
}
public class Test {
	public static void main(String args[]) {
		Scanner input=new Scanner(System.in);
		Scanner charinput=new Scanner(System.in);
		System.out.print("请输入创建的Student对象个数：");
		int number=input.nextInt();
		Student[] student=new Student[number];
		for(int i=0;i<number;i++) {
			String name,gender,grade,college,course,job;
			int age,IDNumber;
			double height,weight,GPA;
			System.out.println("学生姓名：");
			name=charinput.nextLine();
			System.out.println("性别：");
			gender=charinput.nextLine();
			System.out.println("年龄：");
			age=input.nextInt();
			System.out.println("身高(cm)：");
			height=input.nextInt();
			System.out.println("体重(kg)：");
			weight=input.nextInt();
			System.out.println("工作：");
			job=charinput.nextLine();
			System.out.println("学号：");
			IDNumber=input.nextInt();
			System.out.println("GPA：");
			GPA=input.nextInt();
			System.out.println("年级：");
			grade=charinput.nextLine();
			System.out.println("学院：");
			college=charinput.nextLine();
			student[i]=new Student(name,gender,age,height,weight,job,IDNumber,GPA,grade,college);
			System.out.println("所选课程个数：");
			int coursenumber=input.nextInt();
			System.out.println("输入课程（输入一次课程后请按回车）：");
			for(int j=0;j<coursenumber;j++) {
				course=charinput.nextLine();
				student[i].addCourse(course);
			}
		}
		while(true) {
		System.out.println("修改学生信息请按1");
		System.out.println("对同一学院的学生按GPA进行排序请按2");
		System.out.println("为指定的学生添加一门课请按3");
		System.out.println("为指定学生退掉一门课请按4");
		System.out.println("退出程序请按5");
		int choice=input.nextInt();
		if(choice==1) {
			System.out.println("（1）修改姓名");
			System.out.println("（2）修改年龄");
			System.out.println("（3）设置绩点");
			String newname;
			int newage,anotherchoice;
			double newGPA;
			anotherchoice=input.nextInt();
			if(anotherchoice==1) {
				System.out.println("输入想要修改信息的学生的学号：");
				int useIDNumber=input.nextInt();
				int i;
				for(i=0;i<number;i++) {
					if(student[i].IDNumber==useIDNumber) break;
				}
				System.out.println("输入新姓名：");
				newname=charinput.nextLine();
				student[i].setName(newname);
			}
			else if(anotherchoice==2) {
				System.out.println("输入想要修改信息的学生的学号：");
				int useIDNumber=input.nextInt();
				int i;
				for(i=0;i<number;i++) {
					if(student[i].IDNumber==useIDNumber) break;
				}
				System.out.println("输入新年龄：");
				newage=input.nextInt();
				student[i].setAge(newage);
			}
			else if(anotherchoice==3) {
				System.out.println("输入想要修改信息的学生的学号：");
				int useIDNumber=input.nextInt();
				int i;
				for(i=0;i<number;i++) {
					if(student[i].IDNumber==useIDNumber) break;
				}
				System.out.println("输入GPA：");
				newGPA=input.nextInt();
				student[i].setGPA(newGPA);
			}
		}
		else if(choice==2) {
			int a=0,b=0,c;
			Student t;
			System.out.println("请输入指定的学院进行排序：");
			String sortcollege=charinput.nextLine();
			for(c=0;c<number;c++) {
				if(student[c].college.equals(sortcollege)==false) {
					continue;
				}
				else {
					t=student[c];student[c]=student[a];student[a]=t;
					a++;
				}
			}
			for(int i=0;i<a-1;i++) {
				for(b=i,c=i+1;c<a;c++) {
					if(student[c].GPA>=student[b].GPA) b=c;
					if(b!=i) {
						t=student[b];student[b]=student[i];student[i]=t;
					}
				}
			}
			System.out.println("姓名\t学号\tGPA\t年级\t学院\t选课");
			for(int i=0;i<a;i++) {
				System.out.println(student[i].name+"\t"+student[i].IDNumber+"\t"+student[i].GPA+"\t"
						+student[i].grade+"\t"+student[i].college+"\t"+student[i].course);
			}
		}
		else if(choice==3) {
			System.out.println("输入想要修改信息的学生的学号：");
			int useIDNumber=input.nextInt();
			int i;
			for(i=0;i<number;i++) {
				if(student[i].IDNumber==useIDNumber) break;
			}
			System.out.println("请输入要添加的选课个数：");
			int count=input.nextInt();
			for(int j=0;j<count;j++) {
				System.out.println("输入选课：");
				String newCourse=charinput.nextLine();
				if(student[i].course.contains(newCourse)) j--;
				student[i].addCourse(newCourse);
			}
		}
		else if(choice==4) {
			System.out.println("输入想要修改信息的学生的学号：");
			int useIDNumber=input.nextInt();
			int i;
			for(i=0;i<number;i++) {
				if(student[i].IDNumber==useIDNumber) break;
			}
			System.out.println("请输入要删除的选课个数：");
			int count=input.nextInt();
			for(int j=0;j<count;j++) {
				System.out.println("输入要删除的选课：");
				String newCourse=charinput.nextLine();
				if(!student[i].course.contains(newCourse)) j--;
				student[i].deleteCourse(newCourse);
			}
		}
		else if(choice==5) break;
		}
	}
}
