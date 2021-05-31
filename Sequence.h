//
// Created by arina on 04.05.2021.
//

#ifndef LAB2_SEQUENCE_H
#define LAB2_SEQUENCE_H
template<class T>
class Sequence {
public:
    class IndexOutOfRange{
    public:
        int length;
        int index;
        IndexOutOfRange(int length, int index): length(length), index(index) {};
        IndexOutOfRange(): length(-1), index(-1) {};
    };

    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int index) const = 0;
    virtual void Set(T item, int index) = 0;
    virtual T &operator [] (int index) = 0;

    virtual Sequence<T>* GetSubSequence( int startIndex, int endIndex) = 0;
    virtual int GetLength() const = 0;

    virtual void Append (T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void Insert(T item, int index) = 0;

    virtual Sequence<T>* Concat (Sequence<T> *sequence) = 0;

};
#endif //LAB2_SEQUENCE_H
