#include "prog2.h"

//int glVarProg2;

// ����������� ������� ����� ������ � �������� ������
// (�� ���������� � ������� ���������� �������� ���������� �����)
void fun1 (void) {
    
    printf ("fun1 in prog1.c\n");
}



int main (int argc, char *argv[], char *envp[]) {
    
    fun ();
    
    fun1();
    
    // ������������� ���������� ����������, ����������� � ������ ������
    // (����� �������� � ������� ������� �������� ���������� �����)
    printf ("glVarProg2 = %d\n", glVarProg2);
    
    return 0;
}

