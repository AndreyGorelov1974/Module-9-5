/*Задание 5. Из обычных чисел — в римские* (дополнительное задание)
Что нужно сделать
Напишите программу, которая переводит данное пользователем число в римскую запись. Например, 19 в римской записи представляется как XIX.

Римская запись числа получается по следующим правилам. Сначала в ней идут буквы, описывающие количество тысяч в числе.
Затем идут буквы, обозначающие количество сотен, затем буквы, обозначающие количество десятков, и в конце — буквы, обозначающие количество единиц.
Для записи используются следующие буквы: 1 — I, 5 — V, 10 — X, 50 — L, 100 — C, 500 — D и 1000 — M.
Число получается как сумма значений использованных в нём букв, за тем исключением,
что если буква с меньшим значением идёт перед буквой с большим значением, то её значение вычитается из значения числа.
Вычитание используется только в случае, когда надо передать цифру 4 или 9, в остальных случаях используется сложение.
(Например, 9 обозначается как IX, 40 обозначается как XL).
В числе запрещено писать более трёх одинаковых букв подряд (таким образом, максимальное число, которое можно записать по этим правилам, равно 3999).

Программе на вход даётся целое число из диапазона от 1 до 3999. (Вы можете считывать его как число или как строку, если так удобнее.)

Программа должна вывести римскую запись данного числа.

Примеры

Ввод: 351
Вывод: CCCLI
Ввод: 449
Вывод: CDXLIX
Ввод: 1313
Вывод: MCCCXIII
Ввод: 2020
Вывод: MMXX

Рекомендации по выполнению
Решение данного задания похоже на решение задания «Банкомат-2» из модуля 5, только там мы последовательно отнимали купюры от запрошенной суммы, а здесь последовательно подсчитываем римские числа.
Не расстраивайтесь, если не удастся решить данное задание, разбор правильного решения будет в начале следующего модуля.
Что оценивается
Программа выдаёт в результате единственно правильный вариант представления в римской записи.*/

#include <iostream>

int main() {

	int arabicNumber;
	std::cout << "Enter a number to convert to a Roman number: ";
	std::cin >> arabicNumber;

	while (arabicNumber <= 0 || arabicNumber > 3999) {
		std::cout << "The number to convert must be in the range from 1 to 3999. Enter again: ";
		std::cin >> arabicNumber;
	}

	char minDigit = ' ', midlDigit = ' ', maxDigit = ' ';
	std::string romanNumber = "";
	int currentDigit = 0;

	for (int i = 3; i >= 0; i--) {
		currentDigit = arabicNumber % int(std::pow(10, i + 1)) / int(std::pow(10, i));
		if (i == 3) {
			minDigit = 'M';
		}
		if (i == 2) {
			minDigit = 'C';
			midlDigit = 'D';
			maxDigit = 'M';
		}
		if (i == 1) {
			minDigit = 'X';
			midlDigit = 'L';
			maxDigit = 'C';
		}
		if (i == 0) {
			minDigit = 'I';
			midlDigit = 'V';
			maxDigit = 'X';
		}

		if (currentDigit > 0 && currentDigit <= 3) {
			for (int j = 1; j <= currentDigit; j++) {
				romanNumber += minDigit;
			}
		}
		if (currentDigit == 4) {
			romanNumber += minDigit;
			romanNumber += midlDigit;
		}
		if (currentDigit == 5) {
			romanNumber += midlDigit;
		}
		if (currentDigit >= 6 && currentDigit <= 8) {
			romanNumber += midlDigit;
			for (int j = 1; j <= currentDigit - 5; j++) {
				romanNumber += minDigit;
			}
		}
		if (currentDigit == 9) {
			romanNumber += minDigit;
			romanNumber += maxDigit;
		}
	}
	std::cout << "Roman number: " << romanNumber << std::endl;
}