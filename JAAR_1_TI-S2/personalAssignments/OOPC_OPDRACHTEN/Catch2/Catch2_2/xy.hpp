#ifndef XY_HPP
#define XY_HPP

class xy {
public:
   int x;
   int y; 
   
   xy( int x, int y ): 
      x( x ), y( y )
   {}
   
   xy():
      x( 0 ), y( 0 )
   {}
   
};

#endif