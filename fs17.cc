#include <iostream>
#include <filesystem>

#include <cstdlib>
#include <cstring>
#include <cassert>

namespace fs = std::filesystem;

static char* fs17l_strdup(const char* in) {
    assert(in != NULL);
    char *out = static_cast<char*>(malloc(1 + strlen(in)));
    return strcpy(out, in);
}

extern "C"
fs::path* fs17_path_new(const char* path) {
    return new fs::path(path);
}

extern "C"
void fs17_path_gc(fs::path* path) {
    delete path;
}

extern "C"
const char* fs17_absolute(fs::path* path) {
    return fs17l_strdup(fs::absolute(*path).c_str());
}
