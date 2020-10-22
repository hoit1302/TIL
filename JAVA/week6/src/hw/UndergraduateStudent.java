package hw;

public class UndergraduateStudent extends Student {

	public UndergraduateStudent(String name) {
		super(name);
	}

	@Override
	public void computeGrade() {
		grade = "과락";
		if (score >= 70)
			grade = "통과";
	}

}
