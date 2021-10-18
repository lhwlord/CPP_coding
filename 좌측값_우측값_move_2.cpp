#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
    std::string str = "Hello";
    cout << &str << endl;
    std::vector<std::string> v;

    // push_back(const T&) �� �����ε� �Ǿ ���ڿ��� ���簡 �߻��Ѵ�.
    v.push_back(str);
    std::cout << "After copy, str is \"" << str << "\"\n";

    // push_back(T&&) �� �����ε� �Ǽ� ���ڿ��� ���� ���� �״�� ���޵ȴ�.
    v.push_back(std::move(str));
    cout << &v[0] << endl;
    cout << &v[1] << endl;

    // �Ϲ������� �̵��� ��ü�� �����ϴ� ���� �ȵ����� C++ string �� ���
    // ��������� ����ȴ�.
    std::cout << "After move, str is \"" << str << "\"\n";

    std::cout << "The contents of the vector are \"" << v[0] << "\", \"" << v[1]
        << "\"\n";
}