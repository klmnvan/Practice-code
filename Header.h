#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

struct pers {
	char* F;
	char* I;
	char* O;
	char* pas;
	char* kab;
	int year, month, day, number;
};
typedef struct pers Person;

/// <summary>
/// ������� ���������� ����� � ����� info, �� ������ ������ ������
/// </summary>
/// <param name="file">��� ���������� �����</param>
/// <param name="path">���� � �����</param>
/// <returns>���������� �����</returns>
int CountRows()
{
	FILE* file = fopen("info.txt", "r");
	int count = 0;
	while (!feof(file))
	{
		char* buffer = calloc(100, 1);
		fgets(buffer, 100, file);
		if (buffer[0] == '\0')
			continue;
		count++;
		free(buffer);
	}
	return count;
}

/// <summary>
/// ������������� ��� ���������� ������ �� ����� � ���������;
/// </summary>
/// <returns>��������� � ������� �� �����</returns>
Person* initAccount() {
	FILE* file = fopen("info.txt", "r");
	int n = 0;
	Person* Persons = calloc(0, sizeof(Person));
	for (n; n < CountRows(file, "info.txt"); n++) {
		Persons = realloc(Persons, (n + 1) * sizeof(Person));
		Persons[n].F = calloc(100, 1);
		Persons[n].I = calloc(100, 1);
		Persons[n].O = calloc(100, 1);
		Persons[n].kab = calloc(5, 1);
		Persons[n].pas = calloc(30, 1);
		fscanf(file, "%s %s %s %d.%d.%d %s %s\n", Persons[n].F, Persons[n].I, Persons[n].O, &Persons[n].day, &Persons[n].month, &Persons[n].year, Persons[n].kab, Persons[n].pas);
		//printf("%d. %s %s %s %d.%d.%d %s %d\n", n, Persons[n].F, Persons[n].I, Persons[n].O, Persons[n].day, Persons[n].month, Persons[n].year, Persons[n].kab);
	}
	return Persons;
}

/// <summary>
/// ������� ������ ������ � ������������� �� �����
/// ����� ������� � ��������� ������ �� ���������
/// </summary>
void outputAccount(Person* Persons) {
	FILE* file = fopen("info.txt", "r");
	int n = 0;
	//Person* Persons = calloc(CountRows(file, "info.txt"), sizeof(Person));
	for (size_t i = 0; i < CountRows(); i++) printf("%d. %s %s %s %d.%d.%d %s\n", i + 1, Persons[i].F, Persons[i].I, Persons[i].O, Persons[i].day, Persons[i].month, Persons[i].year, Persons[i].kab);
	return Persons;
	//fclose(file);
}

/// <summary>
/// ���������� ������������ � ����
/// </summary>
void inputAccount() {
	FILE* file = fopen("info.txt", "a");
	printf("������� ���: ");
	char* FIO = calloc(100, 1);
	getchar();
	gets(FIO);
	printf("������� ���� �������� (������ - 1.1.2001): ");
	char* date = calloc(100, 1);
	gets(date);
	printf("������� �������: ");
	char* kab = calloc(100, 1);
	gets(kab);
	printf("������� ������: ");
	char* pas = calloc(100, 1);
	gets(pas);
	fprintf(file, "%s %s %s %s\n", FIO, date, kab, pas);
	//scanf("%s%s%s", Persons[0].F, Persons[0].I, Persons[0].O);
	fclose(file);
}

/// <summary>
/// ������ ������ �� ��������� � ����
/// ���������� ����� (��������, ����� ���������� ������������)
/// </summary>
/// <param name="Persons"></param>
void updateStruct(Person* Persons, int str) {
	FILE* file = fopen("info.txt", "w");
	for (size_t i = 0; i < str; i++) fprintf(file, "%s %s %s %d.%d.%d %s %s\n", Persons[i].F, Persons[i].I, Persons[i].O, Persons[i].day, Persons[i].month, Persons[i].year, Persons[i].kab, Persons[i].pas);
	fclose(file);
}

/// <summary>
/// ��������� ��������
/// </summary>
/// <param name="Persons"></param>
void appendAccount(Person* Persons) {
	int p = 0, n = 0;
	printf("������� ����� ������������, �������� �� ������ ��������: ");
	scanf("%d", &p);
	n = p - 1;
	int otvet = 0;
	while (otvet != 1) {
		char* pas = calloc(100, 1);
		printf("������� ������: ");
		scanf("%s", pas);
		if (strcmp(pas, Persons[n].pas) == 0 || strcmp(pas, "admin") == 0) {
			otvet = 1;
			Persons[n].F = calloc(100, 1);
			Persons[n].I = calloc(100, 1);
			Persons[n].O = calloc(100, 1);
			Persons[n].pas = calloc(100, 1);
			Persons[n].kab = calloc(100, 1);
			printf("������� ���: ");
			scanf("%s%s%s", Persons[n].F, Persons[n].I, Persons[n].O);
			printf("������� ���� �������� (������ - 31 10 2001): ");
			scanf_s("%d%d%d", &Persons[n].day, &Persons[n].month, &Persons[n].year);
			printf("������� �������: ");
			scanf("%s", Persons[n].kab);
			printf("������� ������: ");
			scanf("%s", Persons[n].pas);
		}
		else printf("������ ��������. ���������� ��� ���.\n");
	}
}

/// <summary>
/// �������� ������������
/// ���������� � ����� �����, ����� � ���������� ������������ ����,
/// � ����� � ���������, ��� ����� ������ ������������
/// </summary>
/// <param name="Persons"></param>
void deleteAccount(Person* Persons) {
	int numAc = 0, n = 0;
	printf("������� ����� ������������, �������� �� ������ �������: ");
	scanf("%d", &numAc);
	n = numAc - 1;
	int otvet = 0;
	while (otvet != 1) {
		char* pas = calloc(100, 1);
		printf("������� ������: ");
		scanf("%s", pas);
		if (strcmp(pas, Persons[n].pas) == 0 || strcmp(pas, "admin") == 0) {
			otvet = 1;
			Person Swap;
			for (int i = 0; i < CountRows(); i++)
				if (i > numAc - 1) {
					Swap = Persons[i];
					Persons[i] = Persons[numAc - 1];
					Persons[numAc - 1] = Swap;
					numAc++;
				}
		}
		else printf("������ ��������. ���������� ��� ���.\n");
	}
	//Persons = realloc(Persons, CountRows() - 1 * sizeof(Person));
}

/// <summary>
/// ���������� ���������, ���������� ���������� � �������������
/// �� ��������
/// </summary>
/// <param name="Struct">��������������� �� �������� ��������� �������������</param>
void SortAlphavit(Person* Struct) {
	int str = CountRows();
	Person Swap;
	for (int i = 0; i < str; i++)
		for (int j = i + 1; j < str; j++)
			for (int k = 0; k < strlen(Struct[i].F) || k < strlen(Struct[j].F); ) //k < strlen(Struct[i].Name) || k < strlen(Struct[j].Name)
			{
				if (Struct[i].F[k] == Struct[j].F[k])
					k++;
				if (Struct[i].F[k] > Struct[j].F[k]) {
					Swap = Struct[i];
					Struct[i] = Struct[j];
					Struct[j] = Swap;
					break;
				}
				if (Struct[i].F[k] < Struct[j].F[k])
					break;
			}
}

/// <summary>
/// ���������� ���������, ���������� ���������� � �������������
/// �� ���� ��������
/// </summary>
/// <param name="Struct">��������������� �� ���� �������� ��������� �������������</param>
void initAge(Person* Struct) {
	int str = CountRows();
	Person Swap;
	for (int i = 0; i < str; i++)
		for (int j = i + 1; j < str; j++) {
			if (Struct[i].year > Struct[j].year) {
				Swap = Struct[i];
				Struct[i] = Struct[j];
				Struct[j] = Swap;
				break;
			}
			if (Struct[i].year == Struct[j].year) {
				if (Struct[i].month > Struct[j].month) {
					Swap = Struct[i];
					Struct[i] = Struct[j];
					Struct[j] = Swap;
					break;
				}
				if (Struct[i].month == Struct[j].month)
					if (Struct[i].day > Struct[j].day) {
						Swap = Struct[i];
						Struct[i] = Struct[j];
						Struct[j] = Swap;
						break;
					}
			}
		}
}