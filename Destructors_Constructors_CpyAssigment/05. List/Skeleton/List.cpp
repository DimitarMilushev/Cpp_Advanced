#include "List.h"

//NODE INIT

List::Node::Node(int value, List::Node* prev, List::Node* next) : value(value), prev(prev), next(next)
{}

int List::Node::getValue() const
{
	return this->value;
}

void List::Node::setValue(int value)
{
	this->value = value;
}

List::Node* List::Node::getNext() const
{
	return this->next;
}

void List::Node::setNext(Node* next)
{
	this->next = next;
}

List::Node* List::Node::getPrev() const
{
	return this->prev;
}

void List::Node::setPrev(Node* prev)
{
	this->prev = prev;
}

//LIST INIT

List::List() : head(nullptr), tail(nullptr), size(0) {}

List::List(const List& other) : List()
{
	this->addAll(other);
}


List& List::operator=(const List& other) 
{
	if (this != &other)
	{
		this->removeAll();
		const List temp = other;


		this->addAll(temp);

	}

	return  *this;
}

List::~List()
{
	this->removeAll();
}

int List::first() const
{
	return this->head->getValue();
}

void List::add(int value)
{
	Node* newNode = new Node(value, this->tail, nullptr);
	if (this->isEmpty())
	{
		this->head = newNode;
	}
	else
	{
		this->tail->setNext(newNode);
	}

	this->tail = newNode;
	++this->size;
}

void List::addAll(const List& other)
{
	Node* node = other.head;
	while (node != nullptr) {
		this->add(node->getValue());
		node = node->getNext();
	}
}

void List::removeFirst()
{
	if (!this->isEmpty())
	{
		Node* currentHead = this->head;
		if (this->size != 1)
		{
			this->head = currentHead->getNext();
		}
		else
		{
			this->head = nullptr;
			this->tail = nullptr;
		}
		delete currentHead;
		--this->size;
	}
}

void List::removeAll()
{
	if (!this->isEmpty())
	{
		Node* node = this->head;
		while (node != nullptr) {
			Node* toDelete = node;
			node = node->getNext();
			delete toDelete;
		}
		this->head = nullptr;
		this->tail = nullptr;
		this->size = 0;
	}
}

size_t List::getSize() const
{
	return this->size;
}

bool List::isEmpty() const 
{
	if (this->size == 0)
		return true;
	return false;
}

List List::getReversed(List l)
{
	List newList = List();
	Node* currentListPtr = l.tail;
	newList.add(currentListPtr->getValue());

	for (size_t i = 1; i < l.getSize(); i++)
	{
		currentListPtr = currentListPtr->getPrev();
		newList.add(currentListPtr->getValue());
	}

	return newList;
}

std::string List::toString() const
{
	std::ostringstream ss;

	Node* ptr = this->head;
	for (size_t i = 0; i < this->size; i++)
	{
		ss << ptr->getValue() << ' ';
		ptr = ptr->getNext();
	}

	return ss.str();
}

List& List::operator<<(const int& value)
{
	this->add(value);

	return *this;
}

List& List::operator<<(const List& other)
{
	this->addAll(other);

	return *this;
}


