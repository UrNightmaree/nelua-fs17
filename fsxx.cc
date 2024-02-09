#include <filesystem>
#include <memory>

#include <cstdlib>
#include <cstring>
#include <cassert>

namespace fs = std::filesystem;

static char* fsxxl_strdup(const char* in)
{
    assert(in != NULL);
    char *out = static_cast<char*>(malloc(1 + strlen(in)));
    return strcpy(out, in);
}

extern "C"
std::unique_ptr<fs::path> fsxx_path_new(const char* path)
{
    return std::unique_ptr<fs::path>(new fs::path(path));
}

extern "C"
void fsxx_path_gc(fs::path* path)
{
    delete path;
}

extern "C"
const char* fsxx_path_tostring(fs::path* path)
{
    return fsxxl_strdup(path->c_str());
}

extern "C"
fs::path* fsxx_absolute(fs::path* path)
{
    return new fs::path(fs::absolute(*path));
}
