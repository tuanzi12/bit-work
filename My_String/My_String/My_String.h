#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

namespace mystr
{
    class string
    {
    public:
        typedef char* iterator;
        typedef const char* const_iterator;
        
        //构造函数
        //初始化变量
        string(const char* str = "")//缺省参数默认构造空串
        {
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }

        //拷贝构造函数
        //默认生成的构造函数只支持浅拷贝，自行构造一个函数实现深拷贝
        string(const string& s)
        {
            _str = new char[s._capacity + 1];
            strcpy(_str, s._str);
            _size = s._size;
            _capacity = s._capacity;
        }
        //赋值重载
        string& operator=(const string& s);

        //析构函数
        ~string()
        {
            delete[]_str;
            _str = nullptr;//nullptr专门形容空指针
            _capacity = _size = 0;
        }

        //////////////////////////////////////////////////////////////
        // iterator
        iterator begin()
        {
            return _str;
        }
        iterator end()
        {
            return _str + _size;
        }

        const_iterator begin() const
        {
            return _str;
        }
        const_iterator end() const
        {
            return _str + _size;

        }
        /////////////////////////////////////////////////////////////
        // modify
        void push_back(char c)
        {
            insert(_size, c);//复用insert，在最后插入
        }

        string& operator+=(char c)
        {
            insert(_size, c);
            return *this;
        }

        void append(const char* str);

        string& operator+=(const char* str)
        {
            append(str);
            return *this;
        }

        void clear()
        {
            _size = 0;
            _str[0] = '\0';
        }
        void swap(string& s)
        {
            std::swap(_str, s._str);
            std::swap(_size, s._size);
            std::swap(_capacity, s._capacity);
        }
        
        const char* c_str()const
        {
            assert(_str);
            return _str;
        }

        /////////////////////////////////////////////////////////////
        // capacity
        size_t size()const
        {
            return _size;
        }
        size_t capacity()const
        {
            return _capacity;
        }

        bool empty()const
        {
            return _size == 0;
        }

        void resize(size_t n, char c = '\0');
        
        void reserve(size_t n);

        /////////////////////////////////////////////////////////////
        // access
        char& operator[](size_t index)
        {
            assert(index <= _size);
            return _str[index];//返回index下标的数据
        }
        const char& operator[](size_t index)const
        {
            assert(index <= _size);
            return _str[index];
        }

        /////////////////////////////////////////////////////////////
        //relational operators
        bool operator<(const string& s)
        {
            return (strcmp(_str, s._str) < 0);
        }
        bool operator<=(const string& s)
        {
            return (*this < s) || (*this == s);
        }
        bool operator>(const string& s)
        {
            return !(*this <= s);
        }
        bool operator>=(const string& s)
        {
            return !(*this < s);
        }
        bool operator==(const string& s)
        {
            return (strcmp(_str, s._str) == 0);
        }
        bool operator!=(const string& s)
        {
            return !(*this == s);
        }

        // 返回c在string中第一次出现的位置
        size_t find(char c, size_t pos = 0) const;

        // 返回子串s在string中第一次出现的位置
        size_t find(const char* s, size_t pos = 0) const;

        // 在pos位置上插入字符c/字符串str，并返回该字符的位置
        string& insert(size_t pos, char c);
        string& insert(size_t pos, const char* str);

        // 删除pos位置上的元素，并返回该元素的下一个位置
        string& erase(size_t pos, size_t len);
    private:
        char* _str;
        size_t _capacity;
        size_t _size;
        static const size_t npos = -1;
    };
    ostream& operator<<(ostream& _cout, const mystr::string& s);
    istream& operator>>(istream& _cin, mystr::string& s);
    void print_str(const string& s);
   
};
