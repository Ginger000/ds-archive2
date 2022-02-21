#pragma once

class Circle {
  private:
    double r;

  public:
    double getArea();
    void setRadius(double r);

    void pass_by_value(Circle c);
  void pass_by_pointer(Circle* ptr);
  void pass_by_ref(Circle & c);
};
