
#include <unistd.h>

#include "thread.h"
#include "headers.h"

void GtoolThread::process(){
	GLogD("this is child thread tid: %d", this->getTid());
	while(1)  {
		sleep(1);
		if(m_queue.length()) {
			GLogD("process front data:%d, length:%d", m_queue.front(), m_queue.length());
			if (m_queue.front() == 5) {
				m_queue.pop();
				break;
			}
			m_queue.pop();	
		}
	}
}

extern "C" int thread_main(char **token, int len) {
	GLogD("thread main enter!2");
	GtoolThread* pThread = new GtoolThread();

	pThread->m_queue.push(1);
	pThread->m_queue.push(2);
	pThread->m_queue.push(3);

	GLogD("run!");
	pThread->run();
	
	GLogD("sleep 5s");
	sleep(5);
	GLogD("push 4");
	pThread->m_queue.push(4);
	GLogD("sleep 10s");
	sleep(10);
	GLogD("push 5");
	pThread->m_queue.push(5);
	GLogD("join");
	pThread->join();
	GLogD("return");
	return 0;
}