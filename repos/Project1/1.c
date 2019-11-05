#include <stdio.h>
#include <string.h>
char* maxword(char* s, char* t)
{

	char  chs, cht;
	char* res;
	/*res = (char*)malloc(sizeof(char) * 100);*/
	char* temp = NULL;
	int i, j, found, maxlen = 0;
	while (*s != '\0')
	{
		while (*s == ' ') { s++; } /* 过滤s中的空格 */
		for (i = 0; s[i] != ' ' && s[i] != '\0'; i++)
		{
			if (i > maxlen)
			{
				chs = s[i];
				s[i] = '\0';
				temp = t;
				found = 0;
				while (*temp != '\0' && !found)
				{
					while (*temp == ' ')
						temp++; /* 过滤t中的空格 */

					for (j = 0; temp[j] != ' ' && temp[j] != '\0'; j++)  /* 确定t中单词 */
					{
						if (j == i)
						{
							cht = temp[j];
							temp[j] = '\0';
							if (strcmp(s, temp) == 0)
							{
								maxlen = i;
								res = s;
								found = 1;
							}
							temp[j] = cht;
						}
					}

					temp = &temp[j];    /* 回到字符串t的某一位置*/
				}
				s[i] = chs;
			}
		}
		s = &s[i]; /* 回到字符串s的某一位置*/
	}

	if (maxlen == 0)
	{
		return NULL;
	}	/* 未找到最长公共单词，返回NULL */
	else
	{
		res[maxlen + 1]= '\0';
		return res;    /* 找到最长公共单词，返回该单词 */
	}
}

void main()
{
	char s[] = "This is C programming text";
	char t[] = "This is a text for C programming";
	char* maxword(char* s, char* t);
	maxword(s, t);

}




