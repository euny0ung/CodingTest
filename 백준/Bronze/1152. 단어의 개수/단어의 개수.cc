#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string input;

    // 입력을 한 줄로 받기
    std::getline(std::cin, input);

    // 공백을 기준으로 단어를 분리
    std::istringstream iss(input);
    std::string word;
    int word_count = 0;

    // 스트림에서 단어를 하나씩 읽으며 단어의 개수를 셈
    while (iss >> word) {
        word_count++;
    }

    // 단어의 개수 출력
    std::cout << word_count << std::endl;

    return 0;
}