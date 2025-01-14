#pragma once
#include <iostream>
#include <assert.h>
using namespace std;
namespace Myvector
{
    template<class T>
    class vector
    {
    public:
       // Vector的迭代器是一个原生指针
        typedef T* iterator;
            typedef const T* const_iterator;
            // construct and destroy
            vector()
            {
            }
            
            vector(int n, const T& value = T())
            {
                resize(n, value);
            }

            iterator begin()
            {
                return _start;
            }
            iterator end()
            {
                return _finish;
            }
            const_iterator begin() const
            {
                return _start;
            }
            const_iterator end() const
            {
                return _finish;
            }

            
            //迭代器区间构造
            template<class InputIterator>
            vector(InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    push_back(*first);
                    ++first; 
                }
            }

            //拷贝构造
            vector(const vector<T>& v)
            {
                reserve(v.capacity());
                for (const auto& e : v)
                {
                    push_back(e);
                }
            }

            //赋值重载
            vector<T>& operator= (vector<T> v)
            {
                swap(v);
                return *this;
            }

            //析构函数
            ~vector()
            {
                if (_start)
                {
                    delete[] _start;
                    _start = _finish = _endOfStorage = nullptr;
                }
            }

            // capacity
            size_t size() const
            {
                return _finish - _start;
            }
            size_t capacity() const
            {
                return _endOfStorage - _start;
            }

            void reserve(size_t n)
            {
                if (n > capacity())
                {
                    size_t old = size();
                    T* tmp = new T[n];
                    if (_start)
                    {
                        for (size_t i = 0; i < old; i++)
                        {
                            tmp[i] = _start[i];
                        }
                        delete[] _start;
                    }
                    _start = tmp;
                    _finish = _start + old;
                    _endOfStorage = _start + n;
                }
            }
            void resize(size_t n, const T& value = T())
            {
                if (n > size())
                {
                    reserve(n);
                    while (_finish < _start + n)
                    {
                        *_finish = value;
                        ++_finish;
                    }
                }
                else
                {
                    _finish = _start + n;
                }
            }

            ///////////////access///////////////////////////////
            T& operator[](size_t pos)
            {
                assert(pos < size());
                return _start[pos];
            }
            const T& operator[](size_t pos)const
            {
                assert(pos < size());
                return _start[pos];
            }

            ///////////////modify/////////////////////////////
            void push_back(const T& x)
            {
                if (_finish == _endOfStorage)
                {
                    size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
                    reserve(newcapacity);
                }
                *_finish = x;
                ++_finish;
            }
            void pop_back()
            {
                assert(size() > 0);
                --_finish;
            }
            void swap(vector<T>& v)
            {
                std::swap(_start, v._start);
                std::swap(_finish, v._finish);
                std::swap(_endOfStorage, v._endOfStorage);
            }
            iterator insert(iterator pos, const T& x)
            {
                assert(pos >= _start && pos <= _finish);
                if (_finish == _endOfStorage)
                {
                    size_t len = pos - _start;
                    reserve(capacity() == 0 ? 4 : capacity() * 2);
                    pos = _start + len;
                }
                iterator end = _finish - 1;
                while (end >= pos)
                {
                    *(end + 1) = *end;
                    --end;
                }
                *pos = x;
                ++_finish;
                return pos;
            }

            iterator erase(iterator pos)
            {
                assert(pos >= _start && pos < _finish);
                iterator it = pos + 1;
                while (it < _finish)
                {
                    *(it - 1) = *it;
                    ++it;
                }
                _finish--;
                return pos;
            }
            
    private:
        iterator _start = nullptr; // 指向数据块的开始
        iterator _finish = nullptr; // 指向有效数据的尾
        iterator _endOfStorage = nullptr; // 指向存储容量的尾
    };
    void print_vector(const vector<int>& v)
    {
        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;
    }
}
