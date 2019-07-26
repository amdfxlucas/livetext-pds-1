#include "AccountMessage.h"
#include "ServerException.h"

AccountMessage::AccountMessage(MessageType m, QDataStream& streamIn) : Message(m), user(User())
{
	quint16 field;

	switch (m) {
	case AccountCreate:
		streamIn >> user;
		break;
	case AccountUpDate:
		streamIn >> field;
		switch (field) {
		case changeNickname:
			streamIn >> newField;
			break;

		case removeNickname:
			break;

		case changeIcon:
			streamIn >> newIcon;
			break;

		case removeIcon:
			break;

		case changePassword:
			streamIn >> newField;
			break;

		default:
			throw FieldWrongException(field);
			break;
		}
		break;
	default:
		throw MessageUnknownTypeException(m);
		break;
	}
}

AccountMessage::~AccountMessage()
{
}

QString AccountMessage::getUserName()
{
	return user.getUsername();
}

QString AccountMessage::getNickname()
{
	return user.getNickName();
}

QString AccountMessage::getPasswd()
{
	return user.getPassword();
}

QPixmap AccountMessage::getIcon()
{
	return user.getIcon();
}

quint16 AccountMessage::getFiledType()
{
	return field;
}

QString AccountMessage::getField()
{
	return newField;
}

QPixmap AccountMessage::getNewIcon()
{
	return newIcon;
}
