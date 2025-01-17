#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

namespace MyList
{
    // List的节点类
    template<class T>
    struct ListNode
    {
        ListNode(const T& val = T())
            :_pPre(nullptr)
            , _pNext(nullptr)
            , _val(val)
        {}
        ListNode<T>* _pPre;
        ListNode<T>* _pNext;
        T _val;
    };

    //List的迭代器类
    template<class T, class Ref, class Ptr>
    struct ListIterator
    {
        typedef ListNode<T>* PNode;
        typedef ListIterator<T, Ref, Ptr> Self; 
        PNode _pNode;
        //构造
        ListIterator(PNode pNode = nullptr)
            :_pNode(pNode)
        { }
        //拷贝构造
        //浅拷贝无需显式写出，编译器会自动生成拷贝构造
        ListIterator(const Self& l)
        {
            _pNode = l._pNode;
        }
        Ref operator*()
        {
            return _pNode->_val;
        }
        Ptr operator->()
        {
            return &_pNode->_val;
        }
        Self& operator++()
        {
            _pNode = _pNode->_pNext;
            return *this;
        }
        Self operator++(int)
        {
            Self tmp(*this);
            _pNode = _pNode->_pNext;
            return tmp;
        }
        Self& operator--()
        {
            _pNode = _pNode->_pPre;
            return *this;
        }
        Self& operator--(int)
        {
            Self tmp(*this);
            _pNode = _pNode->_pPre;
            return tmp;
        }
        bool operator!=(const Self& l)
        {
            return _pNode != l._pNode;
        }
        bool operator==(const Self& l)
        {
            return _pNode == l._pNode;
        }
        
    };


    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T&> const_iterator;
    public:
        ///////////////////////////////////////////////////////////////
        // List的构造
        list()
        {
            CreateHead();
        }
        list(int n, const T& value = T())
        {
            CreateHead();
            while (n--)
            {
                push_back(value);
            }
        }
        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            CreateHead();
            Iterator it = first;
            while (it != last)
            {
                push_back(*it);
                ++it;
            }
        }
        list(const list<T>& l)
        {
            CreateHead();
            const_iterator it = l.begin();
            while (it != l.end())
            {
                push_back(*it);
                ++it;
            }
        }
        list<T>& operator=(list<T> l)
        {
            swap(l);
            return *this;
        }
        ~list()
        {
            clear();
            delete _pHead;
            _pHead = nullptr;
        }


        ///////////////////////////////////////////////////////////////
        // List Iterator
        iterator begin()
        {
            return _pHead->_pNext;
        }
        iterator end()
        {
            return _pHead;
        }
        const_iterator begin() const
        {
            return _pHead->_pNext;
        }
        const_iterator end() const
        {
            return _pHead;
        }


        ///////////////////////////////////////////////////////////////
        // List Capacity
        size_t size()const
        {
            return _size;
        }
        bool empty()const
        {
            return _size == 0;
        }


        ////////////////////////////////////////////////////////////
        // List Access
        T& front()
        {
            return _pHead->_pNext->_val;
        }
        const T& front()const
        {
            return _pHead->_pNext->_val;
        }
        T& back()
        {
            return _pHead->_pPre->_val;
        }
        const T& back()const
        {
            return _pHead->_pPre->_val;
        }


        ////////////////////////////////////////////////////////////
        // List Modify
        void push_back(const T& val) 
        { 
            insert(end(), val); 
        }
        void pop_back()
        { 
            erase(--end()); 
        }
        void push_front(const T& val) 
        { 
            insert(begin(), val); 
        }
        void pop_front() 
        { 
            erase(begin()); 
        }
        // 在pos位置前插入值为val的节点
        iterator insert(iterator pos, const T& val)
        {
            Node* cur = pos._pNode;
            Node* prev = cur->_pPre;
            Node* newnode = new Node(val);

            // prev newnode cur
            prev->_pNext = newnode;
            newnode->_pPre = prev;
            newnode->_pNext = cur;
            cur->_pPre = newnode;

            //return iterator(newnode);
            return newnode;
        }
        // 删除pos位置的节点，返回该节点的下一个位置
        iterator erase(iterator pos)
        {
            assert(pos != end());

            Node* cur = pos._pNode;
            Node* prev = cur->_pPre;
            Node* next = cur->_pNext;
            prev->_pNext = next;
            next->_pPre = prev;

            delete cur;

            return next;
        }
        void clear()
        {
            iterator it = begin();
            while (it != end())
            {
                it = erase(it);
            }
        }
        void swap(list<T>& l)
        {
            std::swap(_pHead, l._pHead);
            std::swap(_size, l._size);
        }
    private:
        PNode _pHead;
        size_t _size;
        void CreateHead()
        {
            _pHead = new Node;
            _pHead->_pNext = _pHead;
            _pHead->_pPre = _pHead;
            _size = 0;
        }
    };
};