#include "Array.hpp"
#include <iostream>
#include <stdexcept>
#include <exception>
using namespace std;

Array::Array(const Array::size_type& n)
throw(bad_alloc, invalid_argument)
{
    First = 0;
    Count = Size = n;
    elems = new value_type[Size];
    for (UINT i = 0; i < Size; i++)
        elems[i] = 0;
}

Array::Array(const iterator first, const iterator last)
throw(bad_alloc, invalid_argument)
{
    First = 0;
    if (first <= last) {
        Count = Size = (last - first) + 1;
        elems = new value_type[Size];
        for (UINT i = 0; i < Size; ++i)
            elems[i] = 0;
    }
    else
        throw invalid_argument("!!!");
}

Array::Array(const size_type first, const size_type last)
throw(bad_alloc, invalid_argument)
{
    if (first <= last) {
        First = first;
        Count = Size = (last - first) + 1;
        elems = new value_type[Size];
        for (UINT i = 0; i < Size; ++i)
            elems[i] = 0;
    }
    else
        throw invalid_argument("!!!");
}

Array::Array(const Array& t) throw(bad_alloc)
    : Size(t.Size), Count(t.Count), First(t.First), elems(new value_type[Size])
{
    for (UINT i = 0; i < Size; ++i)
        elems[i] = t.elems[i];
}

Array& Array::operator =(const Array& t)
{
    Array tmp(t);
    swap(tmp);
    return *this;
}

Array::~Array()
{
    delete[]elems;
    elems = 0;
}

void Array::push_back(const value_type& v)
{
    if (Count == Size)
        resize(Size * 2);    
    elems[Count++] = v;
}

Array::value_type Array::pop_back() throw(out_of_range)
{
    if (empty())
        throw out_of_range("Empty array!");
    value_type x = back();
    value_type* tmp = new value_type[size() - 1];
    for (int i = 0; i < Count - 1; ++i)
        tmp[i] = elems[i];
    delete[] elems;
    elems = tmp;
    Size = size() - 1;
    Count--;
    return x;
}

Array::reference Array::operator [](size_type index) throw(out_of_range)
{
    if ((First <= index) && (index < First + Size))
        return elems[index - First];
    else
        throw out_of_range("Index out of range!");
}

Array::const_reference Array::operator [](size_type index) const
throw(out_of_range)
{
    if ((First <= index) && (index < First + Size))
        return elems[index - First];
    else
        throw out_of_range("Index out of range!");
}

void Array::resize(size_type newsize) throw(bad_alloc)
{
    if (newsize > capacity())
    {
        value_type* data = new value_type[newsize];
        for (size_type i = 0; i < Count; ++i)
            data[i] = elems[i];
        delete[] elems;
        elems = data;
        Size = newsize;
    }
}

void Array::swap(Array& other)
{
    std::swap(elems, other.elems);
    std::swap(Size, other.Size);
}

void Array::assign(const value_type& v)
{
    for (int i = 0; i < Count; i++)
    {
        elems[i] = v;
    }
}

Array::size_type Array::capacity() const
{
    return Size;
}

Array::size_type Array::size() const
{
    return Count;
}

bool Array::empty() const
{
    return Count == 0;
}

ostream& operator <<(ostream& out, const Array& tmp)
{
    for (size_t j = 0; j < tmp.Count; j++)
        out << tmp[j] << " ";
    out << endl;
    return out;
}

istream& operator >>(istream& in, Array& tmp)
{
    for (size_t i = 0; i < tmp.Count; i++)
    {
        cout << "arr[" << i << "]: "; in >> tmp[i];
    }
    return in;
}

Array::value_type Array::sum()
{
    value_type sum = 0;
    for (size_t i = 0; i < Count; i++)
        sum += elems[i];
    return sum;
}

Array::value_type Array::average()
{
    value_type sum = 0;
    for (size_t i = 0; i < Count; i++)
        sum += elems[i];
    double average = sum/Count;
    return abs(average);
}

void Array::add_absolute_non_pair()
{
    for (int i = 0; i < Count; i++)
    {
        int a = elems[i];
        if (a % 2 != 0)
        {
            value_type mean = abs(a);
            for (int i = 0; i < Count; i++)
            {
                elems[i] += mean;
            }
            break;
        }
    }
}
