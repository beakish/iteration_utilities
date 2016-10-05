static PyObject *
reduce_one(PyObject *self, PyObject *iterable)
{
    PyObject *iterator;
    PyObject *item1, *item2;

    iterator = PyObject_GetIter(iterable);
    if (iterator == NULL) {
        return NULL;
    }

    item1 = (*Py_TYPE(iterator)->tp_iternext)(iterator);
    if (item1 == NULL) {
        PyErr_Clear();
        Py_DECREF(iterator);
        PyErr_Format(PyExc_ValueError, "not enough values to unpack (expected 1, got 0)");
        return NULL;
    }

    item2 = (*Py_TYPE(iterator)->tp_iternext)(iterator);
    if (item2 != NULL) {
        PyErr_Clear();
        Py_DECREF(iterator);
        Py_DECREF(item1);
        Py_DECREF(item2);
        PyErr_Format(PyExc_ValueError, "too many values to unpack (expected 1).");
        return NULL;
    }

    Py_DECREF(iterator);

    return item1;
}


PyDoc_STRVAR(reduce_one_doc, "one(iterable)\n\
\n\
Return the first value in the `iterable` and expects it only contains one element.\n\
\n\
Parameters\n\
----------\n\
iterable : iterable\n\
    The `iterable` from which to get the one item.\n\
\n\
Returns\n\
-------\n\
one : any type\n\
    The first value.\n\
\n\
Raises\n\
-------\n\
ValueError :\n\
    If the `iterable` contains no items or more than one item.\n\
\n\
Examples\n\
--------\n\
Some basic examples::\n\
\n\
    >>> from iteration_utilities import one\n\
    >>> first([0])\n\
    0\n\
    >>> from iteration_utilities import one\n\
    >>> first('b')\n\
    'b'\n\
\n\
.. warning::\n\
    `one` will access the first two values of the `iterable` so it should\n\
    only be used if the `iterable` must only contain one item!\n\
");