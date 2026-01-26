#pragma once
#include <iostream>

using namespace std;

enum class Type
{
	NUMBER,

	LEFT_PARENTHESIS,
	RIGHT_PARENTHESIS,

	DIVISION,
	MULTIPLICATION,
	ADDITION,
	SUBTRACTION,

	IF,
	NEGATION,
	MIN,
	MAX,

	COMMA
};

class Token
{
public:
	Type type{};
	int value{};

	Token()
	{
	}

	Token(char characters[10]) 
	{
		char firstChar = characters[0];

		if (firstChar == ',')
		{
			type = Type::COMMA;
		}
		else if (firstChar >= '0' and firstChar <= '9')
		{
			type = Type::NUMBER;
			value = atoi(characters);
		}
		else if (firstChar == '(')
		{
			type = Type::LEFT_PARENTHESIS;
		}
		else if (firstChar == ')')
		{
			type = Type::RIGHT_PARENTHESIS;
		}
		else if (firstChar == '/')
		{
			type = Type::DIVISION;
		}
		else if (firstChar == '*')
		{
			type = Type::MULTIPLICATION;
		}
		else if (firstChar == '+')
		{
			type = Type::ADDITION;
		}
		else if (firstChar == '-')
		{
			type = Type::SUBTRACTION;
		}
		else if (firstChar == 'N')
		{
			type = Type::NEGATION;
		}
		else if (characters[0] == 'I' and characters[1] == 'F')
		{
			type = Type::IF;
		}
		else if (characters[0] == 'M' and characters[1] == 'A' and characters[2] == 'X')
		{
			type = Type::MAX;
		}
		else if (characters[0] == 'M' and characters[1] == 'I' and characters[2] == 'N')
		{
			type = Type::MIN;
		}
		else
		{
			cout << "Invalid token!";
		}
	}

	int GetPriority() const
	{
		if (type == Type::LEFT_PARENTHESIS or type == Type::RIGHT_PARENTHESIS)
		{
			return 4;
		}

		if (type == Type::IF or type == Type::NEGATION or type == Type::MIN or type == Type::MAX)
		{
			return 3;
		}

		if (type == Type::DIVISION or type == Type::MULTIPLICATION)
		{
			return 2;
		}

		if (type == Type::ADDITION or type == Type::SUBTRACTION)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	void Print() const
	{
		switch (type)
		{
		case Type::NUMBER:
			cout << value;
			break;
		case Type::DIVISION:
			cout << "/";
			break;
		case Type::MULTIPLICATION:
			cout << "*";
			break;
		case Type::ADDITION:
			cout << "+";
			break;
		case Type::SUBTRACTION:
			cout << "-";
			break;
		case Type::IF:
			cout << "IF";
			break;
		case Type::NEGATION:
			cout << "N";
			break;
		case Type::MIN:
			cout << "MIN" << value;
			break;
		case Type::MAX:
			cout << "MAX" << value;
			break;
		default:
			break;
		}
	}

	friend ostream& operator<<(ostream& os, const Token& token)
	{
		token.Print();

		return os;
	}
};