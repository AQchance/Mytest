package Test3;
import java.util.Scanner;
public class Test {
	public static void main(String args[]) {
		Scanner in=new Scanner(System.in);
		Multimedia[] media=new Multimedia[10];
		media[0]=new Text("wenbenwendang",23,null,"English","java","I love China.");
		media[1]=new Picture("tupian",159,null,1080,720,".jpg");
		media[2]=new Video("shipin",1024,null,1080,720,".mp4",102);
		while(true) {
		System.out.println("请选择要修改的文件类型：\n1:文本文档\n2:图片\n3:视频\n4:退出");
		int choice=in.nextInt();
		if(choice==1) {
			System.out.println("请选择要执行的操作：\n1:修改文件名\n2:修改语言\n3:修改编码方式\n4:打开文件\n5:复制文件");
			int flag=in.nextInt();
			if(flag==1) {
				System.out.println("请输入更改后文件名:");
				String newname=in.next();
				media[0].setName(newname);
			}
			else if(flag==2) {
				System.out.println("请输入更改后语言:");
				String newlanguage=in.next();
				((Text) media[0]).setlanguage(newlanguage);
			}
			else if(flag==3) {
				System.out.println("请输入更改后编码方式:");
				String newcoding=in.next();
				((Text)media[0]).setcoding(newcoding);
			}
			else if(flag==4) {
				((Text)media[0]).show();
			}
			else if(flag==5) {
				((Text)media[0]).copy();
			}
		}
		else if(choice==2) {
			System.out.println("请选择要执行的操作：\n1:修改文件名\n2:修改分辨率\n3:修改图片类型\n4:打开文件\n5:复制文件");
			int flag=in.nextInt();
			if(flag==1) {
				System.out.println("请输入更改后文件名:");
				String newname=in.next();
				media[1].setName(newname);
			}
			else if(flag==2) {
				System.out.println("请输入水平分辨率和垂直分辨率：");
				int x=in.nextInt();
				int y=in.nextInt();
				((Picture)media[1]).setxy(x,y);
			}
			else if(flag==3) {
				System.out.println("请输入更改后图片类型:");
				String newphototype=in.next();
				((Picture)media[1]).setphototype(newphototype);
			}
			else if(flag==4) {
				((Picture)media[1]).show();
			}
			else if(flag==5) {
				((Picture)media[1]).copy();
			}
		}
		else if(choice==3) {
			System.out.println("请选择要执行的操作：\n1:修改文件名\n2:修改分辨率\n3:修改视频时长\n4:打开文件\n5:复制文件");
			int flag=in.nextInt();
			if(flag==1) {
				System.out.println("请输入更改后文件名:");
				String newname=in.next();
				media[2].setName(newname);
			}
			else if(flag==2) {
				System.out.println("请输入水平分辨率和垂直分辨率：");
				int x=in.nextInt();
				int y=in.nextInt();
				((Video)media[2]).setxy(x,y);
			}
			else if(flag==3) {
				System.out.println("请输入修改后的时长：");
				int newlength=in.nextInt();
				((Video)media[2]).setlength(newlength);
			}
			else if(flag==4) {
				((Video)media[2]).show();
			}
			else if(flag==5) {
				((Video)media[2]).copy();
			}
		}
		else break;
		}
	}
}
