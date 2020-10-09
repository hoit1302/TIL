package hw;

public class MainTest {
	public static void main(String[] args) {
		Employee e1 = new Employee("������", 100000);
		Manager e2 = new Manager("������", 200000, 50000);
		Executive e3 = new Executive("������", 400000, 100000, 100000);

		e1.raiseSalary();
		e2.raiseSalary();
		e3.raiseSalary();
		
		System.out.println("===Employee(����)===");
		System.out.println(e1.showInfo());
		System.out.println();
		System.out.println("===Manager(�Ŵ���)===");
		System.out.println(e2.showInfo());
		System.out.println();
		System.out.println("===Executive(�ӿ�)===");
		System.out.println(e3.showInfo());
		System.out.println();
	}
}
