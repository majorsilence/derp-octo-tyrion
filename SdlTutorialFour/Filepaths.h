#ifndef FILEPATHS_INCLUDED
#define FILEPATHS_INCLUDED

#include <iostream>

#if defined(WIN32) || defined(_WIN32)
const std::string PATH_SEPARATOR = "\\";
#else
const std::string PATH_SEPARATOR = "/";
#endif

#endif // FILEPATHS_INCLUDED
