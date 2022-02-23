#pragma once
#include <iostream>
#include <filesystem>
#include <vector>

class File {
public:
	// default constructor
	File() = default;

	// 2-arg constructor
	File(std::filesystem::path f, std::string s, char c) : filePath_(f), fileName_(s), status_(c) {}

	// getters and setters
	std::filesystem::path const& getPathName();
	std::string const& getFileName();
	char& getStatus();
	void showFile(File, int);

private:
	// data members
	std::filesystem::path filePath_;
	std::string fileName_;
	char status_;
};
