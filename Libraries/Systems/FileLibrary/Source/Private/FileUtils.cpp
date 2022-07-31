#include "Libraries/Systems/FileLibrary/Source/Public/FileUtils.h"

#include <algorithm>
#include <filesystem>
#include <fstream>

bool FileUtils::DoesFileExist(const char* filePath)
{
	std::ifstream fileStream;
	fileStream.open(filePath);
	if (fileStream)
	{
		return true;
	}
	return false;
}

std::string FileUtils::RemoveFileExtension(const std::string& filePath)
{
	size_t lastindex = filePath.find_last_of(".");
	if (lastindex != std::string::npos)
	{
		std::string adjustedPath = filePath.substr(0, lastindex);
		return adjustedPath;
	}
	return filePath;
}

std::string FileUtils::RemoveFileName(const std::string& filePath)
{
	size_t forwardSlashLastIndex = filePath.find_last_of("//");
	size_t backwardsSlashLastIndex = filePath.find_last_of("\\");
	size_t lastSlashIndex = 0;

	if (forwardSlashLastIndex != std::string::npos)
	{
		lastSlashIndex = std::max<size_t>(lastSlashIndex, forwardSlashLastIndex);
	}
	if (backwardsSlashLastIndex != std::string::npos)
	{
		lastSlashIndex = std::max<size_t>(lastSlashIndex, backwardsSlashLastIndex);
	}

	if (lastSlashIndex != std::string::npos)
	{
		std::string adjustedPath = filePath.substr(0, lastSlashIndex);
		return adjustedPath;
	}
	return filePath;
}

std::string FileUtils::RemoveRootPath(const std::string& fullFilePath, const std::string& rootFilePath)
{
	size_t rootIndex = fullFilePath.find_first_of(rootFilePath.c_str());
	if (rootIndex != std::string::npos)
	{
		unsigned long staringIndex = static_cast<unsigned long>(rootIndex) + static_cast<unsigned long>(rootFilePath.length());
		std::string adjustedPath = fullFilePath.substr(staringIndex, fullFilePath.length() - staringIndex);
		return adjustedPath;
	}
	return fullFilePath;
}

void FileUtils::CreateDirectoriesIfNeeded(const std::string& filePath)
{
	std::string filePathWithoutName = RemoveFileName(filePath);
	std::filesystem::create_directories(filePathWithoutName.c_str());
}

void FileUtils::GetFileHandle(const char* filePath, HANDLE& fileHandle)
{
	fileHandle = CreateFile(filePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (fileHandle == INVALID_HANDLE_VALUE)
	{
		printf("Could not open file, error %ul\n", GetLastError());
	}
}

void FileUtils::GetFileCreationTime(const char* filePath, FILETIME& creationTime)
{
	HANDLE fileHandle;
	GetFileHandle(filePath, fileHandle);

	GetFileCreationTime(fileHandle, creationTime);
}

void FileUtils::GetFileLastWriteTimeTime(const char* filePath, FILETIME& lastWriteTime)
{
	HANDLE fileHandle;
	GetFileHandle(filePath, fileHandle);

	GetFileLastWriteTimeTime(fileHandle, lastWriteTime);
}

void FileUtils::GetFileCreationTime(HANDLE& fileHandle, FILETIME& creationTime)
{
	if (GetFileTime(fileHandle, &creationTime, nullptr, nullptr) == false)
	{
		printf("Could not get file creation time, error %ul\n", GetLastError());
	}
}

void FileUtils::GetFileLastWriteTimeTime(HANDLE& fileHandle, FILETIME& lastWriteTime)
{
	if (GetFileTime(fileHandle, nullptr, nullptr, &lastWriteTime) == false)
	{
		printf("Could not get file last write time, error %ul\n", GetLastError());
	}
}

void FileUtils::GetFileLastAccessTime(const char* filePath, FILETIME& lastAccessTime)
{
	HANDLE fileHandle;
	GetFileHandle(filePath, fileHandle);

	GetFileLastAccessTime(fileHandle, lastAccessTime);
}

void FileUtils::GetFileLastAccessTime(HANDLE& fileHandle, FILETIME& lastAccessTime)
{
	if (GetFileTime(fileHandle, nullptr, &lastAccessTime, nullptr) == false)
	{
		printf("Could not get file last write time, error %ul\n", GetLastError());
	}
}
