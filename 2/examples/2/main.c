
#include <stdio.h>

// ������������� ����
char charVar;               // 0000 0000 = 0 - 1111 1111 = -1
unsigned char uCharVar;     // 0000 0000 = 0 - 1111 1111 = 255
                            // 1111 1111 + 0000 0001 = 1 0000 0000
short shorVar;
unsigned short uShortVar;
int intVar;
unsigned int uIntVar;
long longVar;
unsigned long uLongVar;
long long lonLongVar;

// ������������ ����
float floatVar;
double doubleVar;
long double longDoubleVar;

// ���������
char *pChar;    // ��� ��������� �� char
int *pInt, a;

// �������
char charBuf[10];   // ��� ������ �� 10 ��������� ���� char
char c1 = -0x10;
char c2 = '0';   // 0x30 = 48
char charBuf2[10] = {'a', 'b', 'c'};    // 'a' -> �����, ������ ASCII-���� ������� a
int intBuf[] = {1, 2, 3};
char charBuf3[4] = {'b', 'u', 'f', '3'};
char charBuf4[] = "buf4";


char *str = "string";
// � ������ ������������� ������ string\0, 
// � str ����� ������� ��������� �� ������� ������� (�.�. ��� �����)

char *str1 = '1234';  // � str1 ����������� �������� 0x31323334



int main (int argc, char *argv[], char *envp[]) {

    printf ("charBuf3: %d\n", sizeof (charBuf3));
    printf ("charBuf4: %d\n", sizeof (charBuf4));

    printf ("size(char) = %d\nsize(short) = %d\nsize(int) = %d\nsize(long) = %d\nsize(size_t) = %d\nsize(long long) = %d\n",
            sizeof (char), sizeof (short), sizeof (int), sizeof (long), sizeof(size_t), sizeof(long long));
    printf ("size(float) = %d\nsize(double) = %d\nsize(long double) = %d\n",
            sizeof (float), sizeof (double), sizeof (long double));

    printf ("%d\n", charBuf[100]);
    charBuf[100] = 111;
    printf ("%d\n", charBuf[100]);

    return 0;
}


