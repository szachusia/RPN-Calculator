#include <iostream>
#include "Token.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

Queue ConvertInfixToPostfix();

void ConvertToken(Token& token, Stack<Token>& operationStack, Queue& postfix);
void ConvertComma(Token& token, Stack<Token>& operationStack, Queue& postfix);
void ConvertRightParenthesis(Stack<Token>& operationStack, Queue& postfix);
void ConvertArithmeticOperation(Token& token, Stack<Token>& operationStack, Queue& postfix);

void CalculatePostfix(Queue& postfix);
void CalculateToken(Token& token, Stack<int>& operandStack);

void ExecuteDivision(Stack<int>& operandStack);
void ExecuteMultiplication(Stack<int>& operandStack);
void ExecuteAddition(Stack<int>& operandStack);
void ExecuteSubtraction(Stack<int>& operandStack);
void ExecuteIF(Stack<int>& operandStack);
void ExecuteMAX(int& range, Stack<int>& operandStack);
void ExecuteMIN(int& range, Stack<int>& operandStack);
void ExecuteNegation(Stack<int>& operandStack);


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	while (n--)
	{
		Queue postfix = ConvertInfixToPostfix();
		postfix.Print();
		CalculatePostfix(postfix);
	}

}

Queue ConvertInfixToPostfix()
{
	Queue postfix;

	char temp[10];
	Stack<Token> operationStack;

	cin >> temp;
	while (temp[0] != '.')
	{
		Token token(temp);
		ConvertToken(token, operationStack, postfix);
		cin >> temp;
	}

	// Move remaining stack operations to postfix
	while (!operationStack.IsEmpty())
	{
		postfix.Enqueue(operationStack.Pop());
	}

	return postfix;
}

void ConvertToken(Token& token, Stack<Token>& operationStack, Queue& postfix)
{
	switch (token.type)
	{
	case Type::NUMBER:
		postfix.Enqueue(token);
		break;
	case Type::COMMA:
		ConvertComma(token, operationStack, postfix);
		break;
	case Type::LEFT_PARENTHESIS:
		operationStack.Push(token);
		break;
	case Type::RIGHT_PARENTHESIS:
		ConvertRightParenthesis(operationStack, postfix);
		break;
	case Type::DIVISION:
		ConvertArithmeticOperation(token, operationStack, postfix);
		break;
	case Type::MULTIPLICATION:
		ConvertArithmeticOperation(token, operationStack, postfix);
		break;
	case Type::SUBTRACTION:
		ConvertArithmeticOperation(token, operationStack, postfix);
		break;
	case Type::ADDITION:
		ConvertArithmeticOperation(token, operationStack, postfix);
		break;
	case Type::MIN:
		operationStack.Push(token);
		break;
	case Type::MAX:
		operationStack.Push(token);
		break;
	case Type::IF:
		operationStack.Push(token);
		break;
	case Type::NEGATION:
		operationStack.Push(token);
		break;
	default:
		cout << "Invalid token";
	}
}

void ConvertComma(Token& token, Stack<Token>& operationStack, Queue& postfix)
{
	while (!operationStack.IsEmpty()) // Move remaining element operations to postfix
	{
		Token top = operationStack.Pop();

		if (top.type == Type::COMMA or
			top.type == Type::LEFT_PARENTHESIS)
		{
			operationStack.Push(top);
			break;
		}

		postfix.Enqueue(top);
	}

	operationStack.Push(token);
}

void ConvertRightParenthesis(Stack<Token>& operationStack, Queue& postfix)
{
	int commas{};
	while (!operationStack.IsEmpty())
	{
		Token operation = operationStack.Pop();
		if (operation.type == Type::LEFT_PARENTHESIS)
		{
			if (!operationStack.IsEmpty())
			{
				Token nextOperation = operationStack.Peek();
				if (nextOperation.type == Type::IF or
					nextOperation.type == Type::MAX or
					nextOperation.type == Type::MIN)
				{
					nextOperation = operationStack.Pop();
					nextOperation.value = commas + 1;
					postfix.Enqueue(nextOperation);
				}
			}
			break;
		}
		else
		{
			if (operation.type == Type::COMMA)
			{
				commas++;
			}
			else
			{
				postfix.Enqueue(operation);
			}
		}
	}
}

void ConvertArithmeticOperation(Token& token, Stack<Token>& operationStack, Queue& postfix)
{
	int priority = token.GetPriority();
	while (!operationStack.IsEmpty())
	{
		Token top = operationStack.Pop();
		if (top.type == Type::COMMA or
			top.type == Type::LEFT_PARENTHESIS or
			top.GetPriority() < priority)
		{
			operationStack.Push(top);
			break;
		}
		postfix.Enqueue(top);
	}
	operationStack.Push(token);
}

void CalculatePostfix(Queue& postfix)
{
	Token token;
	Stack<int> operandStack;

	while (!postfix.IsEmpty())
	{
		token = postfix.Dequeue();
		try
		{
			CalculateToken(token, operandStack);
		}
		catch (...)
		{
			cout << "ERROR\n\n";
			return;
		}
	}
	operandStack.Print();
	cout << "\n";
}

void CalculateToken(Token& token, Stack<int>& operandStack)
{
	if (token.type == Type::NUMBER)
	{
		operandStack.Push(token.value);
	}
	else
	{
		token.Print();
		cout << " ";
		operandStack.Print();

		switch (token.type)
		{
		case Type::DIVISION:
			ExecuteDivision(operandStack);
			break;
		case Type::MULTIPLICATION:
			ExecuteMultiplication(operandStack);
			break;
		case Type::SUBTRACTION:
			ExecuteSubtraction(operandStack);
			break;
		case Type::ADDITION:
			ExecuteAddition(operandStack);
			break;
		case Type::MIN:
			ExecuteMIN(token.value, operandStack);
			break;
		case Type::MAX:
			ExecuteMAX(token.value, operandStack);
			break;
		case Type::IF:
			ExecuteIF(operandStack);
			break;
		case Type::NEGATION:
			ExecuteNegation(operandStack);
			break;
		default:
			cout << "Invalid token";
		}
	}
}

void ExecuteDivision(Stack<int>& operandStack)
{
	int value1{ operandStack.Pop() };

	if (value1 == 0)
	{
		throw("Dividing by 0");
	}
	else
	{
		int value2{ operandStack.Pop() };
		int newValue{ value2 / value1 };

		operandStack.Push(newValue);
	}

}

void ExecuteMultiplication(Stack<int>& operandStack)
{
	int value1{ operandStack.Pop() };
	int value2{ operandStack.Pop() };

	int newValue = value2 * value1;

	operandStack.Push(newValue);
}

void ExecuteAddition(Stack<int>& operandStack)
{
	int value1{ operandStack.Pop() };
	int value2{ operandStack.Pop() };

	int newValue{ value2 + value1 };

	operandStack.Push(newValue);
}

void ExecuteSubtraction(Stack<int>& operandStack)
{
	int value1{ operandStack.Pop() };
	int value2{ operandStack.Pop() };

	int newValue{ value2 - value1 };

	operandStack.Push(newValue);
}

void ExecuteIF(Stack<int>& operandStack)
{
	int value1{ operandStack.Pop() };
	int value2{ operandStack.Pop() };
	int value3{ operandStack.Pop() };


	int newValue = (value3 > 0) ? value2 : value1;

	operandStack.Push(newValue);
}

void ExecuteMAX(int& range, Stack<int>& operandStack)
{
	int maxValue{ operandStack.Pop() };
	range--;

	while (range--)
	{
		int newValue = operandStack.Pop();
		maxValue = (maxValue > newValue) ? maxValue : newValue;
	}

	operandStack.Push(maxValue);
}

void ExecuteMIN(int& range, Stack<int>& operandStack)
{
	int minValue{ operandStack.Pop() };
	range--;

	while (range--)
	{
		int newValue = operandStack.Pop();
		minValue = (minValue < newValue) ? minValue : newValue;
	}

	operandStack.Push(minValue);
}

void ExecuteNegation(Stack<int>& operandStack)
{
	int value{ operandStack.Pop() };
	int newValue = -value;

	operandStack.Push(newValue);
}