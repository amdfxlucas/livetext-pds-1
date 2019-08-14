#include "ServerException.h"


ServerException::ServerException(std::string msg)
	: std::exception(("SERVER ERROR: " + msg).c_str())
{
}


ServerStartException::ServerStartException(std::string msg)
	: ServerException(msg)
{
}


FileException::FileException(std::string msg)
	: ServerException(msg)
{
}

FileLoadException::FileLoadException(std::string filePath)
	: ServerException("Unable to read file " + filePath)
{
}

FileWriteException::FileWriteException(std::string fileName, std::string path)
	: ServerException("Unable to write file '" + fileName + "' in " + path)
{
}

FileCreateException::FileCreateException(std::string fileName, std::string path)
	: FileException("Unable to create file '" + fileName + "' in " + path)
{
}

FileOverwriteException::FileOverwriteException(std::string filePath)
	: ServerException("Unable to overwrite file " + filePath)
{
}

MessageException::MessageException(std::string msg) : 
	ServerException(msg)
{
}

MessageUnexpectedTypeException::MessageUnexpectedTypeException(int type) :
	MessageException("Unknown message type : " + type), errType(type)
{
}

int MessageUnexpectedTypeException::getErrType()
{
	return errType;
}


SocketException::SocketException(std::string msg) :
	ServerException(msg)
{
}

SocketNullException::SocketNullException(std::string msg) :
	SocketException(msg)
{
}

SocketDuplicateException::SocketDuplicateException(std::string msg):
	SocketException(msg)
{
}


UserNotFoundException::UserNotFoundException(std::string msg):
	ServerException(msg)
{
}


