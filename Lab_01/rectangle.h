/*
 * Rectangle.h
 *
 *  Created on: Aug 27, 2014
 *      Author: sunx4
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_


class Rectangle {
  private:
    int width, height;
  public:
    Rectangle();
    int perimeter();
    void set_values (int,int);
    int area();
};




#endif /* RECTANGLE_H_ */
