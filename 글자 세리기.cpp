/* C++ - Solution for week 1 problem 1 */

#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string line;

    while (getline(cin, line))
    {
        int word = 1, letter = 0;

        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == ' ') word++;
            else letter++;
        }

        int temp = line.length() - 1;

        while (line[temp] == ' ')
        {
            word--;
            temp--;
        }

        cout << word << ' ' << letter << endl;
    }

    return 0;
}
