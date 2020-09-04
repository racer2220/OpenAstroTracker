#pragma once

template <class T>
struct Node
{
	T data;
	Node *next;
};

template <class T>
class List
{
	Node<T> *_head;
	int _count;

public:
	List()
	{
		_head = nullptr;
		_count = 0;
	}

	~List()
	{
		while (_head != nullptr)
		{
			Node<T> *n = _head->next;
			delete _head;
			_head = n;
		}
		_count = 0;
	}

	T operator[](int i);

	T getItem(int i)
	{
		Node<T> h = _head;
		while (i > 0)
		{
			if (h == nullptr)
			{
				return nullptr;
			}
			h = h->next;
			i--;
		}

		return h->data;
	}

	void add(T value)
	{
		Node<T> *n = new Node<T>();
		n->data = value;
		n->next = _head;
		_head = n;
		_count++;
	}

	int count()
	{
		return _count;
	}
};