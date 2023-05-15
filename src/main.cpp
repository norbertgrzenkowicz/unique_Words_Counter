#include "File_Map.h"

int main(int argc, char *argv[])
{
    auto fileMap = std::make_unique<File_Map>(argc, std::string{argv[1]});

    fileMap->run_mapping();
    fileMap->count_map();
}