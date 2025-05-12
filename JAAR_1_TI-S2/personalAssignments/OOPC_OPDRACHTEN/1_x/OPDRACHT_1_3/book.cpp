#include <iostream>
#include "book.hpp"

void book::print()
{
  print_title();
  print_author();
  print_text();
}
void book::print_text()
{
  std::cout << text << "\n";
}
void book::print_title()
{
  std::cout << title << "\n";
}
void book::print_author()
{
  std::cout << author << "\n";
}