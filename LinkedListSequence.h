//
// Created by arina on 04.05.2021.
//

#ifndef LAB2_LINKEDLISTSEQUENCE_H
#define LAB2_LINKEDLISTSEQUENCE_H

#include "Sequence.h"
#include "LinkedList.h"

template<class T>
class LinkedListSequence : public Sequence<T> {
private:
    LinkedList<T> linkedlist;
public:
    class IndexOutOfRange {
    public:
        int lenght;
        int index;

        IndexOutOfRange(int lenght, int index) : lenght(lenght), index(index) {};

        IndexOutOfRange() : lenght(-1), index(-1) {};
    };

    LinkedListSequence() {
        linkedlist = LinkedList<T>();
    }

    LinkedListSequence(T *items, int count) {
        linkedlist = LinkedList<T>(items, count);
    }

//проверить
    LinkedListSequence(const LinkedList<T> &list) {
        linkedlist = LinkedList<T>(list);
    }

    T GetFirst() {
        if (linkedlist.GetLength() == 0)
            throw IndexOutOfRange(0, 0);
        return linkedlist.GetFirst();
    }

    T GetLast() {
        if (linkedlist.GetLength() == 0)
            throw IndexOutOfRange(0, 0);
        return linkedlist.GetLast();
    }

    T Get(int index) const {
        if (index < 0 || index >= linkedlist.GetLength())
            throw IndexOutOfRange(linkedlist.GetLength(), index);
        return linkedlist.Get(index);
    }

    T PopEnd() {
        return linkedlist.PopEnd();
    }

    T PopFirst() {
        return linkedlist.PopFirst();
    }

    void Set(int index,T item) {
        if (index < 0 || index >= linkedlist.GetLength())
            throw IndexOutOfRange(linkedlist.GetLength(), index);
        return linkedlist.Set(index,item);
    }

    T &operator[](int index) {
        if (index < 0 || index >= linkedlist.GetLength()) throw IndexOutOfRange(linkedlist.GetLength(), index);
        return linkedlist[index];
    }

    LinkedListSequence<T> *GetSubSequence(int startIndex, int endIndex) {
        if (startIndex < 0 || startIndex >= linkedlist.GetLength())
            throw IndexOutOfRange(linkedlist.GetLength(), startIndex);

        if (endIndex < 0 || endIndex > linkedlist.GetLength())
            throw IndexOutOfRange(linkedlist.GetLength(), endIndex);

        auto *resList = linkedlist.GetSubList(startIndex, endIndex);
        auto *res = new LinkedListSequence<T>(*resList);
        delete resList;

        return res;
    }

    int GetLength() const {
        return linkedlist.GetLength();
    }

    void Append(T item) {
        linkedlist.Append(item);
    }

    void Prepend(T item) {
        linkedlist.Prepend(item);
    }

    void Insert(T item, int index) {
        if (index < 0 || index >= linkedlist.GetLength())
            throw IndexOutOfRange(linkedlist.GetLength(), index);
        linkedlist.Insert(item, index);
    }

    Sequence<T> *Concat(Sequence<T> *list) {
        for (int i = 0; i < list->GetLength(); i++) {
            Append(list->Get(i));
        }
        return this;
    }

    friend std::ostream& operator << (std::ostream& cout, LinkedListSequence<T> linkedListSequence) {
        return cout << linkedListSequence.linkedlist;
    }
    friend std::ostream& operator << (std::ostream& cout, LinkedListSequence<T> *linkedListSequence) {
        return cout << linkedListSequence->linkedlist;
    }

};

#endif //LAB2_LINKEDLISTSEQUENCE_H
