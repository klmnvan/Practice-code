#include "Header.h"

int main(void) {
	system("chcp 1251>nul");
	//setlocale(LC_ALL, ".1251");
	Person* Persons = calloc(0, sizeof(Person));
	int cycle = 1;
	while (cycle != 0) {
		if (CountRows() == 0) printf("Пользователи не добавлены\n");
		else {
			printf("Список пользователей:\n");
			Persons = initAccount(); //заносим в структуру аккаунты из файла
			outputAccount(Persons); //выводим данные из структуры
		}
		printf("Хотите ли вы добавить пользователя? (0 - нет, 1 - да): ");
		int otvet = 0;
		scanf("%d", &otvet);
		while (otvet != 0) {
			inputAccount(); //добавляем пользователя в файл
			printf("Вы добавли пользователя\nОбновлённый список пользователей:\n");
			Persons = initAccount();//обновляем структуру с данными об аккаунтах
			outputAccount(Persons); //выводим данные из структуры
			printf("Хотите ли вы добавить ещё одного пользователя? (0 - нет, 1 - да): ");
			scanf("%d", &otvet);
		}
		printf("Хотите ли вы изменить пользователя? (0 - нет, 1 - да): ");
		scanf("%d", &otvet);
		while (otvet != 0) {
			appendAccount(Persons); //изменяем акк
			updateStruct(Persons, CountRows()); //перезаписываем файл 
			printf("Вы добавили пользователя\nОбновлённый список пользователей:\n");
			//Persons = initAccount(); //обновляем структуру, тк перезаписали файл
			outputAccount(Persons); //выводим данные
			printf("Хотите ли вы изменить ещё одного пользователя? (0 - нет, 1 - да): ");
			scanf("%d", &otvet);
		}
		printf("Хотите ли вы удалить пользователя? (0 - нет, 1 - да): ");
		scanf("%d", &otvet);
		while (otvet != 0) {
			deleteAccount(Persons); //переместили в конец аккаунт, который удаляем
			updateStruct(Persons, CountRows() - 1); //перезаписываем файл без последней строки
			Persons = initAccount(); //обновляем структуру
			outputAccount(Persons); //выводим данные
			printf("Хотите ли вы удалить ещё одного пользователя? (0 - нет, 1 - да): ");
			scanf("%d", &otvet);
		}
		printf("Хотите ли вы отсортировать файл по Фамилии? (0 - нет, 1 - да): ");
		scanf("%d", &otvet);
		if (otvet == 1) {
			SortAlphavit(Persons); //сортируем структуру по алфавиту
			updateStruct(Persons, CountRows()); //перезаписываем файл с новой структурой
			Persons = initAccount(); //обновляем структуру 
			outputAccount(Persons); //выводим данные
		}
		printf("Хотите ли вы отсортировать файл по возрасту? (0 - нет, 1 - да): ");
		scanf("%d", &otvet);
		if (otvet == 1) {
			initAge(Persons);
			updateStruct(Persons, CountRows()); //перезаписываем файл с новой структурой
			Persons = initAccount(); //обновляем структуру 
			outputAccount(Persons); //выводим данные
		}
		printf("Хотите ли вы удалить всех пользователей? (0 - нет, 1 - да): ");
		scanf("%d", &otvet);
		if (otvet == 1) {
			otvet = 0;
			while (otvet != 1) {
				char* pas = calloc(100, 1);
				printf("Введите пароль: ");
				scanf("%s", pas);
				if (strcmp(pas, "admin") == 0) {
					otvet = 1;
					updateStruct(Persons, 0); //перезаписываем файл
					Persons = initAccount(); //обновляем структуру
					printf("Все пользователи удалены\n");
				}
				else printf("Пароль неверный. Попробуйте ещё раз.\n");
			}
		}
		printf("Хотите ли вы запустить программу сначала? (0 - нет, 1 - да): ");
		scanf("%d", &cycle);
	}
	printf("Конец\n");
	system("pause");
	return 0;
}