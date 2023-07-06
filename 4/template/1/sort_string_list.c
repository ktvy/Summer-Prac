

#include "sort_string_list.h"



void SortStringList (StringListEntry *stringList) {
/* ���������: 
�������� ������� ��� �������� � ����������� ����������
��� ������ ������ �������� "�������� ������� ��� �������� ������".
*/

    StringListEntry *head = stringList;
    StringListEntry *currentStringListEntry = stringList;
    ListEntry *currentListEntry;

    // ������ ������ ���� ��������� ������
    currentStringListEntry = head;
    currentListEntry = &currentStringListEntry->listEntry;
    do {
        currentStringListEntry = GET_CONTENT_RECORD(StringListEntry, listEntry, currentListEntry);

        //...

        //currentEntry = currentEntry->next;

        currentListEntry = GetNextEntry (currentListEntry);
        
    } while (currentStringListEntry != head);

}
