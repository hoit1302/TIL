package hw;

public class UndergraduateStudent extends Student {

	public UndergraduateStudent(String name) {
		super(name);
	}

	@Override
	public void computeGrade() {
		grade = "����";
		if (score >= 70)
			grade = "���";
	}

}
