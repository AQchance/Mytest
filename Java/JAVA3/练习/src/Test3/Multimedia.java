package Test3;

import java.util.Date;

public abstract class Multimedia {
	String filename;
	Date filedate;
	int filesize;
	public Multimedia(String filename,int filesize,Date filedate) {
		this.filename=filename;
		this.filesize=filesize;
		this.filedate=filedate;
	}
	public void toString(String filename,int filesize,Date filedate,String filetype) {
		System.out.println("�ļ�����"+filename+"\n"+"�ļ���С:"+filesize+"\n"+"�������ڣ�"+filedate);
	}
	public void setName(String newname) {
		this.filename=newname;
		System.out.println("���ĺ��ļ���Ϊ��"+filename);
	}
}
