#pragma once
#ifndef PROPERTY_HPP
#define PROPERTY_HPP

template <typename T> class Property {
private:
  T &_value;

public:
  Property(T &value) {}
  Property<T> operator=(const T &val) {
    _value = val;
    return *this;
  }

  operator const T &() const { return _value; }
};

#endif
