#pragma once
#include <iostream>
#include <queue>
#include <string>

class Command
{
protected:
	std::string Key;
public:
	Command(std::string key) : Key(key) {}
	virtual ~Command() = default; // 가상 소멸자 : 부모 클래스가 가장 마지막에 소멸
	virtual std::string execute() const = 0;
	std::string GetKey() { return Key; }

};

class FireBall : public Command
{
public:
	FireBall(std::string key) : Command(key) {}
	std::string execute() const override
	{
		return "파이어볼!";
	}
};

class DoomsDay : public Command
{
public:
	DoomsDay(std::string key) : Command(key) {}
	std::string execute() const override
	{
		return "떼바시!!";
	}
};

template <typename T>
class CircularQueue
{
private:
	T* arr;
	int iCount;
	int capacity;
	int front;
	int rear;
public:
	// 생성자
	CircularQueue(int size = 4) 
	{
		arr = new T[size];
		iCount = 0;
		capacity = size;
		front = 0;
		rear = 0;
	}
	~CircularQueue() {}
	
	// 접근자
	T Front()
	{
		return arr[front];
	}
	T Rear()
	{
		return arr[rear];
	}
	int Size()
	{
		return iCount;
	}

	// Helper Method
	bool IsEmpty()
	{
		return front == rear ? true : false;
	}
	bool IsFull()
	{
		return (rear + 1) % capacity == front ? true : false;
	}

	// Main Method
	void Push(T data)
	{
		if (IsFull())
		{
			std::cout << "원형 큐가 가득찼습니다." << std::endl;
		}
		else
		{
			arr[rear] = data;
			rear = (rear+1) % capacity;
			iCount++;
		}
		
	}
	void Pop()
	{
		if (IsEmpty())
		{
			std::cout << "원형 큐가 비었습니다." << std::endl;
			return;
		}
		else
		{
			front = (front + 1) % capacity;
			iCount--;
		}
	}
};

class CommandSystem
{
private:
	std::vector<Command*> Commands; // 원소수가 적을 수록 벡터가 유리
	CircularQueue<std::string> Inputs; // 유저가 보낸 신호를 순서대로 저장
public:
	void addCommand(Command* command)
	{
		Commands.push_back(command);
	}
	void addInput(const std::string& input)
	{
		if (Inputs.Size() < 3)
		{
			Inputs.Push(input);
		}
		if (Inputs.Size() == 3)
		{
			ProcessCommand();
			ClearQueue();
		}
	}
	void ProcessCommand()
	{
		// 유저가 입력한 순서대로 커맨드 실행
		std::string userCommand = "";

		while (!Inputs.IsEmpty())
		{
			userCommand += Inputs.Front();
			Inputs.Pop();
		}

		// 커맨드의 Key와 userCommand 비교 값이 일치하는지 비교
		for (int i = 0; Commands.size();i++) {
			if (userCommand == Commands[i]->GetKey())
			{
				std::cout << Commands[i]->execute() << std::endl;
				return;
			}
		}
		std::cout << "일치하는 커맨드가 없습니다" << std::endl;
		
	}

	void ClearQueue()
	{
		while (!Inputs.IsEmpty())
		{
			Inputs.Pop();
		}
	}

	void ShowPlayerInput()
	{
		std::cout << "현재 입력 값 : [ ";
		CircularQueue<std::string> temp = Inputs;
		while (!temp.IsEmpty())
		{
			std::cout << temp.Front() << " ";
			temp.Pop();
		}
		std::cout << " ]" << std::endl;
	}

	void ShowCommandList()
	{
		std::cout << "---커맨드 목록---" << std::endl;
		std::cout << "Fire 커맨드 : " << "ABC" << std::endl;
		std::cout << "DoomsDay 커맨드 : " << "DEF" << std::endl;
		std::cout << "-----------------" << std::endl;
	}
};

void CommandSystemExample()
{
	CommandSystem manager;
	FireBall cm1("ABC");
	DoomsDay cm2("DEF");
	manager.addCommand(&cm1);
	manager.addCommand(&cm2);

	manager.ShowCommandList();

	std::string input;
	
	while (true)
	{
		manager.ShowCommandList();
		manager.ShowPlayerInput();

		std::cin >> input;
		manager.addInput(input);

		if (input == "Q")
		{
			std::cout << "시스템 종료" << std::endl;
			break;
		}
	}
}