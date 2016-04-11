//
// Created by magomed on 03.04.16.
//

#ifndef EX4_ARRAY_H
#define EX4_ARRAY_H


class Array {
public:
    Array();

    ~Array();

    Array(const Array &tmp);

    bool is_empty() const;

    char get_at(int index) const;

    void push_back(char element);

    void operator=(const Array &tmp);

    bool operator==(const Array &tmp) const;

    int get_reallsize() const;

    void print() const;

private:
    void grow();

    char *buffer_;
    int buffsize_;
    int reallsize_;
};


#endif //EX4_ARRAY_H
