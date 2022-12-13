package 第三次上机作业;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.ArrayList;
public class Student {
	String name;
	ArrayList<String> teacherName = new ArrayList<String>();
	ArrayList<String> knowledge=new ArrayList<String>();
	ArrayList<String> course = new ArrayList<String>();
	public Student(String name,String teacherName) {
		this.name=name;
		this.teacherName.add(teacherName);
	}
	public void addKnowledge(String knowledge) {
		if(this.knowledge.contains(knowledge)) {
			System.out.println("该知识点已经掌握!");
		}
		else {
			this.knowledge.add(knowledge);
		}
	}
	public boolean study() {
		// 将老师主题发送的 knowledge 存储到学生名对应的文本文件中
		try {
			RandomAccessFile studentTxt = new RandomAccessFile(this.name+".txt","rwd");
			try {
				long sTLength = studentTxt.length();
				studentTxt.seek(sTLength);
				Calendar calendar = Calendar.getInstance();
				SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
				byte[] b = new String(formatter.format(calendar.getTime())+" "+knowledge+"\n").getBytes("utf-8");
				studentTxt.write(b);
				studentTxt.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		return false;
	}
}
