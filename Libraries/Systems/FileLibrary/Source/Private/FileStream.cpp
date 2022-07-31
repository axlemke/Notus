#include "Libraries/Systems/FileLibrary/Source/Public/FileStream.h"

#include "Libraries/Systems/FileLibrary/Source/Public/FileUtils.h"
#include "Libraries/Framework/LibraryShell/Source/Public/CustomAssert.h"
#include <sstream>

using namespace HaveBlue;

FileStream::FileStream(const char* filePath)
	: m_filePath(filePath)
	, m_fileHandle(nullptr)
	, m_isOpenForRead(false)
	, m_isOpenForWrite(false)
	, m_isBinary(false)
{
}

FileStream::~FileStream()
{
	Close();
}

void FileStream::GetFileAccessStats()
{
	FileUtils::GetFileHandle(m_filePath, m_fileHandle);

	FileUtils::GetFileLastWriteTimeTime(m_fileHandle, m_lastWriteTime);
	FileUtils::GetFileCreationTime(m_fileHandle, m_creationTime);

	CloseHandle(m_fileHandle);
}

void FileStream::OpenForRead()
{
	m_fileStream.open(m_filePath, std::fstream::in);
	HB_ASSERT(IsOpen());

	GetFileAccessStats();

	m_isOpenForRead = true;
	m_isBinary = false;
}

void FileStream::OpenForReadBinary()
{
	m_fileStream.open(m_filePath, std::fstream::in | std::fstream::binary);
	HB_ASSERT(IsOpen());

	GetFileAccessStats();

	m_isOpenForRead = true;
	m_isBinary = true;
}

void FileStream::OpenForWrite()
{
	m_fileStream.open(m_filePath, std::fstream::out);
	HB_ASSERT(IsOpen());
	m_isOpenForWrite = true;
	m_isBinary = false;
}

void FileStream::OpenForWriteBinary()
{
	m_fileStream.open(m_filePath, std::fstream::out | std::fstream::binary);
	HB_ASSERT(IsOpen());
	m_isOpenForWrite = true;
	m_isBinary = true;
}

void FileStream::OpenForWriteBinaryReplace()
{
	m_fileStream.open(m_filePath, std::fstream::out | std::fstream::binary | std::fstream::trunc);
	HB_ASSERT(IsOpen());
	m_isOpenForWrite = true;
	m_isBinary = true;
}

bool FileStream::IsOpen() const
{
	return m_fileStream.is_open();
	//HB_ASSERT(m_fileStream.is_open() == (m_isOpenForRead || m_isOpenForWrite));
	//return (m_isOpenForRead || m_isOpenForWrite);
}

bool FileStream::IsOpenForRead() const
{
	HB_ASSERT(m_fileStream.is_open() == m_isOpenForRead);
	return m_isOpenForRead;
}

bool FileStream::IsOpenForWrite() const
{
	HB_ASSERT(m_fileStream.is_open() == m_isOpenForWrite);
	return m_isOpenForWrite;
}

bool FileStream::IsBinary() const
{
	return m_isBinary;
}

void FileStream::Close()
{
	m_fileStream.close();
	m_isOpenForRead = false;
	m_isOpenForWrite = false;
	m_isBinary = false;
}

bool FileStream::GetLine(std::string& line)
{
	HB_ASSERT(m_isOpenForRead);
	getline(m_fileStream, line);

	return m_fileStream.eof();
}

bool FileStream::AppendLineToString(std::string& line)
{
	HB_ASSERT(m_isOpenForRead);

	m_scratchString.clear();
	getline(m_fileStream, m_scratchString);
	m_scratchString.append("\0");
	line.append(m_scratchString);
	m_scratchString.clear();

	return m_fileStream.eof();
}

bool FileStream::GetCharBlock(char* scratch, unsigned long numberOfCharacters)
{
	HB_ASSERT(m_isOpenForRead);
	m_fileStream.read(scratch, numberOfCharacters);

	return m_fileStream.eof();
}

void FileStream::WriteText(const char* text, unsigned long textLength)
{
	HB_ASSERT(m_isOpenForWrite);

	if (textLength > 0)
	{
		m_fileStream.write(text, textLength);
	}
}

void FileStream::WriteString(const std::string& text)
{
	unsigned long textLength = static_cast<unsigned long>(text.length());
	WriteText(text.c_str(), textLength);
}

void FileStream::WriteLine(const std::string& line)
{
	WriteString(line);
	NewLine();
}

void FileStream::WriteCharBlock(const char* scratch, unsigned long numberOfCharacters)
{
	HB_ASSERT(m_isOpenForWrite);
	m_fileStream.write(scratch, numberOfCharacters);
}

void FileStream::EndLine()
{
	NewLine();
}

void FileStream::NewLine()
{
	WriteText("\n", 1);
}

void FileStream::WriteBinaryString(const std::string& text)
{
	unsigned long numberOfCharacters = static_cast<unsigned long>(text.size());

	WriteData<unsigned long>(numberOfCharacters);

	if (numberOfCharacters > 0)
	{
		WriteBlock<char>(text.c_str(), sizeof(char), numberOfCharacters);
	}
}

void FileStream::ReadBinaryString(std::string& text)
{
	unsigned long numberOfCharacters = 0;
	GetData<unsigned long>(numberOfCharacters);

	if (numberOfCharacters > 0)
	{
		text.resize(numberOfCharacters);
		GetBlock<char>(&text[0], sizeof(char), numberOfCharacters);
	}
}

FILETIME FileStream::GetLastWriteTime()
{
	return m_lastWriteTime;
}
