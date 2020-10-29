#define _CRT_SECURE_NO_WARNINGS 1
char ju(char ch)
{
	if (ch == '[')
		return ']';
	else if (ch == '{')
		return '}';
	else
		return ')';
}
typedef struct linkStack
{
	char data;
	struct linkStackNode* next;
}linkStackNode;
bool isValid(char * s){
	linkStackNode* str = NULL;
	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			linkStackNode* temp;

			temp = (linkStackNode*)malloc(sizeof(linkStackNode));
			temp->data = *s;
			temp->next = str;
			str = temp;
			s++;

		}
		else
		{
			if (str == NULL)
			{

				return false;
			}
			else
			{
				if (ju(str->data) == *s)
				{

					str = str->next;
				}
				else
				{

					return false;
				}
			}
			s++;
		}
	}
	if (str == NULL)
	{

		return true;
	}
	else
	{

		return false;
	}
}