#include <iostream>
using namespace std;
unsigned short P16 = 0xB7E1;
unsigned int P32 = 0xB7E15163;
unsigned long P64 = 0xB7E151628AED2A6B;
unsigned short Q16 = 0x9E37;
unsigned int Q32 = 0x9E3779B9;
unsigned long Q64 = 0x9E3779B97F4A7C15;
//размер слова в битах 16/32/63 
const int w = 16;
//количество раундов 0-255
const int r = 8;
//Количество октетов (8-битных байт) в секретном ключе 0-255
const int b = 8;//число в байтах
template <typename T>
T shiftL(T _value,T _shift)
{
    return ((_value)<<(_shift&(w-1))) | ((_value)>>(w-(_shift&(w-1))));
}
template <typename T>
T shiftR(T _value,T _shift)
{
    return ((_value)>>(_shift&(w-1))) | ((_value)<<(w-(_shift&(w-1))));
}
void new_K( unsigned char *K)
{
    unsigned int u = w / 8;
    unsigned int c = b / u;
    unsigned long int L[c];

    for ( int i = 0; i < 4; ++i )
    {
         L[i] = 0;
    }
    for ( int i = b - 1; i >= 0; --i )
    {
        cout << "L[" << i/u << "]: " << L[i/u] << endl;
        L[i/u] = shiftL<unsigned long int>(L[i/u],8) + K[i];
        cout << "L[" << i/u << "]: " << L[i/u] << "\n\n";
    }
    for ( int i =0; i < c; ++i )
    {
        cout << L[i] << endl;
    }

}
int main()
{
    unsigned char K[b]={2,2,3,4,5,6,7,9};
    new_K(K);

    return 0;
}