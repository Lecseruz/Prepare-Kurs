//
// Created by magomed on 05.04.16.
//

#ifndef EX5_ARRAY_H
#define EX5_ARRAY_H


class Array {
public:
    Array();

    ~Array();

    Array(const Array &tmp);

    bool is_empty() const;

    int get_at(int index) const;

    virtual void push_back(int element);

    void operator=(const Array &tmp);

    int get_reallsize() const;

    void print() const;

protected:
    void grow();

    int *buffer_;
    int buffsize_;
    int reallsize_;
};


#endif //EX5_ARRAY_H
