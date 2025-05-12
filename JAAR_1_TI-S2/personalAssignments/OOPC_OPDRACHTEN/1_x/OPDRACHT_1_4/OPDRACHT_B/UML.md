-----------------------------------|
STOOL                              |
- n_legs: int                      |
- n_seats: int                     |
-----------------------------------|
+ Stool(legs: int, seats: int)     |
+ print_legs(): void               |
+ print_seats(): void              |
+ print_stool(): void              |
+ remove_legs(): void              |
-----------------------------------|


-----------------------------------------|
TABLE                                    |
- n_legs: int                            |
- length: int                            |
- width: int                             |
- print_legs(): void                     |
- print_length(): void                   |
- print_width(): void                    |
-----------------------------------------|
Table(legs: int, length: int, width: int)|
receive_legs(received_legs: int): void   |
print_table(): void                      |
-----------------------------------------|


-----------------------------------------|
FURNITURE                                |
- Stool stool1                           |
- Stool stool1                           |
- Stool stool1                           |
- Stool stool1                           |
- Table table1                           |
-----------------------------------------|
+ Furniture