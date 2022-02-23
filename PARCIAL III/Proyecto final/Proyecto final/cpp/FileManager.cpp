#include "FileManager.h"
#include "File.h"



// copy constructor
FileManager::FileManager(FileManager const& rhs)
	: sourceDir(rhs.sourceDir), backupDir(rhs.backupDir), totalSize(rhs.totalSize) {
	getPaths();
	backup();
	report();
}

// copy assignment operator
FileManager& FileManager::operator = (FileManager const& rhs) {
	sourceDir = rhs.sourceDir;
	backupDir = rhs.backupDir;
	totalSize = rhs.totalSize;
	return *this;
}

/*
Function Name: getSource()
Purpose: return the source directory, so it is accessible outside of the class
Accepts: nothing
Returns: path
*/
std::filesystem::path const& FileManager::getSource() {
	return sourceDir;
}

/*
Function Name: getBackup()
Purpose: return the backup directory, so it is accessible outside of the class
Accepts: nothing
Returns: path
*/
std::filesystem::path const& FileManager::getBackup() {
	return backupDir;
}

/*
Function Name: printDirectories()
Purpose: print source and backup directories to console
Accepts: nothing
Returns: void
*/
void FileManager::printDirectories() {
	std::cout << "Root Directory: " << absolute(sourceDir) << std::endl;
	std::cout << "Backup Directory: " << absolute(backupDir) << std::endl;
}

void FileManager::init() {
	if (!std::filesystem::exists("./backup"))
		std::filesystem::create_directory("./backup");
	//printDirectories();
	getPaths();
	backup();
	report();
}

/*
Function Name: getPaths()
Purpose: populates sourcePaths vector with files in the source directory
Accepts: nothing
Returns: void
*/
void FileManager::getPaths() {
	for (auto& d : std::filesystem::recursive_directory_iterator(sourceDir)) {
		std::string sBackup = backupDir.string();
		std::string sFileName = d.path().filename().string();
		std::filesystem::path temp = sBackup + "\\" + sFileName;
		// validate extension
		if (d.path().extension() == ".db") {
			// find length of largest path name
			if (sFileName.size() > pathSize_)
				pathSize_ = sFileName.size();
			if (!exists(temp)) {
				File f(d, d.path().filename().string(), '+');
				sourcePaths.push_back(f);
				numFiles++;
			}
			else {
				File f(d, d.path().filename().string(), '-');
				sourcePaths.push_back(f);
			}
		}
	}
}
//.append(std::to_string(lt.wHour + lt.wMinute + lt.wSecond))
/*
Function Name: backup()
Purpose: create backup files by recursively scanning the source directory,
		 and copying them over to the backup directory
Accepts: nothing
Returns: void
*/
void FileManager::backup() {
	SYSTEMTIME lt;
	std::string newName = "";
	for (auto& p : sourcePaths) {
		GetLocalTime(&lt);
		std::string sBackup = backupDir.string();
		std::string sFileName = p.getFileName();
		std::filesystem::path temp = sBackup + "\\" + sFileName;
		if (p.getStatus() == '+') {
			copy(p.getPathName(), backupDir);
			totalSize += file_size(p.getPathName());

			newName.append("./backup/MySQLiteDatabase ");
			newName.append(std::to_string(lt.wHour));
			newName.append(" - ");
			newName.append(std::to_string(lt.wMinute));
			newName.append(" - ");
			newName.append(std::to_string(lt.wSecond));
			newName.append(".db");

			std::rename("./backup/MySQLiteDatabase.db", newName.c_str());
		}

	}// end loop
}// end function

/*
Function Name: report()
Purpose: shows files in the source directory, whether they've been backed up, and their size
Accepts: nothing
Returns: void
*/
void FileManager::report() {
	std::cout << "BackUp realizado con exito! " << std::endl;
}


void FileManager::showBackups() {
	std::vector<File> pathsBacks;
	pathsBacks.clear();
	int i = 0, opc = 0;
	for (auto& d : std::filesystem::recursive_directory_iterator(backupDir)) {
		if (d.path().extension() == ".db") {
			File f(d, d.path().filename().string(), '-');
			pathsBacks.push_back(f);
		}
	}

	std::cout << "N.   Nombre.\t\tHora.\t\t\t\tTamano." << std::endl;
	//FUNCION LAMBDA O FUNCION QUE RECIBE OTRA FUNCION
	for (auto& p : pathsBacks) {
		printList(p, [&]() {
			i++;
			std::cout << "[" << i << "]." << p.getFileName() << std::setw(25) << " Size: " << std::filesystem::file_size(p.getPathName()) << std::endl;
			});
	}

	i = 0;
	std::cout << "Que copia desea restaurar: " << std::endl;
	std::cin >> opc;
	for (auto& p : pathsBacks) {
		i++;
		if (i == opc) {
			std::rename("MySQLiteDatabase.db", "temp.db");
			copy(p.getPathName(), sourceDir);
			std::rename(p.getFileName().c_str(), "MySQLiteDatabase.db");
			std::cout << "Copia restaurada." << std::endl;
		}
	}
	std::remove("temp.db");
}

void FileManager::printList(File p, std::function<void()> show) {	
	if (p.getStatus() == '-') {
		show();
	}
}