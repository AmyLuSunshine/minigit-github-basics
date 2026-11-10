#pragma once
#include <filesystem>
#include <string>

namespace minigit {
    std::filesystem::path metadataDirectory(const std::filesystem::path& root);
    std::filesystem::path getHead(const std::filesystem::path& root);

    // Reads the entire file without changing text or line endings.
    // Returns false if the file cannot be opened or read.
    bool readTextFile(const std::filesystem::path& path, std::string& text);
}