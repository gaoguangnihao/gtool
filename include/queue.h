
#ifndef QUEUI_H
#define QUEUI_H 

#include <pthread.h>

#include "log.h"

using namespace std;

#define DEBUG_QUEUE false

template <typename T>
class Node
{	
public:
	Node():next(NULL), data(NULL){};

	Node<T> * next;
	T data;
};

template <typename T>
class Queue
{
public:
	Queue();
	~Queue();

	void pop();
	void push(T data);

	T front();

	int length();

	bool empty();

private: 
	Node<T>* m_pFront;
	Node<T>* m_pBack;

	int mLength;
	mutable pthread_mutex_t             mLock;            // mutex lock

};

template <typename T>
Queue<T>::Queue():m_pFront(new Node<T>()){
	m_pFront->next = NULL;
	m_pFront->data = NULL;

	m_pBack = m_pFront;

	mLength = 0;

	pthread_mutex_init(&mLock, NULL);
}

template <typename T>
Queue<T>::~Queue() {
	delete m_pFront;
	m_pFront = NULL;
	m_pBack = NULL;

	mLength = 0;

	pthread_mutex_destroy(&mLock);
}

template <typename T>
int Queue<T>::length() {
	if (DEBUG_QUEUE) GLogD("Queue length = %d", mLength);
	return mLength;
};


template <typename T>
void Queue<T>::pop() {
	if (DEBUG_QUEUE) GLogD("Queue pop , m_pFront = %d data:%d, m_pBack = %d data:%d", 
		m_pFront, m_pFront->data, m_pBack, m_pBack->data);

	pthread_mutex_lock(&mLock);
	if (m_pFront->next) {
		Node<T>* p = m_pFront->next;
		m_pFront->next = p->next;
		if (p == m_pBack) {
			m_pBack = m_pFront;
		}
		delete p;
		p = NULL;
		mLength -= 1;
	}
	pthread_mutex_unlock(&mLock);
	if (DEBUG_QUEUE) GLogD("Queue pop end , m_pFront = %d data:%d, m_pBack = %d data:%d", 
		m_pFront, m_pFront->data, m_pBack, m_pBack->data);
}

template <typename T>
void Queue<T>::push(T data) {
	pthread_mutex_lock(&mLock);
	Node<T>* pTemp = new Node<T>();
	m_pBack->next = pTemp;
	pTemp->next = NULL;
	pTemp->data = data;

	m_pBack = pTemp;

	mLength += 1;
	pthread_mutex_unlock(&mLock);
	if (DEBUG_QUEUE) GLogD("Queue push , m_pFront = %d data:%d, m_pBack = %d data:%d", 
		m_pFront, m_pFront->data, m_pBack, m_pBack->data);
}

template <typename T>
bool Queue<T>::empty() {
	if (DEBUG_QUEUE) GLogD("Queue empty , m_pFront = %d data:%d, m_pBack = %d data:%d", 
		m_pFront, m_pFront->data, m_pBack, m_pBack->data);
	//bool ret = m_pFront == m_pBack;
	return mLength == 0 ? true : false;
}

template <typename T>
T Queue<T>::front() {
	if (DEBUG_QUEUE) GLogD("Queue front 11111");
	T *pData = NULL;
	pthread_mutex_lock(&mLock);
	if (m_pFront->next) {
		pData = &(m_pFront->next->data);
	}
	pthread_mutex_unlock(&mLock);
	return *pData;
}

#endif