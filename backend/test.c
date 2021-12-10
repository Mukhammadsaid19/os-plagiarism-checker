#include <stdio.h>
#include <Python.h>

int main()
{
	PyObject *pName, *pModule, *pFunc;
    PyObject *pArgs, *pValue;
    int i;
	const char* module_name = "main";
	const char* func_name = "compare";

    Py_Initialize();
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('.')");
	PyRun_SimpleString("sys.path.append('../logic')");
    pName = PyUnicode_DecodeFSDefault(module_name);

    pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        pFunc = PyObject_GetAttrString(pModule, func_name);
        /* pFunc is a new reference */

        if (pFunc && PyCallable_Check(pFunc)) {
			int arg_count = 2;
			const char *args[2];
			args[0] = "original";
			args[1] = "copy";
            pArgs = PyTuple_New(arg_count);
            for (i = 0; i < arg_count; ++i) {
				pValue = PyUnicode_DecodeFSDefault(args[i]);
                // pValue = PyLong_FromLong(atoi(args[i]));
                if (!pValue) {
                    Py_DECREF(pArgs);
                    Py_DECREF(pModule);
                    fprintf(stderr, "Cannot convert argument\n");
                    return 1;
                }
                /* pValue reference stolen here: */
                PyTuple_SetItem(pArgs, i, pValue);
            }
            pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);
            if (pValue != NULL) {
                printf("Result of call: %f\n", PyFloat_AsDouble(pValue));
                Py_DECREF(pValue);
            }
            else {
                Py_DECREF(pFunc);
                Py_DECREF(pModule);
                PyErr_Print();
                fprintf(stderr,"Call failed\n");
                return 1;
            }
        }
        else {
            if (PyErr_Occurred())
                PyErr_Print();
            fprintf(stderr, "Cannot find function \"%s\"\n", func_name);
        }
        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load \"%s\"\n", func_name);
        return 1;
    }
    if (Py_FinalizeEx() < 0) {
        return 120;
    }
    return 0;
}