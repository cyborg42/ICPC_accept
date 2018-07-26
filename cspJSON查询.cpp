#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<map>
#include<stack>

class object
{
public:
	std::map<std::string, std::string> str;
	std::map<std::string, object*> obj;
};

int main()
{
	int n, m;
	char ch[100], curChar;
	std::stack<object*> S;
	scanf("%d%d\n", &n, &m);
	bool isStr = false;
	bool isSlash = false;
	bool isFirstStr = false;
	std::string curFirstStr = "", curSecondStr = "", curStr = "";
	object *mainObj, *curObj;
	std::map<std::string, std::string>::iterator itStr;
	std::map<std::string, object*>::iterator itObj;
	while (n--)
	{
		std::cin.getline(ch, 100);
		int i = 0;
		while (ch[i] != '\0')
		{
			curChar = ch[i];
			if (isStr) {
				i++;
				if (isSlash == false && curChar == '\\') 
				{
					isSlash = true;
					continue;
				}
				if (isFirstStr)
				{
					if (isSlash == true)
					{
						curFirstStr += curChar;
						isSlash = false;
						continue;
					}
					if (curChar == '"')
					{
						isStr = false;
						continue;
					}
					curFirstStr += curChar;
				}
				else
				{
					if (isSlash == true)
					{
						curSecondStr += curChar;
						isSlash = false;
						continue;
					}
					if (curChar == '"')
					{
						object* curObj = S.top();
						curObj->str[curFirstStr] = curSecondStr;
						curFirstStr = "";
						curSecondStr = "";
						isStr = false;
						continue;
					}
					curSecondStr += curChar;
				}
				continue;
			}
			object *o;
			switch (curChar)
			{
				case '{':
					o = new object;
					if (S.size() == 0)
					{
						S.push(o);
						isFirstStr = true;
						break;
					}
					S.top()->obj[curFirstStr] = o;
					S.push(o);
					curFirstStr = "";
					curSecondStr = "";
					isFirstStr = true;
					break;
				case '}':
					if (S.size() == 1) mainObj = S.top();
					S.pop();
					break;
				case '"':
					isStr = !isStr;
					break;
				case ':':
					isFirstStr = false;
					break;
				case ',':
					isFirstStr = true;
					break;
				default:
					break;
			}
			i++;
		}
	}

	while (m--)
	{
		std::cin.getline(ch, 100);
		int i = 0;
		curObj = mainObj;
		bool failed = false;
		while (ch[i] != '\0')
		{
			curChar = ch[i];

			if (curChar != '.')
			{
				curStr += curChar;
			}
			else
			{
				
				itObj = curObj->obj.find(curStr);
				if (itObj == curObj->obj.end())
				{
					failed = true;
					break;
				}
				curObj = itObj->second;
				curStr = "";
			}
			i++;
		}
		if (failed)
		{
			std::cout << "NOTEXIST" << std::endl;
			curStr = "";
			continue;
		}
		itObj = curObj->obj.find(curStr);
		if (itObj != curObj->obj.end())
		{
			std::cout << "OBJECT" << std::endl;
			curStr = "";
			continue;
		}
		itStr = curObj->str.find(curStr);
		if (itStr != curObj->str.end())
		{
			std::cout << "STRING " << itStr->second << std::endl;
			curStr = "";
			continue;
		}
		std::cout << "NOTEXIST" << std::endl;
		curStr = "";
	}
	//system("pause");
	return 0;
}