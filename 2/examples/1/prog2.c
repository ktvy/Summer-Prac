#include <stdio.h>
#include "prog2.h"

// ����������� ���������� ����������
//(� ��� ����� �������� � ������� ���������� �������� ���������� �����)
int glVarProg2;

static void fun1 (void) {
    
    printf ("fun1 in prog2.c\n");
}

void fun (void) {

    printf ("Hello, World!\n");
    
    fun1();
    
    return;
}


