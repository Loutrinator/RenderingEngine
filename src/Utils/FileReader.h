//
// Created by Antoine on 05/01/2026.
//

#ifndef RENDERINGENGINE_FILEREADER_H
#define RENDERINGENGINE_FILEREADER_H

#include <string>

class FileReader
{
public:
    static std::string readFile(const std::string& path);
};

#endif //RENDERINGENGINE_FILEREADER_H