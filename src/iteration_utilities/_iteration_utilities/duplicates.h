#ifndef PYIU_DUPLICATES_H
#define PYIU_DUPLICATES_H

#include <Python.h>
#include "helpercompat.h"

typedef struct {
    PyObject_HEAD
    PyObject *iterator;
    PyObject *key;
    PyObject *seen;
} PyIUObject_Duplicates;

extern PyTypeObject PyIUType_Duplicates;

#endif