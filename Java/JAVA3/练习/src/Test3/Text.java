package Test3;

import java.util.Date;

public class Text extends Multimedia implements Spread {
	String language;
	String codingScheme;
	String content;
	public Text(String filename, int filesize, Date filedate,String language,String codingScheme,String content) {
		super(filename, filesize, filedate);
		this.language=language;
		this.codingScheme=codingScheme;
		this.content=content;
	}

	@Override
	public void show() {
		System.out.println("�ı��ĵ�"+super.filename+".txt�ѱ���");
	}

	@Override
	public void copy() {
		System.out.println("�ı��ĵ�"+super.filename+".txt�ѱ����Ƶ�������");
	}
	public void setlanguage(String newlanguage) {
		this.language=newlanguage;
		System.out.println("���ĺ����ԣ�"+language);
	}
	public void setcoding(String newcoding) {
		this.codingScheme=newcoding;
		System.out.println("���ĺ���룺"+codingScheme);
	}
}
