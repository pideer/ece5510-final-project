#pragma once

class Lock {
  public:
    virtual bool contains() = 0;
    virtual bool remove() = 0;
    virtual bool add() = 0;
};