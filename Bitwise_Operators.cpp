#include<bits/stdc++.h>
using namespace std;

int main()
{
    //1. C++ Bitwise AND Operator
    /*int a = 12,b = 25;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout<<"a & b = " << (a&b) <<endl;
    cout<<"a|b = "<< a|b <<endl;  ---invalid
    a = 10, b = 20;
    cout<<"a & b = " << (a&b) <<endl;
    */

    // 2. C++ Bitwise OR Operator

    //cout<< "a|b = "<<(a|b) <<endl;

    //4. C++ Bitwise Complement Operator
    /* int c = 35;
     int d = ~35;
     cout<<d<<endl;

    int num1 = 35;   // the bitwise complement of 35 should be -(35 + 1) = -36
    int num2 = -36;
    cout<<"~(" << num1 << ") = " << (~num1)<<endl;
    cout<<"~(" << num2 << ") = " << (~num2)<<endl;


    //The bitwise complement of 35 = - (35 + 1) = -36
            //i.e. ~35 = -36

    //The bitwise complement of -150 = - (-150 + 1) = - (-149) = 149
           //i.e. ~(-150) = 149

    //5. C++ Right Shift Operator:
        // When we shift any number to the right,
        // the least significant bits are discarded,
        // while the most significant bits are replaced by zeroes.
        // As a result, the right-most bit is discarded, while the left-most bit remains vacant.
        // This vacancy is replaced by a 0.
        // 13-> 1101   13>>1 means 6 -> 0110
        //  6-> 0110

    int num3 = 13;
    int num4 = num3>>1;
    cout<<num4<<endl;
    */


    //6. C++ Left Shift Operator
    //As a result, the left-most bit is discarded,
    //while the right-most bit remains vacant.
    //This vacancy is replaced by a


    int num3 = 10;
    int num4 = num3<<1;
    cout<<num4<<endl;

    // declaring two integer variables
    int num = 0;

    // Shift Right Operation
    cout << "Shift Right:" << endl;

    // Using for loop for shifting num right from 0 bit to 3 bits
    for (int i = 0; i < 4; i++)
    {
        cout << "32 >> " << i << " = " << (num >> i) << endl;
    }

    // Shift Left Operation
    cout << "\nShift Left:" << endl;

    // Using for loop for shifting num left from 0 bit to 3 bits
    for (int i = 0; i < 4; i++) {
        cout << "32 << " << i << " = " << (num << i) << endl;
    }



    return 0;
}
