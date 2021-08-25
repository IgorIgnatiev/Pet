#pragma once
#include<vector>
#include<algorithm>
#include<ostream>
using std::vector;
class C_String
{
private:
	std::vector<char>* _cont;
public:
	C_String()
	{
		this->_cont = new std::vector<char>;
		this->_cont->resize(5);
	}
	C_String(const char* obj)
	{
		this->_cont = new std::vector<char>;
		for (int i = 0; i < strlen(obj); i++)
		{
			this->_cont->push_back(obj[i]);
		}
	}
	C_String(C_String& obj)
	{
		this->_cont = new std::vector<char>;
		this->_cont->resize(obj.get_cont()->size());
		*this->_cont = *obj.get_cont();
	}
	void operator =(C_String& obj)
	{
		this->_cont->resize(obj.get_cont()->size());
		*this->_cont = *obj.get_cont();
	}
	int get_length()
	{
		int count = 0;
		for (auto i = this->_cont->begin(); i != this->_cont->end(); i++)
		{
			count++;
		}
		return count;
	}
	void clear()
	{
		this->_cont->clear();
	}
	std::vector<char>* get_cont()
	{
		return this->_cont;
	}
	void set_cont(std::vector<char> obj)
	{
		*this->_cont = obj;
	}
	C_String operator +(C_String& obj)
	{
		C_String res(*this);
		for (auto i = obj._cont->begin(); i != obj._cont->end(); i++)
		{
			res._cont->push_back(*i);
		}
		return res;

	}
	C_String operator +(const char* obj)
	{
		C_String res(*this);
		for (auto i = 0; i <= strlen(obj); i++)
		{
			res._cont->push_back(obj[i]);
		}
		return res;

	}
	void operator +=(C_String& obj)
	{
		for (auto i = obj._cont->begin(); i != obj._cont->end(); i++)
		{
			this->_cont->push_back(*i);
		}
		
	}
	void operator +=(const char* obj)
	{
		for (auto i = 0; i <= strlen(obj); i++)
		{
			this->_cont->push_back(obj[i]);
		}
	}
	bool operator==(C_String& obj)
	{
		if (this->get_length() != obj.get_length())
		{
			return false;
		}
		bool f = true;
		for (int i = 0; i < this->get_length(); i++)
		{
			if (this->_cont->at(i) != obj._cont->at(i))
			{
				f = false;
				break;
			}
		}
		return f;
	}
	bool operator!=(C_String& obj)
	{
		if (this->get_length() != obj.get_length())
		{
			return true;
		}
		bool f = false;
		for (int i = 0; i < this->get_length(); i++)
		{
			if (this->_cont->at(i) != obj._cont->at(i))
			{
				f = true;
				break;
			}
		}
		return f;
	}
	friend std::ostream& operator<<(std::ostream& out, const C_String& obj)
	{
		for (auto i = obj._cont->begin(); i != obj._cont->end(); i++)
		{
			out << *i;
		}
		return out;
	}
	~C_String()
	{
		delete this->_cont;
	}
};