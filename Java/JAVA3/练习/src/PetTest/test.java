package PetTest;
import java.util.Scanner;
abstract class Pet {
	public static int ID=1;
	public String name;
	Pet(String name)
	{
		this.name=name;
	}
	public String getName()
	{
		return this.name;
	}
	public static String judgePet(Pet pet)
	{
		if(pet instanceof Dog) {
			return "Dog";
		}
		if(pet instanceof Cat) {
			return "Cat";
		}
		else
			return "Bird";
	}
	public abstract int getID();
}
class Dog extends Pet{
	public Dog(String name)
	{
		super(name);
	}
	public int PetID=ID++;
	public int getID()
	{
		return PetID;
	}
}
class Cat extends Pet {
	public Cat(String name)
	{
		super(name);
	}
	int PetID=ID++;
	public int getID()
	{
		return PetID;
	}
}

class Bird extends Pet {
	public Bird(String name)
	{
		super(name);
	}
	int PetID=ID++;
	public int getID()
	{
		return PetID;
	}
}
public class test {
	public static void main(String args[]) {
		Pet[] pets=new Pet[100];
		int choice;
		Scanner input=new Scanner(System.in);
		Scanner charinput=new Scanner(System.in);
		while(true) {
			System.out.println("请选择以下操作\n1:寄养宠物\n2:查询宠物信息\n3:领走宠物\n4:喂养宠物\n5:退出程序");
			choice=input.nextInt();
			if(choice==1) {
				System.out.println("请选择要寄养宠物的类型\n1:狗\n2:猫\n3:鸟\n4:返回上一步");
				int flag=input.nextInt();
				if(flag==1) {
					System.out.println("请输入宠物的名字:");
					String Petname=charinput.nextLine();
					Dog dog=new Dog(Petname);
					pets[dog.getID()]=dog;
					System.out.println("寄养成功!");
				}
				else if(flag==2) {
					System.out.println("请输入宠物的名字:");
					String Petname=charinput.nextLine();
					Cat cat=new Cat(Petname);
					pets[cat.getID()]=cat;
					System.out.println("寄养成功!");
				}
				else if(flag==3) {
					System.out.println("请输入宠物的名字:");
					String Petname=charinput.nextLine();
					Bird bird=new Bird(Petname);
					pets[bird.getID()]=bird;
					System.out.println("寄养成功!");
				}
				else {
					System.out.println("已返回上一步");
					continue;
				}
			}
			else if(choice==2) {
			System.out.println("1:按宠物名称查询\n2:按宠物种类查询\n3:按宠物序号查询\n4:输出所有宠物信息\n5:返回上一步");
			int tmp=input.nextInt();
			String Petname;
			String breed;
			int use=0;
			int petID;
			if(tmp==1) {
				System.out.println("请输入宠物名称:");
				Petname=charinput.nextLine();
				for(int i=1;i<100;i++) {
					if(pets[i]!=null) {
						if(pets[i].getName().equals(Petname)) {
							use=1;
							System.out.println(" 序号:"+pets[i].getID()+" 类型:"+Pet.judgePet(pets[i])+" 名称:"+pets[i].getName());
						}
					}
				}
				if(use==0) {
					System.out.println("宠物不存在!");
				}
			}
			else if(tmp==2) {
				use=0;
				System.out.println("请输入宠物种类");
				breed=charinput.next();
				for(int i=1;i<=99;i++) {
					if(pets[i]!=null) {
						if(Pet.judgePet(pets[i]).equals(breed)) {
							use=1;
							System.out.println(" 序号:"+pets[i].getID()+" 种类:"+Pet.judgePet(pets[i])+" 名称:"+pets[i].getName());
						}
					}
				}
				if(use==0) {
					System.out.println("宠物不存在!");
				}
			}
			else if(tmp==3) {
				System.out.println("请输入宠物序号");
				petID=input.nextInt();
				if(pets[petID]!=null) System.out.println(" 序号:"+pets[petID].getID()+" 种类:"+Pet.judgePet(pets[petID])+" 名称:"+pets[petID].getName());
				else System.out.println("宠物不存在");
			}
			else if(tmp==4) {
				for(int i=1;i<=99;i++)
				{
						if(pets[i]!=null) System.out.println(" 序号:"+pets[i].getID()+" 种类:"+Pet.judgePet(pets[i])+" 名称:"+pets[i].getName());
				}
			}
			else {
				System.out.println("已返回上一步");
				continue;
			}
		}
		else if(choice==3) {
			System.out.println("1:输入宠物序号:\n2:返回上一步");
			int flag=input.nextInt();
			if(flag==1) {
				int petID=input.nextInt();
				System.out.println("序号:"+petID+" 种类:"+Pet.judgePet(pets[petID])+" 名称:"+pets[petID].getName()+" 该宠物被成功领走");
				pets[petID]=null;
			}
			else {
				continue;
			}
		}
		else if(choice==4) {
			System.out.println("请输入要喂养的宠物的序号:");
			int feedNumber=input.nextInt();
			System.out.println("序号:"+feedNumber+" 种类:"+Pet.judgePet(pets[feedNumber])+" 名称:"+pets[feedNumber].getName()+" 该宠物已被喂养");
		}
		else if(choice==5) break;
		}
		System.out.println("欢迎下次光临");
		}
}
