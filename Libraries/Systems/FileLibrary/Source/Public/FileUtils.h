#pragma once

#include "Systems/FileLibrary/Source/Public/FileCommon.h"

#include <string>
#include <stddef.h>
#include <windows.h>

namespace FileUtils
{
	FILE_LIBRARY_USAGE bool DoesFileExist(const char* filePath);

	FILE_LIBRARY_USAGE std::string RemoveFileExtension(const std::string& filePath);
	FILE_LIBRARY_USAGE std::string RemoveFileName(const std::string& filePath);
	FILE_LIBRARY_USAGE std::string RemoveRootPath(const std::string& fullFilePath, const std::string& rootFilePath);

	FILE_LIBRARY_USAGE void CreateDirectoriesIfNeeded(const std::string& filePath);

	FILE_LIBRARY_USAGE void GetFileHandle(const char* filePath, HANDLE& fileHandle);

	FILE_LIBRARY_USAGE void GetFileCreationTime(const char* filePath, FILETIME& creationTime);
	FILE_LIBRARY_USAGE void GetFileCreationTime(HANDLE& fileHandle, FILETIME& creationTime);

	FILE_LIBRARY_USAGE void GetFileLastWriteTimeTime(const char* filePath, FILETIME& lastWriteTime);
	FILE_LIBRARY_USAGE void GetFileLastWriteTimeTime(HANDLE& fileHandle, FILETIME& lastWriteTime);

	FILE_LIBRARY_USAGE void GetFileLastAccessTime(const char* filePath, FILETIME& lastAccessTime);
	FILE_LIBRARY_USAGE void GetFileLastAccessTime(HANDLE& fileHandle, FILETIME& lastAccessTime);
}
