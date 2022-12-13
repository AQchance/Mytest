package Test3;

import java.util.Date;

public class Video extends Multimedia implements Spread {
	int x,y;
	String videoformat;
	int videolength;
	public Video(String filename, int filesize, Date filedate,int x,int y,String videoformat,int videolength) {
		super(filename, filesize, filedate);
		this.x=x;
		this.y=y;
		this.videoformat=videoformat;
		this.videolength=videolength;
	}

	@Override
	public void show() {
		System.out.println("��Ƶ"+super.filename+videoformat+"���ڲ���");
	}

	@Override
	public void copy() {
		System.out.println("��Ƶ"+super.filename+videoformat+"�ѱ����Ƶ�������");
	}
	public void setxy(int newx,int newy) {
		this.x=newx;
		this.y=newy;
		System.out.println("ˮƽ�ֱ���Ϊ��"+x+"\n��ֱ�ֱ���Ϊ:"+y);
	}
	public void setlength(int newlength) {
		this.videolength=newlength;
		System.out.println("���ĺ���Ƶʱ��Ϊ��"+videolength);
	}
}
