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
		System.out.println("��ѡ��Ҫ�޸ĵ��ļ����ͣ�\n1:�ı��ĵ�\n2:ͼƬ\n3:��Ƶ\n4:�˳�");
		int choice=in.nextInt();
		if(choice==1) {
			System.out.println("��ѡ��Ҫִ�еĲ�����\n1:�޸��ļ���\n2:�޸�����\n3:�޸ı��뷽ʽ\n4:���ļ�\n5:�����ļ�");
			int flag=in.nextInt();
			if(flag==1) {
				System.out.println("��������ĺ��ļ���:");
				String newname=in.next();
				media[0].setName(newname);
			}
			else if(flag==2) {
				System.out.println("��������ĺ�����:");
				String newlanguage=in.next();
				((Text) media[0]).setlanguage(newlanguage);
			}
			else if(flag==3) {
				System.out.println("��������ĺ���뷽ʽ:");
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
			System.out.println("��ѡ��Ҫִ�еĲ�����\n1:�޸��ļ���\n2:�޸ķֱ���\n3:�޸�ͼƬ����\n4:���ļ�\n5:�����ļ�");
			int flag=in.nextInt();
			if(flag==1) {
				System.out.println("��������ĺ��ļ���:");
				String newname=in.next();
				media[1].setName(newname);
			}
			else if(flag==2) {
				System.out.println("������ˮƽ�ֱ��ʺʹ�ֱ�ֱ��ʣ�");
				int x=in.nextInt();
				int y=in.nextInt();
				((Picture)media[1]).setxy(x,y);
			}
			else if(flag==3) {
				System.out.println("��������ĺ�ͼƬ����:");
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
			System.out.println("��ѡ��Ҫִ�еĲ�����\n1:�޸��ļ���\n2:�޸ķֱ���\n3:�޸���Ƶʱ��\n4:���ļ�\n5:�����ļ�");
			int flag=in.nextInt();
			if(flag==1) {
				System.out.println("��������ĺ��ļ���:");
				String newname=in.next();
				media[2].setName(newname);
			}
			else if(flag==2) {
				System.out.println("������ˮƽ�ֱ��ʺʹ�ֱ�ֱ��ʣ�");
				int x=in.nextInt();
				int y=in.nextInt();
				((Video)media[2]).setxy(x,y);
			}
			else if(flag==3) {
				System.out.println("�������޸ĺ��ʱ����");
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
