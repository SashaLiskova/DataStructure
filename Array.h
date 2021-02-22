#pragma once

#define DEF_SIZE 10

using namespace std;

template<typename T>
class Array
{
private:
    int user_size;
    int actual_size;
    T* array;



public:
    Array();
    Array(int n);
    Array(int n, T object);
    Array(T *list, int size);


    ~Array();




    int get_size();

    T show_element();//shows last element 
    T show_elememt_at(int pos);

    void push(T element);//push to last position 
    void push_at(T elemnt, int poz);

    T pull();//get from last position
    T pull_at(int poz);

    void to_print();
    void expand();
    void shrink();



    //iterators&

};

template<typename T>
Array<T>::Array()
{
    

    user_size = 0;
    actual_size = DEF_SIZE;
    array = new T[actual_size];

    //constructor call test
    cout << ":Array()" << endl;
    to_print();

};

template<typename T>
Array<T>::Array(int n)
{

    user_size = 0;
    actual_size = n+ DEF_SIZE;
    array = new T[actual_size];

    //constructor call test
    cout << ":Array(int n)" << endl;
    to_print();
}

template<typename T>
Array<T>::Array(int n, T obj)
{
    user_size = n;
    actual_size = n + 10;
    array = new T[actual_size];

    for (int i = 0; i < user_size; ++i)
    {
        array[i] = obj;//??
    }

    //constructor call test
    cout << ":Array(int n, T obj)" << endl;
    to_print();
}

template<typename T>
Array<T>::Array(T *list, int size)
{
    user_size = size;
    actual_size = user_size + DEF_SIZE;

    array = new T[actual_size];
    for (int i = 0; i < user_size; ++i)
    {
        array[i] = list[i];

    }


    //constructor call test
    cout << "Array(T *list, int size)" << endl;
    to_print();
    
}

template<typename T>
Array<T>::~Array()
{
    delete[] array;
}

template <typename T>
int Array<T>::get_size()
{
    return user_size;
}

template<typename T>
T Array<T>::show_element()
{
    if (user_size == 0)
        return nullptr;
    else
        return array[user_size - 1];
}

template <typename T>
T Array<T>::show_elememt_at(int pos)
{
    if (user_size == 0 || pos >= user_size - 1 || pos < 0)
        return nullptr;
    else
        return array[pos];
}

template <typename T>
void Array<T>::push(T element)
{
    if (user_size >= actual_size)
        expand();

    array[user_size] = element;
    user_size++;
}

template<typename T>
void Array<T>::push_at(T elemnt, int poz)
{
    
    if (poz > user_size)//go to the end
    {
        push(elemnt);
    }
    else if (poz < 0)
    {
        //do notheng, or insert on first position

    }else
    {
        if (user_size >= actual_size)
            expand();

        T* temp_array = new T[actual_size];

        for (int i = 0; i < poz; ++i)
        {
           
            temp_array[i] = array[i];
        }

        temp_array[poz] = elemnt;

        for (int i = poz; i < user_size; ++i)
        {
            temp_array[i+1] = array[i];
        }

        user_size++;

        delete[] array;
        array = nullptr;
        array = temp_array;

        temp_array = nullptr;
    }
}

template<typename T>
void Array<T>::expand()
{
    T* temp_array = new T[actual_size * 2];
    
    for (int i = 0; i < user_size; ++i)
    {
        temp_array[i] = array[i];
    }

    delete[] array;
    array = nullptr;
    array = temp_array;

   temp_array = nullptr;//if i will coment this i will have mistake dont know why
    delete[] temp_array;
    actual_size = actual_size * 2;
}

template <typename T>
void  Array<T>::to_print()
{
    cout << "array size is:"<<user_size<<" elements are: ";
    for (int i = 0; i < user_size; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

template <typename T>
T Array<T>::pull()
{
    //just simply copy ?
    T res = array[user_size - 1];
    user_size--;
     //is there a sence of cleaning memory after pull?
    return res;
    


}

template <typename T>
T Array<T>::pull_at(int poz)
{

    if (poz > user_size)//go to the end
    {
        return NULL;//another better way?? exception ?
    }
    else if (poz < 0)
    {
        //do notheng, or insert on first position
        //exception?
    }
    else
    {
       
        T* temp_array = new T[actual_size];

        for (int i = 0; i < poz; ++i)
        {

            temp_array[i] = array[i];
        }

        T res = array[poz];

        for (int i = poz; i < user_size-1; ++i)
        {
            temp_array[i] = array[i+1];//??
        }

        user_size--;

        delete[] array;
        array = nullptr;
        array = temp_array;

        temp_array = nullptr;

        return res;
    }
}
