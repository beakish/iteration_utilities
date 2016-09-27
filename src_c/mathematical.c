#include <Python.h>
#include <structmember.h>

/******************************************************************************
 * Wrapper functions for simple arithmetic functions.
 *
 * square   : identical to pow(x, 2)
 *****************************************************************************/

// global variable
static PyObject *mathematical_long_2 = NULL;

// return global variable or if it's NULL initialize it.
// TODO: That's really weird to do it like this, no idea what the alternative
//       would be...
static PyObject*
mathematical_get_2(void) {
    if (mathematical_long_2 == NULL)
        mathematical_long_2 = PyLong_FromLong((long)2);

    return mathematical_long_2;
}

static PyObject*
mathematical_square(PyObject *self, PyObject *args) {
    return PyNumber_Power(args, mathematical_get_2(), Py_None);
}

PyDoc_STRVAR(mathematical_square_doc,
"square(value)\n\
\n\
Returns the squared `value`.\n\
\n\
Parameters\n\
----------\n\
value : any type\n\
    The value to be squared. The type of the `value` must support ``pow``.\n\
\n\
Returns\n\
-------\n\
square : any type\n\
    Returns ``value**2``.\n\
\n\
Examples\n\
--------\n\
It is not possible to apply ``functools.partial`` to ``pow`` so that one has\n\
a one-argument square function and is significantly faster than ``lambda x: x**2``::\n\
\n\
    >>> from iteration_utilities import square\n\
    >>> square(1)\n\
    1\n\
    >>> square(2.0)\n\
    4.0\n\
");