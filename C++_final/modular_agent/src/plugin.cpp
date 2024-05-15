// src/plugin.cpp
#include <iostream>
#include <Python.h>

void loadPlugins() {
    std::cout << "Loading Python plugin modules...\n";

    // Initialize Python interpreter
    Py_Initialize();

    // Add plugins directory to Python module search path
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append('plugins')");

    // Import gpt4_api module for plugin generation
    PyObject *pNameGPT4 = PyUnicode_DecodeFSDefault("gpt4_api");
    PyObject *pModuleGPT4 = PyImport_Import(pNameGPT4);
    Py_DECREF(pNameGPT4);

    if (pModuleGPT4 != NULL) {
        // Call generatePlugins function from gpt4_api module
        PyObject *pFuncGeneratePlugins = PyObject_GetAttrString(pModuleGPT4, "generatePlugins");
        if (pFuncGeneratePlugins && PyCallable_Check(pFuncGeneratePlugins)) {
            PyObject *pArgs = PyTuple_New(0);
            PyObject *pGeneratedPlugins = PyObject_CallObject(pFuncGeneratePlugins, pArgs);
            Py_DECREF(pArgs);

            if (pGeneratedPlugins != NULL && PyList_Check(pGeneratedPlugins)) {
                // Iterate over the generated plugins
                Py_ssize_t num_plugins = PyList_Size(pGeneratedPlugins);
                for (Py_ssize_t i = 0; i < num_plugins; ++i) {
                    PyObject *pPlugin = PyList_GetItem(pGeneratedPlugins, i);
                    if (pPlugin != NULL && PyDict_Check(pPlugin)) {
                        // Extract plugin name and content from the dictionary
                        PyObject *pNameObj = PyDict_GetItemString(pPlugin, "name");
                        PyObject *pContentObj = PyDict_GetItemString(pPlugin, "content");
                        if (pNameObj != NULL && pContentObj != NULL) {
                            const char *name = PyUnicode_AsUTF8(pNameObj);
                            const char *content = PyUnicode_AsUTF8(pContentObj);

                            // Write the generated plugin to a file
                            std::string filename = "plugins/" + std::string(name) + ".py";
                            FILE *file = fopen(filename.c_str(), "w");
                            if (file != NULL) {
                                fprintf(file, "%s", content);
                                fclose(file);
                                std::cout << "Generated plugin written to " << filename << std::endl;

                                // Import the generated plugin module
                                PyObject *pNamePlugin = PyUnicode_DecodeFSDefault(name);
                                PyObject *pModulePlugin = PyImport_Import(pNamePlugin);
                                Py_DECREF(pNamePlugin);

                                if (pModulePlugin != NULL) {
                                    // Call a function from the generated plugin module
                                    PyObject *pFunc = PyObject_GetAttrString(pModulePlugin, "execute");
                                    if (pFunc && PyCallable_Check(pFunc)) {
                                        PyObject *pArgs = PyTuple_New(0);
                                        PyObject *pResult = PyObject_CallObject(pFunc, pArgs);
                                        Py_DECREF(pArgs);

                                        if (pResult != NULL) {
                                            // Print the result
                                            char *result;
                                            PyArg_Parse(pResult, "s", &result);
                                            std::cout << "Plugin " << name << " executed: " << result << std::endl;
                                            Py_DECREF(pResult);
                                        } else {
                                            PyErr_Print();
                                            std::cerr << "Call to plugin " << name << " failed" << std::endl;
                                        }
                                        Py_XDECREF(pFunc);
                                    } else {
                                        if (PyErr_Occurred())
                                            PyErr_Print();
                                        std::cerr << "Cannot find function 'execute' in plugin " << name << std::endl;
                                    }
                                    Py_DECREF(pModulePlugin);
                                } else {
                                    PyErr_Print();
                                    std::cerr << "Failed to import plugin " << name << std::endl;
                                }
                            } else {
                                std::cerr << "Failed to write plugin " << name << " to file" << std::endl;
                            }
                        } else {
                            std::cerr << "Failed to extract plugin name or content" << std::endl;
                        }
                    } else {
                        std::cerr << "Invalid plugin object" << std::endl;
                    }
                }
            } else {
                PyErr_Print();
                std::cerr << "Failed to get generated plugins" << std::endl;
            }
            Py_XDECREF(pFuncGeneratePlugins);
        } else {
            if (PyErr_Occurred())
                PyErr_Print();
            std::cerr << "Cannot find function 'generatePlugins' in gpt4_api module" << std::endl;
        }
        Py_DECREF(pModuleGPT4);
    } else {
        PyErr_Print();
        std::cerr << "Failed to import gpt4_api module" << std::endl;
    }

    // Finalize Python interpreter
    Py_Finalize();
}

int main() {
    loadPlugins();
    return 0;
}
