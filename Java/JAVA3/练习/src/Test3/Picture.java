package Test3;

import java.util.Date;

public class Picture extends Multimedia implements Spread {
	int x,y;
	String phototype;
	public Picture(String filename, int filesize, Date filedate,int x,int y,String phototype) {
		super(filename, filesize, filedate);
		this.x=x;
		this.y=y;
		this.phototype=phototype;
	}

	@Override
	public void show() {
		System.out.println("ͼƬ"+super.filename+phototype+"�ѱ���");
	}

	@Override
	public void copy() {
		System.out.println("ͼƬ"+super.filename+phototype+"�ѱ����Ƶ�������");
	}
	public void setxy(int newx,int newy) {
		this.x=newx;
		this.y=newy;
		System.out.println("ˮƽ�ֱ���Ϊ��"+x+"\n��ֱ�ֱ���Ϊ:"+y);
	}
	public void setphototype(String newphototype) {
		this.phototype=newphototype;
		System.out.println("�޸ĺ�ͼƬ����Ϊ��"+phototype);
	}
}
