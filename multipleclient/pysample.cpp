 #include <Python.h>
 #include "server.h"
 
 static PyObject *py_mnmain(PyObject *self, PyObject *args) {
     int x, y, result;
 
     if (!PyArg_ParseTuple(args, "ii", &x, &y)) {
         return NULL;
     }
     result = mnmain(x, y);
     return Py_BuildValue("i", result);
 }
 
 
 /* module method table */
 static PyMethodDef SampleMethods[] = {
     {"mnmain", py_mnmain, METH_VARARGS, "Greatest commond divisor"},
    // {"divide", py_divide, METH_VARARGS, "Integer division"},
     {NULL, NULL, 0, NULL}
 };
 
 static struct PyModuleDef samplemodule = {
     PyModuleDef_HEAD_INIT,
     "sample",    /* name of module */
     "A sample module",  /* doc string, may be NULL */
     -1, /* size of per-interpreter state of the module, 
            or -1 if the module keeps state in global variables */
     SampleMethods   /* methods table */
 };  
 
 PyMODINIT_FUNC
 PyInit_sample(void){
     return PyModule_Create(&samplemodule);
 } 
