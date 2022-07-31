#pragma once

#include "Systems/FileLibrary/Source/Public/FileCommon.h"
#include <Systems/StringLibrary/Source/Public/StringUtil.h>
#include <fstream>
#include <String>
#include <windows.h>

namespace HaveBlue
{
	class FileStream
	{
	public:
		FILE_LIBRARY_USAGE FileStream(const char* filePath);
		FILE_LIBRARY_USAGE ~FileStream();

		FILE_LIBRARY_USAGE void OpenForRead();
		FILE_LIBRARY_USAGE void OpenForReadBinary();
		FILE_LIBRARY_USAGE void OpenForWrite();
		FILE_LIBRARY_USAGE void OpenForWriteBinary();
		FILE_LIBRARY_USAGE void OpenForWriteBinaryReplace();
		FILE_LIBRARY_USAGE void Close();
		 
		FILE_LIBRARY_USAGE bool IsOpen() const;
		FILE_LIBRARY_USAGE bool IsOpenForRead() const;
		FILE_LIBRARY_USAGE bool IsOpenForWrite() const;
		FILE_LIBRARY_USAGE bool IsBinary() const;

		FILE_LIBRARY_USAGE bool GetLine(std::string& line);
		FILE_LIBRARY_USAGE bool AppendLineToString(std::string& line);
		FILE_LIBRARY_USAGE bool GetCharBlock(char* scratch, unsigned long numberOfCharacters);

		FILE_LIBRARY_USAGE void WriteText(const char* text, unsigned long textLength);
		FILE_LIBRARY_USAGE void WriteString(const std::string& text);
		FILE_LIBRARY_USAGE void WriteLine(const std::string& line);
		FILE_LIBRARY_USAGE void WriteCharBlock(const char* scratch, unsigned long numberOfCharacters);

		FILE_LIBRARY_USAGE void NewLine();
		FILE_LIBRARY_USAGE void EndLine();

		FILE_LIBRARY_USAGE void WriteBinaryString(const std::string& text);
		FILE_LIBRARY_USAGE void ReadBinaryString(std::string& text);

		FILE_LIBRARY_USAGE FILETIME GetLastWriteTime();

		template<typename NumberType>
		void WriteNumber(NumberType value)
		{
			std::string scratchString = std::to_string(value);
			WriteString(scratchString);
		}

		template<typename NumberType>
		void WriteNumberNewline(NumberType value)
		{
			std::string scratchString = std::to_string(value);
			WriteString(scratchString);
			NewLine();
		}

		template<typename DataType>
		void WriteBlock(const DataType* value, unsigned long totalSize)
		{
			WriteCharBlock(reinterpret_cast<const char*>(value), totalSize / sizeof(char));
		}

		template<typename DataType>
		void WriteBlock(const DataType* value, size_t totalSize)
		{
			WriteCharBlock(reinterpret_cast<const char*>(value), static_cast<unsigned long>(totalSize / sizeof(char)));
		}

		template<typename DataType>
		void WriteBlock(const DataType* value, unsigned long elementSize, unsigned long elementCount)
		{
			WriteBlock<DataType>(value, elementSize * elementCount);
		}

		template<typename DataType>
		void WriteBlock(const DataType* value, size_t elementSize, unsigned long elementCount)
		{
			WriteBlock<DataType>(value, elementSize * elementCount);
		}

		template<typename DataType>
		void WriteData(const DataType& value)
		{
			WriteBlock<DataType>(&value, sizeof(value));
		}

		template<typename FloatingPointNumberType>
		FloatingPointNumberType GetFloatingPointNumberFromLine()
		{
			std::string scratchString;
			GetLine(scratchString);
			const char* text = scratchString.c_str();

			FloatingPointNumberType value;
			StringUtil::ConvertStringToFloatingPointNumber<FloatingPointNumberType>(text, value);
			return value;
		}

		template<typename IntegerNumberType>
		IntegerNumberType GetIntegerNumberFromLine()
		{
			std::string scratchString;
			GetLine(scratchString);
			const char* text = scratchString.c_str();

			IntegerNumberType value;
			StringUtil::ConvertStringToIntegerPointNumber<IntegerNumberType>(text, value);
			return value;
		}

		template<typename FloatingPointNumberType>
		void ReadFloatingPointNumberFromLine(FloatingPointNumberType& value)
		{
			std::string scratchString;
			GetLine(scratchString);
			const char* text = scratchString.c_str();
			StringUtil::ConvertStringToFloatingPointNumber<FloatingPointNumberType>(text, value);
		}

		template<typename IntegerNumberType>
		void ReadIntegerNumberFromLine(IntegerNumberType& value)
		{
			std::string scratchString;
			GetLine(scratchString);
			const char* text = scratchString.c_str();
			StringUtil::ConvertStringToIntegerPointNumber<IntegerNumberType>(text, value);
		}

		template<typename FloatingPointNumberType>
		void ReadFloatingPointNumber(FloatingPointNumberType& value)
		{
			ReadFloatingPointNumberFromLine<FloatingPointNumberType>(value);
		}

		template<typename IntegerNumberType>
		void ReadInteger(IntegerNumberType& value)
		{
			ReadIntegerNumberFromLine<IntegerNumberType>(value);
		}

		template<typename DataType>
		void GetBlock(DataType* value, unsigned long totalSize)
		{
			GetCharBlock(reinterpret_cast<char*>(value), totalSize / sizeof(char));
		}

		template<typename DataType>
		void GetBlock(DataType* value, unsigned long elementSize, unsigned long elementCount)
		{
			GetBlock<DataType>(value, elementSize * elementCount);
		}

		template<typename DataType>
		void GetData(DataType& value)
		{
			GetBlock<DataType>(&value, sizeof(value));
		}

		template<typename DataType>
		DataType GetData()
		{
			DataType scratch;
			GetBlock<DataType>(&scratch, sizeof(scratch));
			return scratch;
		}

	private:
		void GetFileAccessStats();

		std::string m_scratchString;
		std::fstream m_fileStream;
		HANDLE m_fileHandle;

		FILETIME m_creationTime;
		FILETIME m_lastWriteTime;

		const char* m_filePath;
		bool m_isOpenForRead;
		bool m_isOpenForWrite;
		bool m_isBinary;
	};
}
