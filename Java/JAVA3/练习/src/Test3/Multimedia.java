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
		System.out.println("文件名："+filename+"\n"+"文件大小:"+filesize+"\n"+"创建日期："+filedate);
	}
	public void setName(String newname) {
		this.filename=newname;
		System.out.println("更改后文件名为："+filename);
	}
}
