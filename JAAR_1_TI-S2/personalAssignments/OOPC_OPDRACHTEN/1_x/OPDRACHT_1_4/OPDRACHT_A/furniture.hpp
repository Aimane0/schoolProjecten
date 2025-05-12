#ifndef FURNITURE.HPP
#define FURNITURE .HPP

#include <ostream>

class Stool
{
private:
    int n_legs;
    int n_seats;

public:
    Stool(int legs, int seats) : n_legs(legs), n_seats(seats) {}
    void print_legs();
    void print_seats();
    void print_stool();
    void remove_legs();
};

class Table
{
private:
    int n_legs;
    int length;
    int width;
    void print_legs();
    void print_length();
    void print_width();

public:
    Table(int legs, int length, int width) : n_legs(legs), length(length), width(width){}
    void receive_legs(int received_legs);
    void print_table();
    
};

class Furniture
{
private:
    Stool stool1;
    Stool stool2;
    Stool stool3;
    Stool stool4;
    Table table1;

public:
    Furniture();
    void makeMoreHipster();
    void print_furniture();
};

#endif // FURNITURE_HPP