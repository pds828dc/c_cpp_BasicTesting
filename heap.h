// Data Structure Test: Priority Queue MaX Heap
#ifndef HEAP_H
#define HEAP_H

template <typename T>
class MaxHeap{
    private:
        T *Heap;
        int Capacity, HeapSize;
    public:
        MaxHeap(int=10);
        ~MaxHeap();
        bool IsEmpty();
        void ChangeSize1D(T* &, const int&, const int&);
        const T &Top();
        void Push(const T&);
        void Pop();
};
template <typename T>
MaxHeap<T>::MaxHeap(int theCapacity)
    : Capacity(theCapacity > 0 ? theCapacity : 10),
      HeapSize(0) 
{
    Heap = new T[Capacity + 1];
}
template<typename T>
MaxHeap<T>::~MaxHeap(){
    delete [] Heap;   
}
template<typename T>
void MaxHeap<T>::ChangeSize1D(T * &arr,const int& size,const int& ToSize){
    T* tmp = new T[size];
    tmp = arr;
    arr = new T[ToSize];
    for(int i=0; i< size; ++i){
    arr[i] = tmp[i];
    }
    delete[] tmp;
}
template<typename T>
bool MaxHeap<T>::IsEmpty(){
    if(HeapSize==0){
        return true;
    }
    return false;
}
template<typename T>
const T& MaxHeap<T>::Top(){
    if(!IsEmpty())
    {
        return Heap[1];
    }
    throw "Heap is EMPTY !!";
    return Heap[0];
}
template<typename T>
void MaxHeap<T>::Push(const T& e){
    if(HeapSize==Capacity){
        ChangeSize1D(Heap, Capacity, 2 * Capacity);
        Capacity *= 2;
    }
    int CurrentNode = ++HeapSize;
    while(CurrentNode!=1 && Heap[CurrentNode/2]<e){
        Heap[CurrentNode] = Heap[CurrentNode / 2];
        CurrentNode = CurrentNode / 2;
    }
    Heap[CurrentNode] = e;
}
template<typename T>
void MaxHeap<T>::Pop(){
    if(IsEmpty())
        throw "Heap is EMPTY NOW!!";
    Heap[1].~T();    // destroy max element
    T lastE = Heap[HeapSize--];

    int CurrentNode = 1;
    int Child = 2;
    while(Child<=HeapSize){
        if(Child<HeapSize && Heap[Child]< Heap[Child + 1])
            Child++;
        if (lastE >= Heap[Child])
            break;
        Heap[CurrentNode] = Heap[Child];
        CurrentNode = Child;
        Child *= 2;
    }
    Heap[CurrentNode] = lastE;
}
#endif