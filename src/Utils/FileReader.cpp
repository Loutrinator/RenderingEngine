//
// Created by Antoine on 05/01/2026.
//

#include "FileReader.h"
#include <fstream>
#include <ios>

///Reads the entirety of the file at the given path and returns it as a string
std::string FileReader::readFile(const std::string &path)
{
    std::ifstream in(path, std::ios::in | std::ios::binary);
    if (in)
    {
        std::string contents;
        in.seekg(0, std::ios::end);
        contents.resize(in.tellg());
        in.seekg(0, std::ios::beg);
        in.read(&contents[0], contents.size());
        in.close();
        return contents;
    }

    throw std::ios_base::failure("Could not find or read file at '" + path + "'");
}
