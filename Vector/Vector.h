#ifndef __VECTOR_H__
#define __VECTOR_H__//test
#include <iostream>
#include <exception>
using namespace std;
template <typename T> 
class Vector {

    private:
    T *vector;
    int size, capacity;

    void reset();
    void resize();
    void sizeDown();
    void sizeUp();

    public:
    //constructors
    Vector();
    Vector(const Vector & v);
    Vector<T> & operator=(const Vector<T> & rhs);
    Vector(Vector<T> && v);
    Vector<T> & operator=(Vector<T> && v);
    ~Vector();

    //getters
    int getCapacity();
    int getSize();
    T getAt(int position);
    int getFirst();
    int getLast();

    bool isEmpty();

    //operations
    void assign(int n, T x);
    void placeAt(int position, T x);
    void fitAt(int position, T x);
    void pushBack(T x);
    void popBack();
    void removeAt(int position);

	void free();
    T& operator[](int index);

    //print
    void print() const;
    
};

template <typename T>
void Vector<T>::reset(){

    size = 0;
    capacity = 1;
    vector = new T[capacity];
}
template <typename T>
void Vector<T>::resize(){

    T *temp = new T[2 * capacity];
    for(int i = 0; i < capacity; i++) {
        
        temp[i] = vector[i];
    }
    delete[] vector;
    vector = temp;
}
template <typename T>
void Vector<T>::sizeDown(){

    if(size > capacity / 2){

        return;
    }
    capacity /= 2;
    //resize();
}
template <typename T>
void Vector<T>::sizeUp(){

    resize();
    capacity *=2;
}
template <typename T>
Vector<T>::Vector(){ 
    reset(); 
}
template <typename T>
Vector<T>::Vector(const Vector& v):size(v.size), capacity(v.capacity), vector(new T[v.size]) {
    for (int i = 0; i < size; i++)
    {
        this->vector[i] = v.vector[i];
    }
    
}
template <typename T>
Vector<T> & Vector<T>::operator=(const Vector<T> & rhs){

    if (this != &rhs)
    {
        this -> size = rhs.size;
        delete[] vector;
        this->vector = new T[rhs.size];

        for (int i = 0; i < size; i++)
        {
            this->vector[i] = rhs.vector[i];
        }
    }
    
    
    return *this;
}
template <typename T>

Vector<T>::Vector(Vector<T> && v) {

    size = v.size;
    capacity = v.capacity;
    vector = v.vector;

    v.size = 0;
    v.capacity = 0;
    v.vector = nullptr;
}
template <typename T>
Vector<T> & Vector<T>::operator=(Vector<T> && v){

    if (this != &v){

        delete[] vector;

        size = v.size;
        capacity = v.capacity;
        vector = v.vector;

        v.size = 0;
        v.capacity = 0;
        v.vector = nullptr;
    }
    return *this;
}

template <typename T>
Vector<T>::~Vector(){ 
    delete[] vector; 
}
template <typename T>
int Vector<T>::getCapacity() {

    return capacity;
}
template <typename T>
int Vector<T>::getSize() {

    return size;
}
template <typename T>
bool Vector<T>::isEmpty() {

    return size == 0;
}
template <typename T>
T Vector<T>::getAt(int position) {

    if(!isEmpty()) { return vector[position]; }
    return 0;
}
template <typename T> 
int Vector<T>::getFirst() {

    if(!isEmpty()) return vector[0];
}
template <typename T>
int Vector<T>::getLast() {

    return vector[size - 1];
}
template <typename T>
void Vector<T>::assign(int n, T x) {

    delete[] vector;
    reset();
    for(int i = 0; i < n; i++){

        pushBack(x);
    }
}
template <typename T>
void Vector<T>::placeAt(int position, T x) {

    if (position > capacity) 
    {
        sizeUp();
    }
    vector[position] = x;
}
template <typename T>
void Vector<T>::fitAt(int position, T x) {

    if (size == capacity || position > capacity)
    {
        sizeUp();
    }
    for (int i = size; position < i; i--) {
        vector[i] = vector[i - 1];
    }
    vector[position] = x;
    size++;
}

template <typename T>
void Vector<T>::pushBack(T x){

    if (size == capacity)
    {
        sizeUp();
    }
    
    vector[size] = x;
    size++;
    
}
template <typename T>

void Vector<T>::popBack(){

    size--;
}
template <typename T>
void Vector<T>::removeAt(int position){

    if(isEmpty() || position >= size) { return; }
    for(int i = position; i < size; i++) {

        vector[i] = vector[i + 1];
    }
    //sizeDown();
    size--;
}
template <typename T>
void Vector<T>::print() const {

    for (int i = 0; i < size; i++)
    {
        cout << vector[i] << " "; 
    }
    cout << '\n';
}
template <typename T>
T& Vector<T>::operator[](int index) {

    if (index >= size)
    {
        throw runtime_error("Too big index");
    }
    return *(vector + index);
}

template <typename T>
void Vector<T>::free() { delete[] this-> vector; }
#endif