//字符串_AC自动机_多模式匹配
#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>

class Trie {
public:
	Trie() :_root(new _TrieNode()) {}
	void insert(::std::string);				//插入
	int search(::std::string);				//查找
	void remove(::std::string);				//移除
	void dfs()								//遍历
	{
		::std::string str;
		_dfs(_root, str);
	}
private:
	static const int _char_num = 26;  //字母表大小
	static const char _start_char = 'a';    //首字母
	struct _TrieNode {
		int count;
		_TrieNode *branch[_char_num];
		_TrieNode() :count(0)
		{
			memset(branch, 0, sizeof(branch));
		}
	};
	_TrieNode *_root;
	void _dfs(_TrieNode*, string);
};
void Trie::insert(string str)
{
	int len = str.length();
	_TrieNode *pos = _root;

	for (int i = 0; i < len; i++)
	{

		if (pos->branch[str[i] - _start_char] == NULL)
		{
			pos->branch[str[i] - _start_char] = new _TrieNode();
		}
		pos = pos->branch[str[i] - _start_char];
	}
	pos->count++;
}
int Trie::search(string str)
{
	int len = str.length();
	_TrieNode *pos = _root;
	for (int i = 0; i < len; i++)
	{
		if (pos->branch[str[i] - _start_char] == NULL)return 0;
		pos = pos->branch[str[i] - _start_char];
	}
	return pos->count;
}
void Trie::remove(string str)
{
	int len = str.length();
	_TrieNode *pos = _root;
	for (int i = 0; i < len; i++)
	{
		if (pos->branch[str[i] - _start_char] == NULL)return;
		pos = pos->branch[str[i] - _start_char];
	}
	if (pos->count > 0)pos->count--;
}
void Trie::_dfs(_TrieNode* ptr, string str)
{
	if (ptr->count)cout << str << " " << ptr->count << endl;
	for (int i = 0; i < _char_num; i++)
	{
		if (ptr->branch[i])
		{
			string temp = "0";
			temp[0] = _start_char + i;
			_dfs(ptr->branch[i], str + temp);
		}
	}

}
int main()
{
	Trie t;
	t.insert("abc");
	t.insert("abc");
	t.insert("abeg");
	t.insert("beth");
	//	t.remove("abeg");
	cout << t.search("abc") << " " << t.search("abeg") << " " << t.search("beth") << endl;
	t.dfs();
	system("pause");
}


