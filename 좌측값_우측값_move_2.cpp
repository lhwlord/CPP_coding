#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
    std::string str = "Hello";
    cout << &str << endl;
    std::vector<std::string> v;

    // push_back(const T&) 가 오버로딩 되어서 문자열의 복사가 발생한다.
    v.push_back(str);
    std::cout << "After copy, str is \"" << str << "\"\n";

    // push_back(T&&) 가 오버로딩 되서 문자열의 복사 없이 그대로 전달된다.
    v.push_back(std::move(str));
    cout << &v[0] << endl;
    cout << &v[1] << endl;

    // 일반적으로 이동된 객체를 접근하는 것은 안되지만 C++ string 의 경우
    // 비어있음이 보장된다.
    std::cout << "After move, str is \"" << str << "\"\n";

    std::cout << "The contents of the vector are \"" << v[0] << "\", \"" << v[1]
        << "\"\n";
}