package sec01;

public class Student {
	// 필드 선언
	// 국적, 이름, 나이, 학과
	String nation = "대한민국";
	String name;
	int age;
	String dept;
	
	// 생성자
	Student() { }
	Student(String name, int age){
//		this.name = name;
//		this.age = age;
		this(name, age, "소프트웨어학과");
	}
//	Student(String name, int a){ // 변수 타입 같
//		this.name = name;
//		this.age = a;
//	}
	Student(String name, int age, String dept){
		this.name = name;
		this.age = age;
		this.dept = dept;
	}
	
	// 메소드 (접근자/설정자)
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
