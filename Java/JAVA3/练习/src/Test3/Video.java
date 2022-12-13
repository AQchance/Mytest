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
		System.out.println("视频"+super.filename+videoformat+"正在播放");
	}

	@Override
	public void copy() {
		System.out.println("视频"+super.filename+videoformat+"已被复制到剪贴板");
	}
	public void setxy(int newx,int newy) {
		this.x=newx;
		this.y=newy;
		System.out.println("水平分辨率为："+x+"\n垂直分辨率为:"+y);
	}
	public void setlength(int newlength) {
		this.videolength=newlength;
		System.out.println("更改后视频时长为："+videolength);
	}
}
