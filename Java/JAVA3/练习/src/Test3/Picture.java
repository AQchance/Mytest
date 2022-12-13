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
		System.out.println("图片"+super.filename+phototype+"已被打开");
	}

	@Override
	public void copy() {
		System.out.println("图片"+super.filename+phototype+"已被复制到剪贴板");
	}
	public void setxy(int newx,int newy) {
		this.x=newx;
		this.y=newy;
		System.out.println("水平分辨率为："+x+"\n垂直分辨率为:"+y);
	}
	public void setphototype(String newphototype) {
		this.phototype=newphototype;
		System.out.println("修改后图片类型为："+phototype);
	}
}
