#include "assignment4.h"
#include <iostream>
#include <iomanip>
#include <queue>


using namespace std;

int main() {
	Queue q;
	string op;
	int val = 0;

	cout << "operation -- size front end" << endl;
	cin >> op;
	while (!cin.eof()) {
		if (op == "push") {
			cin >> val;
			q.push(val);
			cout << op << " " << val << "    -- ";
		}
		else if (op == "pop") {
			q.pop();
			cout << op << "       -- ";
		}
		else {
			cerr << "Error input: " << op << endl;
			return 1;
		}
		cout << setw(3) << q.size() << setw(5) << q.front() << setw(5) << q.back() << endl;
		cin >> op;
	}

	while (!q.empty())
		q.pop();

	return 0;
}

//
bool Queue::empty() const
{
	if (s1.empty() && s2.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//
int Queue::size() const
{
	return s1.size() + s2.size();
}

//
int Queue::front()
{
	if (s2.empty())
	{
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}
	return s2.top();
}

//
int Queue::back()
{
	return s1.top();
}

//
void Queue::push(const int& val)
{
	s1.push(val);
}

//
void Queue::pop()
{
	s2.pop();
}