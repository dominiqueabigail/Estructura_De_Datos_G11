#include "File.h"

// filePath getter
std::filesystem::path const& File::getPathName() { return filePath_; }

// fileName getter
std::string const& File::getFileName() { return fileName_; }

// status getter
char& File::getStatus() { return status_; }

void File::showFile(File file, int  i) {
	std::cout << "[" << i << "]. " << file.getFileName() << std::setw(25) << " Size: " << file_size(file.getPathName()) << std::endl;
}
