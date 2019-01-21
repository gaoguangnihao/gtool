


#ifndef GTOOLTHREAD_H
#define GTOOLTHREAD_H 


#include <utils/Thread.h>
#include "Queue.h"

using namespace android;

class GtoolThread : public Thread
{
public:
	GtoolThread(){};
	~GtoolThread(){};
	
	void process();
	
	Queue<int> m_queue;
private:
	bool threadLoop() {
		this->process();
		return false;
	};


};

#endif