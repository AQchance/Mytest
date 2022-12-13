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
		System.out.println("文本文档"+super.filename+".txt已被打开");
	}

	@Override
	public void copy() {
		System.out.println("文本文档"+super.filename+".txt已被复制到剪贴板");
	}
	public void setlanguage(String newlanguage) {
		this.language=newlanguage;
		System.out.println("更改后语言："+language);
	}
	public void setcoding(String newcoding) {
		this.codingScheme=newcoding;
		System.out.println("更改后编码："+codingScheme);
	}
}
