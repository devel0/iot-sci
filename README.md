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

Install using vscode command palette `PlatformIO: New Terminal` referring to [platformio registry](https://platformio.org/lib/show/11564/iot-utils/installation) cli mode doc.

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

## How this project was built

- platformio / new project
- set platformio.ini and library.json

References:
- [Creating Library](https://docs.platformio.org/en/latest/librarymanager/creating.html?utm_medium=piohome&utm_source=platformio)
- [library.json](https://docs.platformio.org/en/latest/librarymanager/config.html)
