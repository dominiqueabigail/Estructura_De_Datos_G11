#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>	// format output
#include <windows.h>
#include <functional>
#include "File.h"


class FileManager {
	// data members	
	std::filesystem::path sourceDir = std::filesystem::current_path();// Current working directory
	std::filesystem::path backupDir = "./backup";	// backup directory
	uintmax_t totalSize = 0;		// total size of files backed up
	unsigned numFiles = 0;			// number of files backed up
	std::vector<File> sourcePaths;	// hold paths
	unsigned pathSize_ = 0;		// length of path name in characters
public:
	// default constructor
	FileManager() {
	};

	// one arg constructor
	FileManager(std::filesystem::path sd)
		: sourceDir(sd) {
		if (!exists(sd))
			sourceDir = std::filesystem::current_path();
		if (!std::filesystem::exists("C:\\backup"))
			std::filesystem::create_directory("C:\\backup");
		printDirectories();
		getPaths();
		backup();
		report();
	}

	// two arg constructor
	FileManager(std::filesystem::path sd, std::filesystem::path bd)
		: sourceDir(sd), backupDir(bd) {
		if (!exists(sd))
			sourceDir = std::filesystem::current_path();
		if (!exists(backupDir))
			backupDir = "C:\\backup";
		printDirectories();
		getPaths();
		backup();
		report();
	}

	// copy constructor
	FileManager(FileManager const&);

	// copy assignment operator
	FileManager& operator=(FileManager const&);

	FileManager(FileManager&&) = delete; // disable move constructor
	FileManager& operator= (FileManager&&) = delete; //disable move assignment operator
	~FileManager() = default;

	void init();
	void getPaths();// populate paths vector with all appropriate files
	void backup();	// backup files from source directory
	void report();	// shows files in source directory
	void printDirectories(); // print directories on execution
	std::filesystem::path const& getSource();	// getter for source directory
	std::filesystem::path const& getBackup();	// getter for source directory
	void showBackups();
	void printList(File p, std::function<void()> show);
};