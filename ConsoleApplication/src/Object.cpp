#include "Object.h"

Object::Object() : x(3), y(2), z(1)
{

}

Object::~Object()
{
    x = 0;
    y = 0;
    z = 0;
}
