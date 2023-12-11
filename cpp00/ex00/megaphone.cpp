#include <iostream>
#include <string>
#include <cctype>

int	main(int ac, char **av)
{

	return (0);
}


int main(int argc, char *argv[]) { // 메인 함수 시작. argc는 인자의 개수, argv는 인자의 배열을 나타냄
	if (argc < 2) { // 인자가 없는 경우 (argc가 2 미만일 때, argc는 프로그램 이름도 포함하므로 인자가 없으면 값이 1이 됨)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl; // 에러 메시지 출력
		return 1; // 비정상 종료를 나타내며 프로그램 종료
	}
	
	for (int i = 1; i < argc; ++i) { // 인자를 순회하는 반복문 (argv[0]은 프로그램 이름이므로 i는 1부터 시작)
		std::string arg = argv[i]; // 현재 인자를 std::string 객체로 변환
		
		for (char &c : arg) { // 문자열의 각 문자에 대한 루프
			c = std::toupper(c); // 각 문자를 대문자로 변환
		}
		
		std::cout << arg << " "; // 변환된 문자열 출력
	}
	
	std::cout << std::endl; // 모든 인자를 처리한 후, 줄 바꿈
	
	return 0; // 정상 종료를 나타내며 프로그램 종료
}