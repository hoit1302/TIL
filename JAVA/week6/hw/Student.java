package hw;

public abstract class Student {
	protected int type;
	protected String name;
	protected int score;
	protected String grade;
	
	public Student (String name) {
		this.name = name;
	}

	public int getType() {
		return type;
	}

	public void setType(int type) {
		this.type = type;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getScore() {
		return score;
	}

	public void setScore(int score) {
		this.score = score;
	}

	public String getGrade() {
		return grade;
	}

	public void setGrade(String grade) {
		this.grade = grade;
	}
	
	public abstract void computeGrade();
	
	public String showInfo() {
		String result = "소속\t이름\t점수\t학점\n";
		
		if (type == 1)
			result += "학부생";
		else
			result += "대학원생";
		
		result += "\t" + getName();
		result += "\t" + getScore();
		result += "\t" + getGrade();
		return result;
	}
}
