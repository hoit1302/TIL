package sec01;

class AA {
	AA(){
		System.out.println("������ AA");
	}
	AA(int x){ // �⺻ ������ �̿��� �����ڰ� ������ �⺻ �����ڴ� �ڵ����� ȣ����� ����
		System.out.println("������ AA " + x);
	}
}
class BB extends AA {
	BB() {
		System.out.println("������ BB");
	}
	BB(int x){
//		super(x); ������ AA�� �⺻ ������ ����
		System.out.println("������ BB " + x);
	}
}
public class ConstructorTest {
	public static void main(String[] args) {
		BB b = new BB(20);
	}
}
