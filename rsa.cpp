#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>

using namespace std;

//X and Y are large prime numbers
int x;
int y;

//n serves modulous
int n;

//t is totient function
int t;

//Encryption values array
long int e[50];

//Decryption values array
long int d[50];

//Prime flag
int flag;

//prime method pointer
long int j;

//Prime function
int prime(long int);

//Common difference function
long int cd(long int);

//Message array
char msg[100];

//message character array
char m[50];

//i is a universal pointer
int i;

//Temporary Array
long int temp[50];

//Encrypted characters
char en[50];

//Other counters:
long int pt;
long int ct;
long int k;
long int len;

int main()
{
    cout << "RSA Encryption, Decryption\n";
    cout << "\nEnter the first prime number\n";
    cin >> x;

    flag = prime(x);
    if (flag == 0)
    {
        cout << "INVALID INPUT";
        exit(0);
    }

    cout << "\nEnter the second prime number\n";
    cin >> y;

    if (flag == 0 || x == y)
    {
        cout << "INVALID INPUT";
        exit(0);
    }

    cout << "\nEnter a string or message to encrypt\n";
    cin >> msg;

    for (i = 0; msg[i] != NULL; i++)
    {
        m[i] = msg[i];
    }

    n = x * y;
    t = (x - 1) * (y - 1);

    cout << "The modulous of " << x << " and " << y << " is " << n << " and the totient is " << t << "\n";

    //Encryption Key
    int k = 0;
    for (i = 2; i < t; i++)
    {
        if (t % i == 0)
        {
            continue;
        }
        flag = prime(i);
        if (flag == 1 && i != x && i != y)
        {
            e[k] = i;
            flag = cd(e[k]);
            if (flag > 0)
            {
                d[k] = flag;
                k++;
            }
            if (k == 99)
                break;
        }
    }

    cout << "\nPOSSIBLE VALUES OF\n";
    cout << "e\td\n";

    for (i = 0; i < j - 1; i++)
    {
        cout << "\n"
             << e[i] << "\t" << d[i];
    }

    //Encryption
    long int enc_key = e[0];
    i = 0;
    len = strlen(msg);

    while (i != len)
    {
        pt = m[i];
        pt = pt - 96;
        k = 1;
        for (j = 0; j < enc_key; j++)
        {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 96;
        en[i] = ct;
        i++;
    }
    en[i] = -1;
    cout << "\n\nTHE ENCRYPTED MESSAGE IS\n";
    for (i = 0; en[i] != -1; i++)
    {
        cout << en[i];
    }

    //Decryption
    long int dec_key = d[0];
    i = 0;
    while (en[i] != -1)
    {
        ct = temp[i];
        k = 1;
        for (j = 0; j < dec_key; j++)
        {
            k = k * ct;
            k = k % n;
        }
        pt = k + 96;
        m[i] = pt;
        i++;
    }
    m[i] = -1;
    cout << "\n\nTHE DECRYPTED MESSAGE IS\n";
    for (i = 0; m[i] != -1; i++)
        cout << m[i];

    cout << endl;

    return 0;
}

//Checks for prime values
int prime(long int pr)
{
    int i;
    j = sqrt(pr);
    for (i = 2; i <= j; i++)
    {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}

//Checks for common difference
long int cd(long int a)
{
    long int k = 1;
    while (1)
    {
        k = k + t;
        if (k % a == 0)
            return (k / a);
    }
}