#include "Header.h"

int main(void) {
	system("chcp 1251>nul");
	//setlocale(LC_ALL, ".1251");
	Person* Persons = calloc(0, sizeof(Person));
	int cycle = 1;
	while (cycle != 0) {
		if (CountRows() == 0) printf("������������ �� ���������\n");
		else {
			printf("������ �������������:\n");
			Persons = initAccount(); //������� � ��������� �������� �� �����
			outputAccount(Persons); //������� ������ �� ���������
		}
		printf("������ �� �� �������� ������������? (0 - ���, 1 - ��): ");
		int otvet = 0;
		scanf("%d", &otvet);
		while (otvet != 0) {
			inputAccount(); //��������� ������������ � ����
			printf("�� ������� ������������\n���������� ������ �������������:\n");
			Persons = initAccount();//��������� ��������� � ������� �� ���������
			outputAccount(Persons); //������� ������ �� ���������
			printf("������ �� �� �������� ��� ������ ������������? (0 - ���, 1 - ��): ");
			scanf("%d", &otvet);
		}
		printf("������ �� �� �������� ������������? (0 - ���, 1 - ��): ");
		scanf("%d", &otvet);
		while (otvet != 0) {
			appendAccount(Persons); //�������� ���
			updateStruct(Persons, CountRows()); //�������������� ���� 
			printf("�� �������� ������������\n���������� ������ �������������:\n");
			//Persons = initAccount(); //��������� ���������, �� ������������ ����
			outputAccount(Persons); //������� ������
			printf("������ �� �� �������� ��� ������ ������������? (0 - ���, 1 - ��): ");
			scanf("%d", &otvet);
		}
		printf("������ �� �� ������� ������������? (0 - ���, 1 - ��): ");
		scanf("%d", &otvet);
		while (otvet != 0) {
			deleteAccount(Persons); //����������� � ����� �������, ������� �������
			updateStruct(Persons, CountRows() - 1); //�������������� ���� ��� ��������� ������
			Persons = initAccount(); //��������� ���������
			outputAccount(Persons); //������� ������
			printf("������ �� �� ������� ��� ������ ������������? (0 - ���, 1 - ��): ");
			scanf("%d", &otvet);
		}
		printf("������ �� �� ������������� ���� �� �������? (0 - ���, 1 - ��): ");
		scanf("%d", &otvet);
		if (otvet == 1) {
			SortAlphavit(Persons); //��������� ��������� �� ��������
			updateStruct(Persons, CountRows()); //�������������� ���� � ����� ����������
			Persons = initAccount(); //��������� ��������� 
			outputAccount(Persons); //������� ������
		}
		printf("������ �� �� ������������� ���� �� ��������? (0 - ���, 1 - ��): ");
		scanf("%d", &otvet);
		if (otvet == 1) {
			initAge(Persons);
			updateStruct(Persons, CountRows()); //�������������� ���� � ����� ����������
			Persons = initAccount(); //��������� ��������� 
			outputAccount(Persons); //������� ������
		}
		printf("������ �� �� ������� ���� �������������? (0 - ���, 1 - ��): ");
		scanf("%d", &otvet);
		if (otvet == 1) {
			otvet = 0;
			while (otvet != 1) {
				char* pas = calloc(100, 1);
				printf("������� ������: ");
				scanf("%s", pas);
				if (strcmp(pas, "admin") == 0) {
					otvet = 1;
					updateStruct(Persons, 0); //�������������� ����
					Persons = initAccount(); //��������� ���������
					printf("��� ������������ �������\n");
				}
				else printf("������ ��������. ���������� ��� ���.\n");
			}
		}
		printf("������ �� �� ��������� ��������� �������? (0 - ���, 1 - ��): ");
		scanf("%d", &cycle);
	}
	printf("�����\n");
	system("pause");
	return 0;
}