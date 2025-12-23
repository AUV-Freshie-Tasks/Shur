#pragma once

#include <unordered_map>
using namespace std;

template <typename T>
class Node {
	public:
	size_t key;
	T value;
	Node* next;
	Node* prev;

	Node(size_t key, T value) : key(key), value(value) {
	next = nullptr;
	prev = nullptr;
	}
};
template <typename T>
class LRUcache {
	public:
		size_t capacity;
		Node<T>* head = new Node(0, T());
		Node<T>* tail = new Node(0, T());
		unordered_map<size_t,Node<T>*> cache;
	
	LRUcache() : capacity(5) {
        head -> prev = nullptr;
	head -> next = tail;
	tail -> next = nullptr;
	tail -> prev = head;}

	void addNode(Node<T>* newNode)
	{
		Node<T>* temp = head -> next;
		head -> next = newNode;
		newNode -> next = temp;
		temp -> prev = newNode;
		newNode -> prev = head;
	}

	void rmNode(Node<T>* oldNode)
	{
		Node<T>* oldNodeNext = oldNode -> next;
		Node<T>* oldNodePrev = oldNode -> prev;
		oldNodeNext -> prev = oldNodePrev;
		oldNodePrev -> next = oldNodeNext;
		oldNode -> prev = nullptr;
		oldNode -> next = nullptr;
	}

	T get(size_t key)
	{
		if(cache.find(key) != cache.end())
		{
			Node<T>* temp = cache[key];
			rmNode(temp);
			addNode(temp);
			
			return (*temp).value;
		}

		return T();
	}

	void put(size_t key, T value)
	{
		if(cache.find(key) != cache.end())
		{
			Node<T>* temp = cache[key];
			rmNode(temp);
			addNode(temp);
			(*temp).value = value;
			return;
		}
		if(cache.size()>capacity-1)
		{
			Node<T>* tempp = tail -> prev;
			cache.erase((*tempp).key);
			rmNode(tempp);
		}

		Node<T>* temppp = new Node(key, value);
		addNode(temppp);
		cache[key] = temppp;
		return;
	}
};



