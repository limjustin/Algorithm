#include <stdio.h>

int main(void) {
	int calendar[365];
	int count = 0;
	int real = 0;
	int month, day = 0;
	scanf("%d %d", &month, &day);

	for (int m = 1; m <= 12; m++) {
		for (int d = 1; d <= 31; d++) {
			count++;
			if (month == m && day == d)
				real = count;
			if ( (((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12)) && d == 31) ||
				(((m == 4) || (m == 6) || (m == 9) || (m == 11)) && d == 30) ||
				((m == 2) && (d == 28))
				) {
				break;
			}
		}
	}
	if (real % 7 == 0)
		printf("SUN\n");
	else if (real % 7 == 1)
		printf("MON\n");
	else if (real % 7 == 2)
		printf("TUE\n");
	else if (real % 7 == 3)
		printf("WED\n");
	else if (real % 7 == 4)
		printf("THU\n");
	else if (real % 7 == 5)
		printf("FRI\n");
	else if (real % 7 == 6)
		printf("SAT\n");
	return 0;
}