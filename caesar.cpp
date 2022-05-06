#include <iostream>
using namespace std;

int main()
{
    int i;
    int c;
    char str[100];

    cout << "Simple Caesar Cipher\n";

    cout << "Please enter a string\t";
    cin >> str;

    cout << "\nChoose 1 or 2\n";
    cout << "1 = Encrypt the string.\n";
    cout << "2 = Decrypt the string.\n";
    cin >> c;

    switch (c)
    {
    case 1:
        for (i = 0; (i < 100 && str[i] != '\0'); i++)
        {
            str[i] = str[i] + 2;
        }
        cout << "\nEncrypted string: " << str << endl;
        break;
    case 2:
        for (i = 0; (i < 100 && str[i] != '\0'); i++)
        {
            str[i] = str[i] - 2;
        }
        cout << "\nDecrypted string: " << str << endl;
        break;
    default:
        cout << "\nInvalid input.\n";
    }
    return 0;
}