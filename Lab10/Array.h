//
// Created by Olariu Robert on 08.05.2023.
//

#ifndef LAB10_ARRAY_H
#define LAB10_ARRAY_H

#include <exception>
#include <iostream>
using namespace std;


class exceptie1: public exception{
    virtual const char* what() const throw(){
        return "Indexul este inafara domeniului!";
    }
};

class Compare

{

public:

    virtual int CompareElements(void* e1, void* e2) {

        return e1 > e2;

    }

};
template<class T>
class ArrayIterator {
private:
    int Current;
    T** List;

public:
    ArrayIterator() : Current(0), List(nullptr) {};

    ArrayIterator(T** list, int current) : List(list), Current(current) {};

    ArrayIterator<T>& operator++() {
        Current++;
        return *this;
    }

    ArrayIterator<T>& operator--() {
        Current--;
        return *this;
    }


    bool operator!=(const ArrayIterator<T>& other) const {
        return Current != other.Current;
    }

    T& operator*() {
        return *List[Current];
    }

    bool operator=(const ArrayIterator<T>& other) {
        List = other.List;
        Current = other.Current;
        return true;
    }

    T* GetElement() {
        return List[Current];
    }

};
template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
public:
    Array() : Capacity(0), Size(0), List(nullptr) {};

    ~Array() {

        for (int i = 0; i < Size; ++i) {
            delete List[i];
        }

        delete [] List;
        Capacity = 0;
        Size = 0;
    }
    Array(int capacity); // Lista e alocata cu 'capacity' elemente
    Array(const Array<T> &otherArray); // constructor de copiere

    T& operator[] (int index) {
        exceptie1 index_out_of_bounds;
        try
        {
            if (index < 0 || index >= Size)
                throw index_out_of_bounds;

            else return *(List[index]);
        }
        catch (exception& e)
        {
            cout << "Exceptie: " << e.what() << endl;
        }

    } // arunca exceptie daca index este out of range

    const Array<T>& operator+=(const T &newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this
    const Array<T>& Insert(int index, const T& newElem) {

        exceptie1 index_out_of_bounds;
        try
        {
            if (index < 0 || index > Size)
                throw index_out_of_bounds;
            else {
                List[index] = new T( newElem);

                Size++;

                return *this;
            }

        }
        catch (exception& e)
        {
            cout << "Exceptie: " << e.what() << endl;
        }



    }// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

    bool operator=(const Array<T> &otherArray);

    void Sort(); // sorteaza folosind comparatia intre elementele din T
    void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
    void Sort(Compare *comparator); // sorteaza folosind un obiect de comparatie

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
    int BinarySearch(const T& elem, Compare *comparator);//  cauta un element folosind binary search si un comparator

    int Find(const T& elem); // cauta un element in Array
    int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
    int Find(const T& elem, Compare *comparator);//  cauta un element folosind un comparator

    int GetSize();
    int GetCapacity();

    ArrayIterator<T> GetBeginIterator();
    ArrayIterator<T> GetEndIterator();
};


#endif //LAB10_ARRAY_H
