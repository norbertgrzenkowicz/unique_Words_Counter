#include "File_Map.h"

File_Map::File_Map(const int args_count, const std::string &filename) : page_size{get_page_mask()},
                                                                        file_read_only{open(filename.c_str(), O_RDONLY)}
{
    if (args_count > 2)
        throw std::runtime_error("Invalid Input: Too many arguments!");

    std::ifstream file(filename, std::ios::in | std::ios::binary | std::ios::ate);
    if (!file.good())
        throw std::runtime_error("Invalid Input: Wrong Path!");

    map = std::make_unique<std::unordered_map<std::string, char>>();

    std::cout << "Opening and mem mapping file: " << filename << std::endl;

    file_size(file);

    _memory_buffer_size = (static_cast<size_t>(size) + page_size) & ~page_size;
    file_buffer = reinterpret_cast<char *>(mmap(0, _memory_buffer_size, PROT_READ, MAP_PRIVATE, file_read_only, 0));

    std::cout << "File mapped.\n"
              << std::endl;
}

File_Map::~File_Map()
{
    std::cout << "Turning off program, closing file... ";
    if (munmap(file_buffer, _memory_buffer_size) != 0)
        abort();

    file_buffer = nullptr;

    close(file_read_only);
    std::cout << "Success!" << std::endl;
}

std::unordered_map<std::string, char> File_Map::map_unique_words(const char *chunk_buff) noexcept
{
    std::unordered_map<std::string, char> chunk_map;
    size_t i = 0U;

    // std::cout << "LOG chunk_buffer: " << reinterpret_cast<const int *>(chunk_buff) << std::endl;

    while (i < page_size)
    {
        size_t j = 0U;
        std::stringstream ss;

        while (chunk_buff[j + i] >= ASCII_a && chunk_buff[j + i] <= ASCII_z)
        {
            ss << chunk_buff[j + i];
            ++j;
        }
        auto temp_word = ss.str();

        if (chunk_map.find(temp_word) == chunk_map.end() && temp_word != "")
            chunk_map[temp_word];

        i += j + 1;
    }
    return chunk_map;
}

void File_Map::file_size(std::ifstream &file) noexcept
{
    char *mem_block;
    if (file.is_open())
    {
        size = file.tellg();
        mem_block = new char[size];
        file.seekg(0, std::ios::beg);
        file.read(mem_block, size);
        file.close();
        delete[] mem_block;
    }
    std::cout << "File's size: " << size << " bytes." << std::endl;
}

void File_Map::count_map() noexcept
{
    std::cout << "Counted unique words: " << map->size() << "\n"
              << std::endl;
}

void File_Map::run_mapping() noexcept
{
    std::cout << "Running memory mapped size of a file: " << _memory_buffer_size << " bytes." << std::endl;

    for (size_t i = 0; i < (_memory_buffer_size)-page_size; i += page_size)
    {
        size_t to_space_buffer = 0;

        while (i && !std::isspace((file_buffer + i - to_space_buffer)[0]))
            to_space_buffer++;

        if (i && to_space_buffer)
            i -= to_space_buffer;

        auto future_of_chunk = std::async(std::launch::async,
                                          &File_Map::map_unique_words, this, file_buffer + i);
        auto map_of_chunk = future_of_chunk.get();

        map->insert(map_of_chunk.begin(), map_of_chunk.end());
    }
}