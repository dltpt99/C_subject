#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 

int main()
{
	FILE *fp_send, *fp_bring;
	char *string = (char*) malloc(2);
	int i = 0, max = 2;
	int temp;

	fopen_s(&fp_send, "File_IO.txt", "w");	

	printf("������ ���ڿ��� �Է��ϼ��� \n");

	while (1)
	{
		temp = getchar();

		if (temp == '\n' || temp == EOF)
		{
			string[i] = 0;
			break;
		}

		string[i] = temp;

		if (i == max - 1)
		{
			max++;
			string = (char*)realloc(string, max);
		}
		i++;
	}
	char *bring_string = (char*)malloc(max);
	

	fprintf(fp_send,"%s",string);
	printf("���Ͽ� ���� �Ϸ� \n");
	fclose(fp_send);

	if ((fp_bring = fopen("File_IO.txt", "r")) == NULL)
	{
		printf("error");
		return;
	}

	printf("�б��������� ���� ���� �Ϸ�\n");

	fscanf(fp_bring,"%s", bring_string);

	printf("%s", bring_string);

	free(bring_string);
	free(string);

	fclose(fp_send);
	fclose(fp_bring);
}