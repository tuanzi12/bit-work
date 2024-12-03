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
        
        //���캯��
        //��ʼ������
        string(const char* str = "")//ȱʡ����Ĭ�Ϲ���մ�
        {
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }

        //�������캯��
        //Ĭ�����ɵĹ��캯��ֻ֧��ǳ���������й���һ������ʵ�����
        string(const string& s)
        {
            _str = new char[s._capacity + 1];
            strcpy(_str, s._str);
            _size = s._size;
            _capacity = s._capacity;
        }
        //��ֵ����
        string& operator=(const string& s);

        //��������
        ~string()
        {
            delete[]_str;
            _str = nullptr;//nullptrר�����ݿ�ָ��
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
            insert(_size, c);//����insert����������
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
            return _str[index];//����index�±������
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

        // ����c��string�е�һ�γ��ֵ�λ��
        size_t find(char c, size_t pos = 0) const;

        // �����Ӵ�s��string�е�һ�γ��ֵ�λ��
        size_t find(const char* s, size_t pos = 0) const;

        // ��posλ���ϲ����ַ�c/�ַ���str�������ظ��ַ���λ��
        string& insert(size_t pos, char c);
        string& insert(size_t pos, const char* str);

        // ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
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
