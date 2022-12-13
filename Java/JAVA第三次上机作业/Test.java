package 第三次上机作业;
import java.util.Random;
import java.util.Scanner;
public class Test {
	public static void main(String args[]) {
		@SuppressWarnings("resource")
		Scanner in=new Scanner(System.in);
		@SuppressWarnings("resource")
		Scanner charin=new Scanner(System.in);
		Teacher[] teachers=new Teacher[100];
		Student[] students=new Student[100];
		while(true) {
			System.out.println("\n操作菜单：\n1.创建老师\n2.创建学生\n3.教师列表\n4.学生列表\n5.学生选课\n"
					+ "6.学生退课\n7.上课\n8.课堂提问\n9.考试\n10.退出\n请选择操作：");
			int flag=in.nextInt();
			if(flag==1) {
				System.out.println("请输入要新建的老师的个数:");
				int number=in.nextInt();
				for(int i=0;i<number;i++) {
				System.out.println("请输入新建老师的姓名:");
				String name = charin.nextLine();
				System.out.println("请输入老师讲授的课程:");
				String course = charin.nextLine();
				System.out.println("请输入老师开课的时间（时间点采用24小时制,所有课程都是持续一小时）:");
				int time=in.nextInt();
				teachers[i].name=name;
				teachers[i].courses.add(course);
				teachers[i].time=time;
				}
			}
			else if(flag==2) {
				System.out.println("请输入要创建的学生的个数:");
				int number=in.nextInt();
				for(int i=0;i<number;i++) {
					System.out.println("请输入学生的姓名:");
					String name = charin.nextLine();
				}
			}
			else if(flag==3) {
				System.out.println("老师列表:\n");
				for(int i=0;teachers[i]!=null;i++) {
					System.out.println("老师姓名\t老师课程\t老师开课时间");
					System.out.println(teachers[i].name+"\t"+teachers[i].courses+"\t"+teachers[i].time);
				}
			}
			else if(flag==4) {
				System.out.println("学生列表:\n");
				for(int i=0;students[i]!=null;i++) {
					System.out.println("学生姓名\t所选老师\t所选课程");
					System.out.println(students[i].name+"\t"+students[i].teacherName+"\t"+students[i].course);
				}
			}
			else if(flag==5) {
				int i;
				System.out.println("请输入要选课的学生的姓名:");
				String name=charin.nextLine();
				for(i=0;students[i]!=null;i++) {
					if(students[i].name.equals(name)) break;
				}
				System.out.println("请输入要选课程的老师姓名:");
				String teacherName=charin.nextLine();
				System.out.println("请输入要选课程:");
				String course=charin.nextLine();
				if(students[i].teacherName.contains(teacherName)) {
					System.out.println("该学生已经选了该老师的课了!");
				}
				else {
				students[i].teacherName.add(teacherName);
				students[i].course.add(course);
				}
			}
			else if(flag==6) {
				int i;
				System.out.println("请输入要退课的学生的姓名:");
				String name=charin.nextLine();
				for(i=0;students[i]!=null;i++) {
					if(students[i].name.equals(name)) break;
				}
				System.out.println("请输入要退选课程的老师姓名:");
				String teacherName=charin.nextLine();
				System.out.println("请输入要退选课程:");
				String course=charin.nextLine();
				if(!students[i].teacherName.contains(teacherName)) {
					System.out.println("该学生的老师列表没有该老师!");
				}
				else {
				students[i].teacherName.remove(teacherName);
				students[i].course.remove(course);
				}
			}
			else if(flag==7) {
				System.out.println("请输入当前时间（例：此时时间点位于下午两点到三点，则输入14）:");
				int t=in.nextInt();
				int i;
				for(i=0;teachers[i]!=null;i++) {
					if(teachers[i].time==t) break;
				}
				System.out.println(teachers[i].name+"正在上课");
				System.out.println("请输入txt文本路径");
				String text=charin.nextLine();
				teachers[i].getKnowledge(text);
				for(int j=0;students[j]!=null;j++) {
					if(students[j].teacherName.contains(teachers[i].name)) {
						students[i].knowledge.add(teachers[i].knowledge);
					}
				}
			}
			else if(flag==8) {
				System.out.println("请输入提问的老师姓名:");
				String teacherName=charin.nextLine();
				System.out.println("请输入提问的知识点:");
				String knowledge=charin.nextLine();
				while(true) {
					Random r = new Random(1);
				    int ran1=r.nextInt(100);
				    if(students[ran1]!=null&&students[ran1].teacherName.contains(teacherName)) {
				    	if(students[ran1].knowledge.contains(knowledge)) {
				    		System.out.println("该同学掌握该知识点!");
				    	}
				    	else {
				    		System.out.println("该同学没有掌握该知识点!");
				    	}
				    	break;
				    }
				    else continue;
				}
			}
			else if(flag==9) {
				System.out.println("请输入考试老师姓名:");
				String teacherName=charin.nextLine();
				System.out.println("请输入考核知识点:");
				String knowledge=charin.nextLine();
				for(int i=0;students[i]!=null;i++) {
					if(students[i].teacherName.contains(teacherName)) {
						if(students[i].knowledge.contains(knowledge)) {
							System.out.println("该班同学掌握该知识点!");
						}
						else {
							System.out.println("该班同学未掌握该知识点!");
						}
						break;
					}
					else continue;
				}
			}
			else if(flag==10) break;
		}
	}
}
