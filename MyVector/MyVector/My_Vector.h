#pragma once
#include <iostream>
#include <assert.h>
namespace Myvector
{
    template<class T>
    class vector
    {
    public:
       // Vector的迭代器是一个原生指针
        typedef T* iterator;
            typedef const T* const_iterator;
            iterator begin()
            {
                return _start;
            }
            iterator end()
            {
                return _finish;
            }
            const_iterator cbegin() const
            {
                return _start;
            }
            const_iterator cend() const
            {
                return _finish;
            }

            // construct and destroy
            vector();
            vector(int n, const T& value = T())
            {
                resize(n, value);
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
                if (n > capacity)
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
                if (n > size)
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
            T& operator[](size_t pos);
            const T& operator[](size_t pos)const;

            ///////////////modify/////////////////////////////
            void push_back(const T& x);
            void pop_back();
            void swap(vector<T>& v);
            iterator insert(iterator pos, const T& x);
            iterator erase(iterator pos);

    private:
        iterator _start = nullptr; // 指向数据块的开始
        iterator _finish = nullptr; // 指向有效数据的尾
        iterator _endOfStorage = nullptr; // 指向存储容量的尾

    };

}