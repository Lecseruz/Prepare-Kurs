#include <iostream>
#include "array.h"
#include "Worker.h"

using namespace std;


void worker_experience(Worker *&worker, int count, int year, int experience) {
    cout << "Task a:" << endl;
    for (int i = 0; i < count; ++i) {
        int experience_worker = year - worker[i].get_year();
        if (experience_worker > experience) {
            worker[i].show();
        }
    }
}

void worker_salary(Worker *&worker, int count, int salary) {
    cout << "Task b:" << endl;

    for (int i = 0; i < count; ++i) {
       if (worker[i].get_salary() > salary) {
            worker[i].show();
        }

    }
}

void worker_work(Worker *workers, int count, Array work) {
    cout << "Task c" << endl;
    for (int i = 0; i < count; ++i) {
        if (workers[i].get_work() == work) {
            workers[i].show();
        }
    }
}

int main() {
    int count;
    cin >> count;
    char ch;
    Worker *workers = new Worker[count];
    for (int i = 0; i < count; ++i) {
        Array surname;
        Array initials;
        Array work;
        int year;
        int salary;
        while ((ch = (char) getchar()) == ' ' || ch == '\n');
        do {
            if (ch != '\n') {
                surname.push_back(ch);
            }
        }
        while ((ch = (char) getchar()) != ' ');

        while ((ch = (char) getchar()) == ' ' || ch == '\n');

        do {
            if (ch != '\n') {
                initials.push_back(ch);
            }
        }
        while ((ch = (char) getchar()) != ' ');

        while ((ch = (char) getchar()) == ' ' || ch == '\n');
        do {
            if (ch != '\n') {
                work.push_back(ch);
            }
        }
        while ((ch = (char) getchar()) != ' ');
        cin >> year >> salary;
        workers[i].set_surname(surname);
        workers[i].set_initials(initials);
        workers[i].set_work(work);
        workers[i].set_year(year);
        workers[i].set_salary(salary);

    }
    worker_salary(workers, count,50);
    worker_experience(workers, count, 2016, 55);
    delete[] workers;
    return 0;
}
