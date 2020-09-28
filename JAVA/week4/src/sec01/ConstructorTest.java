package sec01;

class AA {
	AA(){
		System.out.println("생성자 AA");
	}
	AA(int x){ // 기본 생성자 이외의 생성자가 있으면 기본 생성자는 자동으로 호출되지 않음
		System.out.println("생성자 AA " + x);
	}
}
class BB extends AA {
	BB() {
		System.out.println("생성자 BB");
	}
	BB(int x){
//		super(x); 없으면 AA의 기본 생성자 실행
		System.out.println("생성자 BB " + x);
	}
}
public class ConstructorTest {
	public static void main(String[] args) {
		BB b = new BB(20);
	}
}
