package sec01;

public class Student {
	// �ʵ� ����
	// ����, �̸�, ����, �а�
	String nation = "���ѹα�";
	String name;
	int age;
	String dept;
	
	// ������
	Student() { }
	Student(String name, int age){
//		this.name = name;
//		this.age = age;
		this(name, age, "����Ʈ�����а�");
	}
//	Student(String name, int a){ // ���� Ÿ�� ��
//		this.name = name;
//		this.age = a;
//	}
	Student(String name, int age, String dept){
		this.name = name;
		this.age = age;
		this.dept = dept;
	}
	
	// �޼ҵ� (������/������)
	public String getNation() {
		return nation;
	}
	public void setNation(String nation) {
		this.nation = nation;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public String getDept() {
		return dept;
	}
	public void setDept(String dept) {
		this.dept = dept;
	}
	
	void show() {
		System.out.println("nation:"+nation);
		System.out.println("name:"+name);
		System.out.println("age:"+age);
		System.out.println("dept:"+dept);
		System.out.println();
	}
}
