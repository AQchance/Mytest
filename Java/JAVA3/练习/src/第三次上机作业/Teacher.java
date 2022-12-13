package 第三次上机作业;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.Charset;
public class Teacher implements Subject {
	String name;
	String knowledge;
	int time;
	ArrayList<String> courses = new ArrayList<String>();
	ArrayList<String> students = new ArrayList<String>();
	public Teacher(String name,String course) {
		this.name=name;
		this.courses.add(course);
	}
	public String toString() {
		return this.name+"    "+this.courses;
	}
	public void registerObserver(Student stu) {
		if(students.contains(stu.name)) {
			System.out.println("您已经选过该课了!");
		}
		else {
			students.add(stu.name);
		}
	}
	public void removeObserver(Student stu) {
		if(!students.contains(stu.name)) {
			System.out.println("您的课表中没有该课程!");
		}
		else {
			students.remove(stu.name);
		}
	}
	public void notifyObservers(Student stu) {
			stu.knowledge.add(knowledge);
	}
	public void getKnowledge(String text) {
		BufferedReader textIn = new BufferedReader(new InputStreamReader
				(new ByteArrayInputStream(text.getBytes(Charset.forName("utf8"))), Charset.forName("utf8"))); 
		 String line; 
		 //下面是异常处理机制，防止程序在出错时卡住
		 try {
				while ( (line = textIn.readLine()) != null ) {  
				     if(!line.equals("")){
				    	 knowledge = line;
				    	 System.out.println("读取的知识点如下:");
				    	 System.out.println(line);
				     }
				 }
			}catch (IOException e) {
				e.printStackTrace();
			} 
	}
}
