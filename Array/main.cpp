#include <iostream>
#include <cstring>

using namespace std;

template <class T>
class Array {
public:
    Array();

    ~Array();

    Array(const Array &tmp);

    bool is_empty() const;

    T get_at(int index) const;

    virtual void push_back(T element);

    void operator=(const Array &tmp);

    int get_reallsize() const;

    void print() const;

protected:
    void grow();

    T *buffer_;
    int buffsize_;
    int reallsize_;
};

template <class T>
Array<T>::Array() :
        buffer_(new T[10]),
        reallsize_(0),
        buffsize_(10) { }

template <class T>
Array<T>::~Array() {
    delete[] buffer_;
}

template <class T>
Array<T>::Array(const Array &tmp)
        : reallsize_(0),
          buffsize_(tmp.buffsize_)
{
    buffer_ = new T[tmp.buffsize_];
    for (int i = 0; i < tmp.reallsize_; ++i) {
        buffer_[reallsize_++] = tmp.buffer_[i];
    }
}

template <class T>
T Array<T>::get_at(int index) const {
    return buffer_[index];
}

template <class T>
bool Array<T>::is_empty() const {
    return reallsize_ == 0;
}

template <class T>
void Array<T>::grow() {
    int new_buffsize = max(buffsize_ * 2, 1);
    T *new_arr = new T[new_buffsize];
    memcpy(new_arr, buffer_, reallsize_ * sizeof(T));
    delete[] buffer_;
    buffer_ = new_arr;
    buffsize_ = new_buffsize;
}

template <class T>
void Array<T>::push_back(T element) {
    if (reallsize_ == buffsize_) { grow(); }
    buffer_[reallsize_++] = element;
}

template <class T>
void Array<T>::print() const {
    for (int i = 0; i < reallsize_; ++i) {
        cout << buffer_[i] << " ";
    }
}

template <class T>
void Array<T>::operator=(const Array &tmp) {
    for (int i = 0; i < tmp.reallsize_; ++i) {
        push_back(tmp.get_at(i));
    }
    reallsize_ = tmp.reallsize_;
    buffsize_ = tmp.buffsize_;
}

template <class T>
int Array<T>::get_reallsize() const {
    return reallsize_;
}

int main() {
    Array<char> tmp;
    tmp.print();
    return 0;
}