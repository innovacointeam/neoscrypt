#include <Python.h>

#include "neoscrypt.h"

static PyObject *neoscrypt_gost_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    neoscrypt((char *)PyBytes_AsString((PyObject*) input), output);
#else
    neoscrypt((char *)PyString_AsString((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef neoscryptMethods[] = {
    { "getPoWHash", neoscrypt_gost_getpowhash, METH_VARARGS, "Returns the proof of work hash using neoscrypt hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef neoscryptModule = {
    PyModuleDef_HEAD_INIT,
    "neoscrypt",
    "...",
    -1,
    neoscryptMethods
};

PyMODINIT_FUNC PyInit_neoscrypt(void) {
    return PyModule_Create(&neoscryptModule);
}

#else

PyMODINIT_FUNC initneoscrypt(void) {
    (void) Py_InitModule("neoscrypt", neoscryptMethods);
}
#endif