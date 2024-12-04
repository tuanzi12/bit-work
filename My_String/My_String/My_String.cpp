#include "My_String.h"

namespace mystr
{
    //赋值重载
   /* string& string::operator=(const string& s)
    {
        if (this != &s)
        {
            _size = s._size;
            _capacity = s._size;
            char* tmp = new char[s._capacity + 1];
            delete[] _str;
            strcpy(tmp, s._str);
            _str = tmp;
        }
        return *this;
    }*/
    //新版 深赋值
    string& string::operator=(const string& s)
    {
        if (this != &s)
        {
            string tmp(s);
            swap(tmp);
        }
        return *this;
    }

    //调整字符串容量
    void string::reserve(size_t n)
    {
        if (n > _capacity)
        {
            char* tmp = new char[n + 1];//开辟新空间
            strcpy(tmp, _str);//将原数据拷贝进新空间
            delete[] _str;//释放原空间
            _str = tmp;//交付空间
            _capacity = n;//调整容量
        }
    }
    //调整字符串大小
    void string::resize(size_t n, char c)
    {
        if (n > _capacity)
        {
            reserve(_capacity + (n - _capacity));//复用reserve开辟空间
        }
        if (n > _size)
        {
            for (size_t i = _size; i < n; ++i)
            {
                _str[i] = c;
            }
        }
        _size = n;
        _str[n] = '\0';
    }

    //在pos位置上插入字符c，并返回该字符的位置
    string& string::insert(size_t pos, char c)
    {
        assert(pos <= _size);
        if (_size == _capacity)
        {
            size_t newCapacity = _capacity == 0 ? 4 : _capacity * 2;
            reserve(newCapacity);
        }
        size_t end = _size + 1;
        while (end > pos)
        {
            _str[end] = _str[end - 1];//将pos位置后的数据向后移动
            --end;
        }
        _str[pos] = c;
        _size++;
        return *this;
    }
    //在pos位置上插入字符串str，并返回该字符的位置
    string& string::insert(size_t pos, const char* str)
    {
        assert(pos <= _size);
        size_t len = strlen(str);
        if (_size + len > _capacity)
        {
            reserve(_size + len);
        }
        int end = _size;
        while (end >= (int)pos)//不使用size_t防止死循环
        {
            _str[end + len] = _str[end];
            --end;
        }
        strncpy(_str + pos, str, len);
        _size += len;
        return *this;
    }

    void string::append(const char* str)
    {
        size_t len = strlen(str);
        if ((_size + len) > _capacity)
        {
            reserve(_size + len);
        }
        strcpy(_size + _str, str);
        _size += len;
    }

    // 删除pos位置上的元素，并返回该元素的下一个位置
    string& string::erase(size_t pos, size_t len)
    {
        assert(pos < _size);
        //要删除的长度大于剩余字符串长度或两个加起来大于字符串大小则删除后面所有字符串
        if(len == npos || pos + len >= _size)
        {
            _str[pos] = '\0';
            _size = pos;
        }
        else
        {
            strcpy(_str + pos, _str + pos + len);//将要删除长度后的数据覆盖到pos位置后
            _size -= len;
        }
        return *this;
    }

    // 返回c在string中第一次出现的位置
    size_t string::find(char c, size_t pos) const
    {
        for (size_t i = pos; i <= _size; i++)
        {
            if (_str[i] == c)
            {
                return i;
            }
        }
        return npos;
    }

    // 返回子串s在string中第一次出现的位置
    size_t string::find(const char* s, size_t pos) const
    {
        const char* ptr = strstr(_str+pos, s);
        if (ptr == nullptr)
        {
            return npos;
        }
        else
        {
            return ptr - _str;
        }
    }

    string string::substr(size_t pos, size_t len)
    {
        assert(pos < _size);
        size_t end = pos + len;
        if (len == npos || pos + len >= _size)
        {
            end = _size;
        }
        string str;
        for (int i = pos; i < end; i++)
        {
            str += _str[i];
        }
        return str;

    }
    ostream& mystr::operator<<(ostream& _cout, const mystr::string& s)
    {
        for (auto& ch : s)
        {
            _cout << ch;
        }
        return _cout;
    }

    istream& mystr::operator>>(istream& _cin, mystr::string& s)
    {
        s.clear();
        char buff[128];//定义缓冲区
        char ch = _cin.get();//提取单个字符
        size_t sub = 0;//缓冲区下标

        while (ch != ' ' && ch != '\n' && !_cin.eof())//直到空字符或回车结束提取
        {
            buff[sub++] = ch;//往缓冲区存入字符
            if (sub == 127)
            {
                buff[sub] = '\0';
                s += buff;
                sub = 0;
            }
            ch = _cin.get();
        }

        if (sub != 0)//以防缓冲区还有数据未存入
        {
            buff[sub] = '\0';
            s += buff;
        }
        return _cin;
    }

    
}