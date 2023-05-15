#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <unordered_map>
#include <future>
#include <exception>

#define ASCII_a (97)
#define ASCII_z (122)

class File_Map
{
public:
    File_Map(const int args_count, const std::string &filename);
    ~File_Map();

    static inline size_t get_page_mask() { return (sysconf(_SC_PAGE_SIZE)); }

    std::unordered_map<std::string, char> map_unique_words(const char *chunk_buff) noexcept;

    void file_size(std::ifstream &filename) noexcept;
    void count_map() noexcept;
    void run_mapping() noexcept;

private:
    std::unique_ptr<std::unordered_map<std::string, char>> map;

    std::streampos size;

    const size_t page_size;
    size_t _memory_buffer_size;
    int file_read_only;
    char *file_buffer;
};