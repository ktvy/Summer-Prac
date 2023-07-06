
#include <stdio.h>
#include <malloc.h>


void fun1 (void) {

// ����������� ��������� ����������
static int a = 0;

    ++a;

    printf ("fun1 a = %d\n", a);

    return;
}



int* GetDynamicVar (int initValue) {

int *ret;

    ret = (int*) malloc (sizeof(int));

    *ret = initValue;
    return ret;
}



void UseDynamicVar (int *dynamicVar) {

    printf ("%p: dynamicVar = %d\n", dynamicVar, *dynamicVar);
    free (dynamicVar);
}



void TestFun (void) {

int a = 0, b = 0, c = 0, d = 0;
//������� ��������
// - + ! * & ~
// ++, --
    -1, - - - - - - -(+1), !1, *(char*)1;
// ���������� ���������
    ++a;
    //b = ++a;
    b = a++;
/*
��������� ����������� ����������
prefix_operator++(a) {
    a += 1;
    return a;
    }
*/
// ����������� ���������
    a++;
/*
��������� ������������ ����������
postfix_operator++(a) {
    tmp = a;
    a += 1;
    return tmp;
}
*/

    a = a + b;
    a += b;

// �������� ��������
// - + * / %                        a + b + c +d  ->  ((a + b) + c) + d   ����� ��������������� 
// && ||
// & | ^ << >>
// < <= > >= == !=
// = *= += -= /= &= |= ^= <<= >>=   a = b = c = 0  ->  a = (b = (c = 0))       ������ ���������������
    // ((a = b) = c) = d; // => a = d

10, 11, 0;
//a = (b = (c = 1))
//((a + b) + c) + d
// ,                                a, b, c, d  -> ((a, b), c), d
//for (i = 0, j = 0; j=2, i < 0; i += 2, j += 3)
10 + 5, 5 * 52, a = 1;
10 + 5;
// ��������� ��������
// op1 ? op2 : op3
// a < b ? a : b

//fun1(10) + fun2(fun3(10));


}


int a;

int main (int argc, char *argv[], char *envp[]) {

int a = 10;
int *dynamicVar;

    fun1();
    fun1();
    fun1();

    dynamicVar = GetDynamicVar (100);
    UseDynamicVar (dynamicVar);

    {
    // ��������������� ��������� ���������� ������ �����
    int a = 5;
    a = 6;
    printf ("a = %d\n", a);
    }

    printf ("a = %d\n", a);


    return 0;
}
