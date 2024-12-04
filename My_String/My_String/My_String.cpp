#include "My_String.h"

namespace mystr
{
    //��ֵ����
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
    //�°� �ֵ
    string& string::operator=(const string& s)
    {
        if (this != &s)
        {
            string tmp(s);
            swap(tmp);
        }
        return *this;
    }

    //�����ַ�������
    void string::reserve(size_t n)
    {
        if (n > _capacity)
        {
            char* tmp = new char[n + 1];//�����¿ռ�
            strcpy(tmp, _str);//��ԭ���ݿ������¿ռ�
            delete[] _str;//�ͷ�ԭ�ռ�
            _str = tmp;//�����ռ�
            _capacity = n;//��������
        }
    }
    //�����ַ�����С
    void string::resize(size_t n, char c)
    {
        if (n > _capacity)
        {
            reserve(_capacity + (n - _capacity));//����reserve���ٿռ�
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

    //��posλ���ϲ����ַ�c�������ظ��ַ���λ��
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
            _str[end] = _str[end - 1];//��posλ�ú����������ƶ�
            --end;
        }
        _str[pos] = c;
        _size++;
        return *this;
    }
    //��posλ���ϲ����ַ���str�������ظ��ַ���λ��
    string& string::insert(size_t pos, const char* str)
    {
        assert(pos <= _size);
        size_t len = strlen(str);
        if (_size + len > _capacity)
        {
            reserve(_size + len);
        }
        int end = _size;
        while (end >= (int)pos)//��ʹ��size_t��ֹ��ѭ��
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

    // ɾ��posλ���ϵ�Ԫ�أ������ظ�Ԫ�ص���һ��λ��
    string& string::erase(size_t pos, size_t len)
    {
        assert(pos < _size);
        //Ҫɾ���ĳ��ȴ���ʣ���ַ������Ȼ����������������ַ�����С��ɾ�����������ַ���
        if(len == npos || pos + len >= _size)
        {
            _str[pos] = '\0';
            _size = pos;
        }
        else
        {
            strcpy(_str + pos, _str + pos + len);//��Ҫɾ�����Ⱥ�����ݸ��ǵ�posλ�ú�
            _size -= len;
        }
        return *this;
    }

    // ����c��string�е�һ�γ��ֵ�λ��
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

    // �����Ӵ�s��string�е�һ�γ��ֵ�λ��
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
        char buff[128];//���建����
        char ch = _cin.get();//��ȡ�����ַ�
        size_t sub = 0;//�������±�

        while (ch != ' ' && ch != '\n' && !_cin.eof())//ֱ�����ַ���س�������ȡ
        {
            buff[sub++] = ch;//�������������ַ�
            if (sub == 127)
            {
                buff[sub] = '\0';
                s += buff;
                sub = 0;
            }
            ch = _cin.get();
        }

        if (sub != 0)//�Է���������������δ����
        {
            buff[sub] = '\0';
            s += buff;
        }
        return _cin;
    }

    
}