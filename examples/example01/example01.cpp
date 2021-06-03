#ifndef UNIT_TEST

#include <sys-debug.h>
#include <string-utils.h>
#include <number-utils.h>

#include "Vector3D.h"
#include "Circle3D.h"
#include "Arc3D.h"
#include "CoordinateSystem3D.h"

#define TEST_ASSERT_TRUE ;
#define TEST_ASSERT_FALSE ;

#if defined(ARDUINO)
void setup()
#else
int main()
#endif
{         
    printf("START\n");

    Vector3D a(1, 2, 3);
    Vector3D b(4, 5, 6);

    Vector3D v = a + b;

    printf("%s\n", v.ToString().c_str());
}

#if defined(ARDUINO)
void loop()
{
}
#endif

#endif