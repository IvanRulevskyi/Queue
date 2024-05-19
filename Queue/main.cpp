#include <iostream>
#include "queue"
using namespace std;

class Event
{
private:
    string eventName;
public:
    Event(const std::string& name) : eventName(name)
    { }
    std::string getName() const
    {
        return eventName;
    }
};

class EventProcessor
{
public:
    void processEvent(const Event& event)
    {
        cout << "Processing event: " << event.getName() << endl;
    }
};


int main()
{
    queue<queue<Event>> outerQueue;
    
    queue<Event> queue1;
    queue1.push(Event("Event1.1"));
    queue1.push(Event("Event1.2"));
    
    queue<Event> queue2;
    queue1.push(Event("Event2.1"));
    queue1.push(Event("Event2.2"));
    
    queue<Event> queue3;
    queue1.push(Event("Event3.1"));
    queue1.push(Event("Event3.2"));
    
    EventProcessor processor;

    while (!outerQueue.empty()) {
            queue<Event>& currentQueue = outerQueue.front();
            
            while (!currentQueue.empty()) {
                Event currentEvent = currentQueue.front();
                processor.processEvent(currentEvent);
                currentQueue.pop();
            }

            outerQueue.pop();
        }
    
    
}
