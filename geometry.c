#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct for_circle
{
	double coordinate1;
	double coordinate2;
	double radius;
} circle;

int main()
{
	char stroka[100];
	int flag = 0;
	char *pointer = stroka;
	char *end_pointer = stroka;
	char *new_pointer;
	char *end;

	fgets(stroka,sizeof(stroka),stdin);

	while (isalpha(*end_pointer) != 0)
		end_pointer++;

	if ((end_pointer - pointer) <= 6)
	{
		if (strncasecmp(stroka,"circle", 6) == 0)
			flag = 1;
	}
	else if (strncasecmp(stroka,"circle", end_pointer - pointer) == 0)
		flag = 1;

	if (flag == 1)
	{
		flag = 0;
		pointer = end_pointer;
		new_pointer = pointer;

		while (*new_pointer != 10)
		{
			if (*new_pointer == '(')
			{
				pointer = new_pointer;
				flag = 1;
				break;
			}
		        new_pointer++;
		}

		if (flag == 0)
		{
			printf("ERROR: expected 'circle' (\n");
			return 0;
		}

		while (isdigit(*pointer) == 0)//вытаскиваем 1-е число
		{
			if ((*pointer == ' ') || (*pointer == '('))
				pointer++;
			else
			{
				printf("ERROR X\n");
				return 0;
			}
		}

		if (isdigit(*pointer) != 0)
		{
			circle.coordinate1 = strtod(pointer, &end);
			pointer = end;
			//printf("%f\n", circle.coordinate1);
		}

		while (isdigit(*pointer) == 0)//вытаскиваем 2-е число
		{
			if (*pointer == ' ')
				pointer++;
			else
			{
				printf("ERROR Y\n");
				return 0;
			}
		}

		if (isdigit(*pointer) != 0)
		{
			circle.coordinate2 = strtod(pointer, &end);
			pointer = end;
			//printf("%f\n", circle.coordinate2);
		}

		new_pointer = pointer;
		flag = 0;

		while (*new_pointer != 10)
		{
			if ((*new_pointer != ' ') && (*new_pointer != ','))
			{
				printf("ERROR ,\n");
				return 0;
			}
			else if (*new_pointer == ',')
			{
				pointer = new_pointer;
				flag = 1;
				break;
			}
			else
				new_pointer++;
		}

		if (flag == 0)
			printf("ERROR ,");

		while (isdigit(*pointer) == 0)//вытаскиваем 3-е число
		{
			if ((*pointer == ' ') || (*pointer == ','))
				pointer++;
			else
			{
				printf("ERROR Radius\n");
				return 0;
			}
		}

		if (isdigit(*pointer) != 0)
		{
			circle.radius = strtod(pointer, &end);
			pointer = end;
			//printf("%f\n", circle.radius);
		}

		flag = 0;
		new_pointer = pointer;

		while (*new_pointer != 10)
		{
			if ((*new_pointer != ' ') && (*new_pointer != ')'))
			{
				printf("ERROR )\n");
				return 0;
			}
			else if (*new_pointer == ')')
			{
				pointer = new_pointer;
				flag = 1;
				break;
			}
			else
				new_pointer++;
		}

		if (flag == 0)
		{
			printf("ERROR )\n");
			return 0;
		}

		pointer++;

 		while (*pointer != 10)
		{
			if  (*pointer != ' ')
			{
				printf("ERROR: no items expected\n");
				return 0;
			}
			else
				pointer++;
		}
		printf("data entered correctly\n");
		return 0;
	}

	else printf("ERROR: expected 'circle'\n");
	return 0;
}
