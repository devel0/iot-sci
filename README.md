# iot-sci

<!-- TOC -->
* [Description](#description)
* [API](#api)
* [Quickstart](#quickstart)
* [Examples](#examples)
* [Debugging](#debugging)
* [Unit tests](#unit-tests)
* [How this project was built](#how-this-project-was-built)
<!-- TOCEND -->

<hr/>

## Description

Sci lib for ststm32 platform, mbed os framework.

## API

- [classes](data/api/index_classes.md)
- sci (arduino, mbed)
    - [Arc3D](data/api/Files/_arc3_d_8h.md)
    - [Circle3D](data/api/Files/_circle3_d_8h.md)
    - [CoordinateSystem3D](data/api/Files/_coordinate_system3_d_8h.md)
    - [Line3D](data/api/Files/_line3_d_8h.md)
    - [Matrix3D](data/api/Files/_matrix3_d_8h.md)
    - [Quaternion](data/api/Files/_quaternion_8h.md)
    - [Transform3D](data/api/Files/_transform3_d_8h.md.md)
    - [Vector3D](data/api/Files/_vector3_d_8h.md.md)

## Quickstart

Install using vscode command palette `PlatformIO: New Terminal` referring to [platformio registry](https://platformio.org/lib/show/12380/iot-sci/installation) cli mode doc.

## Examples
 

## Debugging

to debug examples/example01.cpp (included through [src/debug-main.cpp](src/debug-main.cpp));

from vscode hit F5. 

- [other references/troubleshoot](https://github.com/devel0/iot-stm32-ledblink-interrupt-debug#iot-stm32-ledblink-interrupt-debug)

## Unit tests

Test available [here](test/test-main.cpp).

To execute tests, from vscode command palette `PlatformIO: New Terminal` then

```sh
pio test
```

note: after start RESET may need to be pressed to start the test.

```
Testing...
If you don't see any output for the first 10 secs, please reset board (press reset button)

Stest/test-main.cpp:1592:torefact_Line3DTest_SplitTest  [PASSED]
test/test-main.cpp:1593:torefact_Line3DTest_EnsureFromTest      [PASSED]
test/test-main.cpp:1594:torefact_Line3DTest_NormalizedTest      [PASSED]
test/test-main.cpp:1595:torefact_Line3DTest_BisectTest  [PASSED]
test/test-main.cpp:1596:torefact_Line3DTest_LineOffseted        [PASSED]
test/test-main.cpp:1597:torefact_old_Line3DTest [PASSED]
test/test-main.cpp:1598:torefact_old_Vector3DTest       [PASSED]
test/test-main.cpp:1599:torefact_old_Vector3DTest2      [PASSED]
test/test-main.cpp:1600:torefact_old_Matrix3DTest       [PASSED]
test/test-main.cpp:1601:torefact_old_Circle3DTest       [PASSED]
test/test-main.cpp:1603:test_vector3d_normalized        [PASSED]
test/test-main.cpp:1604:test_vector3d_distance  [PASSED]
test/test-main.cpp:1605:test_transform3d        [PASSED]
test/test-main.cpp:1606:test_coordinate_system3d        [PASSED]
-----------------------
47 Tests 0 Failures 0 Ignored
================================================ [PASSED] Took 9.91 seconds ================================================

Test    Environment    Status    Duration
------  -------------  --------  ------------
*       nucleo_f446re  PASSED    00:00:09.907
=============================================== 1 succeeded in 00:00:09.907 ===============================================
```

## How this project was built

- platformio / new project
- set platformio.ini and library.json

References:
- [Creating Library](https://docs.platformio.org/en/latest/librarymanager/creating.html?utm_medium=piohome&utm_source=platformio)
- [library.json](https://docs.platformio.org/en/latest/librarymanager/config.html)
