package �������ϻ���ҵ;
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
			System.out.println("���Ѿ�ѡ���ÿ���!");
		}
		else {
			students.add(stu.name);
		}
	}
	public void removeObserver(Student stu) {
		if(!students.contains(stu.name)) {
			System.out.println("���Ŀα���û�иÿγ�!");
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
		 //�������쳣������ƣ���ֹ�����ڳ���ʱ��ס
		 try {
				while ( (line = textIn.readLine()) != null ) {  
				     if(!line.equals("")){
				    	 knowledge = line;
				    	 System.out.println("��ȡ��֪ʶ������:");
				    	 System.out.println(line);
				     }
				 }
			}catch (IOException e) {
				e.printStackTrace();
			} 
	}
}
