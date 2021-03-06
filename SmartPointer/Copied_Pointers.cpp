#include <string>
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

class String
{
public:

	String()
	{
		_length = 0;
		_string = NULL;
	}

	String(const char* str)
	{
		_length = strlen(str);
		_string = new char[_length];

		strcpy(_string, str);
	}

	String(const String& str)
	{
		_length = str._length;
		_string = new char[_length];

		strcpy(_string, str._string);
	}

	char charAt(int index) const
	{
		return _string[index];
	}

	int length() const
	{
		return _length;
	}

	void print(char* str)
	{
		for (int i = 0; i < strlen(str); i++)
		{
			cout << str[i];
		}
		cout << endl;
	}

	void print()
	{
		for (int i = 0; i < _length; i++)
		{
			cout << _string[i];
		}
		cout << endl;
	}

	void reserve(int charLength)
	{
		char* temp = new char[_length];
		strcpy(temp, _string);

		_string = new char[_length + charLength];
		strcpy(_string, temp);
		_length += charLength;
	}

	void append(char c)
	{
		reserve(1);	
		_string[_length - 1] = c;
		_string[_length] = '\0';
	}

	~String()
	{
		if (_string != NULL)
		{
			delete[] _string;
			_string = NULL;
		}
	}

private:

	int _length;
	char* _string;
};


int main(int argc, char *argv[])
{
	String string ("Testing the program.");
	string.append('x');
	string.append('y');
	string.append('z');
	string.print();
	
	return 0;
}

