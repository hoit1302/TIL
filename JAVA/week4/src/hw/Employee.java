package hw;

public class Employee {
	// �ڽ� Ŭ�������� ���� �����ϰ�!
	protected String name;
	protected int salary;

	Employee(String name, int salary) {
		this.name = name;
		this.salary = salary;
	}

	public String getName() {
		return name;
	}

	public int getSalary() {
		return salary;
	}

	public int raiseSalary() {
		int increased_salary;
		increased_salary = (int) (salary * 1.3);
		return increased_salary;
	}

	public String showInfo() {
		String result = "\n�̸�:" + name;
		result += "\n�޿�:" + salary;
		result += "\n�λ�� �޿�:" + raiseSalary();
		return result;
	}

}
