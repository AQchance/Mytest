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
		return super.toString()+"ѧ�ţ�"+IDNumber+"\n�꼶��"+grade+"\nѧԺ��"+college+"\nGPA��"+GPA+
				"\nѡ�ο�Ŀ��"+this.course;
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
			System.out.println("ѡ�γɹ�!");
		}
	}
	static public void deleteCourse(String newCourse) {
		if(!course.contains(newCourse)) {
			System.out.println("This course is not inside");
		}
		else {
			course.remove(newCourse);
			System.out.println("�˿γɹ�!");
		}
	}
}
public class Test {
	public static void main(String args[]) {
		Scanner input=new Scanner(System.in);
		Scanner charinput=new Scanner(System.in);
		System.out.print("�����봴����Student���������");
		int number=input.nextInt();
		Student[] student=new Student[number];
		for(int i=0;i<number;i++) {
			String name,gender,grade,college,course,job;
			int age,IDNumber;
			double height,weight,GPA;
			System.out.println("ѧ��������");
			name=charinput.nextLine();
			System.out.println("�Ա�");
			gender=charinput.nextLine();
			System.out.println("���䣺");
			age=input.nextInt();
			System.out.println("���(cm)��");
			height=input.nextInt();
			System.out.println("����(kg)��");
			weight=input.nextInt();
			System.out.println("������");
			job=charinput.nextLine();
			System.out.println("ѧ�ţ�");
			IDNumber=input.nextInt();
			System.out.println("GPA��");
			GPA=input.nextInt();
			System.out.println("�꼶��");
			grade=charinput.nextLine();
			System.out.println("ѧԺ��");
			college=charinput.nextLine();
			student[i]=new Student(name,gender,age,height,weight,job,IDNumber,GPA,grade,college);
			System.out.println("��ѡ�γ̸�����");
			int coursenumber=input.nextInt();
			System.out.println("����γ̣�����һ�ογ̺��밴�س�����");
			for(int j=0;j<coursenumber;j++) {
				course=charinput.nextLine();
				student[i].addCourse(course);
			}
		}
		while(true) {
		System.out.println("�޸�ѧ����Ϣ�밴1");
		System.out.println("��ͬһѧԺ��ѧ����GPA���������밴2");
		System.out.println("Ϊָ����ѧ�����һ�ſ��밴3");
		System.out.println("Ϊָ��ѧ���˵�һ�ſ��밴4");
		System.out.println("�˳������밴5");
		int choice=input.nextInt();
		if(choice==1) {
			System.out.println("��1���޸�����");
			System.out.println("��2���޸�����");
			System.out.println("��3�����ü���");
			String newname;
			int newage,anotherchoice;
			double newGPA;
			anotherchoice=input.nextInt();
			if(anotherchoice==1) {
				System.out.println("������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�");
				int useIDNumber=input.nextInt();
				int i;
				for(i=0;i<number;i++) {
					if(student[i].IDNumber==useIDNumber) break;
				}
				System.out.println("������������");
				newname=charinput.nextLine();
				student[i].setName(newname);
			}
			else if(anotherchoice==2) {
				System.out.println("������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�");
				int useIDNumber=input.nextInt();
				int i;
				for(i=0;i<number;i++) {
					if(student[i].IDNumber==useIDNumber) break;
				}
				System.out.println("���������䣺");
				newage=input.nextInt();
				student[i].setAge(newage);
			}
			else if(anotherchoice==3) {
				System.out.println("������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�");
				int useIDNumber=input.nextInt();
				int i;
				for(i=0;i<number;i++) {
					if(student[i].IDNumber==useIDNumber) break;
				}
				System.out.println("����GPA��");
				newGPA=input.nextInt();
				student[i].setGPA(newGPA);
			}
		}
		else if(choice==2) {
			int a=0,b=0,c;
			Student t;
			System.out.println("������ָ����ѧԺ��������");
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
			System.out.println("����\tѧ��\tGPA\t�꼶\tѧԺ\tѡ��");
			for(int i=0;i<a;i++) {
				System.out.println(student[i].name+"\t"+student[i].IDNumber+"\t"+student[i].GPA+"\t"
						+student[i].grade+"\t"+student[i].college+"\t"+student[i].course);
			}
		}
		else if(choice==3) {
			System.out.println("������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�");
			int useIDNumber=input.nextInt();
			int i;
			for(i=0;i<number;i++) {
				if(student[i].IDNumber==useIDNumber) break;
			}
			System.out.println("������Ҫ��ӵ�ѡ�θ�����");
			int count=input.nextInt();
			for(int j=0;j<count;j++) {
				System.out.println("����ѡ�Σ�");
				String newCourse=charinput.nextLine();
				if(student[i].course.contains(newCourse)) j--;
				student[i].addCourse(newCourse);
			}
		}
		else if(choice==4) {
			System.out.println("������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�");
			int useIDNumber=input.nextInt();
			int i;
			for(i=0;i<number;i++) {
				if(student[i].IDNumber==useIDNumber) break;
			}
			System.out.println("������Ҫɾ����ѡ�θ�����");
			int count=input.nextInt();
			for(int j=0;j<count;j++) {
				System.out.println("����Ҫɾ����ѡ�Σ�");
				String newCourse=charinput.nextLine();
				if(!student[i].course.contains(newCourse)) j--;
				student[i].deleteCourse(newCourse);
			}
		}
		else if(choice==5) break;
		}
	}
}
